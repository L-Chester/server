#include "string.h"
#include "../inc/simIO.h"


using namespace sim;

simIO::simIO()
:file_fd_(-1){

}

simIO::~simIO(){
    if(-1 != file_fd_){
        error_num_ = errno;
    }
}

int32_t simIO::readOpen(const char* fileName, int32_t flag){
    file_fd_ = open(fileName,O_RDONLY|flag);
    if(-1 == file_fd_){
        error_num_ = errno;
    }
    return file_fd_;
}

int32_t simIO::wirteOpen(const char* fileName, int32_t flag){
    file_fd_ = open(fileName,O_WRONLY|flag);
    if(-1 == file_fd_){
        error_num_ = errno;
    }
    return file_fd_;
}

int32_t simIO::rdwrOpen(const char* fileName, int32_t flag){
    file_fd_ = open(fileName,O_RDWR|flag);
    if(-1 == file_fd_){
        error_num_ = errno;
    }
    return file_fd_;
}

int64_t simIO::getSeek(int32_t fd = -1){
    fd = file_fd_;
    int64_t ost = lseek(fd, 0, SEEK_CUR);
    if(-1 == ost){
        error_num_ = errno;
    }
    return ost;
}

int64_t simIO::seekBegin(int64_t offset, int32_t fd = -1){
    fd = file_fd_;
    int64_t ost = lseek(fd, offset, SEEK_SET);
    if(-1 == ost){
        
        error_num_ = errno;
    }
    return ost;
}
int64_t simIO::seekCurrent(int64_t offset, int32_t fd = -1){
    fd = file_fd_;
    int64_t ost = lseek(fd, offset, SEEK_CUR);
    if(-1 == ost){
        
        error_num_ = errno;
    }
    return ost;
}
int64_t simIO::seekEnd(int64_t offset, int32_t fd = -1){
    fd = file_fd_;
    int64_t ost = lseek(fd, offset, SEEK_END);
    if(-1 == ost){
        
        error_num_ = errno;
    }
    return ost;
}
void simIO::printErrno(){
    strerror(error_num_);
}