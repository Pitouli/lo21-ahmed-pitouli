#ifndef EXPRESSION_H
#define EXPRESSION_H

// DEFINITION DES VALEURS ASSOCIEES A CHAQUE TYPE

#define TYPE_EXPRESSION 0

#define TYPE_CSTE_START 10

    #define TYPE_EXPRESSION_C 13

    #define TYPE_NOMBRE_START 15
	// L'ordre des valeurs pour les types de nombres est très important
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
	#define TYPE_DROP 143
	#define TYPE_SWAP 147
	#define TYPE_EVAL 150
    #define TYPE_OPERATION_NONAIRE_END 198

    #define TYPE_OPERATION_UNAIRE_START 200
	#define TYPE_SUM 210
	#define TYPE_MEAN 212
	#define TYPE_SIN 214
	#define TYPE_COS 216
	#define TYPE_TAN 218
	#define TYPE_SINH 220
	#define TYPE_COSH 222
	#define TYPE_TANH 224
	#define TYPE_LN 226
	#define TYPE_LOG 228
	#define TYPE_INV 230
	#define TYPE_SQRT 232
	#define TYPE_SQR 234
	#define TYPE_CUBE 236
	#define TYPE_FACTORIEL 238
	#define TYPE_DEGTORAD 242
	#define TYPE_RADTODEG 244
    #define TYPE_SIGN 246
    #define TYPE_OPERATION_UNAIRE_END 299

    #define TYPE_OPERATION_BINAIRE_START 300
	#define TYPE_SOMME 305
	#define TYPE_DIFFERENCE 310
	#define TYPE_MULTIPLICATION 315
    #define TYPE_DIVISION 320
    #define TYPE_MOD 325
    #define TYPE_POW 330
    #define TYPE_OPERATION_BINAIRE_END 399

#define TYPE_OPERATION_END 400

#define PI 3.14159265

// FIN DE DEFINITION DES TYPES DE VALEURS

/**
  *\file expression.h
  *\brief Toutes les expressions utilisees par la calculatrice
  *\version 1.42
  */

#include <iostream>
#include <cmath>
#include <sstream>
#include <QStringList>
//#include "pile.h"

class Pile;
class Motor;

using namespace std;

namespace expression{

/**
  *\class Expression
  *\brief Classe abstraite qui regroupe tous les types de nombre et d'operation
  */
    //Classe abstraite qui regroupe tous les types de nombre et d'operation
    class Expression{
        private:
           int type;
        public:
            Expression(int _type=TYPE_EXPRESSION):type(_type){}
            /**
              *\brief operation
              * execute l'operation associee a la classe
              *\return Expression* obtenu à partir du resultat de l'operation. Throw des erreurs en cas de problème.
              */
            virtual Expression* operation()=0;

            /**
              *\brief clone
              * clone l'element sur lequel on applique la fonction
              *\return un pointeur du meme type que l'element sur lequel on applique la fonction. Throw des erreurs en cas de problème.
              */
            virtual Expression* clone()const=0;

            /**
              *\brief toString
              * Construit une chaine de caractere correspondant à l'expression
              *\return string cree.
              */
            virtual string toString()const=0;


            int getType()const {return type;}
    };

    class FabriqueExpression{
        private:
            string exp;
    };


    /**
      *\class ExpressionConcrete
      *\brief Expression non evaluée
      */

    //Expression non evaluée
    class ExpressionConcrete: public Expression{
        private:
            string exp; /**< chaine de caractere qui contient l'expression concrete */
        public:
            ExpressionConcrete(string _exp=""):Expression(TYPE_EXPRESSION_C),exp(_exp){}
            ExpressionConcrete* clone()const{return new ExpressionConcrete(*this);}
            string toString()const{stringstream ss; ss<<"'"<<exp<<"'"; return ss.str();}
            ExpressionConcrete* operation(){return NULL;}
	    string getExp()const{return exp;}
    };

    /**
      *\class Nombre
      *\brief Classe abstraite qui regroupe tous les types de nombre
      */
    class Nombre: public Expression{
        public:
            Nombre(int _type=TYPE_NOMBRE):Expression(_type){}
            virtual Nombre* clone()const=0;
            virtual string toString()const=0;
            Nombre* operation()=0;
    };

