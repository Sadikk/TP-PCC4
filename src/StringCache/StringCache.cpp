/*************************************************************************
                           StringCache  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <StringCache> (fichier StringCache.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "StringCache.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
StringCache::StringCache()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <StringCache>" << endl;
#endif
} //----- Fin de StringCache


StringCache::~StringCache()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <StringCache>" << endl;
#endif
} //----- Fin de ~StringCache


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

