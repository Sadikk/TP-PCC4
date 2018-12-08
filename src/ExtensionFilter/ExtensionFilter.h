/*************************************************************************
                           ExtensionFilter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ExtensionFilter> (fichier ExtensionFilter.h) ----------------
#if ! defined ( EXTENSION_FILTER_H )
#define EXTENSION_FILTER_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractFilter/AbstractFilter.h"
#include "../Request/Request.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ExtensionFilter>
//
//
//------------------------------------------------------------------------

class ExtensionFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Check(Request &request) const;


//------------------------------------------------- Surcharge d'opérateurs
    ExtensionFilter & operator = ( const ExtensionFilter & other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ExtensionFilter ( const ExtensionFilter & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ExtensionFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ExtensionFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <ExtensionFilter>

#endif // ABSTRACT_SERIALIZER_H
