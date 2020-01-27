#include "volume.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "../partition/defines.h"
#include "../partition/partition.h"

// Describes how many bits are in a block
#define SIMFS_BITS_IN_BLOCK (SIMFS_BLOCK_SIZE * 8)
// Describes how many bytes are needed in the bitvector
#define SIMFS_BYTES_IN_VECTOR \
  ( (SIMFS_NUMBER_OF_BLOCKS / 8) + ((SIMFS_NUMBER_OF_BLOCKS % 8) == 0) )
// Describes how many blocks in the partition are needed for the bitvector
#define SIMFS_BLOCKS_IN_VECTOR                       \
  ((SIMFS_BYTES_IN_VECTOR / SIMFS_BLOCK_SIZE) +      \
       ((SIMFS_BYTES_IN_VECTOR % SIMFS_BLOCK_SIZE) == \
   0))
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
    // should point to the first block after the last bitvector block
    SIMFS_INDEX_TYPE rootNodeIndex;
    int numberOfBlocks;
    int blockSize;
  } attr;
} SIMFS_SUPERBLOCK_TYPE;

typedef SIMFS_PARTITION_BLOCK SIMFS_BITVECTOR_TYPE[SIMFS_BLOCKS_IN_VECTOR];
typedef SIMFS_PARTITION_BLOCK SIMFS_BLOCKS_TYPE[SIMFS_BLOCKS_IN_VOLUME];

static void createSuperblock() {
  SIMFS_SUPERBLOCK_TYPE *superblock =
      simfs_partition_getBlock(SIMFS_SUPERBLOCK_INDEX);
  superblock->attr.numberOfBlocks = SIMFS_BLOCKS_IN_VOLUME;
  superblock->attr.blockSize = simfs_partition_sizeOfBlock();
}

static void createBitvector() {
  for (int i = 0; i < SIMFS_BLOCKS_IN_VECTOR; ++i)
    memset(simfs_partition_getBlock(SIMFS_BITVECTOR_INDEX + i), 0,
           sizeof(SIMFS_PARTITION_BLOCK));
}

static void createRoot() {
  time_t rawTime;
  time(&rawTime);

  SIMFS_BLOCK_TYPE block = {0};
  block.type = FOLDER_CONTENT_TYPE;

  SIMFS_FILE_DESCRIPTOR_TYPE *fd = &block.content.descriptor;
  strcpy(fd->name, "");
  fd->type = FOLDER_CONTENT_TYPE;
  fd->creationTime = rawTime;
  fd->lastAccessTime = rawTime;
  fd->lastModificationTime = rawTime;
  fd->accessRights = 0666;
  fd->owner = getuid();
  fd->group = getgid();
  fd->size = 0;
  fd->block_ref = SIMFS_INVALID_INDEX;
  fd->parent = SIMFS_INVALID_INDEX;

  SIMFS_INDEX_TYPE rootIndex = simfs_volume_allocateBlock();
  SIMFS_SUPERBLOCK_TYPE *superblock =
      simfs_partition_getBlock(SIMFS_SUPERBLOCK_INDEX);
  superblock->attr.rootNodeIndex = rootIndex;
  simfs_volume_setBlock(&block, rootIndex);
}

/**
 * Creates a volume using the file name if provided.
 * @param filename if filename is NULL, creates a new volume. If the
 * filename is invalid, writes an error to stderr and calls exit. If the
 * filename is valid, it reads the contents of the file into the volume.
 */
void simfs_volume_create(char *filename) {
  // TODO - Done
  bool newPartition = simfs_partition_create(filename);
  if (!newPartition) {
    createSuperblock();
    createBitvector();
    createRoot();
  }
}

/**
 * Saves the volume to the file.
 * @param filename if filename is NULL, writes an error to stderr. If filename
 * is invalid, writes a different error to stderr. If the filename is valid,
 * writes the contents of the volume to the file.
 */
void simfs_volume_save(char *filename) {
  // TODO - Done
  simfs_partition_save(filename);
}

/**
 * Releases the volume, putting it in an invalid state.
 * @note This is mostly for testing purposes and memory cleanup.
 */
