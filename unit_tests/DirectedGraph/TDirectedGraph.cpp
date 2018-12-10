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
#include "../../src/ResourceNode/ResourceNode.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testAdd()
{
    cout << "testAdd..." << "\r\n";

    DirectedGraph<ResourceNode> graph;
    std::ostream & os = cout;

	ResourceNode node0(0, false);
	ResourceNode node1(1, false);
	ResourceNode node2(2, false);


	ResourceNode referer0(0, true);
	ResourceNode referer1(1, true);
	ResourceNode referer2(2, true);


	graph.Add(referer0, node1);
	graph.Add(referer0, node2);
	graph.Add(referer1, node0);
	graph.Add(referer1, node0);
	graph.Add(referer2, node0);

	graph.Serialize(os);

    cout << "ok" << "\r\n";
}

static void testSize()
{
	cout << "testSize..." << "\r\n";
	//test should be extended. as we're not actively using it now, well... maybe next time ;)
	DirectedGraph<ResourceNode> graph;

	ResourceNode node0(0, false);
	ResourceNode node1(1, false);
	ResourceNode node2(2, false);


	ResourceNode referer0(0, true);
	ResourceNode referer1(1, true);
	ResourceNode referer2(2, true);


	graph.Add(referer0, node1);
	graph.Add(referer0, node2);
	graph.Add(referer1, node0);

	assert(graph.Size() == 3);
	cout << "ok" << "\r\n";
}

static void testGetDegree()
{
	//test should be extended. as we're not actively using it now, well... maybe next time ;)
	cout << "testGetDegree..." << "\r\n";
	DirectedGraph<ResourceNode> graph;

	ResourceNode node0(0, false);
	ResourceNode node1(1, false);
	ResourceNode node2(2, false);


	ResourceNode referer0(0, true);
	ResourceNode referer1(1, true);
	ResourceNode referer2(2, true);


	graph.Add(referer0, node1);
	graph.Add(referer0, node2);
	graph.Add(referer1, node0);

	assert(graph.GetDegree(node0) == 3);
	assert(graph.GetDegree(node1) == 2);
	assert(graph.GetDegree(node2) == 1);
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
    testGetDegree();
} //----- fin de main
