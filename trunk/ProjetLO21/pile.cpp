#include "pile.h"

Pile* Pile::_curPile = NULL;
string Pile::sauv = "";
Pile* Pile::get_curPile() { return _curPile; }
void Pile::set_curPile(Pile* newCurPile) { _curPile = newCurPile; }

Pile::Pile()
{
    _curPile = this;
}

void Pile::sauv_piles(){
    string filename = "sauvegarde.txt";

    // ouverture en écriture avec effacement du fichier ouvert
    ofstream fichier(filename.c_str(), ios::out | ios::trunc);

    if(!fichier.fail()){

        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Pile::clear()
{
    while(!this->isEmpty())
    {
	expression::Expression* expr = this->takeFirst(); // On supprime le 1er élément de la pile
	delete expr; // On supprime l'élément de la mémoire
    }
}

void Pile::swap()
{
    expression::Expression* i = this->pop();
    expression::Expression* j = this->pop();

    if(i->getType() == TYPE_ENTIER && j->getType() == TYPE_ENTIER)
    {
	expression::Entier* entier_i = static_cast<expression::Entier*>(i);
	expression::Entier* entier_j = static_cast<expression::Entier*>(j);
	int int_i = entier_i->getVal()-1;
	int int_j = entier_j->getVal()-1;

	if(int_i >= 0 && int_j >= 0 && int_i <= this->size() && int_j <= this->size())
	{
	    this->QList<expression::Expression*>::swap(int_i,int_j);
	    delete i;
	    delete j;
	}
	else
	{
	    this->push(j);
	    this->push(i);
	    throw("SWAP impossible : les paramètres ne sont pas valides (au delà des bornes de la pile)");
	}
    }
    else
    {
	this->push(j);
	this->push(i);
	throw("SWAP impossible : les paramètres ne sont pas valides (ce ne sont pas des entiers)");
    }
}

expression::Expression* Pile::sum(const expression::Expression* x)
{
    if(x->getType() == TYPE_ENTIER)
    {
	const expression::Entier* entier_x = static_cast<const expression::Entier*>(x);
	int int_x = entier_x->getVal();

	if(int_x > this->size()) int_x = this->size(); // Si on essaie de sommer plus que la hauteur de la pile, on somme toute la pile.
	if(int_x < 0) int_x = 0; // Si x est négatif, on ne somme rien

	if(int_x != 0) // Si on somme plus d'1 élément
	{
	    qDebug() << "Le int_x vaut : " << int_x;

	    expression::Expression* resultat = this->pop();
	    expression::Somme* somme = new expression::Somme; // On initialise la somme avec les deux 1er éléments

	    for(int i = int_x - 1; i > 0; i--) // i représente le nb de sommes à faire
	    {
		somme->setExp(this->pop(),resultat);
		resultat = somme->operation(); // On effectue l'opération qu'on récupère dans résultat
		delete somme->getExpLeft();
		delete somme->getExpRight();
	    }

	    delete somme;

	    return resultat;
	}
	else // Si on somme 0 élément
	    return new expression::Entier(0); // Si on ne somme rien, on empile 0
    }
    else
	throw("SUM impossible : le paramètre n'est pas valide (ce n'est pas un entier)");
}

expression::Expression* Pile::mean(const expression::Expression* x)
{
    if(x->getType() == TYPE_ENTIER)
    {
	const expression::Entier* entier_x = static_cast<const expression::Entier*>(x);
	int int_x = entier_x->getVal();

	if(int_x > this->size()) int_x = this->size(); // Si on essaie de moyenner plus que la hauteur de la pile, on somme toute la pile.
	if(int_x < 0) int_x = 0; // Si x est négatif, on ne moyenne rien

	if(int_x != 0) // Si on moyenne plus d'1 élément
	{
	    qDebug() << "Le int_x vaut : " << int_x;

	    expression::Expression* resSomme = this->sum(x); // On fait faire la somme par sum()

	    expression::Division* division = new expression::Division(resSomme, x); // On initialise la division avec le résultat de la somme et le nb par lequel diviser

	    expression::Expression* resultat = division->operation();

	    delete resSomme;
	    delete division;

	    return resultat;
	}
	else // Si on moyenne 0 élément
	    return new expression::Entier(0); // Si on ne moyenne rien, on empile 0
    }
    else
	throw("MEAN impossible : le paramètre n'est pas valide (ce n'est pas un entier)");
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
