/*************************************************************************
                           Cache  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cache> (fichier Cache.h) ----------------
#ifndef Cache_H
#define Cache_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cache>
//
// Représente une mémoire cache associant un identifiant entier à un objet
// quelconque. Permet de sauvegarder de l'espace mémoire si l'objet est
// volumineux, en utilisant uniquement un entier lors des manipulations.
// Un même objet possède un identifiant unique.
//------------------------------------------------------------------------
template <typename T>
class Cache;

template <typename T>
void swap(Cache<T> & first, Cache<T> & second);

template <typename T>
class Cache {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int Put ( const T item );
    // Mode d'emploi :
    // Stocke un objet en cache
    // Params :
    //      - item : objet à ajouter
    // Retourne: l'identifiant entier correspondant
    // Contrat :
    //

    T Get (const int & identifier) const;
    // Mode d'emploi :
    // Récupère un objet en cache à partir de son identifiant
    // Params :
    //      - identifier : identifiant entier de l'objet à récupérer
    // Retourne : l'objet récupéré.
    // Note : Soulève une exception out_of_range si l'identifiant n'est pas connu du cache
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Cache<T> &operator=(Cache<T> other);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cache(const Cache<T> &other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cache();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cache();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap<T>(Cache<T> & first, Cache<T> & second);
//----------------------------------------------------- Attributs protégés
    std::unordered_map<int, T> cache;
    std::unordered_map<T, int> reverseCache;
    int currentKey;
};

//-------------------------------- Autres définitions dépendantes de <Cache>

#endif // Cache_H

