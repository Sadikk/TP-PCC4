/*************************************************************************
                           DirectedGraph  -  description
                             -------------------
    début                : 09/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <DirectedGraph> (fichier DirectedGraph.h) ----------------
#ifndef DirectedGraph_H
#define DirectedGraph_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DirectedGraph>
//
// Représente un graphe orienté de noeuds de type S et d'arcs T.
// S et T doivent implémenter les operateurs <<, <, ==
//------------------------------------------------------------------------
template <typename S, typename T>
class DirectedGraph;

template <typename S, typename T>
void swap(DirectedGraph<S, T> & first, DirectedGraph<S, T> & second);


template <typename S, typename T>
class DirectedGraph {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Add(T& edge, S& to);
    // Mode d'emploi :
    //      Ajoute un arc au graphe ayant pour cible le noeud 'to'.
    //          - edge : arc
    //          - to : objet d'arrivée
    // Contrat :
    //      edge et to sont des objets stables non nuls

    void Serialize(std::ostream& os) const;
    // Mode d'emploi :
    //      Serialize le graphe dans un flux de données
    // Contrat :
    //

    int Size() const;
    // Mode d'emploi :
    //      Retourne le nombre de noeuds ayant au moins un noeud enfant qui le cible
    // Contrat :
    //

    std::vector<std::pair<S, int>>* Top(int n) const;
    // Mode d'emploi :
    //      Retourne les n noeuds les plus lourds par ordre décroissant de poids
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    DirectedGraph<S,T> &operator=(DirectedGraph<S,T> other);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    DirectedGraph(const DirectedGraph<S, T> &other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DirectedGraph();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DirectedGraph();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap<S,T>(DirectedGraph<S, T> & first, DirectedGraph<S, T> & second);
//----------------------------------------------------- Attributs protégés
    std::unordered_map<S, std::unordered_set<T>> adjacencyMap;
    std::unordered_map<S, int> nodesWeight;

};

//-------------------------------- Autres définitions dépendantes de <DirectedGraph>


#endif // DirectedGraph_H