void simfs_volume_release() {
  // TODO - Done
  simfs_partition_release();
}

static SIMFS_BLOCK_TYPE *getVolumeBlock(SIMFS_INDEX_TYPE index) {
  return simfs_partition_getBlock(SIMFS_BLOCKS_INDEX + index);
}

/**
 * Returns the contents of the block indicated by index.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @return If index is invalid, a default block is returned. If index is valid,
 * will return a copy of the block at the given index.
 */
SIMFS_BLOCK_TYPE simfs_volume_getBlock(SIMFS_INDEX_TYPE index) {
  // TODO - Done
  if (index < simfs_volume_numberOfBlocks()) {
    return *getVolumeBlock(index);
  }
  return (SIMFS_BLOCK_TYPE){0};
}

/**
 * Changes the contents of a block in the volume indicated by index.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @param block A block containing the contents wished to be copied.
 */
void simfs_volume_setBlock(SIMFS_BLOCK_TYPE *block, SIMFS_INDEX_TYPE index) {
  // TODO - Done
  if (index < simfs_volume_numberOfBlocks()) {
    simfs_partition_setBlock(block, SIMFS_BLOCKS_INDEX + index);
  }
}

static SIMFS_INDEX_TYPE findFreeBlockInByte(uint8_t b) {
  for (int i = 0; i < 8; ++i)
    if (((1 << i) & b) == 0) return i;
  return SIMFS_INVALID_INDEX;
}

static SIMFS_INDEX_TYPE findFreeBlockInVectorBlock(SIMFS_INDEX_TYPE index) {
  SIMFS_PARTITION_BLOCK *block = simfs_partition_getBlock(index);
  for (int i = 0; i < SIMFS_BLOCK_SIZE; ++i) {
    SIMFS_INDEX_TYPE byte = findFreeBlockInByte((*block)[i]);
    if (byte != SIMFS_INVALID_INDEX) return 8 * i + byte;
  }
  return SIMFS_INVALID_INDEX;
}

/**
 * Finds the first available free block and returns its index.
 * If there are no free blocks, then SIMFS_INVALID_INDEX is returned.
 */
SIMFS_INDEX_TYPE simfs_volume_allocateBlock() {
  // TODO - Done
  for (int b = 0; b < SIMFS_BLOCKS_IN_VECTOR; ++b) {
    SIMFS_INDEX_TYPE freeBlock =
        findFreeBlockInVectorBlock(SIMFS_BITVECTOR_INDEX + b);
    if (freeBlock != SIMFS_INVALID_INDEX)
      return SIMFS_BLOCK_SIZE * b + freeBlock;
  }
  return SIMFS_INVALID_INDEX;
}

/**
 * Releases the block in the volume indicated by index to be allowed to be
 * allocated again.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @note if index is invalid, nothing happens.
 */
void simfs_volume_deallocateBlock(SIMFS_INDEX_TYPE index) {
  // TODO - Done
  if (index < simfs_volume_numberOfBlocks()) return;

  int block = index / SIMFS_BITS_IN_BLOCK;
  index -= block * SIMFS_BITS_IN_BLOCK;
  int byte = index / 8;
  index -= block * 8;
  int bit = index;

  SIMFS_PARTITION_BLOCK *pblock =
      simfs_partition_getBlock(SIMFS_BITVECTOR_INDEX + block);
  (*pblock)[byte] |= 0xFF ^ (1 << bit);
}

static SIMFS_SUPERBLOCK_TYPE *getSuperblock() {
  return simfs_partition_getBlock(SIMFS_SUPERBLOCK_INDEX);
}

/**
 * Returns an index to the root folder's descriptor block.
 */
SIMFS_INDEX_TYPE simfs_volume_getRootNodeIndex() {
  // TODO - Done
  return getSuperblock()->attr.rootNodeIndex;
}

/**
 * Returns the number of blocks in the volume
 */
int simfs_volume_numberOfBlocks() {
  // TODO - Done
  return getSuperblock()->attr.numberOfBlocks;
}

/**
 * Returns the size of one of the blocks.
 */
int simfs_volume_sizeOfBlock() {
  // TODO - Done
  return getSuperblock()->attr.blockSize;
}
