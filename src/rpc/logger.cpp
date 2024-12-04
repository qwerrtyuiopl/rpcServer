#include "logger.h"


void rpc::Logger::updata(muduo::Timestamp time)
{
    std::string nowTime = time.toFormattedString().substr(0, 8);
    if (_nextTime != nowTime)
    {
        _nextTime = nowTime;
        if (_logger.is_open())
        {
            _logger.close();
        }
        _logger.open(_nextTime);
    }
}

void rpc::Logger::diskWrite(const LogMessage &logMessage)
{
    updata(logMessage.get_time());
    _logger << logMessage.toString();
}

std::string rpc::LogMessage::toString() const
{
    return _time.toFormattedString(false) + ':' + _message + "/n";
}