    /**
      *\class Reel
      *\brief Classe qui contient les reels
      */
    class Reel: public Nombre{
        private:
            double val; /**< double qui contient la valeur du reel */
        public:
            Reel(double _val=0):Nombre(TYPE_REEL),val(_val){}
            Reel(const Nombre& n);
            Reel operator+(const Reel& n)const;
            Reel operator*(const Reel& n)const;
            Reel operator-(const Reel& n)const;
            Reel operator/(const Reel& n)const;
            Reel* clone()const{return new Reel(*this);}
            string toString()const;
            double getVal()const{return val;}
            Nombre* operation(){return NULL;}
    };

    /**
      *\class Complexe
      *\brief Classe qui contient les complexes
      */
    class Complexe: public Nombre{
        private:
            Nombre* partieR; /**< Partie reel du complexe */
            Nombre* partieI; /**< Partie imaginaire du complexe */
        public:
            Complexe(Nombre* _partieR=0, Nombre* _partieI=0);
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
            string toString()const;
            const Nombre* getPartieR()const{return partieR;}
            const Nombre* getPartieI()const{return partieI;}
            Reel getPartieRVal()const{return Reel(*partieR);}
            Reel getPartieIVal()const{return Reel(*partieI);}
            Nombre* operation(){return NULL;}
    };

    /**
      *\class NombreE
      *\brief Classe abstraite qui regroupe tous les types de nombre qui contiennent des entiers
      */
    class NombreE: public Nombre{
        public:
            NombreE(int _type=20):Nombre(_type){}
            virtual NombreE* clone()const=0;
            virtual string toString()const=0;
            NombreE* operation()=0;
    };

    /**
      *\class Entier
      *\brief Classe qui contient les entiers
      */
    class Entier: public NombreE{
        private:
            int val; /**< int qui contient la valeur de l'entier */
        public:
            Entier(int _val=0):NombreE(TYPE_ENTIER),val(_val){}
            Entier(const Nombre& n);
            Entier operator+(const Entier& n)const;
            Entier operator*(const Entier& n)const;
            Entier operator-(const Entier& n)const;
            Reel operator/(const Entier& n)const;
            Entier* clone()const{return new Entier(*this);}
            string toString()const;
            int getVal()const{return val;}
            void setVal(int _val){val=_val;}
            NombreE* operation(){return NULL;}
    };

    /**
      *\class Rationnel
      *\brief Classe qui contient les rationnels
      */
    class Rationnel: public NombreE{
        private:
            Entier* num; /**< Numerateur du rationnel */
            Entier* denom; /**< Denominateur du rationnel */
        public:
            Rationnel(Entier* _num=0, Entier* _denom=0);
            Rationnel(const Nombre& _num, const Nombre& _denom);
            Rationnel(const Rationnel& c);
            Rationnel(const Nombre& n);
            ~Rationnel();
            int pgcd(int a, int b)const;
            void simplification();
            Rationnel operator+(const Rationnel& n)const;
            Rationnel operator*(const Rationnel& n)const;
            Rationnel operator-(const Rationnel& n)const;
            Rationnel operator/(const Rationnel& n)const;
            Rationnel& operator=(const Rationnel& n);
            Rationnel* clone()const{return new Rationnel(*this);}
            string toString()const;

            //accesseurs et mutateurs
            const Entier* getNum()const{return num;}
            const Entier* getDenom()const{return denom;}
            Entier getNumVal()const{return *num;}
            Entier getDenomVal()const{return *denom;}
            void setNum(int _val){num->setVal(_val);}
            void setDenom(int _val){denom->setVal(_val);}


            NombreE* operation(){return NULL;}
    };

    /**
      *\class Operation
      *\brief Classe abstraite qui regoupe toutes les operations
      */
    //Classe abstraite qui regoupe toutes les operations
    class Operation: public Expression{
        private:
            Expression* res;
        public:
            Operation(int _type=TYPE_OPERATION):Expression(_type){}
            virtual Expression* operation()=0;
            virtual Operation* clone()const=0;
            virtual string toString()const=0;
	    void setRes(Expression* _res){delete res; res=_res;}
            Expression* getRes()const{return res;}
    };

