#ifndef PILE_H
#define PILE_H

#include <QList>
#include "expression.h"

class Pile : public QList<expression::Expression*>
{
public:
    Pile();

    static Pile* get_curPile() { return _curPile; } // Retourne le pointeur vers la pile courante
    static void set_curPile(Pile* newCurPile) { _curPile = newCurPile; } // Change la pile courante

    void push(expression::Expression* const expr) { this->append(expr); }
    expression::Expression* pop() { return this->takeLast(); }

    void clear();
    void swap(expression::Expression* i, expression::Expression* j);
    void sum(expression::Expression* x);
    void mean(expression::Expression* x);
    void dup();
    void drop();
private:
    static Pile* _curPile; // Stocke le pointeur vers la pile en cours d'utilisation
};

#endif // PILE_H
