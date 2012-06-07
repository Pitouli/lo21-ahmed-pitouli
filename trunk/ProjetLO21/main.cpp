#include <QtGui/QApplication>
#include "mainwindow.h"
#include "pile.h"
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("plastique");
    MainWindow w;
    w.show();

    return a.exec();
}
