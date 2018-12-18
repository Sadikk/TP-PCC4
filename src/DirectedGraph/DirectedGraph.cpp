/*************************************************************************
                           DirectedGraph  -  description
                             -------------------
    début                : 09/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <DirectedGraph> (fichier DirectedGraph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <iterator>
#include <utility>
#include <algorithm>
#include <vector>
//------------------------------------------------------ Include personnel
#include "DirectedGraph.h"
#include "../RefererEdge/RefererEdge.h"
#include "../StringCache/StringCache.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
template <typename S, typename T>
void DirectedGraph<S, T>::Add(T& from, S& to)
// Algorithme :
//
{
    auto p = (adjacencyMap[to]).insert(from);
    std::cout << typeid(p).name();
} //----- Fin de Add

template<>
void DirectedGraph<int, RefererEdge>::Add(RefererEdge& from, int& to)
// Algorithme :
//
{
    std::pair<std::unordered_map<int, std::unordered_set<RefererEdge>>::iterator, bool> p = adjacencyMap.insert(std::pair<int, std::unordered_set<RefererEdge>>(to, std::unordered_set<RefererEdge>()));
    auto referer_exist =  p.first->second.insert(from);
    if (!referer_exist.second)
    {
        //increase referer count
        referer_exist.first->Hit();
    }

    std::pair<std::unordered_map<int, int>::iterator, bool> w = nodesWeight.insert(std::pair<int, int>(to, 1));
    if (!w.second) {
        w.first->second++;
    }
} //----- Fin de Add

template <typename S, typename T>
void DirectedGraph<S, T>::Serialize(std::ostream &os) const
// Algorithme :
//
{
    os << "digraph {" << std::endl;
    for (std::pair<const S, std::unordered_set<T>> const& pair : adjacencyMap)
    {
        os << pair.first;
        for (const T& referer: pair.second) {
            os << pair.second;
        }
    }
    os << "}" << std::endl;
}

template <>
void DirectedGraph<int, RefererEdge>::Serialize(std::ostream &os) const
// Algorithme :
//
{
    os << "digraph {" << std::endl;
    for (std::pair<const int, std::unordered_set<RefererEdge>> const& pair : adjacencyMap)
    {
        os << "\tnode" << pair.first << " [label=\"" << StringCache::GetInstance().Get(pair.first) << "\"]" << std::endl;
        for (const RefererEdge& referer: pair.second) {
            os <<  "\tnode" << referer.GetId() << " -> " << "node" << pair.first << " [label=\"" << referer.GetLabel() << "\"]" << std::endl;
        }
    }
    os << "}" << std::endl;
}

template <typename S, typename T>
int DirectedGraph<S, T>::Size() const
// Algorithme :
//
{
    return adjacencyMap.size();
}


template <typename S, typename T>
std::vector<std::pair<S, int>>* DirectedGraph<S, T>::Top(int n) const
// Algorithme :
//
{
    std::vector<std::pair<S, int>>* elems = new std::vector<std::pair<S,int>>(nodesWeight.begin(), nodesWeight.end());

    //sort by weight
    std::sort(elems->begin(), elems->end(), [] (const std::pair<S, int>& a, const std::pair<S, int>& b) {
        return a.second > b.second;
    });

    elems->resize(n);
    return elems;

}

//------------------------------------------------- Surcharge d'opérateurs
template <typename S, typename T>
DirectedGraph<S, T> &DirectedGraph<S, T>::operator=(DirectedGraph<S, T> other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
template <typename S, typename T>
DirectedGraph<S, T>::DirectedGraph(const DirectedGraph<S, T> &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DirectedGraph>" << endl;
#endif
    adjacencyMap = other.adjacencyMap;
} //----- Fin de DirectedGraph (constructeur de copie)

template <typename S, typename T>
DirectedGraph<S, T>::DirectedGraph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DirectedGraph>" << endl;
#endif
} //----- Fin de DirectedGraph

template <typename S, typename T>
DirectedGraph<S, T>::~DirectedGraph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DirectedGraph>" << endl;
#endif
} //----- Fin de ~DirectedGraph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
template <typename S, typename T>
void swap(DirectedGraph<S, T> & first, DirectedGraph<S, T> & second)
{
    using std::swap;

    swap(first.adjacencyMap, second.adjacencyMap);
}





template class DirectedGraph<int, RefererEdge>;
