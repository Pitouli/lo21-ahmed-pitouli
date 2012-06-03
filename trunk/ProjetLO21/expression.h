#ifndef EXPRESSION_H
#define EXPRESSION_H

// DEFINITION DES VALEURS ASSOCIEES A CHAQUE TYPE

#define TYPE_EXPRESSION 0

#define TYPE_CSTE_START 10

    #define TYPE_EXPRESSION_C 13

    #define TYPE_NOMBRE_START 15
	// L'ordre des valeurs pour les types de nombres est tr�s important
	#define TYPE_NOMBRE 18
	#define TYPE_COMPLEXE 21
	#define TYPE_REEL 25
	#define TYPE_RATIONNEL 28
	#define TYPE_ENTIER 32
    #define TYPE_NOMBRE_END 95

#define TYPE_CSTE_END 99

#define TYPE_OPERATION_START 100

    #define TYPE_OPERATION 110

    #define TYPE_OPERATION_NONAIRE_START 125
	#define TYPE_CLEAR 135
	#define TYPE_DUP 139
    #define TYPE_OPERATION_NONAIRE_END 198

    #define TYPE_OPERATION_UNAIRE_START 200
	#define TYPE_SUM 210
	#define TYPE_MEAN 212
    #define TYPE_OPERATION_UNAIRE_END 299

    #define TYPE_OPERATION_BINAIRE_START 300
	#define TYPE_SOMME 305
    #define TYPE_OPERATION_BINAIRE_END 399

#define TYPE_OPERATION_END 400

// FIN DE DEFINITION DES TYPES DE VALEURS

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

    class OperationNonaire: public Operation{
	public:
	    Expression* operation()=0;
    };

    class OperationUnaire: public Operation{
        private:
            const Expression* exp;
        public:
            OperationUnaire(const Expression* _exp):exp(_exp){}
            Expression* operation()=0;
	    void setExp(const Expression* _exp) { exp = _exp; }
            const Expression* getExp()const{return exp;}
    };

    class OperationBinaire: public Operation{
        private:
            const Expression* expLeft;
            const Expression* expRight;
        public:
            OperationBinaire(const Expression* _expLeft, const Expression* _expRight):expLeft(_expLeft),expRight(_expRight){}
            virtual Expression* operation()=0;
	    void setExp(const Expression* _expLeft, const Expression* _expRight) { expLeft = _expLeft; expRight = _expRight; }
	    void setExpLeft(const Expression* _expLeft) { expLeft = _expLeft; }
	    void setExpRight(const Expression* _expRight) { expRight = _expRight; }
	    const Expression* getExpLeft()const{return expLeft;}
            const Expression* getExpRight()const{return expRight;}

    };

    class Somme: public OperationBinaire{
    public:
	Somme(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight){}
	Expression* operation();
	Somme* clone() const { return new Somme(*this); }
    };

    class Difference: public OperationBinaire{
    public:
	Difference(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();
	Difference* clone() const { return new Difference(*this); }
    };

    class Multiplication: public OperationBinaire{
    public:
	Multiplication(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();
	Multiplication* clone() const { return new Multiplication(*this); }
    };

    class Division: public OperationBinaire{
    public:
	Division(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight){}
        Expression* operation();
	Division* clone() const { return new Division(*this); }
    };

    class Sin: public OperationUnaire{
    public:
	Sin(const Expression* _exp = NULL);
        Expression* operation();
	Sin* clone() const { return new Sin(*this); }
    };

    class Cos: public OperationUnaire{
    public:
	Cos(const Expression* _exp = NULL);
        Expression* operation();
	Cos* clone() const { return new Cos(*this); }
    };

    class Tan: public OperationUnaire{
    public:
	Tan(const Expression* _exp = NULL);
        Expression* operation();
	Tan* clone() const { return new Tan(*this); }
    };

    class Sinh: public OperationUnaire{
    public:
	Sinh(const Expression* _exp = NULL);
        Expression* operation();
	Sinh* clone() const { return new Sinh(*this); }
    };

    class Cosh: public OperationUnaire{
    public:
	Cosh(const Expression* _exp = NULL);
        Expression* operation();
	Cosh* clone() const { return new Cosh(*this); }
    };

    class Tanh: public OperationUnaire{
    public:
	Tanh(const Expression* _exp = NULL);
        Expression* operation();
	Tanh* clone() const { return new Tanh(*this); }
    };

    class Ln: public OperationUnaire{
    public:
	Ln(const Expression* _exp = NULL);
        Expression* operation();
	Ln* clone() const { return new Ln(*this); }
    };

    class Log: public OperationUnaire{
    public:
	Log(const Expression* _exp = NULL);
        Expression* operation();
	Log* clone() const { return new Log(*this); }
    };

    class Inv: public OperationUnaire{
    public:
	Inv(const Expression* _exp = NULL);
        Expression* operation();
	Inv* clone() const { return new Inv(*this); }
    };

    class Sqrt: public OperationUnaire{
    public:
	Sqrt(const Expression* _exp = NULL);
        Expression* operation();
	Sqrt* clone() const { return new Sqrt(*this); }
    };

    class Sqr: public OperationUnaire{
    public:
	Sqr(const Expression* _exp = NULL);
        Expression* operation();
	Sqr* clone() const { return new Sqr(*this); }
    };

    class Cube: public OperationUnaire{
    public:
	Cube(const Expression* _exp = NULL);
        Expression* operation();
	Cube* clone() const { return new Cube(*this); }
    };

    class Factoriel: public OperationUnaire{
    public:
	Factoriel(const Expression* _exp = NULL);
        Expression* operation();
	Factoriel* clone() const { return new Factoriel(*this); }
    };
    class Eval: public OperationUnaire{
    public:
	Eval(const Expression* _exp = NULL);
        Expression* operation();
	Eval* clone() const { return new Eval(*this); }
    };
}



#endif // EXPRESSION_H
