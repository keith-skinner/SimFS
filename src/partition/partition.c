#include "partition.h"
#include <stdint.h>
#include "defines.h"

typedef uint8_t simfs_partition_block[SIMFS_BLOCK_SIZE];
static simfs_partition_block simfs_partition[SIMFS_NUMBER_OF_BLOCKS];

void simfs_partition_create(char *filename)
{
    // TODO
}

void simfs_partition_save(char *filename)
{
    // TODO
}

void simfs_partition_release()
{
    // TODO
}

void *simfs_partition_getBlock(SIMFS_INDEX_TYPE index)
{
    // TODO
    return NULL;
}

void simfs_partition_setBlock(void *block, SIMFS_INDEX_TYPE index)
{
    // TODO
}