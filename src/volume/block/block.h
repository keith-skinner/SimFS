#pragma once

// SIMFS_BLOCK_SIZE is needed for some of the calculations within this file, but
// the definitions in ../../parition/defines.h should not be part of the
// interface  of this file. Therefore we remove the macro definitions after the
// fact.
#ifdef SIMFS_BLOCK_SIZE
#define SIMFS_BLOCK_SIZE_SAVE SIMFS_BLOCK_SIZE
#endif

#ifdef SIMFS_NUMBER_OF_BLOCKS
#define SIMFS_NUMBER_OF_BLOCKS_SAVE SIMFS_NUMBER_OF_BLOCKS
#endif

#include "../../partition/defines.h"
#include "content.h"
#include "descriptor.h"

#define SIMFS_CONTENT_SIZE                         \
  (SIMFS_BLOCK_SIZE - sizeof(SIMFS_CONTENT_TYPE) - \
   4)  // The -4 is a hidden int only visible by the compiler (it has to do with
       // a union's active member)
#define SIMFS_DATA_SIZE (SIMFS_CONTENT_SIZE / sizeof(unsigned char))
#define SIMFS_INDEX_SIZE (SIMFS_CONTENT_SIZE / sizeof(SIMFS_INDEX_TYPE))

typedef unsigned char SIMFS_DATA_TYPE[SIMFS_DATA_SIZE];
typedef SIMFS_INDEX_TYPE SIMFS_INDICES_TYPE[SIMFS_INDEX_SIZE];

typedef struct simfs_block_type {
  // Describes what data the block is holding
  SIMFS_CONTENT_TYPE type;
  union content_tag {
    // meta information for folders and files
    SIMFS_FILE_DESCRIPTOR_TYPE descriptor;
    // array of raw data for files
    SIMFS_DATA_TYPE data;
    // array of indices to other blocks.
    // the last index will be invalid or another index block to "chain" index
    // blocks
    SIMFS_INDICES_TYPE index;
  } content;
} SIMFS_BLOCK_TYPE;

#undef SIMFS_BLOCK_SIZE
#ifdef SIMFS_BLOCK_SIZE_SAVE
#define SIFMS_BLOCK_SIZE SIMFS_BLOCK_SIZE_SAVE
#endif

#undef SIMFS_NUMBER_OF_BLOCKS
#ifdef SIMFS_NUMBER_OF_BLOCKS_SAVE
#define SIMFS_NUMBER_OF_BLOCKS SIMFS_NUMBER_OF_BLOCKS_SAVE
#endif
