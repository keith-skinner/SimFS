# SimFS
Simulated File System Final Project for Operating Systems

## Instructions

### Introduction

In the next several classes, you will be working on implementing an "in-memory" file system simulator. You will then integrate it with [FUSE][fuse_repo], to allow users to interact with your simulated file system (SimFS). There will be no distinction between interacting with the simulated file system and any other file system available to the users of the operating system. 

You will be able to explore the simulated file system; create and delete files and folders; inspect the folders and files; open and close files; read and write to files.

This repository contains the declarations for the data structures and functions that you must use in this assignment. At the end of each step make a tag and palce an x in the corresponding box, declaring a mark of your progress.

This project is large and will take you a significant amount of time to complete. ***Do not underestimate this assignment.***

This assignment can take large amounts of RAM to use. If you are using a virtual machine, and in general while testing, it may be a good idea to define SIMFS_LITE

- [X] Step 0 - An example
- [ ] [Step 1 - Creating the Volume](./Step_1.md)

#### Project Structure

This project has multiple libraries offering different layers of abstraction. These libraries have clear lines of who uses who and therefore you are not allowed to break those lines. This is intended to preserve some kind of modularity in your code and thus, reusability. Remebering that correctness comes first and clarity, not speed, comes second on your priority list. There should be no reason to break modularity.

# TODO: KEITH: IMAGE HERE SHOWING LAYERS OF ABSTRACTION

[fuse_repo]: https://github.com/libfuse/libfuse
