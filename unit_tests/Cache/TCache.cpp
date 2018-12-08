/*************************************************************************
                           TCache  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TCache> (fichier TCache.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cassert>
#include <string>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TCache.h"
#include "../../src/Cache/Cache.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testGet()
{
    cout << "testGet..." << "\r\n";
    Cache<std::string> cache;
    cache.Put("a");
    cache.Put("b");

    assert(cache.Get(0) == "a");
    assert(cache.Get(1) == "b");

    try {
        cache.Get(5);
    }
    catch (const std::out_of_range& e)
    {
        cout << "ok" << "\r\n";
        return;
    }

    assert(0 == 1);
}

static void testPut()
{
    cout << "testPut..." << "\r\n";
    Cache<std::string> cache;
    int identifier = cache.Put("a");
    assert(identifier == 0);

    identifier = cache.Put("b");
    assert(identifier == 1);

    identifier = cache.Put("");
    assert(identifier == 2);

    cout << "ok" << "\r\n";
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
    testPut();
    testGet();
} //----- fin de main


