#pragma once

/**
 * Describes the content used inside either a block or a file descriptor.
 */
typedef enum
{
    INVALID_CONTENT_TYPE,
    FOLDER_CONTENT_TYPE,
    FILE_CONTENT_TYPE,
    INDEX_CONTENT_TYPE,
    DATA_CONTENT_TYPE
} SIMFS_CONTENT_TYPE;
