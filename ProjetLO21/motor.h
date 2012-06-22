#ifndef MOTOR_H
#define MOTOR_H

/**
  *\file motor.h
  *\brief Syst�me de coordination des modules calculatrice
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
  * Classe permettant de faire interagir entre eux les diff�rents �l�ments de la calculatrice
  * Moteur est un singleton.
  */
class Motor : public QObject
{
    Q_OBJECT
public:
    /**
      *\brief Cr�ation/r�cup�ration
      * Motor �tant un singleton, c'est via cette m�thode que l'on peut r�cup�rer (apr�s avoir �ventuellement cr��) l'objet Motor.
      * \return Pointeur vers l'unique Motor.
      */
    static Motor* get_motor();
    /**
      *\brief Suppression
      * La m�thode permet la suppression du singleton, le destructeur �tant lui prot�g�.
      * Elle est accessible en static.
      */
    static void del_motor();
    /**
      *\brief Empileur de texte saisie
      * Empile re�oit le texte saisi par l'utilisateur, et ex�cute la commande : empiler une expression, effectuer un calcul, ou modifier la pile.
      *\param lineSaisie : Texte saisi par l'utilisateur
      */
    void empile(QString lineSaisie);
    /**
      *\brief Evaluateur de ExpressionC
      * Au moment de l'�valuation d'une expression concr�te, le Motor va la consid�rer comme une suite d'entr�e individuellement faites apr l'utilisateur qu'il va se soumettre en boucle avec empile()
      */
    void eval();
    /**
      *\brief Retour du param�tre trigonom�trique
      * Le moteur a en charge la gestion des variables d'environnement. Cette m�thode permet de renvoyer la valeur d�sir�e.
      *\return PARAM_RADIAN ou PARAM_DEGRE en fonction du r�gmage que l'utilisateur a appliqu� � la calculatrice
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
      * La classe �tant un singleton, le constructeur doit �tre appel� via la m�thode get_motor()
      */
    Motor():_paramTrigo(PARAM_RADIAN){}
    /**
      *\brief Constructeur par recopie
      * La classe �tant un singleton, le constructeur par recopie n'est pas accessible � l'utilisateur
      */
    Motor(const Motor&);
    /**
      *\brief Destructeur
      * Destructueur de la classe Motor
      * La classe �tant un singleton, il doit �tre appel� via la m�thode del_factory();
      */
    virtual ~Motor();
private:
    static Motor* _motor; /**< Pointeur sur le singleton */
    int _paramTrigo; /**< Param�tre trigonom�trique */
};

#endif // MOTOR_H
