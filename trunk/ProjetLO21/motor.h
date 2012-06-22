#ifndef MOTOR_H
#define MOTOR_H

/**
  *\file motor.h
  *\brief Système de coordination des modules calculatrice
  *\version 1.33.7.42
  */

#include <QString>
#include <QObject>
#include "mainwindow.h"
#include "pile.h"
#include "expression.h"
#include "logsystem.h"

#define PARAM_RADIAN 1
#define PARAM_DEGRE 0

/**
  *\class Motor
  *\brief Moteur de la calculatrice
  * Classe permettant de faire interagir entre eux les différents éléments de la calculatrice
  * Moteur est un singleton.
  */
class Motor : public QObject
{
    Q_OBJECT
public:
    /**
      *\brief Création/récupération
      * Motor étant un singleton, c'est via cette méthode que l'on peut récupérer (après avoir éventuellement créé) l'objet Motor.
      * \return Pointeur vers l'unique Motor.
      */
    static Motor* get_motor();
    /**
      *\brief Suppression
      * La méthode permet la suppression du singleton, le destructeur étant lui protégé.
      * Elle est accessible en static.
      */
    static void del_motor();
    /**
      *\brief Empileur de texte saisie
      * Empile reçoit le texte saisi par l'utilisateur, et exécute la commande : empiler une expression, effectuer un calcul, ou modifier la pile.
      *\param lineSaisie : Texte saisi par l'utilisateur
      */
    void empile(QString lineSaisie);
    /**
      *\brief Evaluateur de ExpressionC
      * Au moment de l'évaluation d'une expression concrète, le Motor va la considérer comme une suite d'entrée individuellement faites apr l'utilisateur qu'il va se soumettre en boucle avec empile()
      */
    void eval();
    /**
      *\brief Retour du paramètre trigonométrique
      * Le moteur a en charge la gestion des variables d'environnement. Cette méthode permet de renvoyer la valeur désirée.
      *\return PARAM_RADIAN ou PARAM_DEGRE en fonction du régmage que l'utilisateur a appliqué à la calculatrice
      */
    int get_paramTrigo() { return _paramTrigo; }
signals:
    void sig_updatePileView();
    void sig_emptyLineSaisie();
    void sig_updateUiStatusBar(QString text);
public slots:
    void slot_setParamTrigo(bool radianChecked) { _paramTrigo = radianChecked ? PARAM_RADIAN : PARAM_DEGRE; qDebug()<<"param trigo : "<<_paramTrigo; }
protected:
    /**
      *\brief Constructeur
      * La classe étant un singleton, le constructeur doit être appelé via la méthode get_motor()
      */
    Motor():_paramTrigo(PARAM_RADIAN){}
    /**
      *\brief Constructeur par recopie
      * La classe étant un singleton, le constructeur par recopie n'est pas accessible à l'utilisateur
      */
    Motor(const Motor&);
    /**
      *\brief Destructeur
      * Destructueur de la classe Motor
      * La classe étant un singleton, il doit être appelé via la méthode del_factory();
      */
    virtual ~Motor();
private:
    static Motor* _motor; /**< Pointeur sur le singleton */
    int _paramTrigo; /**< Paramètre trigonométrique */
};

#endif // MOTOR_H
