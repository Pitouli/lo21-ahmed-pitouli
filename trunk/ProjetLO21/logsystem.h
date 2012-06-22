#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

/**
  *\file logsystem.h
  *\brief Syst�me de journalisation des information
  *\version 1.3.37
  */

#include <QString>
#include <string>
#include <iostream>
#include <fstream>
#include <QDate>

#define LOG_WARNING 1
#define LOG_ERROR 2
#define LOG_INFO 0

/**
  *\class LogMessage
  *\brief Classe d�signant un message de log
  */
class LogMessage
{
public:
    /**
      *\brief Constructeur
      * Permet de construire un message de log
      *\param message : Le message � ajouter au log
      *\param priorite : Type de message : LOG_WARNING, LOG_ERROR ou LOG_INFO (d�faut : LOG_INFO)
      *\param date : Date du message (d�faut : date courante)
      */
    LogMessage(std::string const message, int priorite = LOG_INFO, QDateTime date = QDateTime::currentDateTime()):
	_message(message), _priorite(priorite), _date(date) {}
    /**
      *\brief Convertisseur texte
      * Permet de retourner le message de log sous forme d'une cha�ne de caract�re
      *\return Standard string correspondant au message mis en forme
      */
    std::string toString() const;
private:
    std::string _message; /**< Le message � proprement parler */
    int _priorite; /**< La priorit� du message : LOG_WARNING, LOG_ERROR ou LOG_INFO */
    QDateTime _date; /**< La date du message */
};

/**
  *\class LogSystem
  *\brief Classe permettant la gestion des messages de LOG
  * LogSystem est un singleton
  */
class LogSystem
{
public:
    /**
      *\brief Cr�ation/r�cup�ration
      * La m�thode �tant un singleton, c'est en passant par get_logger que l'on obtient un pointeur sur l'occurence unique, la construisant �ventuellement au passage.
      *\return Pointeur sur l'occurence unique de LogSystem
      */
    static LogSystem* get_logger();
    /**
      *\brief Suppression
      * Le destruceur �tant priv�, on peut supprimer l'occurence appelante en passant par l'un de ses propres raccourcis
      */
    static void del_logger();
    /**
      *\brief G�n�rer un message d'erreur
      * C'est un alias de la m�thode addMessage(message, LOG_ERROR)
      *\param message : Message d'erreur � publier
      */
    void addError(std::string const message){ this->addMessage(message, LOG_ERROR); }
    /**
      *\brief G�n�rer un message d'erreur
      * C'est un alias de la m�thode addMessage(message, LOG_WARNING)
      *\param message : Message d'avertissement � publier
      */
    void addWarning(std::string const message){ this->addMessage(message, LOG_WARNING); }
    /**
      *\brief G�n�rer un message d'information
      * C'est un alias de la m�thode addMessage(message, LOG_INFO)
      *\param message : Message d'information � publier
      */
    void addInfo(std::string const message){ this->addMessage(message, LOG_INFO); }
    /**
      *\brief G�n�rateur de message
      * Cr�e et publie un message � partir du param�tre message et de sa priorit�
      *\param message : Message � publier
      *\param priorite : Priorit� du message (LOG_INFO, LOG_ERROR, LOG_WARNING)
      */
    void addMessage(std::string const message, int priorite);
protected:
    /**
      *\brief Constructeur
      * La classe �tant un singleton, le constructeur n'est pas publique
      */
    LogSystem(){}
    /**
      *\brief Construteur par recopie
      * La classe �tant un singleton, le constructeur par recopie n'est pas publique
      */
    LogSystem(const LogSystem&);
    /**
      *\brief D�structeur
      * La classe �tant un singleton, le d�strcteur n'est pas publique
      */
    virtual ~LogSystem();
private:
    static LogSystem* _logSystem; /**< Pointeur vers le singleton */
};

#endif // LOGSYSTEM_H
