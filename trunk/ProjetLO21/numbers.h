#ifndef COMPLEX_H
#define COMPLEX_H

namespace maths
{

class Complex
{
public:
    Complex(double reNum = 0, int reDen = 1, double imNum = 0, int imDen = 1);
    // Getters
    int get_reNumEnt() const { return _reNumEnt; }
    double get_reNumDec() const { return _reNumDec; }
    double get_reNum() const { return _reNumEnt+_reNumDec; }
    unsigned int get_reDen() const { return _reDen; }
    int get_imNumEnt() const { return _imNumEnt; }
    double get_imNumDec() const { return _imNumDec; }
    double get_imNum() const { return _imNumEnt+_imNumDec; }
    unsigned int get_imDen() const { return _imDen; }
    // Setters
    void set_reNum(double reNum);
    void set_imNum(double imNum);
    void set_reDen(int reDen);
    void set_imDen(int imDen);
    // Testers
    bool testIsComplexInteger() const { return _reNumDec == 0 && _imNumDec == 0 && _reDen == 1 && _imDen == 1; }
    bool testIsComplexIntegerStrict() const { return testIsComplexInteger() && _imNumEnt != 0; }
    bool testIsComplexFraction() const { return _reNumDec == 0 && _imNumDec == 0; }
    bool testIsComplexFractionStrict() const { return testIsComplexFraction() && _imDen != 0; }
    bool testIsComplexReal() const { return _reDen == 1 && _imDen == 1; }
    bool testIsComplexRealStrict() const { return testIsComplexReal() && _imNumDec != 0; }
    bool testIsInteger() const { return _reNumDec == 0 && _imNumDec == 0 && _reDen == 1 && _imDen == 1 && _imNumEnt == 0; }
    bool testIsIntegerStrict() const { return testIsInteger(); }
    bool testIsFraction() const { return _reNumDec == 0 && _imNumDec == 0 && _imDen == 1 && _imNumEnt == 0; }
    bool testIsFractionStrict() const { return testIsFraction() && _reDen != 1; }
    bool testIsReal() const { return _imNumDec == 0 && _reDen == 1 && _imDen == 1 && _imNumEnt == 0; }
    bool testIsRealStrict() const { return testIsReal() && _reNumDec != 0; }
    // Various
    void simplify();
private:
    int _reNumEnt;
    double _reNumDec;
    unsigned int _reDen;
    int _imNumEnt;
    double _imNumDec;
    unsigned int _imDen;
};

// Renvoie l'arrondi "entier relatif" le plus proche du nombre
inline int round(double nb);

// Renvoie le pgcd de deux nombres
int pgcd(int a, int b);

}

#endif // COMPLEX_H
