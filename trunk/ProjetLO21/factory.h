#ifndef FACTORY_H
#define FACTORY_H

/**
  *\file factory.h
  *\brief Convertisseur QString <-> Expression
  *\version 1.42
  */

#include <QString>
#include <QList>
#include <QRegExp>
#include "expression.h"

namespace expression
{
    class Expression;
    class Nombre;
    class Operation;
}

/**
  *\class Factory
  *\brief Fabrique d'Expression*
  * Classe permettant la conversion d'une cha�ne de caract�re en un objet expression
  * Factory est un singleton.
  */
class Factory
{
public:
    /**
      *\brief Analyseur de cha�ne de caract�re
      * L'analyseur permet � partir d'une QString de renvoyer l'objet Expression* correspondant.
      *\param adn : la QString � convertir en Expression*
      *\return Expression* obtenue � partir de la cha�ne. Throw des erreurs en cas de probl�me.
      */
    expression::Expression* analyze(QString const adn) const;
    /**
      *\brief Cr�ation/r�cup�ration
      * Factory �tant un singleton, c'est via cette m�thode que l'on peut r�cup�rer (apr�s avoir �ventuellement cr��) l'objet Factory.
      * \return Pointeur vers l'unique Factory.
      */
    static Factory* get_factory();
    /**
      *\brief Suppression
      * La m�thode permet la suppression du singleton, le destructeur �tant lui prot�g�.
      * Elle est accessible en static.
      */
    static void del_factory();
protected:
    /**
      *\brief Constructeur
      * La classe �tant un singleton, le constructeur doit �tre appel� via la m�thode get_factory()
      */
    Factory(){}
    /**
      *\brief Constructeur par recopie
      * La classe �tant un singleton, le constructeur par recopie n'est pas accessible � l'utilisateur
      */
    Factory(const Factory&);
    /**
      *\brief Destructeur
      * Destructueur de la classe Factory
      * La classe �tant un singleton, il doit �tre appel� via la m�thode del_factory();
      */
    virtual ~Factory();
private:
    static Factory* _factory; /**< Pointeur sur le singleton */
    /**
      *\brief Analyseur de Nombre
      * Analyseur sp�cialis� pour transformer une cha�ne de caract�re correspondant � un nombre en objet ad�quat
      *\param adn : la QString � convertir en expression::Nombre*
      *\return Nombre* obtenu � partir de la cha�ne. Throw des erreurs en cas de probl�me.
      */
    expression::Nombre* analyzeNombre(QString const adn) const;
    /**
      *\brief Analyseur d'Op�ration
      * Analyseur sp�cialis� pour transformer une cha�ne de caract�re corresponsant � une op�ration en objet ad�quat
      *\param adn : la QString � convertir en expression::Operation*
      *\return Operation* obtenue � partir de la cha�ne. Throw des erreurs en cas de probl�me.
      */
    expression::Operation* analyzeOperation(QString const adn) const;
};

#endif // FACTORY_H
