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
#include <map>
#include <unordered_set>
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DirectedGraph>
//
// Représente un graphe orienté de noeuds de type T.
// T doit implémenter les operateurs <<, <, ==
//------------------------------------------------------------------------
template <typename T>
class DirectedGraph;

template <typename T>
void swap(DirectedGraph<T> & first, DirectedGraph<T> & second);


template <typename T>
class DirectedGraph {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Add(T& from, T& to);
    // Mode d'emploi :
    //      Ajoute un arc au graphe du noeud 'from' au noeud 'to'.
    //          - from : objet de départ
    //          - to : objet d'arrivée
    // Contrat :
    //      from et to sont des objets stables non nuls

    void Serialize(std::ostream& os) const;
    // Mode d'emploi :
    //      Serialize le graphe dans un flux de données
    // Contrat :
    //

    int GetDegree(T & node) const;
    // Mode d'emploi :
    //      Retourne le degré(valence) d'un noeud du graphe
    // Contrat :
    //

    int Size() const;
    // Mode d'emploi :
    //      Retourne le nombre de noeuds ayant au moins un noeud enfant
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    DirectedGraph<T> &operator=(DirectedGraph<T> other);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    DirectedGraph(const DirectedGraph<T> &other);
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
    friend void swap<T>(DirectedGraph<T> & first, DirectedGraph<T> & second);
//----------------------------------------------------- Attributs protégés
    std::map<T, std::unordered_set<T>> adjacencyMap;
};

//-------------------------------- Autres définitions dépendantes de <DirectedGraph>


#endif // DirectedGraph_H

