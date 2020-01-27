#include <stdio.h>
#include "src/volume/block/descriptor.h"
#include "src/volume/volume.h"

#define println(format) printf(format "\n")
#define printlf(format, ...) printf(format "\n", __VA_ARGS__)

char * content_str[] = {
    "INVALID_CONTENT_TYPE",
    "FOLDER_CONTENT_TYPE",
    "FILE_CONTENT_TYPE",
    "INDEX_CONTENT_TYPE",
    "DATA_CONTENT_TYPE"
}

int main(int argc, char** argv) {
  printf("Testing Step 1");

  if (argc < 2)
    simfs_volume_create(NULL);
  else
    simfs_volume_create(argv[1]);

  SIMFS_INDEX_TYPE root = simfs_volume_getRootNodeIndex();
  SIMFS_BLOCK_TYPE block = simfs_volume_getBlock(root);
  SIMFS_FILE_DESCRIPTOR_TYPE * fd = &block.content.descriptor;

  println("Superblock Information");
  printlf("  Root Node Index: %d", simfs_volume_getRootNodeIndex());
  printlf("  Number of Blocks: %d", simfs_volume_numberOfBlocks());
  printlf("  Size of Blocks: %d", simfs_volume_sizeOfBlock());
  println("");
  println("Root Node Information");
  printlf("  Block Type: %s", content_str[block.type]);
  println("  Content");
  printlf("    Name: %s", block.content.name);

  return 0;
}