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
//Cette classe est instanciée avec une extension donnée e possede une seule méthode
//Check qui vérifie si une Request donnée possède l'extension
// Ex : ExtensionFilter jsFilter(".js") et jsFilter.Check(Request) vérifie
//si Request possède l'extension .js
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

    ExtensionFilter (string extension);

    virtual ~ExtensionFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string extension;

};

//-------------------------------- Autres définitions dépendantes de <ExtensionFilter>

#endif // ABSTRACT_SERIALIZER_H
