#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QString>
#include <QDebug>
#include <QRegExp>

#include "pile.h"
#include "motor.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void slot_buttonClicked();
    void slot_updatePileView();
    void slot_updateUiStatusBar(QString text);
    void slot_toggledCalculAuto(bool);
private:
    void keyReleaseEvent(QKeyEvent *e);
    void keyPressEvent(QKeyEvent *e);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
