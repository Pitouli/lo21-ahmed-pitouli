#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
using namespace std;

namespace expression{

    class Expression{
        private:
           int type;
        public:
            Expression(int _type=0):type(_type){}
            virtual Expression* operation()=0;
            virtual Expression* clone()const=0;
            int getType()const {return type;}
    };

    class FabriqueExpression{
        private:
            string exp;
    };

    class ExpressionConcrete: public Expression{
        private:
            string exp;
        public:
            ExpressionConcrete(string _exp=""):Expression(1),exp(_exp){}
            ExpressionConcrete* clone()const{return new ExpressionConcrete(*this);}
            ExpressionConcrete* operation(){return NULL;}
    };

    class Nombre: public Expression{
        public:
            Nombre(int _type=10):Expression(_type){}
            virtual Nombre* clone()const=0;
            Nombre* operation()=0;
    };

    class Reel: public Nombre{
        private:
            double val;
        public:
            Reel(double _val=0):Nombre(11),val(_val){}
            Nombre* operator+(const Nombre& n);
            Reel* operator+(double c);
            Nombre* operator*(const Nombre& n);
            Reel* operator*(double c);
            Nombre* operator-(const Nombre& n);
            Reel* operator-(double c);
            Nombre* operator/(const Nombre& n);
            Reel* operator/(double c);
            Reel* clone()const{return new Reel(*this);}
            double getVal()const{return val;}
            Nombre* operation(){return NULL;}
    };

    class Complexe: public Nombre{
        private:
            Nombre* partieR;
            Nombre* partieI;
        public:
            Complexe(Nombre* _partieI=0, Nombre* _partieR=0);
            Complexe(double _partieI, double _partieR);
            Complexe(const Complexe& c);
            Complexe* operator+(const Nombre& n);
            Complexe* operator+(double c);
            Complexe* operator*(const Nombre& n);
            Complexe* operator*(double c);
            Complexe* operator-(const Nombre& n);
            Complexe* operator-(double c);
            Complexe* operator/(const Nombre& n);
            Complexe* operator/(double c);
            Complexe* operator=(const Complexe& c);
            Complexe* clone()const{return new Complexe(*this);}
            double getPartieR()const{const Reel* temp = dynamic_cast <const Reel*>(partieR); return temp->getVal();}//MOD
            double getPartieI()const{const Reel* temp = dynamic_cast <const Reel*>(partieI); return temp->getVal();}//MOD
            //const Nombre* getPartieR()const{return partieR;}
            //const Nombre* getPartieI()const{return partieI;}
            Nombre* operation(){return NULL;}
    };

    class NombreE: public Nombre{
        public:
            NombreE(int _type=20):Nombre(_type){}
            virtual NombreE* clone()const=0;
            NombreE* operation()=0;
    };

    class Entier: public NombreE{
        private:
            int val;
        public:
            Entier(int _val=0):NombreE(21),val(_val){}
            Nombre* operator+(const Nombre& n);
            Reel* operator+(double c);
            Entier* operator+(int c);
            Nombre* operator*(const Nombre& n);
            Reel* operator*(double c);
            Entier* operator*(int c);
            Nombre* operator-(const Nombre& n);
            Reel* operator-(double c);
            Entier* operator-(int c);
            Nombre* operator/(const Nombre& n);
            Reel* operator/(double c);
            Entier* operator/(int c);
            Entier* clone()const{return new Entier(*this);}
            double getVal()const{return val;}
            NombreE* operation(){return NULL;}
    };

    class Rationnel: public NombreE{
        private:
            NombreE* num;
            NombreE* denom;
        public:
            Rationnel(NombreE* _num=0, NombreE* _denom=0):NombreE(22){
                if(_num==0)
                    num=new Entier(0);
                else
                   num=_num;
                if(_denom==0)
                    denom=new Entier(1);
                else
                   denom=_denom;
            }
            Rationnel(int _num, int _denom):NombreE(17),num(new Entier(_num)),denom(new Entier(_denom)){}
            Rationnel(const Rationnel& c);
            Rationnel* operator=(const Rationnel& c);
            Nombre* operator+(const Nombre& n);
            Reel* operator+(double c);
            Rationnel* operator+(int c);
            Nombre* operator*(const Nombre& n);
            Reel* operator*(double c);
            Rationnel* operator*(int c);
            Nombre* operator-(const Nombre& n);
            Reel* operator-(double c);
            Rationnel* operator-(int c);
            Nombre* operator/(const Nombre& n);
            Reel* operator/(double c);
            Rationnel* operator/(int c);
            Rationnel* clone()const{return new Rationnel(*this);}
            int getNum()const{const Entier* temp = dynamic_cast <const Entier*>(num); return temp->getVal();}
            int getDenom()const{const Entier* temp = dynamic_cast <const Entier*>(denom); return temp->getVal();}
            NombreE* operation(){return NULL;}
    };

    class Operation: public Expression{
        private:
            Expression* res;
        public:
            Operation(int _type=50):Expression(_type){}
            Expression* operation()=0;
            void setRes(Expression* _res){delete res; res=_res;}
            Expression* getRes()const{return res;}
    };

    class OperationUnaire: public Operation{
        private:
            Expression* exp;
        public:
            OperationUnaire(Expression* _exp):exp(_exp){}
            Expression* operation()=0;
    };

    class OperationBinaire: public Operation{
        private:
            Expression* expLeft;
            Expression* expRight;
        public:
            OperationBinaire(Expression* _expLeft, Expression* _expRight):expLeft(_expLeft),expRight(_expRight){}
            Expression* operation()=0;
            const Expression* getExpLeft()const{return expLeft;}
            const Expression* getExpRight()const{return expRight;}

    };

    class Somme: public OperationBinaire{
    public:
        Somme(Expression* _expLeft, Expression* _expRight):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();

    };

}

#endif // EXPRESSION_H
