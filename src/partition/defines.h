//! This file is all #defines and therefore does not need
//! to worry about being included multiple times and therefore
//! does not need a header guard.

// Total size of parition = 128B * 4096B = 512KB = 0.5GB
#define SIMFS_BLOCK_SIZE 128         // 2^8
#define SIMFS_NUMBER_OF_BLOCKS 4096  // 2^12
