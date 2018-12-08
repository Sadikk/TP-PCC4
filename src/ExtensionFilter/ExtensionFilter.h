/*************************************************************************
                           ExtensionFilter  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ExtensionFilter> (fichier ExtensionFilter.h) ----------------
#ifndef ExtensionFilter_H
#define ExtensionFilter_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractFilter/AbstractFilter.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ExtensionFilter>
//
// Représente un filtre sur l'extension de la resource
//------------------------------------------------------------------------

class ExtensionFilter : public AbstractFilter {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Check(Request & request) const;
    // Mode d'emploi :
    // see : AbstractFilter
    //      Vérifie si une requête valide le filtre ou non (ie. vérifie les
    // conditions ou non)
    // Returns :
    //      - true si la requête passe le filtre
    //      - false si la requête est filtrée
    // Contrat :
    //      request est un objet Request stable

//------------------------------------------------- Surcharge d'opérateurs
    ExtensionFilter &operator=(ExtensionFilter other);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ExtensionFilter(const ExtensionFilter &other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ExtensionFilter(string filteredExtension);
    // Mode d'emploi :
    //      Constructeur
    //          - filteredExtension : extension interdite dans la requête. Ex :
    // pour filter les .js, filteredExtension = "js"
    // Contrat :
    //

    virtual ~ExtensionFilter();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap(ExtensionFilter& first, ExtensionFilter& second);
//----------------------------------------------------- Attributs protégés
    string extension;
};

//-------------------------------- Autres définitions dépendantes de <ExtensionFilter>

#endif // ExtensionFilter_H

