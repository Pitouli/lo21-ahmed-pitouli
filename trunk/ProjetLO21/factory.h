#ifndef FACTORY_H
#define FACTORY_H

#include <QString>
#include <QList>
#include <QRegExp>
#include "expression.h"

namespace expression{
class Expression;
class Nombre;
class Operation;
}


class Factory
{
public:
    //void set_adn(QString const adn) { _adn = adn; _adn = _adn.toUpper(); }
    expression::Expression* analyze(QString const adn) const;
    static Factory* get_factory();
    static void del_factory();
protected:
    Factory(){}
    Factory(const Factory&);
    virtual ~Factory();
private:
    static Factory* _factory;
    expression::Nombre* analyzeNombre(QString const adn) const;
    expression::Operation* analyzeOperation(QString const adn) const;
    //QString _adn; // La chaîne à analyser
};

#endif // FACTORY_H
