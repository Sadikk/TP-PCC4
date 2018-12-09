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
    //TODO doesn't work, when hitCount is updated, key changes so we insert a new element instead of updating
    // old id
    std::cout << "begin add. size = " << adjacencyMap.size() << std::endl;

    std::map<ResourceNode, std::unordered_set<ResourceNode>>::const_iterator it = adjacencyMap.find(to);
    bool flag = false;
    std::pair<std::unordered_set<ResourceNode>::iterator, bool> p;
    if (it != adjacencyMap.end()) {
        std::cout << "key already present" << std::endl;
        // increase hit count
        // in c++ 17 we could use extract instead
        ResourceNode updated(to);
        updated.Hit();
        adjacencyMap[updated] = it->second;
        p = adjacencyMap[updated].insert(from);
        flag = true;
        adjacencyMap.erase(it);
    }

    for (const auto& referer: (adjacencyMap[to])) {
        std::cout << referer.GetId() << std::endl;
    }
    if (!flag) {
        p = adjacencyMap[to].insert(from);
    }
    if (!p.second)
    {
        std::cout << "referer already present, increasing count" << std::endl;
        //value already present, increase referer count
        (*(p.first)).Hit();
    }
    std::cout << "added" << std::endl;
    for (const auto& referer: (adjacencyMap[to])) {
        std::cout << referer.GetId() << std::endl;
    }
    std::cout << "end add. size = " << adjacencyMap.size() << std::endl;
} //----- Fin de Add

template <typename T>
void DirectedGraph<T>::Serialize(std::ostream &os) const
// Algorithme :
//
{
    for (std::pair<T, std::unordered_set<T>> const& pair : adjacencyMap)
    {
        os << pair.first;
        for (const auto& referer: pair.second) {
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
        os << pair.first;
        for (const ResourceNode& referer: pair.second) {
            os << "node" << pair.first.GetId() << " -> " << referer;
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
