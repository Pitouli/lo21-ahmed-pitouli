#ifndef ANALYZER_H
#define ANALYZER_H

#include <QString>
#include <QList>
#include <QRegExp>
#include "expression.h"

class analyzer
{
public:
    analyzer(QString adn = NULL) { set_adn(adn); }
    void set_adn(QString const adn) { _adn = adn; }
    expression::Expression* analyze() const;
private:
    expression::Nombre* analyzeNombre() const;
    expression::Operation* analyzeOperation() const;
    QString _adn; // La chaîne à analyser
};

#endif // ANALYZER_H
