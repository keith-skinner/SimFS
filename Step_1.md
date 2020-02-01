# **Step 1** *Creating the Volume*

At the end of this step your task is to run the application with a valid filename that does not exist

```
> ./step1 hello.txt
```
    
If you've ran this test before, delete the file and run it again or choose a different file name.

The application will call `simfs_volume_create`, with `NULL`. This will create a new `simfs_partition` and format it.
Then, display the contents of the superblock, as well as the root directory, (description of what this should look like below).
Call `simfs_volume_save`, to save the volume to the file called `argv[1]` (yes you will need to start the program with arguments).
Finally call `simfs_volume_create` again, this time with the 
    - This proves the contents of `simfs_volume` will persist through multiple runs just like a real volume.

> "A block, a contiguous number of bytes, is the minimum unit of storage that is read from and written to a disk by a disk driver ... Modern hard disk drives, such as Serial attached SCSI (SAS) and Serial ATA (SATA) drives, appear at their interfaces as a contiguous set of fixed-size blocks; for many years 512 bytes long but beginning in 2009 and accelerating through 2011, all major hard disk drive manufacturers began releasing hard disk drive platforms using the Advanced Format of 4096 byte logical blocks."  
> https://en.wikipedia.org/wiki/Disk_formatting

> "High-level formatting creates the file system format within a disk partition or a logical volume. This formatting includes the data structures used by the OS to identify the logical drive or partition's contents. This may occur during operating system installation, or when adding a new disk. Disk and distributed file system may specify an optional boot block, and/or various volume and directory information for the operating system."  
> https://en.wikipedia.org/wiki/Disk_formatting


## The Partition

The `simfs_partition` is comprised of blocks and our block size is defined as `SIMFS_BLOCK_SIZE`. The format of those blocks will contain 3 sections:

- A superblock for maintaing meta information about the volume
- A bit-vector for maintaining the free/used storage on the volume
- The remaining blocks which provide the storage

But the partition doesn't know that. All it undestands is that it holds blocks. It will be up to you to implement an interface in the volume that allows 

## Superblock

The superblock holds information about the file system such as the number of blocks for storage, the size of a block, and a reference to the block holding the root folder ( "/" or "F:\\" ) of the file system.

## Bitvector

The bitvector, that spans a number of blocks, holds bits that indicate whether the corresponding blocks in the volume are free or not. Hence, there are as many bits in the bitvector as there are blocks in the storage.

**You will need to use [bit-wise operations][bitwise_opers] to search and modify bits in the bitvector.**

## Blocks

The storage section of the `simfs_volume` consists of blocks that are used by folders and files.

Each block can be one of the following:

- A file descriptor (used for both files and folders)
- An array of indices to other blocks
- An array of raw data (in bytes)

The ability to resuse the same space in memory for multiple types (or arrays of types) means that a block has, as its first member, a 'block type'. This will tell you how to interpret a block or needs to be set to the appropriate type when you 'allocate' a block.

## Interface

The only files allowed to use `partition.h` should be `volume.h`.
`partition.h` is a code example of a physical drive and `volume.h` is the logical abstraction of that physical thing so we can use it in code. This makes the volume a wrapper around the partition in our case.

## Example Output

```
PS C:\Users\User\SimFS\build> .\step1.exe hello.txt

Testing Step 1

Superblock Information
  Root Node Index:        0
  Number of Blocks:       4091
  Size of Blocks:         128

Root Node Information
  Block Type:             FOLDER_CONTENT_TYPE
  Name:                   ""
  Type:                   FOLDER_CONTENT_TYPE
  Creation Time:          Tue Jan 28 02:21:03 2020
  Last Access Time:       Tue Jan 28 02:21:03 2020
  Last Modification Time: Tue Jan 28 02:21:03 2020
  Owner:                  7
  Group:                  5
  Size:                   0
  Block Reference:        65535
  Parent Reference:       65535

Superblock Information
  Root Node Index:        0
  Number of Blocks:       4091
  Size of Blocks:         128

Root Node Information
  Block Type:             FOLDER_CONTENT_TYPE
  Name:                   ""
  Type:                   FOLDER_CONTENT_TYPE
  Creation Time:          Tue Jan 28 02:21:03 2020
  Last Access Time:       Tue Jan 28 02:21:03 2020
  Last Modification Time: Tue Jan 28 02:21:03 2020
  Owner:                  7
  Group:                  5
  Size:                   0
  Block Reference:        65535
  Parent Reference:       65535

PS C:\Users\User\SimFS\build>
```

[bitwise_opers]: https://en.cppreference.com/w/c/language/operator_arithmetic