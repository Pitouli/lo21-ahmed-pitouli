#include "expression.h"

using namespace expression;


expression::Reel::Reel(const Nombre& n):Nombre(TYPE_REEL){
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case TYPE_RATIONNEL:    tempRat = dynamic_cast <const Rationnel*> (&n);
                                val=(tempRat->getNum()/tempRat->getDenom()).getVal();
                                break;

        case TYPE_ENTIER:   tempE = dynamic_cast <const Entier*> (&n);
                            val=tempE->getVal();
                            break;

        case TYPE_REEL:     tempR = dynamic_cast <const Reel*> (&n);
                            val=tempR->getVal();
                            break;
        default:    break; //erreur
    };
}

Reel expression::Reel::operator+(const Reel& n)const{
    return Reel(val+n.getVal());
}

Reel expression::Reel::operator*(const Reel& n)const{
    return Reel(val+n.getVal());
}

Reel expression::Reel::operator-(const Reel& n)const{
    return Reel(val-n.getVal());
}

Reel expression::Reel::operator/(const Reel& n)const{
    if(n.getVal()!=0)
        return Reel(val/n.getVal());
    else
        return NULL;
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

expression::Complexe::Complexe(double _partieR, double _partieI):Nombre(TYPE_COMPLEXE){
    partieR=new Reel(_partieR);
    partieI=new Reel(_partieI);
}

expression::Complexe::Complexe(const Nombre& _partieR, const Nombre& _partieI){
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

    switch(n.getType()){
        case TYPE_COMPLEXE: tempC = dynamic_cast <const Complexe*> (&n);
                            partieI=tempC->getPartieI().clone();
                            partieR=tempC->getPartieR().clone();
                            break;

        case TYPE_REEL:     tempR = dynamic_cast <const Reel*> (&n);
                            partieI=new Reel(0);
                            partieR=new Reel(tempR->getVal());
                            break;

        case TYPE_RATIONNEL:    tempRat = dynamic_cast <const Rationnel*> (&n);
                                partieI=new Reel(0);
                                partieR=new Reel(tempRat->getNum()/tempRat->getDenom());
                                break;

        case TYPE_ENTIER:   tempE = dynamic_cast <const Entier*> (&n);
                            partieI=new Reel(0);
                            partieR=new Reel(tempE->getVal());
                            break;

        default:    break; //erreur
    };
}

expression::Complexe::~Complexe(){
    delete partieR;
    delete partieI;
}

Complexe expression::Complexe::operator+(const Complexe& n)const{
    return Complexe(getPartieR()+n.getPartieR(),getPartieI()+n.getPartieI());
}

Complexe expression::Complexe::operator*(const Complexe& n)const{
    return Complexe((getPartieR()*n.getPartieR())-(getPartieI()*n.getPartieI()),
                    (getPartieR()*n.getPartieI())+(getPartieI()*n.getPartieR()));
}

Complexe expression::Complexe::operator-(const Complexe& n)const{
    return Complexe(getPartieR()-n.getPartieR(),getPartieI()-n.getPartieI());
}

Complexe expression::Complexe::operator/(const Complexe& n)const{
    Complexe temp(n.getPartieR()/((n.getPartieR()*n.getPartieR())+(n.getPartieI()*n.getPartieI())),
                  n.getPartieR()/((n.getPartieR()*n.getPartieR())+(n.getPartieI()*n.getPartieI())));

    return Complexe((getPartieR()*temp.getPartieR())-(getPartieI()*temp.getPartieI()),
                    (getPartieR()*temp.getPartieI())+(getPartieI()*temp.getPartieR()));

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

expression::Entier::Entier(const Nombre& n){
    const Entier* tempE;

    switch(n.getType()){
        case TYPE_ENTIER:   tempE = dynamic_cast <const Entier*> (&n);
                            val=tempE->getVal();
                            break;

        default:    break; //erreur
    };
}

Entier expression::Entier::operator+(const Entier& n)const{
    return Entier(val+n.getVal());
}

Entier expression::Entier::operator*(const Entier& n)const{
    return Entier(val+n.getVal());
}

Entier expression::Entier::operator-(const Entier& n)const{
    return Entier(val-n.getVal());
}

Entier expression::Entier::operator/(const Entier& n)const{
    if(n.getVal()!=0)
        return Entier(val/n.getVal());
    else
        return NULL;
}

expression::Rationnel::Rationnel(int _num, int _denom):NombreE(TYPE_RATIONNEL){
    num=new Entier(_num);
    denom=new Entier(_denom);
}

expression::Rationnel::Rationnel(NombreE* _num, NombreE* _denom):NombreE(TYPE_RATIONNEL){
    if(_num==0)
        num=new Entier(0);
    else
       num=_num;
    if(_denom==0)
        denom=new Entier(1);
    else
       denom=_denom;
}

expression::Rationnel::Rationnel(const Nombre& _num, const Nombre& _denom){
    const Reel* tempR;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;
    const Entier* tempE1;
    const Entier* tempE2;

    switch(_num.getType()+_denom.getType()){
        case TYPE_RATIONNEL*2:  tempRat1 = dynamic_cast <const Rationnel*> (&_num);
                                tempRat2 = dynamic_cast <const Rationnel*> (&_denom);
                                num=new Entier(tempRat1->getNum()/tempRat2->getDenom());
                                denom=new Entier(tempRat2->getNum()/tempRat2->getDenom());
                                break;

        case TYPE_ENTIER*2: tempE1 = dynamic_cast <const Entier*> (&_num);
                            tempE2 = dynamic_cast <const Entier*> (&_denom);
                            num=new Entier(tempE1->getVal());
                            denom=new Entier(tempE2->getVal());
                            break;

    default:                tempR = new Reel(_num);
                            num=new Entier((int)tempR->getVal());
                            delete tempR;
                            tempR = new Reel(_denom);
                            denom=new Entier((int)tempR->getVal());
                            delete tempR;
                            break;
    };
}

expression::Rationnel::Rationnel(const Rationnel& c):NombreE(TYPE_RATIONNEL){
    num=c.num->clone();
    denom=c.denom->clone();
}

expression::Rationnel::Rationnel(const Nombre& n):NombreE(TYPE_RATIONNEL){
    const Rationnel* tempRat;
    const Entier* tempE;

    switch(n.getType()){
        case TYPE_RATIONNEL:    tempRat = dynamic_cast <const Rationnel*> (&n);
                                num=tempRat->getNum().clone();
                                denom=tempRat->getDenom().clone();
                                break;

        case TYPE_ENTIER:   tempE = dynamic_cast <const Entier*> (&n);
                            num=new Entier(tempE->getVal());
                            denom=new Entier(0);
                            break;

        default:    break; //erreur
    };
}

Rationnel expression::Rationnel::operator+(const Rationnel& c)const{
    return Rationnel((getNum()*c.getDenom())+(c.getNum()*getDenom()),getDenom()*c.getDenom());
}

Rationnel expression::Rationnel::operator*(const Rationnel& c)const{
    return Rationnel(getNum()*c.getNum(),getDenom()*c.getDenom());
}

Rationnel expression::Rationnel::operator-(const Rationnel& c)const{
    return Rationnel((getNum()*c.getDenom())-(c.getNum()*getDenom()),getDenom()*c.getDenom());
}

Rationnel expression::Rationnel::operator/(const Rationnel& c)const{
    if(c.getNum().getVal()!=0)
        return Rationnel(getNum()*c.getDenom(),getDenom()*c.getNum());
    else
        return NULL;
}

Rationnel& expression::Rationnel::operator=(const Rationnel& n){
    if(this!=&n){
        delete num;
        delete denom;
        num=n.num->clone();
        denom=n.denom->clone();
    }

    return *this;
}

expression::Rationnel::~Rationnel(){
    delete num;
    delete denom;
}

Expression* expression::Somme::operation(){
    const Nombre* expLeftTemp=dynamic_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=dynamic_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);

    if(expLeftTemp->getType()<expRightTemp->getType()){
        switch(expLeftTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = dynamic_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)+(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = dynamic_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)+(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = dynamic_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)+(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = dynamic_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Entier((*tempE1)+(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }
    else{
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = new Complexe(*expLeftTemp);
                                tempC2 = dynamic_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC1)+(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = new Reel(*expLeftTemp);
                                tempR2 = dynamic_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR1)+(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = new Rationnel(*expLeftTemp);
                                    tempRat2 = dynamic_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat1)+(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = new Entier(*expLeftTemp);
                                tempE2 = dynamic_cast <const Entier*> (expRightTemp);
                                setRes(new Entier((*tempE1)+(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }

    delete tempC1;
    delete tempC2;
    delete tempR1;
    delete tempR2;
    delete tempE1;
    delete tempE2;
    delete tempRat1;
    delete tempRat2;

    return getRes();
}

Expression* expression::Difference::operation(){
    const Nombre* expLeftTemp=dynamic_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=dynamic_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);

    if(expLeftTemp->getType()<expRightTemp->getType()){
        switch(expLeftTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = dynamic_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)-(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = dynamic_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)-(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = dynamic_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)-(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = dynamic_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Entier((*tempE1)-(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }
    else{
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = new Complexe(*expLeftTemp);
                                tempC2 = dynamic_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC1)-(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = new Reel(*expLeftTemp);
                                tempR2 = dynamic_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR1)-(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = new Rationnel(*expLeftTemp);
                                    tempRat2 = dynamic_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat1)-(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = new Entier(*expLeftTemp);
                                tempE2 = dynamic_cast <const Entier*> (expRightTemp);
                                setRes(new Entier((*tempE1)-(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }

    delete tempC1;
    delete tempC2;
    delete tempR1;
    delete tempR2;
    delete tempE1;
    delete tempE2;
    delete tempRat1;
    delete tempRat2;

    return getRes();
}

Expression* expression::Multiplication::operation(){
    const Nombre* expLeftTemp=dynamic_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=dynamic_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);

    if(expLeftTemp->getType()<expRightTemp->getType()){
        switch(expLeftTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = dynamic_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)*(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = dynamic_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)*(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = dynamic_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)*(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = dynamic_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Entier((*tempE1)*(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }
    else{
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = new Complexe(*expLeftTemp);
                                tempC2 = dynamic_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC1)*(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = new Reel(*expLeftTemp);
                                tempR2 = dynamic_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR1)*(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = new Rationnel(*expLeftTemp);
                                    tempRat2 = dynamic_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat1)*(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = new Entier(*expLeftTemp);
                                tempE2 = dynamic_cast <const Entier*> (expRightTemp);
                                setRes(new Entier((*tempE1)*(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }

    delete tempC1;
    delete tempC2;
    delete tempR1;
    delete tempR2;
    delete tempE1;
    delete tempE2;
    delete tempRat1;
    delete tempRat2;

    return getRes();
}

Expression* expression::Division::operation(){
    const Nombre* expLeftTemp=dynamic_cast<const Nombre*>(getExpLeft());
    const Nombre* expRightTemp=dynamic_cast<const Nombre*>(getExpRight());

    const Complexe* tempC1;
    const Complexe* tempC2;
    const Reel* tempR1;
    const Reel* tempR2;
    const Entier* tempE1;
    const Entier* tempE2;
    const Rationnel* tempRat1;
    const Rationnel* tempRat2;

    setRes(NULL);

    if(expLeftTemp->getType()<expRightTemp->getType()){
        switch(expLeftTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = dynamic_cast <const Complexe*> (expLeftTemp);
                                tempC2 = new Complexe(*expRightTemp);
                                setRes(new Complexe((*tempC1)/(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = dynamic_cast <const Reel*> (expLeftTemp);
                                tempR2 = new Reel(*expRightTemp);
                                setRes(new Reel((*tempR1)/(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = dynamic_cast <const Rationnel*> (expLeftTemp);
                                    tempRat2 = new Rationnel(*expRightTemp);
                                    setRes(new Rationnel((*tempRat1)/(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = dynamic_cast <const Entier*> (expLeftTemp);
                                tempE2 = new Entier(*expRightTemp);
                                setRes(new Entier((*tempE1)/(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }
    else{
        switch(expRightTemp->getType()){
            case TYPE_COMPLEXE: tempC1 = new Complexe(*expLeftTemp);
                                tempC2 = dynamic_cast <const Complexe*> (expRightTemp);
                                setRes(new Complexe((*tempC1)/(*tempC2)));
                                break;

            case TYPE_REEL:     tempR1 = new Reel(*expLeftTemp);
                                tempR2 = dynamic_cast <const Reel*> (expRightTemp);
                                setRes(new Reel((*tempR1)/(*tempR2)));
                                break;

            case TYPE_RATIONNEL:    tempRat1 = new Rationnel(*expLeftTemp);
                                    tempRat2 = dynamic_cast <const Rationnel*> (expRightTemp);
                                    setRes(new Rationnel((*tempRat1)/(*tempRat2)));
                                    break;

            case TYPE_ENTIER:   tempE1 = new Entier(*expLeftTemp);
                                tempE2 = dynamic_cast <const Entier*> (expRightTemp);
                                setRes(new Entier((*tempE1)/(*tempE2)));
                                break;

            default:    break; //erreur
        };
    }

    delete tempC1;
    delete tempC2;
    delete tempR1;
    delete tempR2;
    delete tempE1;
    delete tempE2;
    delete tempRat1;
    delete tempRat2;

    return getRes();
}


