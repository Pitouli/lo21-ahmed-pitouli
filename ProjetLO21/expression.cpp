#include "expression.h"
#include "pile.h"
#include "motor.h"

using namespace expression;


expression::Reel::Reel(const Nombre& n):Nombre(TYPE_REEL){
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(n.getType()){
    case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (&n);
                            val=(tempRat->getNumVal()/tempRat->getDenomVal()).getVal();
                            break;

	case TYPE_ENTIER:   tempE = static_cast <const Entier*> (&n);
                        val=tempE->getVal();
                        break;

	case TYPE_REEL:     tempR = static_cast <const Reel*> (&n);
                        val=tempR->getVal();
                        break;
    default:            throw "La conversion en Reel n'est possible que pour les entiers et les rationnels";
                        break;
    };
}

/*** Operation pour reel **/

Reel expression::Reel::operator+(const Reel& n)const{
    return Reel(val+n.getVal());
}

Reel expression::Reel::operator*(const Reel& n)const{
    return Reel(val*n.getVal());
}

Reel expression::Reel::operator-(const Reel& n)const{
    return Reel(val-n.getVal());
}

Reel expression::Reel::operator/(const Reel& n)const{
    if(n.getVal()!=0)
        return Reel(val/n.getVal());
    else
        throw "La division par zero est interdite";
}

string expression::Reel::toString()const{
    stringstream ss;
    ss.unsetf(ios_base::floatfield);
    ss.precision(15);
    ss<<val;
    return ss.str();
}


expression::Complexe::Complexe(Nombre* _partieR, Nombre* _partieI):Nombre(TYPE_COMPLEXE){
    if(_partieR==0)
        partieR=new Reel(0);
    else
       partieR=_partieR->clone();

    if(_partieI==0)
        partieI=new Reel(0);
    else
       partieI=_partieI->clone();
}

expression::Complexe::Complexe(const Nombre& _partieR, const Nombre& _partieI):Nombre(TYPE_COMPLEXE){
    partieR=_partieR.clone();
    partieI=_partieI.clone();
}

expression::Complexe::Complexe(const Complexe& c):Nombre(TYPE_COMPLEXE){
       partieR=c.partieR->clone();
       partieI=c.partieI->clone();
}

expression::Complexe::Complexe(const Nombre& n):Nombre(TYPE_COMPLEXE){
    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    //on teste le type pour recuperer le pointeur adequat
    switch(n.getType()){
	case TYPE_COMPLEXE: tempC = static_cast <const Complexe*> (&n);
                        partieI=tempC->getPartieIVal().clone();
                        partieR=tempC->getPartieRVal().clone();
                        break;

	case TYPE_REEL:     tempR = static_cast <const Reel*> (&n);
                        partieI=new Reel(0);
                        partieR=new Reel(tempR->getVal());
                        break;

	case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (&n);
                            partieI=new Reel(0);
                            partieR=new Reel(tempRat->getNumVal()/tempRat->getDenomVal());
                            break;

	case TYPE_ENTIER:   tempE = static_cast <const Entier*> (&n);
                            partieI=new Reel(0);
                            partieR=new Reel(tempE->getVal());
                            break;

    default:            throw "La conversion en Complexe n'est possible que pour les reels, les entiers et les rationnels";
                        break;
    };
}

expression::Complexe::~Complexe(){
    delete partieR;
    delete partieI;
}


/*** Operation pour complexe **/
Complexe expression::Complexe::operator+(const Complexe& n)const{
    return Complexe(getPartieRVal()+n.getPartieRVal(),getPartieIVal()+n.getPartieIVal());
}

Complexe expression::Complexe::operator*(const Complexe& n)const{
    return Complexe((getPartieRVal()*n.getPartieRVal())-(getPartieIVal()*n.getPartieIVal()),
                    (getPartieRVal()*n.getPartieIVal())+(getPartieIVal()*n.getPartieRVal()));
}

Complexe expression::Complexe::operator-(const Complexe& n)const{
    return Complexe(getPartieRVal()-n.getPartieRVal(),getPartieIVal()-n.getPartieIVal());
}

