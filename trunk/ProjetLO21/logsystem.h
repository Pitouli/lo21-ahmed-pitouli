#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

/**
  *\file logsystem.h
  *\brief Système de journalisation des information
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
  *\brief Classe désignant un message de log
  */
class LogMessage
{
public:
    /**
      *\brief Constructeur
      * Permet de construire un message de log
      *\param message : Le message à ajouter au log
      *\param priorite : Type de message : LOG_WARNING, LOG_ERROR ou LOG_INFO (défaut : LOG_INFO)
      *\param date : Date du message (défaut : date courante)
      */
    LogMessage(std::string const message, int priorite = LOG_INFO, QDateTime date = QDateTime::currentDateTime()):
	_message(message), _priorite(priorite), _date(date) {}
    /**
      *\brief Convertisseur texte
      * Permet de retourner le message de log sous forme d'une chaîne de caractère
      *\return Standard string correspondant au message mis en forme
      */
    std::string toString() const;
private:
    std::string _message; /**< Le message à proprement parler */
    int _priorite; /**< La priorité du message : LOG_WARNING, LOG_ERROR ou LOG_INFO */
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
      *\brief Création/récupération
      * La méthode étant un singleton, c'est en passant par get_logger que l'on obtient un pointeur sur l'occurence unique, la construisant éventuellement au passage.
      *\return Pointeur sur l'occurence unique de LogSystem
      */
    static LogSystem* get_logger();
    /**
      *\brief Suppression
      * Le destruceur étant privé, on peut supprimer l'occurence appelante en passant par l'un de ses propres raccourcis
      */
    static void del_logger();
    /**
      *\brief Générer un message d'erreur
      * C'est un alias de la méthode addMessage(message, LOG_ERROR)
      *\param message : Message d'erreur à publier
      */
    void addError(std::string const message){ this->addMessage(message, LOG_ERROR); }
    /**
      *\brief Générer un message d'erreur
      * C'est un alias de la méthode addMessage(message, LOG_WARNING)
      *\param message : Message d'avertissement à publier
      */
    void addWarning(std::string const message){ this->addMessage(message, LOG_WARNING); }
    /**
      *\brief Générer un message d'information
      * C'est un alias de la méthode addMessage(message, LOG_INFO)
      *\param message : Message d'information à publier
      */
    void addInfo(std::string const message){ this->addMessage(message, LOG_INFO); }
    /**
      *\brief Générateur de message
      * Crée et publie un message à partir du paramètre message et de sa priorité
      *\param message : Message à publier
      *\param priorite : Priorité du message (LOG_INFO, LOG_ERROR, LOG_WARNING)
      */
    void addMessage(std::string const message, int priorite);
protected:
    /**
      *\brief Constructeur
      * La classe étant un singleton, le constructeur n'est pas publique
      */
    LogSystem(){}
    /**
      *\brief Construteur par recopie
      * La classe étant un singleton, le constructeur par recopie n'est pas publique
      */
    LogSystem(const LogSystem&);
    /**
      *\brief Déstructeur
      * La classe étant un singleton, le déstrcteur n'est pas publique
      */
    virtual ~LogSystem();
private:
    static LogSystem* _logSystem; /**< Pointeur vers le singleton */
};

#endif // LOGSYSTEM_H
