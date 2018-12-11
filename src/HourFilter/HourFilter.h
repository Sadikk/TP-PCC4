/*************************************************************************
                           HourFilter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <HourFilter> (fichier HourFilter.h) ----------------
#if ! defined ( ABSTRACT_FILTER_H )
#define ABSTRACT_FILTER_H

//--------------------------------------------------- Interfaces utilisées
#include "../AbstractFilter/AbstractFilter.h"
#include "../Request/Request.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Cette classe est instanciée avec une heure donnée startHour et vérifie si une request
// a eu lieu entre startHour et startHour + 1.
//------------------------------------------------------------------------

class HourFilter
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

    HourFilter (int startHour);

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

#endif // ABSTRACT_SERIALIZER_H
