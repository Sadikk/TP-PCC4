/*************************************************************************
                           TLogFileParser  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TLogFileParser> (fichier TLogFileParser.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cassert>
#include <string>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TLogFileParser.h"
#include "../../src/LogFileParser/LogFileParser.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testParse()
{
    cout << "testParse..." << "\r\n";

    LogFileParser parser("/tmp/anonyme.log");
    DirectedGraph<ResourceNode>* graph = parser.Parse();

    graph->Serialize(cout);

    delete graph;
    cout << "ok" << "\r\n";
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
    testParse();
} //----- fin de main


