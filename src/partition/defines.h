#pragma once

#ifdef SIMFS_LIGHT
#define SIMFS_BLOCK_SIZE 64         // 2^6
#define SIMFS_NUMBER_OF_BLOCKS 4096 // 2^12
//Total size of parition = 64B * 4096B = 256 KB
#else                               //SIMFS_LIGHT
#define SIMFS_BLOCK_SIZE 128        // 2^8
#define SIMFS_NUMBER_OF_BLOCKS 4096 // 2^12
//Total size of parition = 128B * 4096B = 512 KB = 0.5 GB
#endif                              //SIMFS_LIGHT