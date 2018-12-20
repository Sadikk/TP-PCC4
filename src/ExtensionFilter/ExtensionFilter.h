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
// Classe représentant un filtre sur l'extension du fichier cible d'une requête
//------------------------------------------------------------------------

class ExtensionFilter : public AbstractFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Check(const Request &request) const;
    // Mode d'emploi :
    //      Vérifie si une requête possède l'extension ou non
    // Returns :
    //      - true si la requête ne possède pas de l'extension
    //      - false si la requête possède l'extension
    // Contrat :
    //      request est un objet Request stable

//------------------------------------------------- Surcharge d'opérateurs
    ExtensionFilter & operator = ( ExtensionFilter other );
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

    ExtensionFilter ( string extension );
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
    friend void swap(ExtensionFilter & first, ExtensionFilter & second);
//----------------------------------------------------- Attributs protégés
    std::string extension;

};

//-------------------------------- Autres définitions dépendantes de <ExtensionFilter>

#endif // ABSTRACT_SERIALIZER_H
