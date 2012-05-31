#include "expression.h"

using namespace expression;

Expression* expression::Somme::operation(){
    return NULL;
}

Reel* expression::Reel::operator+(double c){
    return new Reel(getVal()+c);
}

Nombre* expression::Reel::operator+(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(tempR->getVal()+getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Reel(tempE->getVal()+getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Reel(getVal()+(tempRat->getNum()/tempRat->getDenom()));
                    break;
        default:    break;
    };

    return res;
}

Reel* expression::Reel::operator*(double c){
    return new Reel(getVal()*c);
}

Nombre* expression::Reel::operator*(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(tempR->getVal()*getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI()*getVal(),tempC->getPartieR()*getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Reel(tempE->getVal()*getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Reel(getVal()*(tempRat->getNum()/tempRat->getDenom()));
                    break;
        default:    break;
    };

    return res;
}

Reel* expression::Reel::operator-(double c){
    return new Reel(getVal()-c);
}

Nombre* expression::Reel::operator-(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(getVal()-tempR->getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Reel(getVal()-tempE->getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Reel(getVal()-(tempRat->getNum()/tempRat->getDenom()));
                    break;
        default:    break;
    };

    return res;
}

Reel* expression::Reel::operator/(double c){
    if(c!=0)
        return new Reel(getVal()/c);
    else
        return NULL;
}

Nombre* expression::Reel::operator/(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    if(tempR->getVal()!=0)
                        res=new Reel(getVal()/tempR->getVal());
                    else res = NULL;
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    if(tempR->getVal()!=0)
                        res=new Reel(getVal()/tempE->getVal());
                    else res = NULL;
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Reel(getVal()/(tempRat->getNum()/tempRat->getDenom()));
                    break;
        default:    break;
    };

    return res;
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
    Complexe* res = NULL;
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
    Complexe* res = NULL;
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

Complexe* expression::Complexe::operator*(const Nombre& n){
    Complexe* res = NULL;
    //const Nombre* temp;
    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;
    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Complexe(tempR->getVal()*getPartieI(),tempR->getVal()*getPartieR());
                    break;
        case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    res=new Complexe((getPartieR()*tempC->getPartieI())+(tempC->getPartieR()*getPartieI()),
                                     (getPartieR()*tempC->getPartieR())+(getPartieI()*tempC->getPartieI()));
                    break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Complexe(tempE->getVal()*getPartieI(),getPartieR()*tempE->getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Complexe(new Rationnel(getPartieI()*tempRat->getNum(),tempRat->getDenom()),
                                 new Rationnel(getPartieR()*tempRat->getNum(),tempRat->getDenom()));
                    break;
        default:    break;
    };
    return res;
}

Complexe* expression::Complexe::operator*(double c){
    return new Complexe(c*getPartieI(),c*getPartieR());
}

Complexe* expression::Complexe::operator/(const Nombre& n){
    Complexe* res = NULL;
    //const Nombre* temp;
    const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;
    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Complexe(new Rationnel(getPartieI(),tempR->getVal()),new Rationnel(getPartieR(),tempR->getVal()));
                    break;
        case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    res=new Complexe((getPartieR()*tempC->getPartieI())+(tempC->getPartieR()*getPartieI()),
                                     (getPartieR()*tempC->getPartieR())+(getPartieI()*tempC->getPartieI()));
                    break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Complexe(new Rationnel(getPartieI(),tempE->getVal()),new Rationnel(getPartieR(),tempE->getVal()));
                    break;
        /*case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Complexe(new Rationnel(getPartieI()*tempRat->getNum(),tempRat->getDenom()),
                                 new Rationnel(getPartieR()*tempRat->getNum(),tempRat->getDenom()));
                    break;*/
        default:    break;
    };
    return res;
}



Complexe* expression::Complexe::operator/(double c){
        return new Complexe(new Rationnel(getPartieI(),c),new Rationnel(getPartieR(),c));
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

Reel* expression::Entier::operator+(double c){
    return new Reel(getVal()+c);
}//////////////////////////////////////////////////////////////////////////////

Entier* expression::Entier::operator+(int c){
    return new Entier(getVal()+c);
}

Nombre* expression::Entier::operator+(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(tempR->getVal()+getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Entier(tempE->getVal()+getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel(tempRat->getNum()+(getVal()*tempRat->getDenom()),tempRat->getDenom());
                    break;
        default:    break;
    };

    return res;
}

Entier* expression::Entier::operator*(double c){
    return new Entier(getVal()*c);
}

Nombre* expression::Entier::operator*(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(tempR->getVal()*getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI()*getVal(),tempC->getPartieR()*getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Entier(tempE->getVal()*getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel(tempRat->getNum()*getVal(),tempRat->getDenom());
                    break;
        default:    break;
    };

    return res;
}

Entier* expression::Entier::operator-(double c){
    return new Entier(getVal()-c);
}

Nombre* expression::Entier::operator-(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(getVal()-tempR->getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Entier(getVal()-tempE->getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel((getVal()*tempRat->getDenom())-tempRat->getNum(),tempRat->getDenom());
                    break;
        default:    break;
    };

    return res;
}

Entier* expression::Entier::operator/(double c){
    if(c!=0)
        return new Entier(getVal()/c);
    else
        return NULL;
}

Nombre* expression::Entier::operator/(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    if(tempR->getVal()!=0)
                        res=new Reel(getVal()/tempR->getVal());
                    else res = NULL;
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    if(tempR->getVal()!=0)
                        res=new Reel(getVal()/tempE->getVal());
                    else res = NULL;
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel(getVal()*tempRat->getDenom(),tempRat->getNum());
                    break;
        default:    break;
    };

    return res;
}

Reel* expression::Rationnel::operator+(double c){
    return new Reel((getNum()/getDenom())+c);
}

Rationnel* expression::Rationnel::operator+(int c){
    return new Rationnel(getNum()+(c*getDenom()),getDenom());
}

Nombre* expression::Rationnel::operator+(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(tempR->getVal()+getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Entier(tempE->getVal()+getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel(tempRat->getNum()+(getVal()*tempRat->getDenom()),tempRat->getDenom());
                    break;
        default:    break;
    };

    return res;
}

Reel* expression::Rationnel::operator*(double c){
    return new Reel((getNum()/getDenom())*c);
}

Rationnel* expression::Rationnel::operator*(int c){
    return new Rationnel(getNum()*c,getDenom());
}

Nombre* expression::Rationnel::operator*(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(tempR->getVal()*getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI()*getVal(),tempC->getPartieR()*getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Entier(tempE->getVal()*getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel(tempRat->getNum()*getVal(),tempRat->getDenom());
                    break;
        default:    break;
    };

    return res;
}

Reel* expression::Rationnel::operator-(double c){
    return new Reel((getNum()/getDenom())-c);
}

Rationnel* expression::Rationnel::operator-(int c){
    return new Rationnel(getNum()-(c*getDenom()),getDenom());
}

Nombre* expression::Rationnel::operator-(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    res=new Reel(getVal()-tempR->getVal());
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    res=new Entier(getVal()-tempE->getVal());
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel((getVal()*tempRat->getDenom())-tempRat->getNum(),tempRat->getDenom());
                    break;
        default:    break;
    };

    return res;
}

Reel* expression::Rationnel::operator/(double c){
    if(c!=0)
        return new Reel((getNum()/getDenom())/c);
    else
        return NULL;
}

Rationnel* expression::Rationnel::operator/(int c){
    if(c!=0)
        return new Rationnel(getNum(),c*getDenom());
    else
        return NULL;
}

Nombre* expression::Rationnel::operator/(const Nombre& n){
    Nombre* res = NULL;
    //const Complexe* tempC;
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case 11:    tempR = dynamic_cast <const Reel*> (&n);
                    if(tempR->getVal()!=0)
                        res=new Reel(getVal()/tempR->getVal());
                    else res = NULL;
                    break;
        //case 12:    tempC = dynamic_cast <const Complexe*> (&n);
                    //res=new Complexe(tempC->getPartieI(),tempC->getPartieR()+getVal());
                    //break;
        case 21:    tempE = dynamic_cast <const Entier*> (&n);
                    if(tempR->getVal()!=0)
                        res=new Reel(getVal()/tempE->getVal());
                    else res = NULL;
                    break;
        case 22:    tempRat = dynamic_cast <const Rationnel*> (&n);
                    res=new Rationnel(getVal()*tempRat->getDenom(),tempRat->getNum());
                    break;
        default:    break;
    };

    return res;
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
