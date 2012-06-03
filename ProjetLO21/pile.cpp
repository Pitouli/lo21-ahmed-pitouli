#include "pile.h"

void Pile::clear()
{
    while(!this->isEmpty())
    {
	expression::Expression* expr = this->takeFirst(); // On supprime le 1er �l�ment de la pile
	delete expr; // On supprime l'�l�ment de la m�moire
    }
}

void Pile::swap(expression::Expression* i, expression::Expression* j)
{
    if(i->getType() == TYPE_ENTIER && j->getType() == TYPE_ENTIER)
    {
	expression::Entier* entier_i = static_cast<expression::Entier*>(i);
	expression::Entier* entier_j = static_cast<expression::Entier*>(j);
	int int_i = entier_i->getVal()-1;
	int int_j = entier_j->getVal()-1;

	if(int_i >= 0 && int_j >= 0 && int_i <= this->size() && int_j <= this->size())
	    this->QList<expression::Expression*>::swap(int_i,int_j);
	else
	    throw("SWAP impossible : les param�tres ne sont pas valides (au del� des bornes de la pile)");
    }
    else
	throw("SWAP impossible : les param�tres ne sont pas valides (ce ne sont pas des entiers)");
}

void Pile::sum(expression::Expression* x)
{
    if(x->getType() == TYPE_ENTIER)
    {
	expression::Entier* entier_x = static_cast<expression::Entier*>(x);
	int int_x = entier_x->getVal();

	if(int_x > this->size()) int_x = this->size(); // Si on essaie de sommer plus que la hauteur de la pile, on somme toute la pile.
	if(int_x < 0) int_x = 0; // Si x est n�gatif, on ne somme rien

	if(int_x != 0) // Si on somme plus d'1 �l�ment
	{
	    expression::Expression* resultat = this->pop();
	    expression::Somme* somme = new expression::Somme; // On initialise la somme avec les deux 1er �l�ments

	    for(int i = int_x - 1; i > 0; i--) // i repr�sente le nb de sommes � faire
	    {
		somme->setExp(this->pop(),resultat);
		resultat = somme->operation(); // On effectue l'op�ration qu'on r�cup�re dans r�sultat
		delete somme->getExpLeft();
		delete somme->getExpRight();
	    }

	    delete somme;

	    this->push(resultat);
	}
	else // Si on somme 0 �l�ment
	    this->push(new expression::Entier(0)); // Si on ne somme rien, on empile 0
    }
    else
	throw("SWAP impossible : les param�tres ne sont pas valides (ce ne sont pas des entiers)");
}

void Pile::dup()
{
    if(!this->isEmpty())
    {
	expression::Expression* expr = this->last();
	expression::Expression* exprClone = expr->clone();
	this->push(exprClone);
    }
}

void Pile::drop()
{
    if(!this->isEmpty())
	this->removeLast();
}