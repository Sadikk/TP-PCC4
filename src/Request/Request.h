/*************************************************************************
                           Request  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Request> (fichier Request.h) ----------------
#if ! defined ( REQUEST_H )
#define REQUEST_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Request>
//
//
//------------------------------------------------------------------------

class Request
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
    Request & operator = ( const Request & other );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend std::istream& operator>>(std::istream& str, Request& request);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Request ( const Request & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Request ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Request ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void swap(Request& other);
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Request>

#endif // REQUEST_H

