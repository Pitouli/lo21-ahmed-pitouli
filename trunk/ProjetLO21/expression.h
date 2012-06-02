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
            Reel operator+(const Reel& n)const;
            Reel operator*(const Reel& n)const;
            Reel operator-(const Reel& n)const;
            Reel operator/(const Reel& n)const;
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
            Complexe(const Nombre& _partieR, const Nombre& _partieI);
            Complexe(const Complexe& c);
            Complexe(const Nombre& n);
            ~Complexe();
            Complexe operator+(const Complexe& n)const;
            Complexe operator*(const Complexe& n)const;
            Complexe operator-(const Complexe& n)const;
            Complexe operator/(const Complexe& n)const;
            Complexe& operator=(const Complexe& n);
            Complexe* clone()const{return new Complexe(*this);}
            Reel getPartieR()const{return Reel(*partieR);}
            Reel getPartieI()const{return Reel(*partieI);}
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
            Entier operator+(const Entier& n)const;
            Entier operator*(const Entier& n)const;
            Entier operator-(const Entier& n)const;
            Entier operator/(const Entier& n)const;
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
            Rationnel(const Nombre& _num, const Nombre& _denom);
            Rationnel(const Rationnel& c);
            Rationnel(const Nombre& n);
            ~Rationnel();
            Rationnel operator+(const Rationnel& n)const;
            Rationnel operator*(const Rationnel& n)const;
            Rationnel operator-(const Rationnel& n)const;
            Rationnel operator/(const Rationnel& n)const;
            Rationnel& operator=(const Rationnel& n);
            Rationnel* clone()const{return new Rationnel(*this);}
            Entier getNum()const{return Entier(*num);}
            Entier getDenom()const{return Entier(*denom);}
            NombreE* operation(){return NULL;}
    };

    class Operation: public Expression{
        private:
            Expression* res;
        public:
            Operation(int _type=TYPE_OPERATION):Expression(_type){}
            virtual Expression* operation()=0;
            void setRes(Expression* _res){delete res; res=_res;}
            Expression* getRes()const{return res;}
    };

    class OperationUnaire: public Operation{
        private:
            const Expression* exp;
        public:
            OperationUnaire(const Expression* _exp):exp(_exp){}
            Expression* operation()=0;
            const Expression* getExp()const{return exp;}
    };

    class OperationBinaire: public Operation{
        private:
            const Expression* expLeft;
            const Expression* expRight;
        public:
            OperationBinaire(const Expression* _expLeft, const Expression* _expRight):expLeft(_expLeft),expRight(_expRight){}
            virtual Expression* operation()=0;
            const Expression* getExpLeft()const{return expLeft;}
            const Expression* getExpRight()const{return expRight;}

    };

    class Somme: public OperationBinaire{
    public:
        Somme(const Expression* _expLeft, const Expression* _expRight):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();

    };

    class Difference: public OperationBinaire{
    public:
        Difference(const Expression* _expLeft, const Expression* _expRight):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();

    };

    class Multiplication: public OperationBinaire{
    public:
        Multiplication(const Expression* _expLeft, const Expression* _expRight):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();

    };

    class Division: public OperationBinaire{
    public:
        Division(const Expression* _expLeft, const Expression* _expRight):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();

    };

    class Sin: public OperationUnaire{
    public:
        Sin(const Expression* _exp);
        Expression* operation();
    };

    class Cos: public OperationUnaire{
    public:
        Cos(const Expression* _exp);
        Expression* operation();
    };

    class Tan: public OperationUnaire{
    public:
        Tan(const Expression* _exp);
        Expression* operation();
    };

    class Sinh: public OperationUnaire{
    public:
        Sinh(const Expression* _exp);
        Expression* operation();
    };

    class Cosh: public OperationUnaire{
    public:
        Cosh(const Expression* _exp);
        Expression* operation();
    };

    class Tanh: public OperationUnaire{
    public:
        Tanh(const Expression* _exp);
        Expression* operation();
    };

    class Ln: public OperationUnaire{
    public:
        Ln(const Expression* _exp);
        Expression* operation();
    };

    class Log: public OperationUnaire{
    public:
        Log(const Expression* _exp);
        Expression* operation();
    };

    class Inv: public OperationUnaire{
    public:
        Inv(const Expression* _exp);
        Expression* operation();
    };

    class Sqrt: public OperationUnaire{
    public:
        Sqrt(const Expression* _exp);
        Expression* operation();
    };

    class Sqr: public OperationUnaire{
    public:
        Sqr(const Expression* _exp);
        Expression* operation();
    };

    class Cube: public OperationUnaire{
    public:
        Cube(const Expression* _exp);
        Expression* operation();
    };

    class Factoriel: public OperationUnaire{
    public:
        Factoriel(const Expression* _exp);
        Expression* operation();
    };
    class Eval: public OperationUnaire{
    public:
        Eval(const Expression* _exp);
        Expression* operation();
    };
}



#endif // EXPRESSION_H
