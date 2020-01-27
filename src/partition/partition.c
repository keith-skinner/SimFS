#include "partition.h"
#include <stdint.h>
#include "defines.h"

typedef uint8_t simfs_partition_block[SIMFS_BLOCK_SIZE];
static simfs_partition_block simfs_partition[SIMFS_NUMBER_OF_BLOCKS];

/**
 * Creates a partition using the file name if provided.
 * @param filename if filename is NULL, creates a new partition. If the
 * filename is invalid, writes an error to stderr and calls exit. If the
 * filename is valid, it reads the contents of the file into the partition.
 */
void simfs_partition_create(char *filename) {
  // TODO
}

/**
 * Saves the partition to the file.
 * @param filename if filename is NULL, writes an error to stderr. If filename
 * is invalid, writes a different error to stderr. If the filename is valid,
 * writes the contents of the partition to the file.
 */
void simfs_partition_save(char *filename) {
  // TODO
}

/**
 * Releases the partition, putting it in an invalid state.
 * @note This is mostly for testing purposes and memory cleanup.
 */
void simfs_partition_release() {
  // TODO
}

/**
 * Returns the contents of the block indicated by index.
 * @param index Index is valid in the range [0-SIMFS_NUMBER_OF_BLOCKS).
 * @return If index is invalid, NULL is returned. If index is valid, will return
 * a pointer to a valid block.
 */
void *simfs_partition_getBlock(SIMFS_INDEX_TYPE index) {
  // TODO
  return NULL;
}

/**
 * Sets the contents of a block, indexed at position index, to the value of
 * block provided.
 * @param block If block is NULL, then immidiate return.
 * @param index Index is valid in the range [0-SIMFS_NUMBER_OF_BLOCKS)
 */
void simfs_partition_setBlock(void *block, SIMFS_INDEX_TYPE index) {
  // TODO
}

/**
 * Returns the number of blocks in the partition.
 */
int simfs_partition_numberOfBlocks() {
  // TODO
  return -1;
}

/**
 * Returns the size of a block in the partition.
 */
int simfs_partition_sizeOfBlock() {
  // TODO
  return -1;
}
