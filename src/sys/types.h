#pragma once
//A practice file.
//typedef unsigned int mode_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;

static uid_t getuid() {
    return 7;
}

static gid_t getgid() {
    return 5;
}