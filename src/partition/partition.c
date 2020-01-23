#include "partition.h"
#include <stddef.h>

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

simfs_partition_block *simfs_partition_getBlock(SIMFS_INDEX_TYPE index)
{
    // TODO
    return NULL;
}

void simfs_partition_setBlock(simfs_partition_block *block, SIMFS_INDEX_TYPE index)
{
    // TODO
}