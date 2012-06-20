#include "pile.h"
using namespace std;

Pile* Pile::_curPile = NULL;
Pile* Pile::get_curPile() {
    if(_curPile == NULL)
    {
	_curPile = new Pile();
    }
    return _curPile;
}
void Pile::set_curPile(Pile* newCurPile) { _curPile = newCurPile; }

void Pile::sauvegarde(){
    if(get_curPile()->size()>0){
         string temp=get_curPile()->front()->toString();
         for (QList<expression::Expression*>::iterator i = get_curPile()->begin()+1; i != get_curPile()->end(); ++i)
             temp+=("#"+(*i)->toString());
         sauv.push_back(temp);
         get_curPile()->sauv_pile();
    }
}

vector<string> Pile::explode(const string& str, char c){
    std::istringstream split(str); // flux d'exatraction sur un std::string
    std::vector<std::string> tokens;
    for (std::string each; std::getline(split, each, c); tokens.push_back(each));
    return tokens;
}

void Pile::sauv_pile(){
    string filename = "sauvegarde.txt";
    qDebug("sauvegarde");
    // ouverture en écriture avec effacement du fichier ouvert
    ofstream fichier(filename.c_str(), ios::out | ios::trunc);

    if(!fichier.fail()){
        if(sauv.size()>0){
            fichier<<sauv.back();
            sauv.pop_back();
            while(! sauv.empty()){
                fichier<<"@"<<sauv.back();
                sauv.pop_back();
            }
        }
        fichier.close();
    }
    else
        throw "Impossible d'ouvrir le fichier !";
}

void Pile::recharger_pile(){
    string filename = "sauvegarde.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    string temp;
    ifstream fichier(filename.c_str(), ios::in);

    if(!fichier.fail()){// si l'ouverture a réussi
        fichier>>temp;
        fichier.close();  // je referme le fichier
        vector<string> piles=explode(temp,'@');

        for(vector<string>::reverse_iterator i = piles.rbegin(); i != piles.rend(); ++i){
            sauv.push_back(*i);
        }
        if(sauv.size()>0){
            QString temp;
            vector<string> pile1=explode(sauv[sauv.size()-1],'#');
            for(vector<string>::iterator i = pile1.begin(); i != pile1.end(); ++i){
                temp=(*i).c_str();
                qDebug((*i).c_str());
                get_curPile()->push(Factory::get_factory()->analyze(temp));
            }
        }
        indiceSauv=sauv.size()-1;
        emit sig_updatePileViewAfterReloading();
    }
    else  // sinon
        throw "Erreur à l'ouverture !";
}

void Pile::undo(){
    if(indiceSauv>=0){
        vector<string> pile1=explode(sauv[indiceSauv],'#');
        get_curPile()->clear();
        QString temp;
        for(vector<string>::iterator i = pile1.begin(); i != pile1.end(); ++i){
            temp=(*i).c_str();
            qDebug((*i).c_str());
            get_curPile()->push(Factory::get_factory()->analyze(temp));
        }
        indiceSauv--;
    }
}

void Pile::redo(){
    if(indiceSauv<=(sauv.size()-1)){
        vector<string> pile1=explode(sauv[indiceSauv],'#');
        get_curPile()->clear();
        QString temp;
        for(vector<string>::iterator i = pile1.begin(); i != pile1.end(); ++i){
            temp=(*i).c_str();
            qDebug((*i).c_str());
            get_curPile()->push(Factory::get_factory()->analyze(temp));
        }
        indiceSauv++;
    }
}

void Pile::nouveau(){
    for(unsigned int i=sauv.size()-indiceSauv-1; i<0 && !sauv.empty(); i--)
        sauv.pop_back();
    sauvegarde();
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
    if(this->length() >= 2)
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
    else
    {
	qDebug("Erreur détectée chez swap : ");
	qDebug("Il y a moins de deux opérandes dans la pile.");
	throw("Erreur : il y a moins de deux opérandes dans la pile.");
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

