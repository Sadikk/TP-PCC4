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
#include <string>
#include <ctime>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef std::string string;
typedef struct tm tm;
enum HttpMethod {GET, POST, OPTIONS};
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

    string GetIpAddress() const;

    string GetLogUsername() const;

    std::time_t GetTimestamp() const;

    string GetUrl() const;

    int GetStatusCode() const;

    int GetSize() const;

    string GetReferer() const;

    string GetUserAgent() const;

    bool isError() const;

    HttpMethod parseMethod(string unparsedMethod) const;

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

    friend std::ostream& operator<<(std::ostream & str, const Request& request);


//-------------------------------------------- Constructeurs - destructeur
    Request ( const Request & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Request ( );  // Constructeur par défaut de Request
    // Mode d'emploi :
    //
    // Contrat :
    //

    Request(string, string, string, std::time_t, HttpMethod, string, int, int, string ,string);

    virtual ~Request ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void swap(Request& other);

    string ipAddress;  // Adresse IP de l'emetteur de la requête

    string logUsername; // Nom d'utilisateur du visiteur

    string authUsername; // Nom d'utilisateur (Authenticated User)

    std::time_t timestamp; // Date : Changer le type pour Date

    HttpMethod method; // Type de la requête : GET, POST, OPTIONS

    string url; // URL

    int statusCode; // Return Code HTTP : 200, 404, etc

    int size; // Quantité de données transferées

    string referer; // l'adresse auquel le navigateur se trouvait lorsqu'il a effectué cette requête

    string userAgent; // Identification du client navigateur



//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Request>

#endif // REQUEST_H
