/*************************************************************************
                           StringCache  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <StringCache> (fichier StringCache.h) ----------------
#ifndef StringCache_H
#define StringCache_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "../Cache/Cache.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <StringCache>
//
// Singleton assurant le rôle de cache global des strings utilisées dans
// l'application
//------------------------------------------------------------------------

class StringCache : public Cache<std::string> {
//----------------------------------------------------------------- PUBLIC

public:
    static StringCache& GetInstance()
    {
        static StringCache instance;
        return instance;
    }


//------------------------------------------------- Surcharge d'opérateurs
    StringCache &operator=(const StringCache &other) = delete;
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    StringCache(const StringCache &other) = delete;
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
private:
    StringCache();
    // Mode d'emploi :
    //
    // Contrat :
    //

public:
    virtual ~StringCache();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <StringCache>

#endif // StringCache_H

