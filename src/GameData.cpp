#include "Engine.h"

using namespace MoldEngine;

void* Data::getFileFromData(const char* filename) {
    PHYSFS_init(NULL);
    PHYSFS_mount("resources.data", NULL, 0);

    if(!PHYSFS_exists(filename)) {
        Logging::Error("File not found!");
        Logging::Error(filename);
        exit(-1);
    }

    PHYSFS_File *file = PHYSFS_openRead(filename); //open file
    int fileLen = PHYSFS_fileLength(file)+1;

    void* buffer = malloc(fileLen); //allocate buffer
    memset(buffer,0,fileLen);
    PHYSFS_readBytes(file,buffer,fileLen); //read the bytes

    PHYSFS_close(file); //close the file
    PHYSFS_deinit();
    return buffer;
}

int Data::getFileSize(const char* filename) {
    PHYSFS_init(NULL);
    PHYSFS_mount("resources.data", NULL, 0);
    PHYSFS_File *file = PHYSFS_openRead(filename); //open file
    int fileLen = PHYSFS_fileLength(file)+1;
    PHYSFS_close(file); //close the file
    PHYSFS_deinit();
    return fileLen;
}