#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QString>
#include <string>
#include <iostream>
#include <fstream>
#include <QDate>

#define LOG_WARNING 1
#define LOG_ERROR 2
#define LOG_INFO 0

class LogMessage
{
public:
    LogMessage(std::string const message, int priorite = LOG_INFO, QDateTime date = QDateTime::currentDateTime()):
	_message(message), _priorite(priorite), _date(date) {}
    std::string toString() const;
private:
    std::string _message;
    int _priorite;
    QDateTime _date;
};

class LogSystem
{
public:
    static LogSystem* get_logger();
    static void del_logger();
    void addError(std::string const message){ this->addMessage(message, LOG_ERROR); }
    void addWarning(std::string const message){ this->addMessage(message, LOG_WARNING); }
    void addInfo(std::string const message){ this->addMessage(message, LOG_INFO); }
    void addMessage(std::string const message, int priorite);
protected:
    LogSystem(){}
    LogSystem(const LogSystem&);
    virtual ~LogSystem();
private:
    static LogSystem* _logSystem;
};

#endif // LOGSYSTEM_H
