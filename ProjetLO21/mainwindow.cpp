#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_space, SIGNAL(pressed()), this, SLOT(spacePressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_U:
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_basique);
	break;
    case Qt::Key_I:
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_divers);
	break;
    case Qt::Key_O:
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_trigo);
	break;
    case Qt::Key_P:
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_pile);
	break;
    case Qt::Key_0:
	ui->pushButton_0->setDown(false);
	ui->pushButton_0->click();
	break;
    case Qt::Key_1:
	ui->pushButton_1->setDown(false);
	ui->pushButton_1->click();
	break;
    case Qt::Key_2:
	ui->pushButton_2->setDown(false);
	ui->pushButton_2->click();
	break;
    case Qt::Key_3:
	ui->pushButton_3->setDown(false);
	ui->pushButton_3->click();
	break;
    case Qt::Key_4:
	ui->pushButton_4->setDown(false);
	ui->pushButton_4->click();
	break;
    case Qt::Key_5:
	ui->pushButton_5->setDown(false);
	ui->pushButton_5->click();
	break;
    case Qt::Key_6:
	ui->pushButton_6->setDown(false);
	ui->pushButton_6->click();
	break;
    case Qt::Key_7:
	ui->pushButton_7->setDown(false);
	ui->pushButton_7->click();
	break;
    case Qt::Key_8:
	ui->pushButton_8->setDown(false);
	ui->pushButton_8->click();
	break;
    case Qt::Key_9:
	ui->pushButton_9->setDown(false);
	ui->pushButton_9->click();
	break;
    case Qt::Key_Plus:
	ui->pushButton_plus->setDown(false);
	ui->pushButton_plus->click();
	break;
    case Qt::Key_Minus:
	ui->pushButton_moins->setDown(false);
	ui->pushButton_moins->click();
	break;
    case Qt::Key_Slash:
	ui->pushButton_diviser->setDown(false);
	ui->pushButton_diviser->click();
	break;
    case Qt::Key_Asterisk:
	ui->pushButton_fois->setDown(false);
	ui->pushButton_fois->click();
	break;
    /*case Qt::Key_Space:
	ui->pushButton_space->setDown(false);
	ui->pushButton_space->click();
	break;*/
    case Qt::Key_Comma:
	ui->pushButton_point->setDown(false);
	ui->pushButton_point->click();
	break;
    case Qt::Key_Period:
	ui->pushButton_point->setDown(false);
	ui->pushButton_point->click();
	break;
    default:
	QMainWindow::keyReleaseEvent(e);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_0:
	ui->pushButton_0->setDown(true);
	break;
    case Qt::Key_1:
	ui->pushButton_1->setDown(true);
	break;
    case Qt::Key_2:
	ui->pushButton_2->setDown(true);
	break;
    case Qt::Key_3:
	ui->pushButton_3->setDown(true);
	break;
    case Qt::Key_4:
	ui->pushButton_4->setDown(true);
	break;
    case Qt::Key_5:
	ui->pushButton_5->setDown(true);
	break;
    case Qt::Key_6:
	ui->pushButton_6->setDown(true);
	break;
    case Qt::Key_7:
	ui->pushButton_7->setDown(true);
	break;
    case Qt::Key_8:
	ui->pushButton_8->setDown(true);
	break;
    case Qt::Key_9:
	ui->pushButton_9->setDown(true);
	break;
    case Qt::Key_Plus:
	ui->pushButton_plus->setDown(true);
	break;
    case Qt::Key_Minus:
	ui->pushButton_moins->setDown(true);
	break;
    case Qt::Key_Slash:
	ui->pushButton_diviser->setDown(true);
	break;
    case Qt::Key_Asterisk:
	ui->pushButton_fois->setDown(true);
	break;
    /*case Qt::Key_Space:
	ui->pushButton_space->setDown(true);
	break;*/
    case Qt::Key_Comma:
	ui->pushButton_point->setDown(true);
	break;
    case Qt::Key_Period:
	ui->pushButton_point->setDown(true);
	break;
    default:
	QMainWindow::keyPressEvent(e);
    }
}
