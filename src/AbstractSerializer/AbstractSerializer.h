/*************************************************************************
                           AbstractSerializer  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AbstractSerializer> (fichier AbstractSerializer.h) ----------------
#if ! defined ( ABSTRACT_SERIALIZER_H )
#define ABSTRACT_SERIALIZER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AbstractSerializer>
//
//
//------------------------------------------------------------------------

class AbstractSerializer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    AbstractSerializer & operator = ( const AbstractSerializer & other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AbstractSerializer ( const AbstractSerializer & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AbstractSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AbstractSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <AbstractSerializer>

#endif // ABSTRACT_SERIALIZER_H

