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
//------------------------------------------------------ Include personnel
#include "DirectedGraph.h"
#include "../ResourceNode/ResourceNode.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
template <typename T>
void DirectedGraph<T>::Add(T& from, T& to)
// Algorithme :
//
{
    auto p = (adjacencyMap[to]).insert(from);
    std::cout << typeid(p).name();
} //----- Fin de Add

template<>
void DirectedGraph<ResourceNode>::Add(ResourceNode& from, ResourceNode& to)
// Algorithme :
//
{
    bool flag = false;
    //find by id, because comparator used to order is also used for equality so it cannot be used here
    std::map<ResourceNode, std::unordered_set<ResourceNode>>::iterator it = std::find_if(
            adjacencyMap.begin(),
            adjacencyMap.end(),
            [to] (const std::pair<ResourceNode, std::unordered_set<ResourceNode>>& v) {
                return v.first.GetId() == to.GetId();
            }
    );

    std::pair<std::unordered_set<ResourceNode>::iterator, bool> p;
    if (it != adjacencyMap.end()) {
        // increase hit count
        // in c++ 17 we could use extract instead
        ResourceNode updated(to);
        updated.Hit();

        std::unordered_set<ResourceNode> tmpSet = it->second;
        //we're updating a key, so delete node and inserting it again to keep it balanced
        adjacencyMap.erase(it);
        adjacencyMap[updated] = tmpSet;
        //std::cout << adjacencyMap.insert(std::pair<ResourceNode, std::unordered_set<ResourceNode>>(updated, it->second)).second << std::endl;
        p = adjacencyMap[updated].insert(from);
        flag = true;
    }
    if (!flag) {
        p = adjacencyMap[to].insert(from);
    }

    if (!p.second)
    {
        //value already present, increase referer count
        (*(p.first)).Hit();
    }
} //----- Fin de Add

template <typename T>
void DirectedGraph<T>::Serialize(std::ostream &os) const
// Algorithme :
//
{
    for (std::pair<T, std::unordered_set<T>> const& pair : adjacencyMap)
    {
        os << pair.first;
        for (const T& referer: pair.second) {
            os << pair.second;
        }
    }
}

template <>
void DirectedGraph<ResourceNode>::Serialize(std::ostream &os) const
// Algorithme :
//
{
    for (std::pair<ResourceNode, std::unordered_set<ResourceNode>> const& pair : adjacencyMap)
    {
        os << pair.first << std::endl;
        for (const ResourceNode& referer: pair.second) {
            os <<  "\tnode" << referer.GetId() << " -> " << "node" << pair.first.GetId() << " [label=\"" << referer.GetLabel() << "\"]" << std::endl;
        }
    }
}

template <typename T>
int DirectedGraph<T>::GetDegree(T & node) const
// Algorithme :
//
{
    int out = adjacencyMap.at(node).size();
    int in = 0;
    for (std::pair<T, std::unordered_set<T>> const& pair : adjacencyMap)
    {
        for (const T& n: pair.second) {
            if (n == node)
            {
                in++;
            }
        }
    }
    return in + out;
}

template <typename T>
int DirectedGraph<T>::Size() const
// Algorithme :
//
{
    return adjacencyMap.size();
}

//------------------------------------------------- Surcharge d'opérateurs
template <typename T>
DirectedGraph<T> &DirectedGraph<T>::operator=(DirectedGraph<T> other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
template <typename T>
DirectedGraph<T>::DirectedGraph(const DirectedGraph<T> &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DirectedGraph>" << endl;
#endif
    adjacencyMap = other.adjacencyMap;
} //----- Fin de DirectedGraph (constructeur de copie)

template <typename T>
DirectedGraph<T>::DirectedGraph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DirectedGraph>" << endl;
#endif
} //----- Fin de DirectedGraph

template <typename T>
DirectedGraph<T>::~DirectedGraph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DirectedGraph>" << endl;
#endif
} //----- Fin de ~DirectedGraph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
template <typename T>
void swap(DirectedGraph<T> & first, DirectedGraph<T> & second)
{
    using std::swap;

    swap(first.adjacencyMap, second.adjacencyMap);
}





template class DirectedGraph<ResourceNode>;