Complexe expression::Complexe::operator/(const Complexe& n)const{
    if(((n.getPartieRVal()*n.getPartieRVal())+(n.getPartieIVal()*n.getPartieIVal())).getVal()==0
        ||((n.getPartieRVal()*n.getPartieRVal())+(n.getPartieIVal()*n.getPartieIVal())).getVal()==0)
       throw "La division par zero est interdite";

    //Temp est une variable intermerdiare qui correspond a 1/z avec z le complexe passe en parametre
    Complexe temp(n.getPartieRVal()/((n.getPartieRVal()*n.getPartieRVal())+(n.getPartieIVal()*n.getPartieIVal())),
                  n.getPartieRVal()/((n.getPartieRVal()*n.getPartieRVal())+(n.getPartieIVal()*n.getPartieIVal())));

    return Complexe((getPartieRVal()*temp.getPartieRVal())-(getPartieIVal()*temp.getPartieIVal()),
                    (getPartieRVal()*temp.getPartieIVal())+(getPartieIVal()*temp.getPartieRVal()));

}

Complexe& expression::Complexe::operator=(const Complexe& n){
    if(this!=&n){
        delete partieR;
        delete partieI;
        partieR=n.partieR->clone();
        partieI=n.partieI->clone();
    }

    return *this;
}

string expression::Complexe::toString()const{
    stringstream ss;
    ss<<partieR->toString()<<"$"<<partieI->toString();
    return ss.str();
}

expression::Entier::Entier(const Nombre& n):NombreE(TYPE_ENTIER){
    const Entier* tempE;

        //on teste le type pour recuperer le pointeur adequat
    switch(n.getType()){
	case TYPE_ENTIER:   tempE = static_cast <const Entier*> (&n);
                            val=tempE->getVal();
                            break;

    default:    throw "La conversion en Entier n'est possible que pour les entiers";
                break;
    };
}

/*** Operation pour entier **/
Entier expression::Entier::operator+(const Entier& n)const{
    return Entier(val+n.getVal());
}

Entier expression::Entier::operator*(const Entier& n)const{
    return Entier(val*n.getVal());
}

Entier expression::Entier::operator-(const Entier& n)const{
    return Entier(val-n.getVal());
}

Reel expression::Entier::operator/(const Entier& n)const{
    if(n.getVal()!=0)
        return Reel(val/n.getVal());
    else
        throw "La division par zero est interdite";
}

string expression::Entier::toString()const{
    stringstream ss;
    ss<<val;
    return ss.str();
}

expression::Rationnel::Rationnel(Entier* _num, Entier* _denom):NombreE(TYPE_RATIONNEL){
    if(_num==0)
        num=new Entier(0);
    else
       num=_num;
    if(_denom==0)
        denom=new Entier(1);
    else{
        if(_denom->getVal()==0)//on verifie que le denominateur n'est pas nul
            throw "Le denominateur ne peut pas etre nul";
       denom=_denom;
    }
    simplification();//On simplfie la fraction
}

expression::Rationnel::Rationnel(const Nombre& _num, const Nombre& _denom):NombreE(TYPE_RATIONNEL){
    const Reel* tempR;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;
    const Entier* tempE1;
    const Entier* tempE2;

    //On verifie qu'on a deux objets du meme type
    switch(_num.getType()+_denom.getType()){
	case TYPE_RATIONNEL*2:  tempRat1 = static_cast <const Rationnel*> (&_num);
                            tempRat2 = static_cast <const Rationnel*> (&_denom);
                            if(tempRat2->getDenomVal().getVal()==0)//On verifie que le denominateur n'est pas nul
                                throw "Le denominateur ne peut pas etre nul";
                            num=new Entier(tempRat1->getNumVal()/tempRat2->getDenomVal());
                            denom=new Entier(tempRat2->getNumVal()/tempRat2->getDenomVal());
                            break;

	case TYPE_ENTIER*2: tempE1 = static_cast <const Entier*> (&_num);
                        tempE2 = static_cast <const Entier*> (&_denom);
                        if(tempE2->getVal()==0)//On verifie que le denominateur n'est pas nul
                            throw "Le denominateur ne peut pas etre nul";
                        num=new Entier(tempE1->getVal());
                        denom=new Entier(tempE2->getVal());
                        break;

    default:                //Si les deux sont differends on les convertie en reel
                            tempR = new Reel(_num);
                            num=new Entier((int)tempR->getVal());
                            delete tempR;

                            tempR = new Reel(_denom);
                            if(tempR->getVal()==0)//On verifie que le denominateur n'est pas nul
                                throw "Le denominateur ne peut pas etre nul";
                            denom=new Entier((int)tempR->getVal());
                            delete tempR;
                            break;
    };
    simplification();//On simplfie la fraction
}

