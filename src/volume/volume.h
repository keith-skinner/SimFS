#pragma once
#include "../partition/index.h"
#include "block/block.h"

/**
 * Creates a volume using the file name if provided.
 * @param filename if filename is NULL, creates a new volume. If the
 * filename is invalid, writes an error to stderr and calls exit. If the
 * filename is valid, it reads the contents of the file into the volume.
 */
void simfs_volume_create(char *filename);

/**
 * Saves the volume to the file.
 * @param filename if filename is NULL, writes an error to stderr. If filename
 * is invalid, writes a different error to stderr. If the filename is valid,
 * writes the contents of the volume to the file.
 */
void simfs_volume_save(char *filename);

/**
 * Releases the volume, putting it in an invalid state.
 * @note This is mostly for testing purposes and memory cleanup.
 */
void simfs_volume_release();

/**
 * Returns the contents of the block indicated by index.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @return If index is invalid, a default block is returned. If index is valid,
 * will return a copy of the block at the given index.
 */
SIMFS_BLOCK_TYPE simfs_volume_getBlock(SIMFS_INDEX_TYPE index);

/**
 * Changes the contents of a block in the volume indicated by index.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @param block A block containing the contents wished to be copied.
 */
void simfs_volume_setBlock(SIMFS_INDEX_TYPE index, SIMFS_BLOCK_TYPE *block);

/**
 * Finds the first available free block and returns its index.
 * If there are no free blocks, then SIMFS_INVALID_INDEX is returned.
 */
SIMFS_INDEX_TYPE simfs_volume_allocateBlock();

/**
 * Releases the block in the volume indicated by index to be allowed to be allocated again.
 * @param index Index is valid in the range [0-simfs_volume_numberOfBlocks).
 * @note if index is invalid, nothing happens.
 */
void simfs_volume_deallocateBlock(SIMFS_INDEX_TYPE index);

/**
 * Returns an index to the root folder's descriptor block.
 */
SIMFS_INDEX_TYPE simfs_volume_getRootNodeIndex();

/**
 * Returns the number of blocks in the volume
 */
int simfs_volume_numberOfBlocks();

/**
 * Returns the size of one of the blocks.
 */
int simfs_volume_sizeOfBlock();
