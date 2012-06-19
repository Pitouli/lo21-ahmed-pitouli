#ifndef MOTOR_H
#define MOTOR_H

#include <QString>
#include <QObject>
#include "mainwindow.h"
#include "pile.h"
#include "expression.h"

class Motor : public QObject
{
    Q_OBJECT
public:
    static Motor* get_motor();
    static void del_motor();
    void empile(QString lineSaisie);
    void eval();
signals:
    void sig_updatePileView();
    void sig_emptyLineSaisie();
    void sig_updateUiStatusBar(QString text);
protected:
    Motor(){}
    Motor(const Motor&);
    virtual ~Motor();
private:
    static Motor* _motor;
};

#endif // MOTOR_H
