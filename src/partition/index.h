#pragma once

// Reference type describing positions/offsets in the simfs_volume
// Acts like a fake pointer
typedef unsigned short SIMFS_INDEX_TYPE;

// An always Invalid index
// Acts like NULL for SIMFS_INDEX_TYPE
#define SIMFS_INVALID_INDEX 0xFFFF
