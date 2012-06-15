#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QString>
#include <QDebug>

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
    void buttonPressed();
    void slot_updatePileView();
private:
    void keyReleaseEvent(QKeyEvent *e);
    void keyPressEvent(QKeyEvent *e);
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
