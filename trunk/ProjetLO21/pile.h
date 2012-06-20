#ifndef PILE_H
#define PILE_H

#include <QList>
#include <QDebug>
#include <sstream>
#include <vector>
#include <string>
#include "expression.h"
#include <fstream>
#include "factory.h"
#include "motor.h"
#include <QObject>
#include "mainwindow.h"


using namespace std;

namespace expression{
class Expression;
}


class Pile : public QObject, public QList<expression::Expression*>
{
    Q_OBJECT
public:
    Pile(){}
    virtual ~Pile(){if(_curPile != 0){delete _curPile;}}
    static Pile* get_curPile(); // Retourne le pointeur vers la pile courante
    static void set_curPile(Pile* newCurPile); // Change la pile courante
    void sauv_pile();
    void recharger_pile();
    void undo();
    void redo();
    void nouveau();
    vector<string> explode(const std::string& str, char c);
    void push(expression::Expression* const expr) { this->append(expr); }
    expression::Expression* pop() { return this->takeLast(); }

    void clear();
    void swap();
    expression::Expression* sum(const expression::Expression* x);
    expression::Expression* mean(const expression::Expression* x);
    void sauvegarde();
    void dup();
    void drop();

private:
    static Pile* _curPile; // Stocke le pointeur vers la pile en cours d'utilisation
    vector<string> sauv;
    int indiceSauv;
signals:
    void sig_updatePileViewAfterReloading();
};

#endif // PILE_H
