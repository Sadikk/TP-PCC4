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
enum HttpMethod {GET, POST, OPTIONS , HEAD, PUT, DELETE, CONNECT, TRACE, PATCH};
//------------------------------------------------------------------------
// Rôle de la classe <Request>

// Classe représentant une requête HTTP telle que définie par le format de log
// Apache/Nginx
//------------------------------------------------------------------------

class Request
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool IsError() const;
    // Mode d'emploi :
    //      Indique si la requête est en échec ou non
    //      Retourne :
    //          - true si la requête est en échec
    //          - false si la requête est en succès
    // Contrat :
    //

    string GetIpAddress() const;
    // Mode d'emploi :
    //      Getter de l'adresse ip
    // Contrat :
    //

    string GetLogUsername() const;
    // Mode d'emploi :
    //      Getter du nom d'utilisateur log
    // Contrat :
    //

    string GetAuthUsername() const;
    // Mode d'emploi :
    //      Getter du nom d'utilisateur auth
    // Contrat :
    //

    std::time_t GetTimestamp() const;
    // Mode d'emploi :
    //      Getter du timestamp
    // Contrat :
    //

    string GetUrl() const;
    // Mode d'emploi :
    //      Getter de l'URL cible
    // Contrat :
    //

    int GetStatusCode() const;
    // Mode d'emploi :
    //      Getter du code de statut
    // Contrat :
    //

    int GetSize() const;
    // Mode d'emploi :
    //      Getter de la taille de la requête (en bytes)
    // Contrat :
    //

    string GetReferer() const;
    // Mode d'emploi :
    //      Getter du referer
    // Contrat :
    //

    string GetUserAgent() const;
    // Mode d'emploi :
    //      Getter du user agent
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Request & operator = ( Request other );
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

    Request(string ipAddress = "", string logUsername = "", string authUsername = "", std::time_t tstamp = 0,
            HttpMethod httpMethod = GET, string uri = "", int status = 200, int length = 0, string ref = "" ,
            string uAgent = "");
    // Mode d'emploi :
    //      Constructeur
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
    HttpMethod parseMethod(string unparsedMethod) const;

    string unparseMethod(HttpMethod parsedMethod) const;

    friend void swap(Request& first, Request& second);

//----------------------------------------------------- Attributs protégés
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
};

//-------------------------------- Autres définitions dépendantes de <Request>

#endif // REQUEST_H
