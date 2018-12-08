/*************************************************************************
                           AbstractFilter  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AbstractFilter> (fichier AbstractFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AbstractFilter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AbstractFilter::AbstractFilter()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AbstractFilter>" << endl;
#endif
} //----- Fin de AbstractFilter


AbstractFilter::~AbstractFilter()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AbstractFilter>" << endl;
#endif
} //----- Fin de ~AbstractFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