expression::Rationnel::Rationnel(const Rationnel& c):NombreE(TYPE_RATIONNEL){
    num=c.num->clone();
    denom=c.denom->clone();
    simplification();//On simplfie la fraction
}

expression::Rationnel::Rationnel(const Nombre& n):NombreE(TYPE_RATIONNEL){
    const Rationnel* tempRat;
    const Entier* tempE;

    //on teste le type pour recuperer le pointeur adequat
    switch(n.getType()){
    case TYPE_RATIONNEL:        tempRat = static_cast <const Rationnel*> (&n);
                                num=tempRat->getNumVal().clone();
                                denom=tempRat->getDenomVal().clone();
                                break;

	case TYPE_ENTIER:   tempE = static_cast <const Entier*> (&n);
                            num=new Entier(tempE->getVal());
                            denom=new Entier(1);
                            break;

    default:   throw "La conversion en Rationnel n'est possible que pour les entiers";
               break;
    };
    simplification();//On simplfie la fraction
}

int expression::Rationnel::pgcd(int a, int b) const {
    if (a==0||b==0) return 0;
    if (a<0) a=-a;
    if (b<0) b=-b;
    while(a!=b){
        if (a>b) a=a-b; else b=b-a;
    }
    return a;
}

void expression::Rationnel::simplification(){
    if (getNumVal().getVal()==0) { setDenom(1); return; }
    if (getDenomVal().getVal()==0) return;
    int p=pgcd(getNumVal().getVal(),getDenomVal().getVal());
    setNum(getNumVal().getVal()/p);
    setDenom(getDenomVal().getVal()/p);
    if (getDenomVal().getVal()<0){
        setDenom(-getDenomVal().getVal());
        setNum(-getNumVal().getVal());
    }
}

/*** Operation pour rationnel ***/
Rationnel expression::Rationnel::operator+(const Rationnel& c)const{
    return Rationnel((getNumVal()*c.getDenomVal())+(c.getNumVal()*getDenomVal()),getDenomVal()*c.getDenomVal());
}

Rationnel expression::Rationnel::operator*(const Rationnel& c)const{
    return Rationnel(getNumVal()*c.getNumVal(),getDenomVal()*c.getDenomVal());
}

Rationnel expression::Rationnel::operator-(const Rationnel& c)const{
    return Rationnel((getNumVal()*c.getDenomVal())-(c.getNumVal()*getDenomVal()),getDenomVal()*c.getDenomVal());
}

Rationnel expression::Rationnel::operator/(const Rationnel& c)const{
    if(c.getNumVal().getVal()!=0)
        return Rationnel(getNumVal()*c.getDenomVal(),getDenomVal()*c.getNumVal());
    else
        throw "La division par zero est interdite";
}

Rationnel& expression::Rationnel::operator=(const Rationnel& n){
    if(this!=&n){
        delete num;
        delete denom;
        num=n.num->clone();
        denom=n.denom->clone();
    }
    simplification();//On simplfie la fraction
    return *this;
}

string expression::Rationnel::toString()const{
    stringstream ss;
    ss<<num->toString()<<"/"<<denom->toString();
    return ss.str();
}

expression::Rationnel::~Rationnel(){
    delete num;
    delete denom;
}