    /**
      *\class OperationNonaire
      *\brief Classe abstraite qui regoupe toutes les operations nonaires
      */
    class OperationNonaire: public Operation{
	public:
        OperationNonaire(int _type=TYPE_OPERATION):Operation(_type){}
	    Expression* operation()=0;
        OperationNonaire* clone()const=0;
        virtual string toString()const=0;
    };

    /**
      *\class OperationUnaire
      *\brief Classe abstraite qui regoupe toutes les operations unaires
      */
    class OperationUnaire: public Operation{
        private:
            const Expression* exp;
        public:
            OperationUnaire(const Expression* _exp, int _type=TYPE_OPERATION):Operation(_type),exp(_exp){}
            Expression* operation()=0;
            virtual OperationUnaire* clone() const=0;
            virtual string toString()const=0;
            void setExp(const Expression* _exp) { exp = _exp; }
            const Expression* getExp()const{return exp;}
    };

    /**
      *\class OperationBinaire
      *\brief Classe abstraite qui regoupe toutes les operations binaires
      */
    class OperationBinaire: public Operation{
        private:
            const Expression* expLeft;
            const Expression* expRight;

        public:
            OperationBinaire(const Expression* _expLeft, const Expression* _expRight, int _type=TYPE_OPERATION):Operation(_type),expLeft(_expLeft),expRight(_expRight){}
            virtual Expression* operation()=0;
            virtual OperationBinaire* clone() const=0;
            virtual string toString()const=0;
            void setExp(const Expression* _expLeft, const Expression* _expRight) { expLeft = _expLeft; expRight = _expRight; }
            void setExpLeft(const Expression* _expLeft) { expLeft = _expLeft; }
            void setExpRight(const Expression* _expRight) { expRight = _expRight; }
            const Expression* getExpLeft()const{return expLeft;}
            const Expression* getExpRight()const{return expRight;}

    };

    class Somme: public OperationBinaire{
    public:
    Somme(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight,TYPE_SOMME){}
	Expression* operation();
    string toString()const;
	Somme* clone() const { return new Somme(*this); }
    };

    class Difference: public OperationBinaire{
    public:
    Difference(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight,TYPE_DIFFERENCE){}
    Expression* operation();
    string toString()const;
	Difference* clone() const { return new Difference(*this); }
    };

    class Multiplication: public OperationBinaire{
    public:
    Multiplication(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight,TYPE_MULTIPLICATION){}
    Expression* operation();
    string toString()const;
    Multiplication* clone() const { return new Multiplication(*this); }
    };

    class Division: public OperationBinaire{
    public:
    Division(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight,TYPE_DIVISION){}
    Expression* operation();
    string toString()const;
	Division* clone() const { return new Division(*this); }
    };

    class Mod: public OperationBinaire{
        public:
            Mod(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight,TYPE_MOD){}
            Expression* operation();
            string toString()const;
            Mod* clone() const { return new Mod(*this); }
    };

    class Pow: public OperationBinaire{
        public:
            Pow(const Expression* _expLeft = NULL, const Expression* _expRight = NULL):OperationBinaire(_expLeft,_expRight,TYPE_POW){}
            Expression* operation();
            string toString()const;
            Pow* clone() const { return new Pow(*this); }
    };

    class Sum: public OperationUnaire{
    public:
        Sum(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_SUM){}
        Expression* operation();
	string toString()const;
        Sum* clone() const { return new Sum(*this); }
    };

    class Mean: public OperationUnaire{
    public:
        Mean(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_SUM){}
        Expression* operation();
	string toString()const;
        Mean* clone() const { return new Mean(*this); }
    };

    class Sin: public OperationUnaire{
    public:
        Sin(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_SIN){}
        Expression* operation();
        string toString()const;
	Sin* clone() const { return new Sin(*this); }
    };

    class Cos: public OperationUnaire{
    public:
    Cos(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_COS){}
        Expression* operation();
        string toString()const;
	Cos* clone() const { return new Cos(*this); }
    };

