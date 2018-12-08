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
// Rôle de la classe <HourFilter>
//
//
//------------------------------------------------------------------------

class HourFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Check(Request &request, int targetHour) const;


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

    virtual ~HourFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <HourFilter>

#endif // ABSTRACT_SERIALIZER_H
