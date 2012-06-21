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
		Pile::get_curPile()->nouveau();

		emit sig_emptyLineSaisie();
	    }
	    catch(char const* e)
	    {
		qDebug("Erreur d�tect�e en op�ration nonaire : ");
		qDebug(e);
		LogSystem::get_logger()->addWarning("Erreur d�tect�e en op�ration nonaire : "+std::string(e));
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

		if(param->getType() == TYPE_EXPRESSION_C)
		{
		    expression::ExpressionConcrete* exprC = static_cast<expression::ExpressionConcrete*>(param);
		    Pile::get_curPile()->push(new expression::ExpressionConcrete(exprC->getExp()+" "+opUnaire->toString()));
		    Pile::get_curPile()->nouveau();

		    emit sig_emptyLineSaisie();
		    delete exprC;
		}
		else
		{
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
			qDebug("Erreur d�tect�e en op�ration unaire : ");
			qDebug(e);
			LogSystem::get_logger()->addWarning("Erreur d�tect�e en op�ration unaire : "+std::string(e));
			Pile::get_curPile()->push(param);
			emit sig_updateUiStatusBar(e);
		    }
		}

		delete opUnaire;
	    }
	    else
	    {
		qDebug("Erreur d�tect�e en op�ration unaire : ");
		qDebug("Il y a moins d'un op�rande dans la pile.");
		LogSystem::get_logger()->addWarning("Erreur d�tect�e en op�ration unaire : il y a moins d'un op�rande dans la pile.");
		emit sig_updateUiStatusBar("Erreur d�tect�e en op�ration unaire : il y a moins d'un op�rande dans la pile.");
	    }
	}
	else if(expr->getType() > TYPE_OPERATION_BINAIRE_START && expr->getType() < TYPE_OPERATION_BINAIRE_END)
	{
	    if(Pile::get_curPile()->size() >= 2)
	    {

		expression::OperationBinaire* opBinaire = static_cast<expression::OperationBinaire*>(expr);
		expression::Expression* param2 = Pile::get_curPile()->pop();
		expression::Expression* param1 = Pile::get_curPile()->pop();

		if(param1->getType() == TYPE_EXPRESSION_C && param2->getType() == TYPE_EXPRESSION_C)
		{
		    expression::ExpressionConcrete* exprC1 = static_cast<expression::ExpressionConcrete*>(param1);
		    expression::ExpressionConcrete* exprC2 = static_cast<expression::ExpressionConcrete*>(param2);
		    expression::ExpressionConcrete* res = new expression::ExpressionConcrete(exprC1->getExp()+" "+exprC2->getExp()+" "+opBinaire->toString());

		    Pile::get_curPile()->push(res);
		    Pile::get_curPile()->nouveau();

		    emit sig_emptyLineSaisie();
		    delete exprC1;
		    delete exprC2;
		}
		else if(param1->getType() == TYPE_EXPRESSION_C)
		{
		    expression::ExpressionConcrete* exprC1 = static_cast<expression::ExpressionConcrete*>(param1);
		    expression::ExpressionConcrete* res = new expression::ExpressionConcrete(exprC1->getExp()+" "+param2->toString()+" "+opBinaire->toString());

		    Pile::get_curPile()->push(res);
		    Pile::get_curPile()->nouveau();

		    emit sig_emptyLineSaisie();
		    delete exprC1;
		    delete param2;
		}
		else if(param2->getType() == TYPE_EXPRESSION_C)
		{
		    expression::ExpressionConcrete* exprC2 = static_cast<expression::ExpressionConcrete*>(param2);
		    expression::ExpressionConcrete* res = new expression::ExpressionConcrete(param1->toString()+" "+exprC2->getExp()+" "+opBinaire->toString());

		    Pile::get_curPile()->push(res);
		    Pile::get_curPile()->nouveau();

		    emit sig_emptyLineSaisie();
		    delete param1;
		    delete exprC2;
		}
		else
		{
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
			qDebug("Erreur d�tect�e en op�ration binaire : ");
			qDebug(e);
			LogSystem::get_logger()->addInfo("Erreur d�tect�e en op�ration binaire : "+std::string(e));
			Pile::get_curPile()->push(param1);
			Pile::get_curPile()->push(param2);
			emit sig_updateUiStatusBar(e);
		    }
		}

		delete opBinaire;
	    }
	    else
	    {
		qDebug("Erreur d�tect�e en op�ration binaire : ");
		qDebug("Il y a moins de deux op�randes dans la pile.");
		LogSystem::get_logger()->addWarning("Erreur d�tect�e en op�ration binaire : il y a moins de deux op�randes sur la pile");
		emit sig_updateUiStatusBar("Erreur : il y a moins de deux op�randes dans la pile.");
	    }
	}
    }
    catch(char const* e)
    {
	qDebug("Erreur d�tect�e en factory : ");
	qDebug(e);
	emit sig_updateUiStatusBar("Erreur : nous n'avons pas su interpr�ter la commande.");
	LogSystem::get_logger()->addWarning("Erreur d�tect�e en factory : "+std::string(e));
    }

    emit sig_updatePileView();
}

void Motor::eval()
{
    if(Pile::get_curPile()->size() >= 1)
    {
    Pile::get_curPile()->sauvegarde();
	expression::Expression* param = Pile::get_curPile()->pop();
	const expression::ExpressionConcrete* tempExpC;

	try
	{
	    if(param->getType() == TYPE_EXPRESSION_C) // Si l'op�rande est une expression concr�te on l'�value
	    {
		tempExpC = static_cast<const expression::ExpressionConcrete*>(param);
		QStringList listExp = QString(tempExpC->getExp().c_str()).split(' ');

		QStringList::const_iterator constIterator;
		for (constIterator = listExp.constBegin(); constIterator != listExp.constEnd(); ++constIterator)
		    this->empile(*constIterator);

		delete param;
	    }
	    else // Sinon on rempile l'op�rande
		Pile::get_curPile()->push(param);
        Pile::get_curPile()->sauvegarde();
	}
	catch(char const* e)
	{
	    qDebug("Erreur d�tect�e en op�ration d'�valuation' : ");
	    qDebug(e);
	    LogSystem::get_logger()->addWarning("Erreur d�tect�e en op�ration d'�valuation' : "+std::string(e));
	    Pile::get_curPile()->push(param);
	    emit sig_updateUiStatusBar(e);
	}
    }
    else
    {
	qDebug("Erreur d�tect�e en op�ration d'evaluation' : ");
	qDebug("Il y a moins d'un op�rande dans la pile.");
	LogSystem::get_logger()->addWarning("Erreur d�tect�e en op�ration d'�valuation : il y a moins d'un op�rande dans la pile.");
	emit sig_updateUiStatusBar("Erreur : il y a moins d'un op�rande dans la pile.");
    }
}
