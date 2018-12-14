/*************************************************************************
                           TResourceNode  -  description
                             -------------------
    début                : 09/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation du module <TDirectedGraph> (fichier TDirectedGraph.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cassert>
#include <string>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TResourceNode.h"
#include "../../src/ResourceNode/ResourceNode.h"
#include "../../src/StringCache/StringCache.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testGetLabel()
{
    cout << "testGetLabel..." << "\r\n";
    int id = StringCache::GetInstance().Put("za");

    ResourceNode node(id, true);

    assert(node.GetLabel() == "0");
    node.Hit();

    assert(node.GetLabel() == "1");

    ResourceNode node2(id, false);

    assert(node2.GetLabel() != "za");

    cout << "ok" << "\r\n";
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
    testGetLabel();
} //----- fin de main