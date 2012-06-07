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
    Factory(QString adn = NULL) { set_adn(adn); }
    void set_adn(QString const adn) { _adn = adn; _adn = _adn.toUpper(); }
    expression::Expression* analyze() const;
private:
    expression::Nombre* analyzeNombre() const;
    expression::Operation* analyzeOperation() const;
    QString _adn; // La chaîne à analyser
};

#endif // FACTORY_H
