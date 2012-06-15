#ifndef PILE_H
#define PILE_H

#include <QList>
#include <QDebug>
#include "expression.h"
#include <fstream>
#include "factory.h"

using namespace std;

namespace expression{
class Expression;
}


class Pile : public QList<expression::Expression*>
{
public:
    Pile();

    static Pile* get_curPile(); // Retourne le pointeur vers la pile courante
    static void set_curPile(Pile* newCurPile); // Change la pile courante
    static void sauv_piles();
    void push(expression::Expression* const expr) { this->append(expr); }
    expression::Expression* pop() { return this->takeLast(); }

    void clear();
    void swap();
    expression::Expression* sum(const expression::Expression* x);
    expression::Expression* mean(const expression::Expression* x);
    void dup();
    void drop();
    static void addSauv(expression::Expression* exp){(sauv=="")?sauv+=exp->toString():sauv+=("#"+exp->toString());}

private:
    static Pile* _curPile; // Stocke le pointeur vers la pile en cours d'utilisation
    static string sauv;
};

#endif // PILE_H