Expression* expression::Somme::operation(){
    const Nombre* expLeftTemp=static_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=static_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);
    /*Pour faire les operations une des deux epressions peut �tre converti
      dans le type de l'autre si ce dernier appartient a un ensemble plus grand*/

    /*Le resultat est renvoy� dans un objet du meme type que l'expression qui
      a l'ensemble le plus grand*/

    //On choisit l'expression qui appartient a l'ensemble le plus grand
    if(expLeftTemp->getType()<=expRightTemp->getType()){
        //On teste le type du premier
        switch(expLeftTemp->getType()){
        case TYPE_COMPLEXE:     tempC1 = static_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)+(*tempC2)));
                                delete tempC2;
                                break;

        case TYPE_REEL:         tempR1 = static_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)+(*tempR2)));
                                delete tempR2;
                                break;

        case TYPE_RATIONNEL:        tempRat1 = static_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)+(*tempRat2)));
                                    delete tempRat2;
                                    break;

        case TYPE_ENTIER:       tempE1 = static_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Entier((*tempE1)+(*tempE2)));
                                delete tempE2;
                                break;

        default:    throw "Somme impossible: premier operande invalide";
                    break;
        };
    }
    else{
        //On teste le type du second
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC2 = new Complexe(*expLeftTemp);
                                tempC1 = static_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC1)+(*tempC2)));
                                delete tempC2;
                                break;

            case TYPE_REEL:     tempR2 = new Reel(*expLeftTemp);
                                tempR1 = static_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR1)+(*tempR2)));
                                delete tempR2;
                                break;

            case TYPE_RATIONNEL:    tempRat2 = new Rationnel(*expLeftTemp);
                                    tempRat1 = static_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat1)+(*tempRat2)));
                                    delete tempRat2;
                                    break;

            case TYPE_ENTIER:   tempE2 = new Entier(*expLeftTemp);
                                tempE1 = static_cast <const Entier*> (expRightTemp);
                                setRes(new Entier((*tempE1)+(*tempE2)));
                                delete tempE2;
                                break;

            default:    throw "Somme impossible: deuxieme operande invalide";
                        break;
        };
    }

    return getRes();
}

string expression::Somme::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExpLeft() != NULL && getExpRight() != NULL)
	ss<<getExpLeft()->toString()<<" "<<getExpRight()->toString()<<" +";
    else
	ss<<"+";
    return ss.str();
}

Expression* expression::Difference::operation(){
    const Nombre* expLeftTemp=static_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=static_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);
    /*Pour faire les operations une des deux epressions peut �tre converti
      dans le type de l'autre si ce dernier appartient a un ensemble plus grand*/

    /*Le resultat est renvoy� dans un objet du meme type que l'expression qui
      a l'ensemble le plus grand*/

    //On choisit l'expression qui appartient a l'ensemble le plus grand
    if(expLeftTemp->getType()<expRightTemp->getType()){
        switch(expLeftTemp->getType()){
        case TYPE_COMPLEXE:     tempC1 = static_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)-(*tempC2)));
                                delete tempC2;
                                break;

        case TYPE_REEL:         tempR1 = static_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)-(*tempR2)));
                                delete tempR2;
                                break;

        case TYPE_RATIONNEL:        tempRat1 = static_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)-(*tempRat2)));
                                    delete tempRat2;
                                    break;

        case TYPE_ENTIER:       tempE1 = static_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Entier((*tempE1)-(*tempE2)));
                                delete tempE2;
                                break;

        default:    throw "Difference impossible: premier operande invalide";
                    break;
        };
    }
    else{
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC2 = new Complexe(*expLeftTemp);
                                tempC1 = static_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC2)-(*tempC1)));
                                delete tempC2;
                                break;

            case TYPE_REEL:     tempR2 = new Reel(*expLeftTemp);
                                tempR1 = static_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR2)-(*tempR1)));
                                delete tempR2;
                                break;

            case TYPE_RATIONNEL:    tempRat2 = new Rationnel(*expLeftTemp);
                                    tempRat1 = static_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat2)-(*tempRat1)));
                                    delete tempRat2;
                                    break;

            case TYPE_ENTIER:   tempE2 = new Entier(*expLeftTemp);
                                tempE1 = static_cast <const Entier*> (expRightTemp);
                                setRes(new Entier((*tempE2)-(*tempE1)));
                                delete tempE2;
                                break;

        default:    throw "Difference impossible: deuxieme operande invalide";
                    break;
        };
    }

    return getRes();
}

string expression::Difference::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExpLeft() != NULL && getExpRight() != NULL)
	ss<<getExpLeft()->toString()<<" "<<getExpRight()->toString()<<" -";
    else
	ss<<"-";
    return ss.str();
}

