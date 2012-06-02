#include "expression.h"

using namespace expression;


expression::Reel::Reel(const Nombre& n):Nombre(TYPE_REEL){
    const Reel* tempR;
    const Entier* tempE;
    const Rationnel* tempRat;

    switch(n.getType()){
        case TYPE_RATIONNEL:    tempRat = dynamic_cast <const Rationnel*> (&n);
                                val=((*(tempRat->getNum()))/(*(tempRat->getDenom())))->getVal();
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

Reel* expression::Reel::operator+(const Reel& n)const{
    return new Reel(val+n.getVal());
}

Reel* expression::Reel::operator*(const Reel& n)const{
    return new Reel(val+n.getVal());
}

Reel* expression::Reel::operator-(const Reel& n)const{
    return new Reel(val-n.getVal());
}

Reel* expression::Reel::operator/(const Reel& n)const{
    if(n.getVal()!=0)
        return new Reel(val/n.getVal());
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
                            partieI=tempC->getPartieI()->clone();
                            partieR=tempC->getPartieR()->clone();
                            break;

        case TYPE_REEL:     tempR = dynamic_cast <const Reel*> (&n);
                            partieI=new Reel(0);
                            partieR=new Reel(tempR->getVal());
                            break;

        case TYPE_RATIONNEL:    tempRat = dynamic_cast <const Rationnel*> (&n);
                                partieI=new Reel(0);
                                partieR=new Reel(*((*(tempRat->getNum()))/(*(tempRat->getDenom()))));
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

Complexe* expression::Complexe::operator+(const Complexe& n)const{
    return new Complexe((*(getPartieR()))+(*(n.getPartieR())),(*(getPartieI()))+(*(n.getPartieI())));
}

Complexe* expression::Complexe::operator*(const Complexe& n)const{
    return new Complexe((*((*(getPartieR()))*(*(n.getPartieR())))-(*((*(getPartieI()))*(*(n.getPartieI()))))),
                        ((*((*(getPartieR()))*(*(n.getPartieI()))))+(*((*(getPartieI()))*(*(n.getPartieR()))))));
}

Complexe* expression::Complexe::operator-(const Complexe& n)const{
    return new Complexe((*(getPartieR()))-(*(n.getPartieR())),(*(getPartieI()))-(*(n.getPartieI())));
}

Complexe* expression::Complexe::operator/(const Complexe& n)const{
    Complexe temp((*((*(n.getPartieR()))/(*((*(n.getPartieR()))*(*(n.getPartieR()))))))-(*((*(n.getPartieI()))*(*(n.getPartieI())))),
                  (*((*(n.getPartieI()))/(*((*(n.getPartieR()))*(*(n.getPartieR()))))))-(*((*(n.getPartieI()))*(*(n.getPartieI())))));
    return new Complexe((*((*(getPartieR()))*(*(temp.getPartieR()))))-(*((*(getPartieI()))*(*(temp.getPartieI())))),
                        (*((*(getPartieR()))*(*(temp.getPartieI()))))+(*((*(getPartieI()))*(*(temp.getPartieR())))));

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

Entier* expression::Entier::operator+(const Entier& n)const{
    return new Entier(val+n.getVal());
}

Entier* expression::Entier::operator*(const Entier& n)const{
    return new Entier(val+n.getVal());
}

Entier* expression::Entier::operator-(const Entier& n)const{
    return new Entier(val-n.getVal());
}

Entier* expression::Entier::operator/(const Entier& n)const{
    if(n.getVal()!=0)
        return new Entier(val/n.getVal());
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

expression::Rationnel::Rationnel(const Rationnel& c):NombreE(TYPE_RATIONNEL){
    num=c.num->clone();
    denom=c.denom->clone();
}

expression::Rationnel::Rationnel(const Nombre& n):NombreE(TYPE_RATIONNEL){
    const Rationnel* tempRat;
    const Entier* tempE;

    switch(n.getType()){
        case TYPE_RATIONNEL:    tempRat = dynamic_cast <const Rationnel*> (&n);
                                num=tempRat->getNum()->clone();
                                denom=tempRat->getDenom()->clone();
                                break;

        case TYPE_ENTIER:   tempE = dynamic_cast <const Entier*> (&n);
                            num=new Entier(tempE->getVal());
                            denom=new Entier(0);
                            break;

        default:    break; //erreur
    };
}

Rationnel* expression::Rationnel::operator+(const Rationnel& c)const{
    return new Rationnel((*((*(getNum()))*(*(c.getDenom()))))+(*((*(c.getNum()))*(*(getDenom())))),
                         (*(getDenom()))*(*(c.getDenom())));
}

Rationnel* expression::Rationnel::operator*(const Rationnel& c)const{
    return new Rationnel((*(getNum()))*(*(c.getNum())),(*(getDenom()))*(*(c.getDenom())));
}

Rationnel* expression::Rationnel::operator-(const Rationnel& c)const{
    return new Rationnel((*((*(getNum()))*(*(c.getDenom())))-(*((*(c.getNum()))*(*(getDenom()))))),
                         (*(getDenom()))*(*(c.getDenom())));
}

Rationnel* expression::Rationnel::operator/(const Rationnel& c)const{
    Entier temp(*(c.getNum()));
    if(temp.getVal()!=0)
        new Rationnel((*(getNum()))*(*(c.getDenom())),(*(getDenom()))*(*(c.getNum())));
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
