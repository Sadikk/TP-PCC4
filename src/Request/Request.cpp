/*************************************************************************
                           Request  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Request> (fichier Request.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Request.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Request::getIpAddress() const
{
  #ifdef MAP
      cout << "Appel à la méthode getIpAddress de <Request>" << endl;
  #endif

  return ipAddress;
}

string Request::getLogUsername() const
{
  #ifdef MAP
      cout << "Appel à la méthode getLogUsername de <Request>" << endl;
  #endif

  return logUsername;
}

std::time_t Request::getTimestamp() const
{
  #ifdef MAP
      cout << "Appel à la méthode getTimestamp de <Request>" << endl;
  #endif

  return timestamp;
}

string Request::getUrl() const
{
  #ifdef MAP
      cout << "Appel à la méthode getUrl de <Request>" << endl;
  #endif

  return url;
}

int Request::getStatusCode() const
{
  #ifdef MAP
      cout << "Appel à la méthode getStatusCode de <Request>" << endl;
  #endif

  return statusCode;
}

int Request::getSize() const
{
  #ifdef MAP
      cout << "Appel à la méthode getSize de <Request>" << endl;
  #endif

  return size;
}

string Request::getReferer() const
{
  #ifdef MAP
      cout << "Appel à la méthode getReferer de <Request>" << endl;
  #endif

  return referer;
}

string Request::getUserAgent() const
{
  #ifdef MAP
      cout << "Appel à la méthode getUserAgent de <Request>" << endl;
  #endif

  return userAgent;
}
//------------------------------------------------- Surcharge d'opérateurs
Request & Request::operator = ( const Request & other )
{
  ipAddress = other.ipAddress;
  logUsername = other.logUsername;
  authUsername = other.authUsername;
  timestamp = other.timestamp;
  method = other.method;
  url = other.url;
  statusCode = other.statusCode;
  size = other.size;
  referer = other.referer;
  userAgent = other.userAgent;

    return *this;
} //----- Fin de operator =

std::istream& operator>>(std::istream& str, Request& request)
// Algorithme :
//
{
  /*
    Request tmp;
    std::string line;
    if (std::getline(str, line))
    {
        std::stringstream iss(line);
        if ( std::getline(iss, tmp.ipAddress, ' ')        &&
             std::getline(iss, tmp.logUsername, ' ')         &&
             std::getline(iss, tmp.authUsername, ' ')      &&
             std::getline(iss, tmp.timestamp, '[') &&
             std::getline(iss, tmp.method, ']') &&
             std::getline(iss, tmp.url, '"') &&
             std::getline(iss, tmp.statusCode, ' ') &&
             std::getline(iss, tmp.size, ' ') &&
             std::getline(iss, tmp.referer, '"') &&
             std::getline(iss, tmp.userAgent, '"'))
        {
            //data.swap(tmp);
            request.swap(tmp);
        }
        else
        {
            str.setstate(std::ios::failbit);
        }
    }
    return str;
*/
} //----- Fin de operator >>

//-------------------------------------------- Constructeurs - destructeur
Request::Request ( const Request & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Request>" << endl;
#endif
} //----- Fin de Request (constructeur de copie)


Request::Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Request>" << endl;
#endif
} //----- Fin de Request

Request::Request(string ipAddress, string logUsername, string authUsername,
  std::time_t timestamp, HttpMethod method, string url, int statusCode, int size, string referer, string userAgent)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Request>" << endl;
#endif

this->ipAddress = ipAddress;
this->logUsername = logUsername;
this->authUsername = authUsername;
this->timestamp = timestamp;
this->method = method;
this->url = url;
this->statusCode = statusCode;
this->size = size;
this->referer = referer;
this->userAgent = userAgent;
} //----- Fin de Request


Request::~Request ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Request>" << endl;
#endif
} //----- Fin de ~Request


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Request::swap(Request& other)
{
  
}
