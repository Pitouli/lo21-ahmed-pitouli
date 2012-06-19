#include "factory.h"

Factory* Factory::_factory = 0;

Factory* Factory::get_factory()
{
    if(_factory == 0)
    {
	_factory = new Factory();
    }

    return _factory;
}

void Factory::del_factory()
{
    if(_factory != 0)
	delete _factory;
    _factory = 0;
}

Factory::~Factory()
{
    if(_factory != 0) delete _factory;
}

expression::Expression* Factory::analyze(QString const adn) const
{
    QRegExp regExpressionConcrete("'(.+)'");
    QRegExp regNombre("^(?:(?:([0-9]+)(?:\\$([0-9]+))?)|(?:([0-9]+\\.[0-9]+)(?:\\$([0-9]+\\.[0-9]+))?)|(?:([0-9]+/[0-9]+)(?:\\$([0-9]+/[0-9]+))?))$");
    QRegExp regOperateur("[A-Za-z]+|!|%|\\+|\\-|\\*|/");

    if(regExpressionConcrete.exactMatch(adn))
    {
	return new expression::ExpressionConcrete(regExpressionConcrete.cap(1).toStdString());
    }
    else if(regNombre.exactMatch(adn))
    {
	return analyzeNombre(adn);
    }
    else if(regOperateur.exactMatch(adn))
    {
	return analyzeOperation(adn);
    }
    else
    {
	throw("Echec de l'analyse : Catégorie inconnue");
    }
}

expression::Nombre* Factory::analyzeNombre(QString const adn) const
{
    QRegExp regRelationnel("^(?:([0-9]+)/([0-9]+))$");
    QRegExp regEntier("^([0-9]+)$");
    QRegExp regReel("^((?:[0-9]+)\\.(?:[0-9]+))$");
    QRegExp regComplexe("(.+)\\$(.+)");

    if(regRelationnel.exactMatch(adn))
    return new expression::Rationnel(new expression::Entier(regRelationnel.cap(1).toInt()),
                                     new expression::Entier(regRelationnel.cap(2).toInt()));
    else if(regEntier.exactMatch(adn))
	return new expression::Entier(regEntier.cap(1).toInt());
    else if(regReel.exactMatch(adn))
	return new expression::Reel(regReel.cap(1).toDouble());
    else if(regComplexe.exactMatch(adn))
    {
	expression::Nombre* nb1 = this->analyzeNombre(regComplexe.cap(1));
	expression::Nombre* nb2 = this->analyzeNombre(regComplexe.cap(2));
	expression::Complexe* complexe = new expression::Complexe(nb1,nb2);
	delete nb1;
	delete nb2;
	return complexe;
    }
    else throw("Echec de l'analyse : L'expression n'est pas un nombre");
}

expression::Operation* Factory::analyzeOperation(QString const adn) const
{
    if(adn == "+" || adn == "PLUS")
	return new expression::Somme;
    else if(adn == "-" || adn == "MOINS")
	return new expression::Difference;
    else if(adn == "/" || adn == "DIVISER")
	return new expression::Division;
    else if(adn == "*" || adn == "MULTIPLIER")
	return new expression::Multiplication;
    else if(adn == "POW")
    return new expression::Pow;
    else if(adn == "SQRT")
	return new expression::Sqrt;
    else if(adn == "SQR")
	return new expression::Sqr;
    else if(adn == "CUBE")
	return new expression::Cube;
    else if(adn == "INV")
    return new expression::Inv;
    else if(adn == "SIGN")
    return new expression::Sign;
    else if(adn == "LN")
	return new expression::Ln;
    else if(adn == "LOG")
	return new expression::Log;
    else if(adn == "MOD" || adn == "%")
	return new expression::Mod;
    else if(adn == "FACT" || adn == "!")
	return new expression::Factoriel;
    else if(adn == "EVAL" || adn == "=")
	return new expression::Eval;
    else if(adn == "SIN")
	return new expression::Sin;
    else if(adn == "COS")
	return new expression::Cos;
    else if(adn == "TAN")
	return new expression::Tan;
    else if(adn == "SINH")
	return new expression::Sinh;
    else if(adn == "COSH")
	return new expression::Cosh;
    else if(adn == "TANH")
	return new expression::Tanh;
    else if(adn == "SWAP")
	return new expression::Swap;
    else if(adn == "SUM")
	return new expression::Sum;
    else if(adn == "MEAN")
	return new expression::Mean;
    else if(adn == "CLEAR")
	return new expression::Clear;
    else if(adn == "DUP")
	return new expression::Dup;
    else if(adn == "DROP")
	return new expression::Drop;
    else if(adn == "RADTODEG")
	return new expression::RadToDeg;
    else if(adn == "DEGTORAD")
	return new expression::DegToRad;
    else
	throw("Echec de l'analyse : L'expression n'est pas un élément connu");
}
