//! This file is all #defines and therefore does not need
//! to worry about being included multiple times and therefore
//! does not need a header guard.

#ifdef SIMFS_LIGHT
// Total size of parition = 64B * 4096B = 256KB = 0.25BG
#define SIMFS_BLOCK_SIZE 64         // 2^6
#define SIMFS_NUMBER_OF_BLOCKS 4096 // 2^12
#else
// Total size of parition = 128B * 4096B = 512KB = 0.5GB
#define SIMFS_BLOCK_SIZE 128        // 2^8
#define SIMFS_NUMBER_OF_BLOCKS 4096 // 2^12
#endif