    class Tan: public OperationUnaire{
    public:
    Tan(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_TAN){}
        Expression* operation();
        string toString()const;
	Tan* clone() const { return new Tan(*this); }
    };

    class Sinh: public OperationUnaire{
    public:
    Sinh(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_SINH){}
        Expression* operation();
        string toString()const;
	Sinh* clone() const { return new Sinh(*this); }
    };

    class Cosh: public OperationUnaire{
    public:
    Cosh(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_COSH){}
        Expression* operation();
        string toString()const;
	Cosh* clone() const { return new Cosh(*this); }
    };

    class Tanh: public OperationUnaire{
    public:
    Tanh(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_TANH){}
        Expression* operation();
        string toString()const;
	Tanh* clone() const { return new Tanh(*this); }
    };

    class Ln: public OperationUnaire{
    public:
    Ln(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_LN){}
        Expression* operation();
        string toString()const;
	Ln* clone() const { return new Ln(*this); }
    };

    class Log: public OperationUnaire{
    public:
    Log(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_LOG){}
        Expression* operation();
        string toString()const;
	Log* clone() const { return new Log(*this); }
    };

    class Sign: public OperationUnaire{
    public:
        Sign(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_SIGN){}
        Expression* operation();
        string toString()const;
        Sign* clone() const { return new Sign(*this); }
    };

    class Inv: public OperationUnaire{
    public:
        Inv(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_INV){}
        Expression* operation();
        string toString()const;
        Inv* clone() const { return new Inv(*this); }
    };

    class Sqrt: public OperationUnaire{
    public:
    Sqrt(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_SQRT){}
        Expression* operation();
        string toString()const;
	Sqrt* clone() const { return new Sqrt(*this); }
    };

    class Sqr: public OperationUnaire{
    public:
    Sqr(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_SQR){}
        Expression* operation();
        string toString()const;
	Sqr* clone() const { return new Sqr(*this); }
    };

    class Cube: public OperationUnaire{
    public:
    Cube(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_CUBE){}
        Expression* operation();
        string toString()const;
	Cube* clone() const { return new Cube(*this); }
    };

    class Factoriel: public OperationUnaire{
    public:
    Factoriel(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_FACTORIEL){}
    int fact(int n){return (n==1 || n==0)?1:fact(n-1)*n;}
        Expression* operation();
        string toString()const;
	Factoriel* clone() const { return new Factoriel(*this); }
    };

    class DegToRad: public OperationUnaire{
    public:
    DegToRad(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_DEGTORAD){}
        Expression* operation();
        string toString()const;
    DegToRad* clone() const { return new DegToRad(*this); }
    };

    class RadToDeg: public OperationUnaire{
    public:
    RadToDeg(const Expression* _exp = NULL):OperationUnaire(_exp,TYPE_RADTODEG){}
        Expression* operation();
        string toString()const;
    RadToDeg* clone() const { return new RadToDeg(*this); }
    };

    class Swap: public OperationNonaire{
    public:
        Swap():OperationNonaire(TYPE_SWAP){}
        Expression* operation();
	string toString()const;
        Swap* clone() const { return new Swap(*this); }
    };

    class Clear: public OperationNonaire{
    public:
        Clear():OperationNonaire(TYPE_CLEAR){}
        Expression* operation();
	string toString()const;
        Clear* clone() const { return new Clear(*this); }
    };

    class Dup: public OperationNonaire{
    public:
        Dup():OperationNonaire(TYPE_DUP){}
        Expression* operation();
	string toString()const;
        Dup* clone() const { return new Dup(*this); }
    };

    class Drop: public OperationNonaire{
    public:
        Drop():OperationNonaire(TYPE_DROP){}
        Expression* operation();
	string toString()const;
        Drop* clone() const { return new Drop(*this); }
    };

    class Eval: public OperationNonaire{
    public:
    Eval():OperationNonaire(TYPE_EVAL){}
	Expression* operation();
	string toString()const;
	Eval* clone() const { return new Eval(*this); }
    };
}



#endif // EXPRESSION_H
