#ifndef PILE_H
#define PILE_H

#include <QList>
#include "expression.h"

class Pile : public QList<expression::Expression*>
{
public:
    Pile();
    void clear();
    void swap(expression::Expression* i, expression::Expression* j);
    void dup();
    void push(expression::Expression* const expr) { this->append(expr); }
    expression::Expression* pop() { return this->takeLast(); }
    void drop();
    void sum(expression::Expression* x);
};

#endif // PILE_H
