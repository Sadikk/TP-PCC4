/*************************************************************************
                           Cache  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cache> (fichier Cache.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cache.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
template <typename T>
int Cache<T>::Put ( const T item )
// Algorithme :
//
{
    auto it = reverseCache.find(item);
    if(it != reverseCache.end())
    {
        //element already exists
        return it->second;
    }
    cache[currentKey] = item;
    reverseCache[item] = currentKey;
    return currentKey++;
} //----- Fin de Put

template <typename T>
T Cache<T>::Get ( const int& identifier ) const
// Algorithme :
//
{
    return cache.at(identifier);
} //----- Fin de Get


//------------------------------------------------- Surcharge d'opérateurs
template <typename T>
Cache<T>& Cache<T>::operator=(Cache<T> other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
template <typename T>
Cache<T>::Cache(const Cache<T> &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cache>" << endl;
#endif
    cache = other.cache;
    currentKey = other.currentKey;
} //----- Fin de Cache (constructeur de copie)

template <typename T>
Cache<T>::Cache() : currentKey(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cache>" << endl;
#endif
} //----- Fin de Cache

template <typename T>
Cache<T>::~Cache()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cache>" << endl;
#endif
} //----- Fin de ~Cache


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
template <typename T>
void swap(Cache<T> & first, Cache<T> & second)
{
    using std::swap;

    swap(first.cache, second.cache);
    swap(first.currentKey, second.currentKey);
}


template class Cache<std::string>;