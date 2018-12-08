/*************************************************************************
                           AbstractFilter  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AbstractFilter> (fichier AbstractFilter.h) ----------------
#if ! defined ( ABSTRACT_FILTER_H )
#define ABSTRACT_FILTER_H

//--------------------------------------------------- Interfaces utilisées
#include "../Request/Request.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AbstractFilter>
//
//
//------------------------------------------------------------------------

class AbstractFilter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Check(Request &request) const;


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    AbstractFilter ( const AbstractFilter & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AbstractFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AbstractFilter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <AbstractFilter>

#endif // ABSTRACT_SERIALIZER_H
