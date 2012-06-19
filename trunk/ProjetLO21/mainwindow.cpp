#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // On connecte les boutons
    for (int i = 0; i < ui->gridLayout_tabBasique->count(); ++i)
    {
	QWidget* widget = ui->gridLayout_tabBasique->itemAt(i)->widget();
	QPushButton* button = qobject_cast<QPushButton*>(widget);

	if(button)
	    connect(button, SIGNAL(clicked()), this, SLOT(slot_buttonClicked()));
    }
    for (int i = 0; i < ui->gridLayout_tabDivers->count(); ++i)
    {
	QWidget* widget = ui->gridLayout_tabDivers->itemAt(i)->widget();
	QPushButton* button = qobject_cast<QPushButton*>(widget);

	if(button)
	    connect(button, SIGNAL(clicked()), this, SLOT(slot_buttonClicked()));
    }
    for (int i = 0; i < ui->gridLayout_tabTrigo->count(); ++i)
    {
	QWidget* widget = ui->gridLayout_tabTrigo->itemAt(i)->widget();
	QPushButton* button = qobject_cast<QPushButton*>(widget);

	if(button)
	    connect(button, SIGNAL(clicked()), this, SLOT(slot_buttonClicked()));
    }
    for (int i = 0; i < ui->gridLayout_tabPile->count(); ++i)
    {
	QWidget* widget = ui->gridLayout_tabPile->itemAt(i)->widget();
	QPushButton* button = qobject_cast<QPushButton*>(widget);

	if(button)
	    connect(button, SIGNAL(clicked()), this, SLOT(slot_buttonClicked()));
    }

    connect(ui->pushButton_space, SIGNAL(clicked()), this, SLOT(slot_buttonClicked()));

    // On connecte le motor à l'interface
    connect(Motor::get_motor(), SIGNAL(sig_updatePileView()), this, SLOT(slot_updatePileView()));
    connect(Motor::get_motor(), SIGNAL(sig_emptyLineSaisie()), ui->lineSaisie, SLOT(clear()));
    connect(Motor::get_motor(), SIGNAL(sig_updateUiStatusBar(QString)), this, SLOT(slot_updateUiStatusBar(QString)));
    connect(ui->radioButton_radian, SIGNAL(toggled(bool)), Motor::get_motor(), SLOT(slot_setParamTrigo(bool)));

    // On connecte la checkbox de calculAuto à la fonction en charge des modification
    connect(ui->checkBox_calculAuto, SIGNAL(toggled(bool)), this, SLOT(slot_toggledCalculAuto(bool)));

    ui->lineSaisie->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_buttonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>( sender() );

    if(button)
    {
	QString s = ui->lineSaisie->text();

	if(button == ui->pushButton_space)
	{
	    bool nbWriting = false;
	    bool nbWrited = false;

	    if(s.contains(QRegExp("^(.* )?([0-9]+[0-9/\\$\\.]*)$"))) // Si on est en train d'écrire un nombre
	    {
		for (int i = 0; i < ui->paramSaisie->count(); ++i)
		    if(qobject_cast<QRadioButton*>(ui->paramSaisie->itemAt(i)->widget()) || qobject_cast<QCheckBox*>(ui->paramSaisie->itemAt(i)->widget()))
			ui->paramSaisie->itemAt(i)->widget()->setEnabled(false);

		nbWriting = true;

		// Ecriture d'un réel non complexe
		if(ui->radioButton_reel->isChecked() && !ui->checkBox_complexe->isChecked())
		{
		    if(s.contains(QRegExp("^(.* )?([0-9]+)$"))) // Si la partie entière est ecrite
			ui->lineSaisie->setText(s+"."); // On ajoute le point
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)\\.$"))) // Si la partie entière et le point sont écrits
		    {
			ui->lineSaisie->setText(s+"0"); // On ajoute un zéro en partie décimale
			nbWrited = true;
		    }
		    else
			nbWrited = true;
		}
		// Ecriture d'un rationnel non complexe
		else if(ui->radioButton_rationnel->isChecked() && !ui->checkBox_complexe->isChecked())
		{
		    if(s.contains(QRegExp("^(.* )?([0-9]+)$"))) // Si le numérateur est écrit
			ui->lineSaisie->setText(s+"/"); // On ajoute le slash
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)/$"))) // Si le numérateur et le slash sont écrits
		    {
			ui->lineSaisie->setText(s+"1"); // On ajoute un 1 au dénominateur
			nbWrited = true;
		    }
		    else
			nbWrited = true;
		}
		// Ecriture d'un entier complexe
		else if(ui->radioButton_entier->isChecked() && ui->checkBox_complexe->isChecked())
		{
		    if(s.contains(QRegExp("^(.* )?([0-9]+)$"))) // Si la partie réelle est ecrite
			ui->lineSaisie->setText(s+"$"); // On ajoute le dollars
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)\\$$"))) // Si la partie réelle et le dollar sont écrits
		    {
			ui->lineSaisie->setText(s+"0"); // On ajoute un zéro en partie imaginaire
			nbWrited = true;
		    }
		    else
			nbWrited = true;
		}
		// Ecriture d'un rationnel complexe
		else if(ui->radioButton_rationnel->isChecked() && ui->checkBox_complexe->isChecked())
		{
		    if(s.contains(QRegExp("^(.* )?([0-9]+)$"))) // Si le numérateur réel est écrit
			ui->lineSaisie->setText(s+"/"); // On ajoute le slash
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)/$"))) // Si le numérateur réel et le slash sont écrits
			ui->lineSaisie->setText(s+"1$"); // On ajoute un 1 au dénominateur et un dollar pour la partie imaginaire
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)/([0-9]+)$"))) // Si le numérateur réel, le slash et le dénominateur réel sont écrits
			ui->lineSaisie->setText(s+"$"); // On ajoute un dollar pour la partie imaginaire
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)/([0-9]+)\\$$"))) // Si la partie réelle est écrite mais pas la partie imaginaire
		    {
			ui->lineSaisie->setText(s+"0/1"); // On ajoute la partie imaginaire nulle
			nbWrited = true;
		    }
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)/([0-9]+)\\$([0-9]+)$"))) // Si la partie réelle et le numérateur imaginaire sont écrits
			ui->lineSaisie->setText(s+"/"); // On ajoute le slash
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)/([0-9]+)\\$([0-9]+)/$"))) // s'il ne manque que le dénominateur imaginaire
		    {
			ui->lineSaisie->setText(s+"1"); // On ajoute 1 par défaut
			nbWrited = true;
		    }
		    else
			nbWrited = true;
		}
		// Ecriture d'un réel complexe
		else if(ui->radioButton_reel->isChecked() && ui->checkBox_complexe->isChecked())
		{
		    if(s.contains(QRegExp("^(.* )?([0-9]+)$"))) // Si la partie entière réelle est écrite
			ui->lineSaisie->setText(s+"."); // On ajoute le point
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)\\.$"))) // Si la partie entière réelle et le point sont écrits
			ui->lineSaisie->setText(s+"0$"); // On ajoute un 0 au dénominateur et un dollar pour la partie imaginaire
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)\\.([0-9]+)$"))) // Si la partie entière réelle, le point et la partie décimale réelle sont écrits
			ui->lineSaisie->setText(s+"$"); // On ajoute un dollar pour la partie imaginaire
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)\\.([0-9]+)\\$$"))) // Si la partie réelle est écrite mais pas la partie imaginaire
		    {
			ui->lineSaisie->setText(s+"0.0"); // On ajoute la partie imaginaire nulle
			nbWrited = true;
		    }
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)\\.([0-9]+)\\$([0-9]+)$"))) // Si la partie réelle et la partie entière imaginaire sont écrits
			ui->lineSaisie->setText(s+"."); // On ajoute le point
		    else if(s.contains(QRegExp("^(.* )?([0-9]+)\\.([0-9]+)\\$([0-9]+)\\.$"))) // s'il ne manque que la aprtie décimale imaginaire
		    {
			ui->lineSaisie->setText(s+"0"); // On ajoute 0 par défaut
			nbWrited = true;
		    }
		    else
			nbWrited = true;
		}
		else // Cas d'un entier non complexe
		    nbWrited = true;
	    }

	    // On met à jour la nouvelle valeur de s
	    s = ui->lineSaisie->text();

	    if(nbWriting && nbWrited)
	    {
		for (int i = 0; i < ui->paramSaisie->count(); ++i)
		    if(qobject_cast<QRadioButton*>(ui->paramSaisie->itemAt(i)->widget()) || qobject_cast<QCheckBox*>(ui->paramSaisie->itemAt(i)->widget()))
			ui->paramSaisie->itemAt(i)->widget()->setEnabled(true);

		if(ui->checkBox_calculAuto->isChecked())
		{
		    qDebug("empilement nombre");
		    Motor::get_motor()->empile(ui->lineSaisie->text());
		}
		else
		{
		    qDebug("non empilement nombre");
		    ui->lineSaisie->setText(s+" "); // on l'ajoute
		}

		nbWriting = false;
		nbWrited = false;
	    }
	    else if(!nbWriting)
	    {
		if(ui->checkBox_calculAuto->isChecked() && s.length() > 0)
		{
		    qDebug("empilement non nombre");
		    Motor::get_motor()->empile(ui->lineSaisie->text());
		}
		else
		{
		    qDebug("non empilement non nombre");
		    if(!s.contains(QRegExp("(?: $)|(?:^$)"))) // S'il n'y a pas déjà des un espace
			ui->lineSaisie->setText(s+" "); // on l'ajoute
		}
	    }

	}
	else if(button == ui->pushButton_0 || button == ui->pushButton_1 || button == ui->pushButton_2
		|| button == ui->pushButton_3 || button == ui->pushButton_4 || button == ui->pushButton_5
		|| button == ui->pushButton_6 || button == ui->pushButton_7 || button == ui->pushButton_8
		|| button == ui->pushButton_9)
	{
	    ui->lineSaisie->setText(s+button->text());
	}
	else if(button == ui->pushButton_del)
	{
	    QRegExp regSentenceWithoutLastWord("^(.* )?(?:[\\S]+[ ]?)$");
	    regSentenceWithoutLastWord.exactMatch(ui->lineSaisie->text());
	    ui->lineSaisie->setText(regSentenceWithoutLastWord.cap(1));

	    for (int i = 0; i < ui->paramSaisie->count(); ++i)
		if(qobject_cast<QRadioButton*>(ui->paramSaisie->itemAt(i)->widget()) || qobject_cast<QCheckBox*>(ui->paramSaisie->itemAt(i)->widget()))
		    ui->paramSaisie->itemAt(i)->widget()->setEnabled(true);
	}
	else // Si le bouton n'est ni un chiffre ni la barre espace
	{
	    if(!s.contains(QRegExp("^(.* )?([0-9]+[0-9/\\$\\.]*)$"))) // Si on est en train d'écrire un nombre
	    {
		if(!s.contains(QRegExp("(?: $)|(?:^$)"))) // S'il n'y a pas déjà un espace
		{
		    ui->lineSaisie->setText(s+" "); // on l'ajoute
		    s = ui->lineSaisie->text(); // On met à jour la nouvelle valeur de s
		}

		if(button == ui->pushButton_mod)
		    ui->lineSaisie->setText(s+"%");
		else if(button == ui->pushButton_fact)
		    ui->lineSaisie->setText(s+"!");
		else if(button == ui->pushButton_sin || button == ui->pushButton_cos || button == ui->pushButton_tan)
		    if(ui->checkBox_hyperbolic->isChecked())
			ui->lineSaisie->setText(s+button->text()+"H");
		    else
			ui->lineSaisie->setText(s+button->text());
		else if(button == ui->pushButton_radToDeg)
		    ui->lineSaisie->setText(s+"RADTODEG");
		else if(button == ui->pushButton_degToRad)
		    ui->lineSaisie->setText(s+"DEGTORAD");
		else if(button == ui->pushButton_pi)
		    ui->lineSaisie->setText(s+"3.141592653589793238462643383");
		else
		    ui->lineSaisie->setText(s+button->text());

		s = ui->lineSaisie->text(); // On met à jour la nouvelle valeur de s

		if(ui->checkBox_calculAuto->isChecked() && s.length() > 0)
		{
		    qDebug("empilement operation");
		    Motor::get_motor()->empile(ui->lineSaisie->text());
		}
		else
		{
		    qDebug("non empilement operation");
		    if(!s.contains(QRegExp("(?: $)|(?:^$)"))) // S'il n'y a pas déjà des un espace
			ui->lineSaisie->setText(s+" "); // on l'ajoute
		}
	    }
	    else
		ui->statusBar->showMessage("Finissez d'écrire votre nombre !", 3000);
	}
    }

    // On rend le focus à la barre de saisie
    ui->lineSaisie->setFocus();
    ui->listWidget_pile->scrollToBottom();
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_U)
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_basique);
    else if(e->key() == Qt::Key_I)
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_divers);
    else if(e->key() == Qt::Key_O)
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_trigo);
    else if(e->key() == Qt::Key_P)
	ui->tabWidget_saisie->setCurrentWidget(ui->tab_pile);
    else if(e->key() == Qt::Key_Apostrophe)
	ui->checkBox_calculAuto->toggle();
    else if(e->key() == Qt::Key_0)
    {
	ui->pushButton_0->setDown(false);
	ui->pushButton_0->click();
    }
    else if(e->key() == Qt::Key_1)
    {
	ui->pushButton_1->setDown(false);
	ui->pushButton_1->click();
    }
    else if(e->key() == Qt::Key_2)
    {
	ui->pushButton_2->setDown(false);
	ui->pushButton_2->click();
    }
    else if(e->key() == Qt::Key_3)
    {
	ui->pushButton_3->setDown(false);
	ui->pushButton_3->click();
    }
    else if(e->key() == Qt::Key_4)
    {
	ui->pushButton_4->setDown(false);
	ui->pushButton_4->click();
    }
    else if(e->key() == Qt::Key_5)
    {
	ui->pushButton_5->setDown(false);
	ui->pushButton_5->click();
    }
    else if(e->key() == Qt::Key_6)
    {
	ui->pushButton_6->setDown(false);
	ui->pushButton_6->click();
    }
    else if(e->key() == Qt::Key_7)
    {
	ui->pushButton_7->setDown(false);
	ui->pushButton_7->click();
    }
    else if(e->key() == Qt::Key_8)
    {
	ui->pushButton_8->setDown(false);
	ui->pushButton_8->click();
    }
    else if(e->key() == Qt::Key_9)
    {
	ui->pushButton_9->setDown(false);
	ui->pushButton_9->click();
    }
    else if(e->key() == Qt::Key_Plus)
    {
	ui->pushButton_plus->setDown(false);
	ui->pushButton_plus->click();
    }
    else if(e->key() == Qt::Key_Minus)
    {
	ui->pushButton_moins->setDown(false);
	ui->pushButton_moins->click();
    }
    else if(e->key() == Qt::Key_Asterisk)
    {
	ui->pushButton_fois->setDown(false);
	ui->pushButton_fois->click();
    }
    else if(e->key() == Qt::Key_Slash)
    {
	if(ui->radioButton_rationnel->isChecked() && ui->lineSaisie->text().contains(QRegExp("[0-9]$")))
	{
	    ui->pushButton_space->setDown(false);
	    ui->pushButton_space->click();
	}
	else
	{
	    ui->pushButton_diviser->setDown(false);
	    ui->pushButton_diviser->click();
	}
    }
    else if(e->key() == Qt::Key_Backspace)
    {
	ui->pushButton_del->setDown(false);
	ui->pushButton_del->click();
    }
    else if(e->key() == Qt::Key_Comma || e->key() == Qt::Key_Period || e->key() == Qt::Key_Dollar)
    {
	ui->pushButton_space->setDown(false);
	ui->pushButton_space->click();
    }
    else
	QMainWindow::keyReleaseEvent(e);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_0)
	ui->pushButton_0->setDown(true);
    else if(e->key() == Qt::Key_1)
	ui->pushButton_1->setDown(true);
    else if(e->key() == Qt::Key_2)
	ui->pushButton_2->setDown(true);
    else if(e->key() == Qt::Key_3)
	ui->pushButton_3->setDown(true);
    else if(e->key() == Qt::Key_4)
	ui->pushButton_4->setDown(true);
    else if(e->key() == Qt::Key_5)
	ui->pushButton_5->setDown(true);
    else if(e->key() == Qt::Key_6)
	ui->pushButton_6->setDown(true);
    else if(e->key() == Qt::Key_7)
	ui->pushButton_7->setDown(true);
    else if(e->key() == Qt::Key_8)
	ui->pushButton_8->setDown(true);
    else if(e->key() == Qt::Key_9)
	ui->pushButton_9->setDown(true);
    else if(e->key() == Qt::Key_Plus)
	ui->pushButton_plus->setDown(true);
    else if(e->key() == Qt::Key_Minus)
	ui->pushButton_moins->setDown(true);
    else if(e->key() == Qt::Key_Asterisk)
	ui->pushButton_fois->setDown(true);
    else if(e->key() == Qt::Key_Slash)
	if(ui->radioButton_rationnel->isChecked() && ui->lineSaisie->text().contains(QRegExp("[0-9]$")))
	    ui->pushButton_space->setDown(true);
	else
	    ui->pushButton_diviser->setDown(true);
    else if(e->key() == Qt::Key_Backspace)
	ui->pushButton_del->setDown(true);
    else if(e->key() == Qt::Key_Comma || e->key() == Qt::Key_Period || e->key() == Qt::Key_Dollar)
	ui->pushButton_space->setDown(true);
    else
	QMainWindow::keyPressEvent(e);
}

void MainWindow::slot_updatePileView()
{
    if(Pile::get_curPile()->length() > 0){
	ui->listWidget_pile->clear();
	for(int i = 0 ; i < Pile::get_curPile()->length() ; ++i)
	{
	    string item = Pile::get_curPile()->at(i)->toString();
	    ui->listWidget_pile->addItem(item.c_str());
	}
    }
    else
	ui->listWidget_pile->clear();
}

void MainWindow::slot_updateUiStatusBar(QString text)
{
    ui->statusBar->showMessage(text, 3000);
}

void MainWindow::slot_toggledCalculAuto(bool checked)
{
    if(checked)
    {
	QString s = ui->lineSaisie->text();
	if(s.right(1) == " ") // S'il y'a un espace final
	    s = s.left(s.length() -1); // On l'enlève
	if(s.length()>0)
	{
	    qDebug("empilement expression concrete");
	    Motor::get_motor()->empile("'"+s+"'");
	}
    }
}
