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
// Cette classe est instanciée avec une heure donnée startHour et vérifie si une request
// a eu lieu entre startHour et startHour + 1.
//------------------------------------------------------------------------

class HourFilter : public AbstractFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Check(Request &request) const;


//------------------------------------------------- Surcharge d'opérateurs
    HourFilter & operator = ( const HourFilter & other );
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

//----------------------------------------------------- Attributs protégés

int startHour;
int endHour;

};

//-------------------------------- Autres définitions dépendantes de <HourFilter>

#endif // HOUR_FILTER_H
