#define SIMFS_LIGHT 1
#include <stdio.h>
#include <time.h>
#include "src/volume/block/descriptor.h"
#include "src/volume/volume.h"

char* content_str[] = {"INVALID_CONTENT_TYPE", "FOLDER_CONTENT_TYPE",
                       "FILE_CONTENT_TYPE", "INDEX_CONTENT_TYPE",
                       "DATA_CONTENT_TYPE"};

void printSuperblock() {
  printf("\nSuperblock Information\n");
  printf("  Root Node Index:        %d\n", simfs_volume_getRootNodeIndex());
  printf("  Number of Blocks:       %d\n", simfs_volume_numberOfBlocks());
  printf("  Size of Blocks:         %d\n", simfs_volume_sizeOfBlock());
}

void printRootNode() {
  SIMFS_INDEX_TYPE root = simfs_volume_getRootNodeIndex();
  SIMFS_BLOCK_TYPE block = simfs_volume_getBlock(root);
  SIMFS_FILE_DESCRIPTOR_TYPE* fd = &block.content.descriptor;

  printf("\nRoot Node Information\n");
  printf("  Block Type:             %s\n", content_str[block.type]);
  printf("  Name:                   \"%s\"\n", fd->name);
  printf("  Type:                   %s\n", content_str[fd->type]);
  printf("  Creation Time:          %s", ctime(&fd->creationTime));
  printf("  Last Access Time:       %s", ctime(&fd->lastAccessTime));
  printf("  Last Modification Time: %s", ctime(&fd->lastModificationTime));
  printf("  Owner:                  %d\n", fd->owner);
  printf("  Group:                  %d\n", fd->group);
  printf("  Size:                   %d\n", fd->size);
  printf("  Block Reference:        %d\n", fd->block_ref);
  printf("  Parent Reference:       %d\n", fd->parent);
}

void create_and_print(char* file) {
  simfs_volume_create(file);
  printSuperblock();
  printRootNode();
}

int main(int argc, char** argv) {
  printf("\nTesting Step 1\n\n");
  create_and_print(NULL);
  if (argc >= 2) {
    simfs_volume_save(argv[1]);
    simfs_volume_release();
    create_and_print(argv[1]);
    simfs_volume_release();
  }
  return 0;
}