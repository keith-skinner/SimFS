#pragma once

#ifdef SIMFS_LIGHT
#define SIMFS_BLOCK_SIZE 64         // 2^6
#define SIMFS_NUMBER_OF_BLOCKS 4096 // 2^12
#else                               //SIMFS_LIGHT
#define SIMFS_BLOCK_SIZE 256        // 2^8
#define SIMFS_NUMBER_OF_BLOCKS 4096 // 2^12
#endif                              //SIMFS_LIGHT