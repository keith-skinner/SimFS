#include "partition.h"
#include <stdint.h>
#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#include "defines.h"


typedef uint8_t SIMFS_PARTITION_BLOCK[SIMFS_BLOCK_SIZE];
static SIMFS_PARTITION_BLOCK simfs_partition[SIMFS_NUMBER_OF_BLOCKS];

/**
 * Creates a partition using the file name if provided.
 * @param filename if filename is NULL, creates a new partition. If the
 * filename is invalid, writes an error to stderr and calls exit. If the
 * filename is valid, it reads the contents of the file into the partition.
 */
bool simfs_partition_create(char *filename) {
  // TODO - Done
  if (filename == NULL) {
    memset(simfs_partition, 0, sizeof(simfs_partition));
    return false;
  }

  FILE * file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Unable to open file: %s\n");
    exit(-1);
  }

  size_t count = fread(simfs_partition, SIMFS_BLOCK_SIZE, SIMFS_NUMBER_OF_BLOCKS, file);
  if (count != SIMFS_NUMBER_OF_BLOCKS) {
    printf("Partition file read ended abruptly.\n");
    exit(-1);
  }
  
  return true;
}

/**
 * Saves the partition to the file.
 * @param filename if filename is NULL, does nothing. If filename
 * is invalid, writes a different error to stderr. If the filename is valid,
 * writes the contents of the partition to the file.
 */
void simfs_partition_save(char *filename) {
  // TODO - Done
  if (filename == NULL)
    return;
  
  FILE * file = fopen(filename, "wb");
  if (file == NULL) {
    printf("Unable to open file: %s\n");
    exit(-2);
  }

  size_t count = fwrite(simfs_partition, SIMFS_BLOCK_SIZE, SIMFS_NUMBER_OF_BLOCKS, file);
  if (count != SIMFS_NUMBER_OF_BLOCKS) {
    printf("Error writing partition to file.\n");
  }
}

/**
 * Releases the partition, putting it in an invalid state.
 * @note This is mostly for testing purposes and memory cleanup.
 */
void simfs_partition_release() {
  // TODO - Done
  memset(simfs_partition, 0, sizeof(simfs_partition));
}

static bool validIndex(SIMFS_INDEX_TYPE index)
{
  return (0 < index) && (index < simfs_partition_numberOfBlocks());
}

/**
 * Returns the contents of the block indicated by index.
 * @param index Index is valid in the range [0-SIMFS_NUMBER_OF_BLOCKS).
 * @return If index is invalid, NULL is returned. If index is valid, will return
 * a pointer to a valid block.
 */
void *simfs_partition_getBlock(SIMFS_INDEX_TYPE index) {
  // TODO - Done
  if (validIndex(index))
    return simfs_partition[index];
  return NULL;
}

/**
 * Sets the contents of a block, indexed at position index, to the value of
 * block provided.
 * @param block If block is NULL, does nothing.
 * @param index Index is valid in the range [0-SIMFS_NUMBER_OF_BLOCKS)
 */
void simfs_partition_setBlock(void *block, SIMFS_INDEX_TYPE index) {
  // TODO - Done
  if (validIndex(index))
    memcpy(simfs_partition[index], block, sizeof(simfs_partition[index]));
}

/**
 * Returns the number of blocks in the partition.
 */
int simfs_partition_numberOfBlocks() {
  // TODO - Done
  return SIMFS_NUMBER_OF_BLOCKS;
}

/**
 * Returns the size of a block in the partition.
 */
int simfs_partition_sizeOfBlock() {
  // TODO - Done
  return SIMFS_BLOCK_SIZE;
}
