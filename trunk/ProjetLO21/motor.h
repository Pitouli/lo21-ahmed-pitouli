#ifndef MOTOR_H
#define MOTOR_H

#include <QString>
#include <QObject>
#include "mainwindow.h"
#include "pile.h"
#include "expression.h"
#include "logsystem.h"

#define PARAM_RADIAN 1
#define PARAM_DEGRE 0

class Motor : public QObject
{
    Q_OBJECT
public:
    static Motor* get_motor();
    static void del_motor();
    void empile(QString lineSaisie);
    void eval();
    int get_paramTrigo() { return _paramTrigo; }
signals:
    void sig_updatePileView();
    void sig_emptyLineSaisie();
    void sig_updateUiStatusBar(QString text);
public slots:
    void slot_setParamTrigo(bool radianChecked) { _paramTrigo = radianChecked ? PARAM_RADIAN : PARAM_DEGRE; qDebug()<<"param trigo : "<<_paramTrigo; }
protected:
    Motor():_paramTrigo(PARAM_RADIAN){}
    Motor(const Motor&);
    virtual ~Motor();
private:
    static Motor* _motor;
    int _paramTrigo;
};

#endif // MOTOR_H
