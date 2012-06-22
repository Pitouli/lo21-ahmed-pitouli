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


/**
  *\file pile.h
  *\brief Pile de la calculatrice
  *\version 1.42
*/


using namespace std;

namespace expression{
class Expression;
}

/**
  *\class Pile
  *\brief Pile de la calculatrice
  * Classe contenant la pile et les methodes pour manipuler celle-ci
  * Pile est un singleton.
  */
class Pile : public QObject, public QList<expression::Expression*>
{
    Q_OBJECT
public:
    Pile(){}
    virtual ~Pile(){if(_curPile != 0){delete _curPile;}}

    /**
      *\brief Création/récupération
      * Pile étant un singleton, c'est via cette méthode que l'on peut récupérer (après avoir éventuellement créé) l'objet Pile.
      * \return Pointeur vers l'unique Pile.
      */
    static Pile* get_curPile(); // Retourne le pointeur vers la pile courante

    /**
      *\brief initialisation de l'unique Pile avec une autre
      * Change la pile courante.
      */
    static void set_curPile(Pile* newCurPile); // Change la pile courante

    /**
      *\brief sauvegarde la pile
      * Permet de sauvegarder la pile dans un fichier
      */
    void sauv_pile();

    /**
      *\brief recharge la pile
      * Permet de reintialiser la pile depuis un fichier
      */
    void recharger_pile();

    /**
      *\brief Annuler action
      * Permet d'annuler la derniere action
      */
    void undo();

    /**
      *\brief Refaire action
      * Permet de refaire une action annulee
      */
    void redo();

    /**
      *\brief Permet de signaler a la pile qu'une nouvelle expression a ete empilee
      */
    void nouveau();

    /**
      *\brief Remet a zero le fichier de sauvegarde
      */
    void razFile();

    /**
      *\brief retourne un tableau de chaînes, chacune d'elle étant une sous-chaîne du paramètre str extraite en utilisant le séparateur c.
      *\param str : Chaine de caractere a exploser
      *\param c : delimiteur
      * \return un tableau de chaînes
    */
    vector<string> explode(const std::string& str, char c);


    /**
      *\brief empile une expression
      *\param expr : Expression a empile
    */
    void push(expression::Expression* const expr) { this->append(expr); }

    /**
      *\brief depile la derniere expression
      * \return la derniere expression de la pile
    */
    expression::Expression* pop() { return this->takeLast(); }

    /**
      *\brief Vide le contenu de la pile
    */
    void clear();

    /**
      *\brief Echange deux expressions de la pile
    */
    void swap();

    /**
      *\brief Fait la somme des x derniers elements de la pile
      *\param x : nombre d'elements a additionne
      * \return le resultat de la somme
    */
    expression::Expression* sum(const expression::Expression* x);

    /**
      *\brief Fait la moyenne des x derniers elements de la pile
      *\param x : nombre d'elements sur lesquels on doit faire la moyenne
      * \return la moyenne
    */
    expression::Expression* mean(const expression::Expression* x);

    /**
      *\brief Sauvegarde le contexte de la pile
    */
    void sauvegarde();

    /**
      *\brief Duplique le dernier element de la pile
    */
    void dup();

    /**
      *\brief Supprime le dernier element de la pile
    */
    void drop();

private:
    static Pile* _curPile; /**< Stocke le pointeur vers la pile en cours d'utilisation */
    vector<string> sauv; /**< Stocke l'integralite des piles au fur et a mesure */
    int indiceSauv; /**< Stocke l'indice de la pile a charge depuis la liste de suavegarde */
signals:
    void sig_updatePileViewAfterReloading();
};

#endif // PILE_H
