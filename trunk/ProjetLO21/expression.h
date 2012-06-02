#ifndef EXPRESSION_H
#define EXPRESSION_H

#define TYPE_EXPRESSION 0
#define TYPE_EXPRESSION_C 1
#define TYPE_NOMBRE 2
#define TYPE_COMPLEXE 3
#define TYPE_REEL 4
#define TYPE_RATIONNEL 5
#define TYPE_ENTIER 6
#define TYPE_OPERATION 10

#include <iostream>
using namespace std;

namespace expression{

    class Expression{
        private:
           int type;
        public:
            Expression(int _type=TYPE_EXPRESSION):type(_type){}
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
            ExpressionConcrete(string _exp=""):Expression(TYPE_EXPRESSION_C),exp(_exp){}
            ExpressionConcrete* clone()const{return new ExpressionConcrete(*this);}
            ExpressionConcrete* operation(){return NULL;}
    };

    class Nombre: public Expression{
        public:
            Nombre(int _type=TYPE_NOMBRE):Expression(_type){}
            virtual Nombre* clone()const=0;
            Nombre* operation()=0;
    };

    class Reel: public Nombre{
        private:
            double val;
        public:
            Reel(double _val=0):Nombre(TYPE_REEL),val(_val){}
            Reel(const Nombre& n);
            Reel* operator+(const Reel& n)const;
            Reel* operator*(const Reel& n)const;
            Reel* operator-(const Reel& n)const;
            Reel* operator/(const Reel& n)const;
            Reel* clone()const{return new Reel(*this);}
            double getVal()const{return val;}
            Nombre* operation(){return NULL;}
    };

    class Complexe: public Nombre{
        private:
            Nombre* partieR;
            Nombre* partieI;
        public:
            Complexe(Nombre* _partieR=0, Nombre* _partieI=0);
            Complexe(double _partieR, double _partieI);
            Complexe(const Complexe& c);
            Complexe(const Nombre& n);
            ~Complexe();
            Complexe* operator+(const Complexe& n)const;
            Complexe* operator*(const Complexe& n)const;
            Complexe* operator-(const Complexe& n)const;
            Complexe* operator/(const Complexe& n)const;
            Complexe& operator=(const Complexe& n);
            Complexe* clone()const{return new Complexe(*this);}
            Reel* getPartieR()const{return new Reel(*partieR);}
            Reel* getPartieI()const{return new Reel(*partieI);}
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
            Entier(int _val=0):NombreE(TYPE_ENTIER),val(_val){}
            Entier(const Nombre& n);
            Entier* operator+(const Entier& n)const;
            Entier* operator*(const Entier& n)const;
            Entier* operator-(const Entier& n)const;
            Entier* operator/(const Entier& n)const;
            Entier* clone()const{return new Entier(*this);}
            double getVal()const{return val;}
            NombreE* operation(){return NULL;}
    };

    class Rationnel: public NombreE{
        private:
            NombreE* num;
            NombreE* denom;
        public:
            Rationnel(NombreE* _num=0, NombreE* _denom=0);
            Rationnel(int _num, int _denom);
            Rationnel(const Rationnel& c);
            Rationnel(const Nombre& n);
            ~Rationnel();
            Rationnel* operator+(const Rationnel& n)const;
            Rationnel* operator*(const Rationnel& n)const;
            Rationnel* operator-(const Rationnel& n)const;
            Rationnel* operator/(const Rationnel& n)const;
            Rationnel& operator=(const Rationnel& n);
            Rationnel* clone()const{return new Rationnel(*this);}
            const Entier* getNum()const{return dynamic_cast <const Entier*> (num);}
            const Entier* getDenom()const{return dynamic_cast <const Entier*> (denom);}
            NombreE* operation(){return NULL;}
    };

    class Operation: public Expression{
        private:
            Expression* res;
        public:
            Operation(int _type=TYPE_OPERATION):Expression(_type){}
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
