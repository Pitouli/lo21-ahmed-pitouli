#include "motor.h"

Motor* Motor::_motor = 0;

Motor* Motor::get_motor()
{
    if(_motor == 0)
    {
	_motor = new Motor();
    }

    return _motor;
}

void Motor::del_motor()
{
    if(_motor != 0)
	delete _motor;
    _motor = 0;
}

Motor::~Motor()
{
    if(_motor != 0) delete _motor;
}

void Motor::empile(QString lineSaisie)
{
    try
    {
	expression::Expression* expr = Factory::get_factory()->analyze(lineSaisie);

	if((expr->getType() > TYPE_NOMBRE_START && expr->getType() < TYPE_NOMBRE_END) || expr->getType() == TYPE_EXPRESSION_C)
	{
	    Pile::get_curPile()->push(expr);
        Pile::get_curPile()->nouveau();
	    emit sig_emptyLineSaisie();
	}
	else if(expr->getType() > TYPE_OPERATION_NONAIRE_START && expr->getType() < TYPE_OPERATION_NONAIRE_END)
	{
	    expression::OperationNonaire* opNonaire = static_cast<expression::OperationNonaire*>(expr);

	    try
	    {
		opNonaire->operation();
		emit sig_emptyLineSaisie();
	    }
	    catch(char const* e)
	    {
		qDebug("Erreur détectée en opération nonaire : ");
		qDebug(e);
		emit sig_updateUiStatusBar(e);
	    }

	    delete opNonaire;
	}
	else if(expr->getType() > TYPE_OPERATION_UNAIRE_START && expr->getType() < TYPE_OPERATION_UNAIRE_END)
	{
	    if(Pile::get_curPile()->size() >= 1)
	    {
        Pile::get_curPile()->sauvegarde();
		expression::OperationUnaire* opUnaire = static_cast<expression::OperationUnaire*>(expr);
		expression::Expression* param = Pile::get_curPile()->pop();
		opUnaire->setExp(param);
		try
		{
		    Pile::get_curPile()->push(opUnaire->operation());
            Pile::get_curPile()->nouveau();
		    emit sig_emptyLineSaisie();
		    delete param;
		}
		catch(char const* e)
		{
		    qDebug("Erreur détectée en opération unaire : ");
		    qDebug(e);
		    Pile::get_curPile()->push(param);
		    emit sig_updateUiStatusBar(e);
		}
		delete opUnaire;
	    }
	    else
	    {
		qDebug("Erreur détectée en opération unaire : ");
		qDebug("Il y a moins d'un opérande dans la pile.");
		emit sig_updateUiStatusBar("Erreur : il y a moins d'un opérande dans la pile.");
	    }
	}
	else if(expr->getType() > TYPE_OPERATION_BINAIRE_START && expr->getType() < TYPE_OPERATION_BINAIRE_END)
	{
	    if(Pile::get_curPile()->size() >= 2)
	    {
        Pile::get_curPile()->sauvegarde();
		expression::OperationBinaire* opBinaire = static_cast<expression::OperationBinaire*>(expr);
		expression::Expression* param2 = Pile::get_curPile()->pop();
		expression::Expression* param1 = Pile::get_curPile()->pop();
		opBinaire->setExp(param1, param2);

		try
		{
		    expression::Expression* resultat = opBinaire->operation();
		    Pile::get_curPile()->push(resultat);
            Pile::get_curPile()->nouveau();
		    emit sig_emptyLineSaisie();
		    delete param1;
		    delete param2;
		}
		catch(char const* e)
		{
		    qDebug("Erreur détectée en opération binaire 1 : ");
		    qDebug(e);
		    Pile::get_curPile()->push(param1);
		    Pile::get_curPile()->push(param2);
		    emit sig_updateUiStatusBar(e);
		}

		delete opBinaire;
	    }
	    else
	    {
		qDebug("Erreur détectée en opération binaire 2 : ");
		qDebug("Il y a moins de deux opérandes dans la pile.");
		emit sig_updateUiStatusBar("Erreur : il y a moins de deux opérandes dans la pile.");
	    }
	}
    }
    catch(char const* e)
    {
	qDebug("Erreur détectée en factory : ");
	qDebug(e);
	emit sig_updateUiStatusBar("Erreur : nous n'avons pas su interpréter la commande.");
    }

    emit sig_updatePileView();
}

void Motor::eval()
{
    if(Pile::get_curPile()->size() >= 1)
    {
	expression::Expression* param = Pile::get_curPile()->pop();
	const expression::ExpressionConcrete* tempExpC;

	try
	{
	    if(param->getType() == TYPE_EXPRESSION_C) // Si l'opérande est une expression concrète on l'évalue
	    {
		tempExpC = static_cast<const expression::ExpressionConcrete*>(param);
		QStringList listExp = QString(tempExpC->getExp().c_str()).split(' ');

		QStringList::const_iterator constIterator;
		for (constIterator = listExp.constBegin(); constIterator != listExp.constEnd(); ++constIterator)
		    this->empile(*constIterator);

		delete param;
	    }
	    else // Sinon on rempile l'opérande
		Pile::get_curPile()->push(param);
	}
	catch(char const* e)
	{
	    qDebug("Erreur détectée en opération d'évaluation' : ");
	    qDebug(e);
	    Pile::get_curPile()->push(param);
	    emit sig_updateUiStatusBar(e);
	}
    }
    else
    {
	qDebug("Erreur détectée en opération d'evaluation' : ");
	qDebug("Il y a moins d'un opérande dans la pile.");
	emit sig_updateUiStatusBar("Erreur : il y a moins d'un opérande dans la pile.");
    }
}

