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
  * Classe permettant la conversion d'une chaîne de caractère en un objet expression
  * Factory est un singleton.
  */
class Factory
{
public:
    /**
      *\brief Analyseur de chaîne de caractère
      * L'analyseur permet à partir d'une QString de renvoyer l'objet Expression* correspondant.
      *\param adn : la QString à convertir en Expression*
      *\return Expression* obtenue à partir de la chaîne. Throw des erreurs en cas de problème.
      */
    expression::Expression* analyze(QString const adn) const;
    /**
      *\brief Création/récupération
      * Factory étant un singleton, c'est via cette méthode que l'on peut récupérer (après avoir éventuellement créé) l'objet Factory.
      * \return Pointeur vers l'unique Factory.
      */
    static Factory* get_factory();
    /**
      *\brief Suppression
      * La méthode permet la suppression du singleton, le destructeur étant lui protégé.
      * Elle est accessible en static.
      */
    static void del_factory();
protected:
    /**
      *\brief Constructeur
      * La classe étant un singleton, le constructeur doit être appelé via la méthode get_factory()
      */
    Factory(){}
    /**
      *\brief Constructeur par recopie
      * La classe étant un singleton, le constructeur par recopie n'est pas accessible à l'utilisateur
      */
    Factory(const Factory&);
    /**
      *\brief Destructeur
      * Destructueur de la classe Factory
      * La classe étant un singleton, il doit être appelé via la méthode del_factory();
      */
    virtual ~Factory();
private:
    static Factory* _factory; /**< Pointeur sur le singleton */
    /**
      *\brief Analyseur de Nombre
      * Analyseur spécialisé pour transformer une chaîne de caractère correspondant à un nombre en objet adéquat
      *\param adn : la QString à convertir en expression::Nombre*
      *\return Nombre* obtenu à partir de la chaîne. Throw des erreurs en cas de problème.
      */
    expression::Nombre* analyzeNombre(QString const adn) const;
    /**
      *\brief Analyseur d'Opération
      * Analyseur spécialisé pour transformer une chaîne de caractère corresponsant à une opération en objet adéquat
      *\param adn : la QString à convertir en expression::Operation*
      *\return Operation* obtenue à partir de la chaîne. Throw des erreurs en cas de problème.
      */
    expression::Operation* analyzeOperation(QString const adn) const;
};

#endif // FACTORY_H
