#include "volume.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "../partition/defines.h"
#include "../partition/partition.h"

// Describes how many bytes are needed in the bitvector
#define SIMFS_BYTES_IN_VECTOR (SIMFS_NUMBER_OF_BLOCKS / 8)
// Describes how many blocks in the partition are needed for the bitvector
#define SIMFS_BLOCKS_IN_VECTOR                  \
  ((SIMFS_BYTES_IN_VECTOR / SIMFS_BLOCK_SIZE) + \
   (SIMFS_BYTES_IN_VECTOR % SIMFS_BLOCK_SIZE))
// Describes how many blocks are available for use in the partition
// After excluding those for the superblock, and bitvector
#define SIMFS_BLOCKS_IN_VOLUME \
  (SIMFS_NUMBER_OF_BLOCKS - 1 - SIMFS_BLOCKS_IN_VECTOR)

#define SIMFS_SUPERBLOCK_INDEX 0
#define SIMFS_BITVECTOR_INDEX 1
#define SIMFS_BLOCKS_INDEX (SIMFS_BITVECTOR_INDEX + SIMFS_BLOCKS_IN_VECTOR)

typedef uint8_t SIMFS_PARTITION_BLOCK[SIMFS_BLOCK_SIZE];

typedef union simfs_superblock_type {
  SIMFS_PARTITION_BLOCK dummy;  // this makes the struct exactly one block
  struct attr {
    SIMFS_INDEX_TYPE
    rootNodeIndex;  // should point to the first block after the last bitvector
                    // block
    int numberOfBlocks;
    int blockSize;
  } attr;
} SIMFS_SUPERBLOCK_TYPE;

typedef SIMFS_PARTITION_BLOCK SIMFS_BITVECTOR_TYPE[SIMFS_BLOCKS_IN_VECTOR];
typedef SIMFS_PARTITION_BLOCK SIMFS_BLOCKS_TYPE[SIMFS_BLOCKS_IN_VOLUME];

typedef struct simfs_volume {
  SIMFS_SUPERBLOCK_TYPE *superblock;
  SIMFS_BITVECTOR_TYPE *bitvector;
  SIMFS_BLOCKS_TYPE *blocks;
} SIMFS_VOLUME;

// Singleton instance of volume
static SIMFS_VOLUME simfs_volume;

/**
 * Creates a volume using the file name if provided.
 * @param filename if filename is NULL, creates a new volume. If the
 * filename is invalid, writes an error to stderr and calls exit. If the
 * filename is valid, it reads the contents of the file into the volume.
 */
void simfs_volume_create(char *filename) {
  // TODO
}

/**
 * Saves the volume to the file.
 * @param filename if filename is NULL, writes an error to stderr. If filename
 * is invalid, writes a different error to stderr. If the filename is valid,
 * writes the contents of the volume to the file.
 */
void simfs_volume_save(char *filename) {
  // TODO
}

/**
 * Releases the volume, putting it in an invalid state.
 * @note This is mostly for testing purposes and memory cleanup.
 */
void simfs_volume_release() {
  // TODO
}

/**
 * Returns the contents of the block indicated by index.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @return If index is invalid, a default block is returned. If index is valid,
 * will return a copy of the block at the given index.
 */
SIMFS_BLOCK_TYPE simfs_volume_getBlock(SIMFS_INDEX_TYPE index) {
  // TODO
  return (SIMFS_BLOCK_TYPE){};
}

/**
 * Changes the contents of a block in the volume indicated by index.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @param block A block containing the contents wished to be copied.
 */
void simfs_volume_setBlock(SIMFS_INDEX_TYPE index, SIMFS_BLOCK_TYPE *block) {
  // TODO
}

/**
 * Finds the first available free block and returns its index.
 * If there are no free blocks, then SIMFS_INVALID_INDEX is returned.
 */
SIMFS_INDEX_TYPE simfs_volume_allocateBlock() {
  // TODO
  return SIMFS_INVALID_INDEX;
}

/**
 * Releases the block in the volume indicated by index to be allowed to be
 * allocated again.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @note if index is invalid, nothing happens.
 */
void simfs_volume_deallocateBlock(SIMFS_INDEX_TYPE index) {
  // TODO
}

/**
 * Returns an index to the root folder's descriptor block.
 */
SIMFS_INDEX_TYPE simfs_volume_getRootNodeIndex() {
  // TODO
  return SIMFS_INVALID_INDEX;
}

/**
 * Returns the number of blocks in the volume
 */
int simfs_volume_numberOfBlocks() {
  // TODO
  return -1;
}

/**
 * Returns the size of one of the blocks.
 */
int simfs_volume_sizeOfBlock() {
  // TODO
  return -1;
}
