#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <muduo/base/Timestamp.h>
namespace rpc
{
#define LOGPATH "./log"
    class LogMessage
    {
    public:
        LogMessage(const std::string &message, const muduo::Timestamp time)
            : _message(message), _time(time) {}
        LogMessage(std::string &&message, const muduo::Timestamp time)
            : _message(std::move(message)), _time(time) {}
        LogMessage(LogMessage &&other)
            : _message(std::move(other._message)), _time(other._time) {};
        std::string toString() const;
        muduo::Timestamp get_time() const { return _time; }
        const std::string &get_message() const { return _message; }

    private:
        std::string _message;
        muduo::Timestamp _time;
    };
    class Logger
    {
    public:
        Logger(const std::string &logPath = LOGPATH) : _logPath(logPath) {};
        void updata(muduo::Timestamp time);
        void diskWrite(const LogMessage &logMessage);
        std::ofstream &get_logger() { return _logger; }

    private:
        std::ofstream _logger;
        std::string _nextTime;
        std::string _logPath;
    };
}