/*************************************************************************
                           HourFilter  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <HourFilter> (fichier HourFilter.h) ----------------
#ifndef HourFilter_H
#define HourFilter_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractFilter/AbstractFilter.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <HourFilter>
//
// Représente un filtre sur l'heure à laquelle une requête a été effectuée
// selon un intervalle
//------------------------------------------------------------------------

class HourFilter : public AbstractFilter {
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
    HourFilter &operator=(HourFilter other);
    // Mode d'emploi :
    //      Surcharge de l'opérateur d'affectation
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    HourFilter(const HourFilter &other);
    // Mode d'emploi (constructeur de copie) :
    //      Constructeur de copie
    // Contrat :
    //

    HourFilter(int startingHour, int endingHour = startingHour + 1);
    // Mode d'emploi :
    //      Constructeur
    //          - startingHour : heure de début de l'intervalle autorisée
    //          - endingHour : heure de fin de l'intervalle autorisée
    // Si seul le premier argument est spécifié, l'intervalle de validation sera
    // [startingHour;startingHour+1[
    // Contrat :
    //

    virtual ~HourFilter();
    // Mode d'emploi :
    //      Destructeur
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap(HourFilter& first, HourFilter& second);
//----------------------------------------------------- Attributs protégés
    int startHour;
    int endHour;
};

//-------------------------------- Autres définitions dépendantes de <HourFilter>

#endif // HourFilter_H

