#include "numbers.h"
#include <cmath>

using namespace maths;

maths::Complex::Complex(double reNum, int reDen, double imNum, int imDen)
{
    set_reNum(reNum);
    set_reDen(reDen);
    set_imNum(imNum);
    set_imDen(imDen);
    simplify();
    if((_reNumDec != 0 && _reDen != 1) || (_imNumDec != 0 && _imDen != 1)) throw("Les fractions ne peuvent etre a numerateur non entier");
}

void maths::Complex::set_reNum(double reNum)
{
    _reNumEnt = round(reNum);
    _reNumDec = reNum - _reNumEnt;
    simplify();
}

void maths::Complex::set_imNum(double imNum)
{
    _imNumEnt = round(imNum);
    _imNumDec = imNum - _imNumEnt;
    simplify();
}

void maths::Complex::set_reDen(int reDen)
{
    if(reDen < 0)
    {
	double reNum = get_reNum();
	set_reNum(-reNum);
	_reDen = -reDen;
    }
    else if(reDen == 0) throw("Le denominateur doit etre different de 0");
    else _reDen = reDen;

    simplify();
}

void maths::Complex::set_imDen(int imDen)
{
    if(imDen < 0)
    {
	double imNum = get_imNum();
	set_imNum(-imNum);
	_imDen = -imDen;
    }
    else if(imDen == 0) throw("Le denominateur doit etre different de 0");
    else _imDen = imDen;

    simplify();
}

void maths::Complex::simplify()
{
    if((_reNumDec != 0 && _reDen != 1) || (_imNumDec != 0 && _imDen != 1))
    {
	throw("Les fractions doivent avoir un numerateur entier");
	return;
    }

    if(_reNumEnt == 0) _reDen = 1;
    if(_imNumEnt == 0) _imDen = 1;

    if(_reNumEnt != 0 && _reDen != 1)
    {
	// calcul du pgcd (qui a aussi pour effet de rendre positif le dénominateur)
	int rePgcd = pgcd(_reNumEnt,_reDen);

	_reNumEnt = _reNumEnt / rePgcd;
	_reDen = _reDen / rePgcd;
    }

    if(_imNumEnt != 0 && _imDen != 1)
    {
	// calcul du pgcd (qui a aussi pour effet de rendre positif le dénominateur)
	int imPgcd = pgcd(_imNumEnt,_imDen);

	_imNumEnt = _imNumEnt / imPgcd;
	_imDen = _imDen / imPgcd;
    }
}

int maths::round(double nb)
{
    return floor(nb+0.5);
}

int maths::pgcd(int a, int b)
{
    while (a && (b %= a) && (a %= b));
    return a+b;
}
