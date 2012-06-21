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

void LogSystem::addMessage(std::string const message, int priorite)
{
    LogMessage logMessage(message, priorite);
    std::cout<<logMessage.toString();

    std::string filename = "log.txt";
    // ouverture en écriture avec effacement du fichier ouvert
    std::ofstream fichier(filename.c_str(), std::ios::out | std::ios::app);

    if(!fichier.fail()){
	fichier<<logMessage.toString()<<std::endl;
	fichier.close();
    }
}

std::string LogMessage::toString() const
{
    if(_priorite == LOG_INFO)
	return _date.toString("yyyy-MM-dd hh:mm:ss").toStdString()+" INFO : "+_message;
    else if(_priorite == LOG_WARNING)
	return _date.toString("yyyy-MM-dd hh:mm:ss").toStdString()+" WARNING : "+_message;
    else if(_priorite == LOG_ERROR)
	return _date.toString("yyyy-MM-dd hh:mm:ss").toStdString()+" ERROR : "+_message;
    else
	return _date.toString("yyyy-MM-dd hh:mm:ss").toStdString()+" BIZARRE : "+_message;
}