Expression* expression::Multiplication::operation(){
    const Nombre* expLeftTemp=static_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=static_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);

    /*Pour faire les operations une des deux epressions peut �tre converti
      dans le type de l'autre si ce dernier appartient a un ensemble plus grand*/

    /*Le resultat est renvoy� dans un objet du meme type que l'expression qui
      a l'ensemble le plus grand*/

    //On choisit l'expression qui appartient a l'ensemble le plus grand
    if(expLeftTemp->getType()<expRightTemp->getType()){
        switch(expLeftTemp->getType()){
        case TYPE_COMPLEXE:     tempC1 = static_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)*(*tempC2)));
                                delete tempC2;
                                break;

        case TYPE_REEL:         tempR1 = static_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)*(*tempR2)));
                                delete tempR2;
                                break;

        case TYPE_RATIONNEL:        tempRat1 = static_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)*(*tempRat2)));
                                    delete tempRat2;
                                    break;

        case TYPE_ENTIER:       tempE1 = static_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Entier((*tempE1)*(*tempE2)));
                                delete tempE2;
                                break;

        default:    throw "Multiplication impossible: premier operande invalide";
                    break;
        };
    }
    else{
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC2 = new Complexe(*expLeftTemp);
                                tempC1 = static_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC1)*(*tempC2)));
                                delete tempC2;
                                break;

            case TYPE_REEL:     tempR2 = new Reel(*expLeftTemp);
                                tempR1 = static_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR1)*(*tempR2)));
                                delete tempR2;
                                break;

            case TYPE_RATIONNEL:    tempRat2 = new Rationnel(*expLeftTemp);
                                    tempRat1 = static_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat1)*(*tempRat2)));
                                    delete tempRat2;
                                    break;

            case TYPE_ENTIER:   tempE2 = new Entier(*expLeftTemp);
                                tempE1 = static_cast <const Entier*> (expRightTemp);
                                setRes(new Entier((*tempE1)*(*tempE2)));
                                delete tempE2;
                                break;

        default:    throw "Multiplication impossible: deuxieme operande invalide";
                    break;
        };
    }

    return getRes();
}

string expression::Multiplication::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExpLeft() != NULL && getExpRight() != NULL)
	ss<<getExpLeft()->toString()<<" "<<getExpRight()->toString()<<" *";
    else
	ss<<"*";
    return ss.str();
}

Expression* expression::Division::operation(){
    const Nombre* expLeftTemp=static_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=static_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);
    /*Pour faire les operations une des deux epressions peut �tre converti
      dans le type de l'autre si ce dernier appartient a un ensemble plus grand*/

    /*Le resultat est renvoy� dans un objet du meme type que l'expression qui
      a l'ensemble le plus grand*/

    //On choisit l'expression qui appartient a l'ensemble le plus grand
    if(expLeftTemp->getType()<expRightTemp->getType()){
        switch(expLeftTemp->getType()){
        case TYPE_COMPLEXE:     tempC1 = static_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)/(*tempC2)));
                                delete tempC2;
                                break;

        case TYPE_REEL:         tempR1 = static_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)/(*tempR2)));
                                delete tempR2;
                                break;

        case TYPE_RATIONNEL:        tempRat1 = static_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)/(*tempRat2)));
                                    delete tempRat2;
                                    break;

        case TYPE_ENTIER:       tempE1 = static_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Reel((*tempE1)/(*tempE2)));
                                delete tempE2;
                                break;

        default:    throw "Division impossible: premier operande invalide";
                    break;
        };
    }
    else{
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC2 = new Complexe(*expLeftTemp);
                                tempC1 = static_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC2)/(*tempC1)));
                                delete tempC2;
                                break;

            case TYPE_REEL:     tempR2 = new Reel(*expLeftTemp);
                                tempR1 = static_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR2)/(*tempR1)));
                                delete tempR2;
                                break;

            case TYPE_RATIONNEL:    tempRat2 = new Rationnel(*expLeftTemp);
                                    tempRat1 = static_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat2)/(*tempRat1)));
                                    delete tempRat2;
                                    break;

            case TYPE_ENTIER:   tempE2 = new Entier(*expLeftTemp);
                                tempE1 = static_cast <const Entier*> (expRightTemp);
                                setRes(new Reel((*tempE2)/(*tempE1)));
                                delete tempE2;
                                break;

        default:    throw "Division impossible: deuxieme operande invalide";
                    break;
        };
    }

    return getRes();
}

string expression::Division::toString()const{
    stringstream ss;
    //On verifie que l'operation a des operandes initialises
    if(getExpLeft() != NULL && getExpRight() != NULL)
	ss<<getExpLeft()->toString()<<" "<<getExpRight()->toString()<<" /";
    else
	ss<<"/";
    return ss.str();
}

