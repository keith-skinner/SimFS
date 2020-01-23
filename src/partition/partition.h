#pragma once

#include "index.h"
#include "defines.h"

typedef unsigned char simfs_partition_block[SIMFS_BLOCK_SIZE];

/**
 * Creates a partition using the file name if provided.
 * @param filename if filename is null, creates a new partition. If the
 * filename is invalid, writes an error to stderr and calls exit. If the
 * filename is valid, it reads the contents of the file into the partition.
 */
void simfs_partition_create(char *filename);

/**
 * Saves the partition to the file.
 * @param filename if filename is null, writes an error to stderr. If filename
 * is invalid, writes a different error to stderr. If the filename is valid,
 * writes the contents of the partition to the file.
 */
void simfs_partition_save(char *filename);

/**
 * Releases the partition, putting it in an invalid state.
 * @note This is mostly for testing purposes and memory cleanup.
 */
void simfs_partition_release();

/**
 * Returns the contents of the block indicated by index.
 * @param index Index is valid in the range [0-SIMFS_NUMBER_OF_BLOCKS).
 * @return If index is invalid, NULL is returned. If index is valid, will return a pointer to a valid block.
 */
simfs_partition_block *simfs_partition_getBlock(SIMFS_INDEX_TYPE index);

/**
 * Sets the contents of a block, indexed at position index, to the value of block provided.
 * @param block If block is NULL, then immidiate return.
 * @param index Index is valid in the range [0-SIMFS_NUMBER_OF_BLOCKS)
 */
void simfs_partition_setBlock(simfs_partition_block *block, SIMFS_INDEX_TYPE index);
