#include "analyzer.h"

expression::Expression* analyzer::analyze() const
{
    QRegExp regExpressionConcrete("'(.+)'");
    QRegExp regNombre("^(?:(?:([0-9]+)(?:\\$([0-9]+))?)|(?:([0-9]+\\.[0-9]+)(?:\\$([0-9]+\\.[0-9]+))?)|(?:([0-9]+/[0-9]+)(?:\\$([0-9]+/[0-9]+))?))$");
    QRegExp regOperateur("[A-Za-z]+|!|\\+|\\-|\\*|/");

    if(regExpressionConcrete.exactMatch(_adn))
    {
	return new expression::ExpressionConcrete(regExpressionConcrete.cap(1).toStdString());
    }
    else if(regNombre.exactMatch(_adn))
    {
	return analyzeNombre();
    }
    else if(regOperateur.exactMatch(_adn))
    {
	return analyzeOperation();
    }
    else
    {
	throw("Echec de l'analyse : Catégorie inconnue");
    }
}

expression::Nombre* analyzer::analyzeNombre() const
{
    QRegExp regRelationnel("^(?:([0-9]+)/([0-9]+))$");
    QRegExp regEntier("^([0-9]+)$");
    QRegExp regReel("^((?:[0-9]+)\\.(?:[0-9]+))$");
    QRegExp regComplexe("(.+)\\$(.+)");

    if(regRelationnel.exactMatch(_adn))
	return new expression::Rationnel(regRelationnel.cap(1).toInt(),regRelationnel.cap(2).toInt());
    else if(regEntier.exactMatch(_adn))
	return new expression::Entier(regEntier.cap(1).toInt());
    else if(regReel.exactMatch(_adn))
	return new expression::Reel(regReel.cap(1).toDouble());
    else if(regComplexe.exactMatch(_adn))
    {
	expression::Nombre* nb1 = analyzer(regComplexe.cap(1)).analyzeNombre();
	expression::Nombre* nb2 = analyzer(regComplexe.cap(2)).analyzeNombre();
	expression::Complexe* complexe = new expression::Complexe(nb1,nb2);
	delete nb1;
	delete nb2;
	return complexe;
    }
    else throw("Echec de l'analyse : L'expression n'est pas un nombre");
}

expression::Operation* analyzer::analyzeOperation() const
{
    return NULL;
}