Expression* expression::Mod::operation(){

    setRes(NULL);

    //on teste le type pour recuperer le pointeur adequat
    if(getExpLeft()->getType()==TYPE_ENTIER && getExpRight()->getType()==TYPE_ENTIER){
        const Entier* expLeftTemp=static_cast<const Entier*>(getExpLeft());
        const Entier* expRightTemp=static_cast<const Entier*>(getExpRight());
        setRes(new Entier(expLeftTemp->getVal()%expRightTemp->getVal()));
    }
    else
        throw "L'operation modulo n'est possible que pour les entiers";

    return getRes();
}

string expression::Mod::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExpLeft() != NULL && getExpRight() != NULL)
	ss<<getExpLeft()->toString()<<" "<<getExpRight()->toString()<<" %";
    else
	ss<<"%";
    return ss.str();
}

Expression* expression::Pow::operation(){

    setRes(NULL);
    const Nombre* expTemp=static_cast<const Nombre*>(getExpLeft());
    const Nombre* base=static_cast<const Nombre*>(getExpRight());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(pow(tempR->getVal(),(new Reel(*base))->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                if((tempRat->getNumVal()/tempRat->getDenomVal()).getVal()>=0)
                                    setRes(new Reel(pow((tempRat->getNumVal()/tempRat->getDenomVal()).getVal(),(new Reel(*base))->getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(pow(tempE->getVal(),(new Reel(*base))->getVal())));
                            break;

        default:    throw "L'operation puissance n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Pow::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExpLeft() != NULL && getExpRight() != NULL)
	ss<<getExpLeft()->toString()<<" "<<getExpRight()->toString()<<" POW";
    else
	ss<<"POW";
    return ss.str();
}

Expression* expression::Sin::operation(){

    if(Motor::get_motor()->get_paramTrigo() == PARAM_DEGRE)
    {
	Expression* exprRes = DegToRad(this->getExp()).operation();
	this->setExp(exprRes);
    }

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(sin(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(sin((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(sin(tempE->getVal())));
                            break;

        default:    throw "L'operation Sin n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Sin::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" SIN";
    else
	ss<<"SIN";
    return ss.str();
}

Expression* expression::Cos::operation(){

    if(Motor::get_motor()->get_paramTrigo() == PARAM_DEGRE)
    {
	Expression* exprRes = DegToRad(this->getExp()).operation();
	this->setExp(exprRes);
    }

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(cos(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(cos((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(cos(tempE->getVal())));
                            break;

        default:    throw "L'operation Cos n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Cos::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" COS";
    else
	ss<<"COS";
    return ss.str();
}

Expression* expression::Tan::operation(){

    if(Motor::get_motor()->get_paramTrigo() == PARAM_DEGRE)
    {
	Expression* exprRes = DegToRad(this->getExp()).operation();
	this->setExp(exprRes);
    }

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    /*on teste le type pour recuperer le pointeur adequat et on fait appel
      a la fonction de cmath correspondant a l'operation que l'on effectue*/
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(tan(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(tan((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(tan(tempE->getVal())));
                            break;

        default:    throw "L'operation Tan n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Tan::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" TAN";
    else
	ss<<"TAN";
    return ss.str();
}

Expression* expression::Sinh::operation(){

    //Si on est en mode degre on conertit l'expression en radian
    if(Motor::get_motor()->get_paramTrigo() == PARAM_DEGRE)
    {
	Expression* exprRes = DegToRad(this->getExp()).operation();
	this->setExp(exprRes);
    }

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(sinh(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(sinh((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(sinh(tempE->getVal())));
                            break;

        default:    throw "L'operation Sinh n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Sinh::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" SINH";
    else
	ss<<"SINH";
    return ss.str();
}

Expression* expression::Cosh::operation(){

    if(Motor::get_motor()->get_paramTrigo() == PARAM_DEGRE)
    {
	Expression* exprRes = DegToRad(this->getExp()).operation();
	this->setExp(exprRes);
    }

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(cosh(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(cosh((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(cosh(tempE->getVal())));
                            break;

        default:    throw "L'operation Cosh n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Cosh::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" COSH";
    else
	ss<<"COSH";
    return ss.str();
}

Expression* expression::Tanh::operation(){

    if(Motor::get_motor()->get_paramTrigo() == PARAM_DEGRE)
    {
	Expression* exprRes = DegToRad(this->getExp()).operation();
	this->setExp(exprRes);
    }

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(tanh(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(tanh((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(tanh(tempE->getVal())));
                            break;

        default:    throw "L'operation Tanh n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Tanh::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" TANH";
    else
	ss<<"TANH";
    return ss.str();
}

Expression* expression::Ln::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(log(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(log((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(log(tempE->getVal())));
                            break;

        default:    throw "L'operation Ln n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Ln::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" LN";
    else
	ss<<"LN";
    return ss.str();
}

Expression* expression::Log::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel(log10(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(log10((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(log10(tempE->getVal())));
                            break;

        default:    throw "L'operation Log n'est possible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Log::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" LOG";
    else
	ss<<"LOG";
    return ss.str();
}

Expression* expression::Sign::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());
    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;
    Entier temp(-1);

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){
        case TYPE_COMPLEXE: tempC = static_cast <const Complexe*> (expTemp);
                            setRes(new Complexe(tempC->getPartieRVal()*temp,tempC->getPartieIVal()*temp));
                            break;

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel((*tempR)*temp));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Rationnel(tempRat->getNumVal()*temp,tempRat->getDenomVal()));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Entier((*tempE)*temp));
                            break;

        default:    throw "Operation Sign impossible: operande invalide(disponible pour complexes, reels, rationnels, entiers)";
                    break;
    };

    return getRes();
}

string expression::Sign::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" SIGN";
    else
	ss<<"SIGN";
    return ss.str();
}

Expression* expression::Inv::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Rationnel(new Entier(1),new Entier(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Rationnel(tempRat->getDenomVal(),tempRat->getNumVal()));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Rationnel(new Entier(1),new Entier(*tempE)));
                            break;

        default:    throw "Operation Inv impossible: operande invalide(disponible pour reels, rationnels, entiers)";
                    break;
    };

    return getRes();
}

string expression::Inv::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" INV";
    else
	ss<<"INV";
    return ss.str();
}

Expression* expression::Sqrt::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            if(tempR->getVal()>=0)
                                setRes(new Reel(sqrt(tempR->getVal())));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                if((tempRat->getNumVal()/tempRat->getDenomVal()).getVal()>=0)
                                    setRes(new Reel(sqrt((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                             if(tempE->getVal()>=0)
                                setRes(new Reel(sqrt(tempE->getVal())));
                            break;

        default:    throw "Operation Sqrt impossible: operande invalide(disponible pour reels, rationnels, entiers)";
                    break;
    };

    return getRes();
}

string expression::Sqrt::toString()const{
    stringstream ss;
    //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" SQRT";
    else
	ss<<"SQRT";
    return ss.str();
}

Expression* expression::Sqr::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

        //on teste le type pour recuperer le pointeur adequat
    switch(expTemp->getType()){
        case TYPE_COMPLEXE: tempC = static_cast <const Complexe*> (expTemp);
                            setRes(new Complexe((*tempC)*(*tempC)));
                            break;

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel((*tempR)*(*tempR)));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Rationnel(tempRat->getNumVal()*tempRat->getNumVal(),
                                                     tempRat->getDenomVal()*tempRat->getDenomVal()));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Entier((*tempE)*(*tempE)));
                            break;

        default:    throw "Operation Sqr impossible: operande invalide(disponible pour complexes, reels, rationnels, entiers)";
                    break;
    };

    return getRes();
}

string expression::Sqr::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" SQR";
    else
	ss<<"SQR";
    return ss.str();
}

Expression* expression::Cube::operation(){
    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(expTemp->getType()){
        case TYPE_COMPLEXE: tempC = static_cast <const Complexe*> (expTemp);
                            setRes(new Complexe((*tempC)*(*tempC)*(*tempC)));
                            break;

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel((*tempR)*(*tempR)*(*tempR)));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Rationnel(tempRat->getNumVal()*tempRat->getNumVal()*tempRat->getNumVal(),
                                                     tempRat->getDenomVal()*tempRat->getDenomVal()*tempRat->getDenomVal()));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Entier((*tempE)*(*tempE)*(*tempE)));
                            break;

        default:    throw "Operation Cube impossible: operande invalide(disponible pour complexes, reels, rationnels, entiers)";
                    break;
    };

    return getRes();
}

string expression::Cube::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" CUBE";
    else
	ss<<"CUBE";
    return ss.str();
}

Expression* expression::Factoriel::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            if(tempR->getVal()>=0)
                                setRes(new Entier(fact(tempR->getVal())));
                            else throw "Le factoriel est possible que pour les nombres positifs";
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                if((tempRat->getNumVal()/tempRat->getDenomVal()).getVal()>=0)
                                    setRes(new Entier(fact((tempRat->getNumVal()/tempRat->getDenomVal()).getVal())));
                                else throw "Le factoriel est possible que pour les nombres positifs";
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                             if(tempE->getVal()>=0)
                                setRes(new Entier(fact(tempE->getVal())));
                             else throw "Le factoriel est possible que pour les nombres positifs";
                            break;

        default:    throw "Le factoriel est disponible que pour les reels, les rationnels et les entiers";
                    break;
    };

    return getRes();
}

string expression::Factoriel::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" !";
    else
	ss<<"!";
    return ss.str();
}

Expression* expression::DegToRad::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;
    Reel temp((PI/180.0));

    switch(expTemp->getType()){

        case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
                            setRes(new Reel((*tempR)*temp));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(temp*(tempRat->getNumVal()/tempRat->getDenomVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(temp*(*tempE)));
                            break;

        default:    throw "Operation DegToRad impossible: operande invalide(disponible pour reels, rationnels, entiers)";
                    break;
    };

    return getRes();
}

string expression::DegToRad::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" DEGTORAD";
    else
	ss<<"DEGTORAD";
    return ss.str();
}

Expression* expression::RadToDeg::operation(){

    const Nombre* expTemp=static_cast<const Nombre*>(getExp());

    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;
    Reel temp((180/PI));

    switch(expTemp->getType()){

	case TYPE_REEL:     tempR = static_cast <const Reel*> (expTemp);
			    setRes(new Reel((*tempR)*temp));
                            break;

        case TYPE_RATIONNEL:    tempRat = static_cast <const Rationnel*> (expTemp);
                                setRes(new Reel(temp*(tempRat->getNumVal()/tempRat->getDenomVal())));
                                break;

        case TYPE_ENTIER:   tempE = static_cast <const Entier*> (expTemp);
                            setRes(new Reel(temp*(*tempE)));
                            break;

    default:    throw "Operation RadToDeg impossible: operande invalide(disponible pour reels, rationnels, entiers)";
                break;
    };

    return getRes();
}

string expression::RadToDeg::toString()const{
    stringstream ss;
        //On verifie que l'operation a des operandes initialises
    if(getExp() != NULL)
	ss<<getExp()->toString()<<" RADTODEG";
    else
	ss<<"RADTODEG";
    return ss.str();
}

Expression* expression::Sum::operation(){

    setRes(Pile::get_curPile()->sum(getExp()));
    return getRes();
}

string expression::Sum::toString()const{
    stringstream ss;
    ss<<"SUM";
    return ss.str();
}


Expression* expression::Mean::operation(){

    setRes(Pile::get_curPile()->mean(getExp()));
    return getRes();
}

string expression::Mean::toString()const{
    stringstream ss;
    ss<<"MEAN";
    return ss.str();
}

Expression* expression::Swap::operation(){
    setRes(NULL);
    Pile::get_curPile()->swap();
    return getRes();
}

string expression::Swap::toString()const{
    stringstream ss;
    ss<<"SWAP";
    return ss.str();
}

Expression* expression::Clear::operation(){
    setRes(NULL);
    Pile::get_curPile()->clear();
    Pile::get_curPile()->razFile();
    return getRes();
}

string expression::Clear::toString()const{
    stringstream ss;
    ss<<"CLEAR";
    return ss.str();
}

Expression* expression::Dup::operation(){
    setRes(NULL);
    Pile::get_curPile()->dup();
    return getRes();
}

string expression::Dup::toString()const{
    stringstream ss;
    ss<<"DUP";
    return ss.str();
}

Expression* expression::Drop::operation(){
    setRes(NULL);
    Pile::get_curPile()->drop();
    return getRes();
}

string expression::Drop::toString()const{
    stringstream ss;
    ss<<"DROP";
    return ss.str();
}

Expression* expression::Eval::operation(){
    setRes(NULL);
    Motor::get_motor()->eval();
    return getRes();
}

string expression::Eval::toString()const{
    stringstream ss;
    ss<<"EVAL";
    return ss.str();
}
