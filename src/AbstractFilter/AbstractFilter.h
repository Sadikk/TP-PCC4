/*************************************************************************
                           AbstractFilter  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AbstractFilter> (fichier AbstractFilter.h) ----------------
#ifndef AbstractFilter_H
#define AbstractFilter_H

//--------------------------------------------------- Interfaces utilisées
#include "../Request/Request.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AbstractFilter>
//
// Classe abstraite représentant un filtre sur une requête
//------------------------------------------------------------------------

class AbstractFilter {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Check(Request & request) const = 0;
    // Mode d'emploi :
    //      Vérifie si une requête valide le filtre ou non (ie. vérifie les
    // conditions ou non)
    // Returns :
    //      - true si la requête passe le filtre
    //      - false si la requête est filtrée
    // Contrat :
    //      request est un objet Request stable


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
protected:
    AbstractFilter(const AbstractFilter &other);
    // Mode d'emploi (constructeur de copie) :
    //      Constructeur de copie (ne doit jamais être utilisé)
    // Contrat :
    //

    AbstractFilter();
    // Mode d'emploi :
    //      Constructeur de copie (ne doit jamais être utilisé)
    // Contrat :
    //

public:
    virtual ~AbstractFilter();
    // Mode d'emploi :
    //      Destructeur
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <AbstractFilter>

#endif // AbstractFilter_H
