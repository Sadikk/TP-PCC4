/*************************************************************************
                           HourFilter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <HourFilter> (fichier HourFilter.h) ----------------
#if ! defined ( HOUR_FILTER_H )
#define HOUR_FILTER_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractFilter/AbstractFilter.h"
#include "../Request/Request.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <HourFilter>
//
// Classe représentant un filtre sur l'heure d'une requête
//------------------------------------------------------------------------

class HourFilter : public AbstractFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Check(const Request &request) const;
    // Mode d'emploi :
    //      Vérifie si une requête est dans la bonne plage horaire ou non
    // Returns :
    //      - true si la requête est dans la plage horaire [startHour;endHour[
    //      - false sinon
    // Contrat :
    //      request est un objet Request stable

//------------------------------------------------- Surcharge d'opérateurs
    HourFilter & operator = ( HourFilter other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    HourFilter ( const HourFilter & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    HourFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    HourFilter (int start, int end = -1);

    virtual ~HourFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap(HourFilter & first, HourFilter & second);
//----------------------------------------------------- Attributs protégés
    int startHour;
    int endHour;

};

//-------------------------------- Autres définitions dépendantes de <HourFilter>

#endif // HOUR_FILTER_H
