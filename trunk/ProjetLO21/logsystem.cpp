#include "logsystem.h"

LogSystem* LogSystem::_logSystem = 0;

LogSystem* LogSystem::get_logger()
{
    if(_logSystem == 0)
    {
	_logSystem = new LogSystem();
    }

    return _logSystem;
}

void LogSystem::del_logger()
{
    if(_logSystem != 0)
	delete _logSystem;
    _logSystem = 0;
}

LogSystem::~LogSystem()
{
    if(_logSystem != 0) delete _logSystem;
}

void addMessage(std::string message, int priorite)
{
    LogMessage logMessage(message, priorite);
    std::cout<<logMessage.toString();
}

std::string LogMessage::toString() const
{
    if(_priorite == LOG_INFO)
	return _date.toString().toStdString()+" INFO : "+_message;
    else if(_priorite == LOG_WARNING)
	return _date.toString().toStdString()+" WARING : "+_message;
    else if(_priorite == LOG_ERROR)
	return _date.toString().toStdString()+" ERROR : "+_message;
    else
	return _date.toString().toStdString()+" BIZARRE : "+_message;
}
