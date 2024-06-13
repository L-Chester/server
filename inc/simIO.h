#ifndef __SIMIO_H__
#define __SIMIO_H__

#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

namespace sim{

class simIO{
public:
    //只读打开
    int32_t readOpen(const char* fileName, int32_t flag);
    //只写打开
    int32_t wirteOpen(const char* fileName, int32_t flag);
    //读写打开
    int32_t rdwrOpen(const char* fileName, int32_t flag);
    //创建文件
    int32_t createFile(const char* fileName, mode_t mode);
    //获取光标偏移量
    int64_t getSeek(int32_t fd);
    //光标从头部开始偏移offset个字节
    int64_t seekBegin(int64_t offset, int32_t fd);
    //光标从当前位置开始偏移offset个字节
    int64_t seekCurrent(int64_t offset, int32_t fd);
    //光标从尾部开始偏移offset个字节
    int64_t seekEnd(int64_t offset, int32_t fd);
    //出错打印
    void printErrno();
protected:
private:
    int32_t file_fd_;
    int16_t error_num_;
public:
    simIO();
    ~simIO();
};

};

#endif