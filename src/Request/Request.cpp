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
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Request.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Request::GetIpAddress() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetIpAddress de <Request>" << "\n";
  #endif

  return ipAddress;
}

string Request::GetLogUsername() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetLogUsername de <Request>" << "\n";
  #endif

  return logUsername;
}

std::time_t Request::GetTimestamp() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetTimestamp de <Request>" << "\n";
  #endif

  return timestamp;
}

string Request::GetUrl() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetUrl de <Request>" << "\n";
  #endif

  return url;
}

int Request::GetStatusCode() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetStatusCode de <Request>" << "\n";
  #endif

  return statusCode;
}

int Request::GetSize() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetSize de <Request>" << "\n";
  #endif

  return size;
}

string Request::GetReferer() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetReferer de <Request>" << "\n";
  #endif

  return referer;
}

string Request::GetUserAgent() const
{
  #ifdef MAP
      std::cout << "Appel à la méthode GetUserAgent de <Request>" << "\n";
  #endif

  return userAgent;
}

HttpMethod Request::parseMethod(string unparsedMethod) const {
  if(unparsedMethod == "GET"){
    return GET;
  }
  else if(unparsedMethod == "POST"){
    return POST;
  }
  else if(unparsedMethod == "OPTIONS"){
    return OPTIONS;
  }
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

    Request tmp;
    std::string line;

    string unparsedMethod;
    string tmpStatusCode;
    string tmpSize;
    string tmpTimeStamp;
    string placeholder;
    if (std::getline(str, line))
    {
        std::stringstream iss(line);
        if ( std::getline(iss, tmp.ipAddress, ' ')        &&
             std::getline(iss, tmp.logUsername, ' ')         &&
             std::getline(iss, tmp.authUsername, ' ')      &&
             std::getline(iss, tmpTimeStamp, '"') &&
             std::getline(iss, unparsedMethod, ' ') &&
             std::getline(iss, tmp.url, '"') &&
             std::getline(iss, placeholder, ' ') && // espace entre URL et statusCode
             std::getline(iss, tmpStatusCode, ' ') &&
             std::getline(iss, tmpSize, '"') &&
             std::getline(iss, tmp.referer, '"') &&
             std::getline(iss, placeholder, '"') && // " entre referer et userAgent
             std::getline(iss, tmp.userAgent, '"'))
        {
            struct tm tm;
            strptime(tmpTimeStamp.c_str(), "[%d/%b/%Y :%H:%M:%S %Z]", &tm);
            tmp.timestamp = mktime(&tm);
            tmp.statusCode = std::stoi(tmpStatusCode);
            tmp.size = std::stoi(tmpSize);
            if(unparsedMethod == "GET"){
              tmp.method = GET;
            }
            else if(unparsedMethod == "POST"){
              tmp.method =  POST;
            }
            else if(unparsedMethod == "OPTIONS"){
              tmp.method = OPTIONS;
            }
            request.swap(tmp);
        }
        else
        {
            str.setstate(std::ios::failbit);
        }

    }
    return str;
} //----- Fin de operator >>


  std::ostream& operator<<(std::ostream & str, const Request& request){
    std::cout << "Ip Adress: " << request.ipAddress << "\n";
    std::cout << "Log Username: " << request.logUsername << "\n";
    std::cout << "authUsername: " << request.authUsername << "\n";
    std::cout << "timestamp: " << request.timestamp << "\n";
    std::cout << "Method(ENUM Value)" << request.method << "\n";
    std::cout << "URL: "<< request.url << "\n";
    std::cout << "StatusCode: " << request.statusCode << "\n";
    std::cout << "Size: " << request.size << "\n";
    std::cout << "Referer: " << request.referer << "\n";
    std::cout << "UserAgent: " << request.userAgent << "\n";
    return str;
  }
//-------------------------------------------- Constructeurs - destructeur
Request::Request ( const Request & other )
// Algorithme :
//
{
#ifdef MAP
    std::cout << "Appel au constructeur de copie de <Request>" << "\n";
#endif
} //----- Fin de Request (constructeur de copie)


Request::Request ( )
// Algorithme :
//
{
#ifdef MAP
    std::cout << "Appel au constructeur de <Request>" << "\n";
#endif
} //----- Fin de Request

Request::Request(string ipAddress, string logUsername, string authUsername,
  std::time_t timestamp, HttpMethod method, string url, int statusCode, int size, string referer, string userAgent)
// Algorithme :
//
{
#ifdef MAP
    std::cout << "Appel au constructeur de <Request>" << "\n";
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
    std::cout << "Appel au destructeur de <Request>" << "\n";
#endif
} //----- Fin de ~Request


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Request::swap(Request& other)
{
  *this = other;
}
