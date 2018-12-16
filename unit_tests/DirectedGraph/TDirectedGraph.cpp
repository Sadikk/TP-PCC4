/*************************************************************************
                           TDirectedGraph  -  description
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
#include "TDirectedGraph.h"
#include "../../src/DirectedGraph/DirectedGraph.h"
#include "../../src/RefererEdge/RefererEdge.h"
#include "../../src/StringCache/StringCache.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testAdd()
{
    cout << "testAdd..." << "\r\n";

    DirectedGraph<int, RefererEdge> graph;
    std::ostream & os = cout;

	int t0 = 0;
	int t1 = 1;
	int t2 = 2;

	StringCache::GetInstance().Put("0");
	StringCache::GetInstance().Put("1");
	StringCache::GetInstance().Put("2");

	RefererEdge referer0(0, true);
	RefererEdge referer1(1, true);
	RefererEdge referer2(2, true);


	graph.Add(referer0, t1);
	graph.Add(referer0, t2);
	graph.Add(referer1, t0);
	graph.Add(referer1, t0);
	graph.Add(referer2, t0);

	graph.Serialize(os);

    cout << "ok" << "\r\n";
}

static void testSize()
{
	cout << "testSize..." << "\r\n";
	//test should be extended. as we're not actively using it now, well... maybe next time ;)
	DirectedGraph<int, RefererEdge> graph;

    int t0 = 0;
    int t1 = 1;
    int t2 = 2;


	RefererEdge referer0(0, true);
	RefererEdge referer1(1, true);
	RefererEdge referer2(2, true);


	graph.Add(referer0, t1);
	graph.Add(referer0, t2);
	graph.Add(referer1, t0);

	assert(graph.Size() == 3);
	cout << "ok" << "\r\n";
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
    testAdd();
    testSize();
} //----- fin de main
