#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pile.h"
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("plastique");
    Pile* pile = new Pile();
    MainWindow w;
    w.show();

    return a.exec();
}
