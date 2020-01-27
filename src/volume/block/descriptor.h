#pragma once

#include <sys/types.h>
#include <time.h>
#include "../../partition/index.h"
#include "content.h"
#include "../../sys/types.h"  //TODO: KEITH: Remove this later.  

// The name length has to fit within padding and SIMFS_BLOCK_SIZE

#define SIMFS_MAX_NAME_LENGTH 68

// Describes the size of a file or folder.
typedef unsigned short SIMFS_SIZE_TYPE;

// Defines the maximum length of file and folder names
typedef char SIMFS_NAME_TYPE[SIMFS_MAX_NAME_LENGTH];

typedef struct simfs_file_descriptor_type {
  SIMFS_NAME_TYPE name;         // relative file/folder name
  SIMFS_CONTENT_TYPE type;      // folder or file
  time_t creationTime;          // creation time
  time_t lastAccessTime;        // last access
  time_t lastModificationTime;  // last modification
  mode_t accessRights;          // access rights for the file
  uid_t owner;                  // owner ID
  gid_t group;                  // group ID
  SIMFS_SIZE_TYPE size;         // capacity limited for this project to 2^16
  SIMFS_INDEX_TYPE block_ref;   // reference to the data or index block
  SIMFS_INDEX_TYPE parent;      // reference to the parent folder
} SIMFS_FILE_DESCRIPTOR_TYPE;
