#ifndef __SIM_LOG__
#define __SIM_LOG__

#include <string>
#include <iostream>
#include <memory>
#include <stdint.h>

namespace sim{

//日志分级
enum Error_Level{
    DEBUG = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4,
    FATAL = 5,
};

//日志格式化
class simLogFormater{
private:
    std::string m_info;
public:
    simLogFormater();
    ~simLogFormater();
};

//日志事件
/*
    m_pfile 文件指针
    m_line 行号
    m_pthreadId 线程ID
    m_fiberId 协程ID
    m_time 时间
    m_content 内容
*/
class simLogEvent{
public:
    typedef std::shared_ptr<simLogEvent> sptr;
private:
    const char* m_pfile;
    int32_t m_line;
    uint32_t m_pthreadId;
    uint32_t m_fiberId ;
    uint64_t m_time0;
    std::string m_content;
public:
    simLogEvent();
};

//日志输出器
class simLogAppender{
private:
    std::string m_info;
public:
    simLogAppender();
    ~simLogAppender();
};

//日志主体类
class simLog{
public:
    typedef std::shared_ptr<simLog> sptr;
private:
    std::string m_info;
public:
    simLog();
    ~simLog();
    void log(Error_Level err,const simLogEvent& event);
};

};


#endif