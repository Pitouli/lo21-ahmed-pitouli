#include "expression.h"

using namespace expression;

Expression* expression::Somme::operation(){
    return NULL;
}

expression::Complexe::Complexe(Nombre* _partieR, Nombre* _partieI):Nombre(12){
    if(_partieR==0)
        partieR=new Reel(0);
    else
       partieR=_partieR->clone();

    if(_partieI==0)
        partieI=new Reel(0);
    else
       partieI=_partieI->clone();
}

expression::Complexe::Complexe(double _partieR, double _partieI):Nombre(12){
    partieR=new Reel(_partieR);
    partieI=new Reel(_partieI);
}

expression::Complexe::Complexe(const Complexe& c):Nombre(12){
       partieR=c.partieR->clone();
       partieI=c.partieI->clone();
}

Complexe* expression::Complexe::operator+(const Nombre& n){
    Complexe* res;
    //const Nombre* temp;
    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;
    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Complexe(getPartieI(),getPartieR()+tempR->getVal());
                    break;
        case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    res=new Complexe(getPartieI()+tempC->getPartieI(),getPartieI()+tempC->getPartieI());
                    break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Complexe(getPartieI(),getPartieR()+tempE->getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Complexe(new Entier(getPartieI()),
                                     new Rationnel(tempRat->getNum()+(getPartieR()*tempRat->getDenom()),
                                                   tempRat->getDenom()));
                    break;
        default:    break;
    };
    return res;
}

Complexe* expression::Complexe::operator+(double c){
    return new Complexe(getPartieI(),getPartieR()+c);
}

Complexe* expression::Complexe::operator-(const Nombre& n){
    Complexe* res;
    //const Nombre* temp;
    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;
    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Complexe(getPartieI(),getPartieR()-tempR->getVal());
                    break;
        case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    res=new Complexe(getPartieI()-tempC->getPartieI(),getPartieI()-tempC->getPartieI());
                    break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Complexe(getPartieI(),getPartieR()-tempE->getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Complexe(new Entier(getPartieI()),
                                     new Rationnel(tempRat->getNum()-(getPartieR()*tempRat->getDenom()),
                                                   tempRat->getDenom()));
                    break;
        default:    break;
    };
    return res;
}

Complexe* expression::Complexe::operator-(double c){
    return new Complexe(getPartieI(),getPartieR()-c);
}

Complexe* expression::Complexe::operator=(const Complexe& c){
    if(this == &c)
        return this;
    delete partieR;
    delete partieI;
    partieR=c.partieR->clone();
    partieI=c.partieI->clone();
    return this;
}

/*
    switch(getExpLeft()->getType()){
        case 11:    //Left reel
        case 21:    //Left entier
                    switch(getExpRight()->getType()){
                        case 11:    //Right reel
                        case 21:    //Right entier

                                    break;
                        case 12:    //Right complexe
                                    break;
                        case 22:    //Right rationnel
                                    break;
                    }
                    break;

        case 12:    //Left complexe
                    switch(getExpRight()->getType()){
                        case 11:    //Right reel
                        case 21:    //Right entier
                                    break;
                        case 12:    //Right complexe
                                    break;
                        case 22:    //Right rationnel
                                    break;
                    }
                    break;

        case 22:    //Left rationnel
                    switch(getExpRight()->getType()){
                        case 11:    //Right reel
                        case 21:    //Right entier
                                    break;
                        case 12:    //Right complexe
                                    break;
                        case 22:    //Right rationnel
                                    break;
                    }
                    break;
    }
    return getRes();
*/
