/*************************************************************************
                           GraphvizSerializer  -  description
                             -------------------
    début                : 2018
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GraphvizSerializer> (fichier GraphvizSerializer.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "GraphvizSerializer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GraphvizSerializer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
GraphvizSerializer & GraphvizSerializer::operator = ( const GraphvizSerializer & other )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GraphvizSerializer::GraphvizSerializer ( const GraphvizSerializer & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GraphvizSerializer>" << endl;
#endif
} //----- Fin de GraphvizSerializer (constructeur de copie)


GraphvizSerializer::GraphvizSerializer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphvizSerializer>" << endl;
#endif
} //----- Fin de GraphvizSerializer


GraphvizSerializer::~GraphvizSerializer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphvizSerializer>" << endl;
#endif
} //----- Fin de ~GraphvizSerializer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

