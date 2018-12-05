/*************************************************************************
                           AbstractSerializer  -  description
                             -------------------
    début                : 05/12/18
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AbstractSerializer> (fichier AbstractSerializer.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AbstractSerializer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AbstractSerializer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
AbstractSerializer & AbstractSerializer::operator = ( const AbstractSerializer & other )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AbstractSerializer::AbstractSerializer ( const AbstractSerializer & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AbstractSerializer>" << endl;
#endif
} //----- Fin de AbstractSerializer (constructeur de copie)


AbstractSerializer::AbstractSerializer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AbstractSerializer>" << endl;
#endif
} //----- Fin de AbstractSerializer


AbstractSerializer::~AbstractSerializer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AbstractSerializer>" << endl;
#endif
} //----- Fin de ~AbstractSerializer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

