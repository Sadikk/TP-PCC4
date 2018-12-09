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
  return ipAddress;
}

string Request::GetLogUsername() const
{
  return logUsername;
}

std::time_t Request::GetTimestamp() const
{
  return timestamp;
}

string Request::GetUrl() const
{
  return url;
}

int Request::GetStatusCode() const
{
  return statusCode;
}

int Request::GetSize() const
{
  return size;
}

string Request::GetReferer() const
{
  return referer;
}

string Request::GetUserAgent() const
{
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
  else if(unparsedMethod == "HEAD"){
    return HEAD;
  }
  else if(unparsedMethod == "PUT"){
    return PUT;
  }
  else if(unparsedMethod == "DELETE"){
    return DELETE;
  }
  else if(unparsedMethod == "CONNECT"){
    return CONNECT;
  }
  else if(unparsedMethod == "TRACE"){
    return TRACE;
  }
  else if(unparsedMethod == "PATCH"){
    return PATCH;
  }
}

string Request::unparseMethod(HttpMethod parsedMethod) const {
  switch(parsedMethod){
    case 0 :
    return "GET";
    break;
    case 1 :
    return "POST";
    break;
    case 2 :
    return "OPTIONS";
    break;
    case 3 :
    return "HEAD";
    break;
    case 4 :
    return "PUT";
    break;
    case 5 :
    return "DELETE";
    break;
    case 6 :
    return "CONNECT";
    break;
    case 7 :
    return "TRACE";
    break;
    case 8 :
    return "PATCH";
    break;
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
            tmp.method = request.parseMethod(unparsedMethod);
            request.swap(request, tmp);
        }
        else
        {
            str.setstate(std::ios::failbit);
        }

    }
    return str;
} //----- Fin de operator >>


  std::ostream& operator<<(std::ostream & str, const Request& request){
    struct tm* timeinfo = localtime(&request.timestamp);
    char stringedtime[30];
    strftime(stringedtime,30,"%d/%b/%Y :%H:%M:%S +",timeinfo);
    std::cout <<request.ipAddress<<" ";
    std::cout <<request.logUsername<<" ";
    std::cout <<request.authUsername<<" ";
    //std::cout << "[" << request.timestamp << "] ";
    std::cout << "[" << stringedtime << "] ";
    std::cout << '"' << request.unparseMethod(request.method) << " ";
    std::cout <<request.url << '"'+' ';
    std::cout <<request.statusCode << " ";
    std::cout <<request.size << " ";
    std::cout <<'"'<<request.referer << '"';
    std::cout <<'"'<< request.userAgent <<'"'<<"\n";
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
void Request::swap(Request& first, Request& second)
{
std::swap(first.ipAddress, second.ipAddress);
std::swap(first.logUsername, second.logUsername);
std::swap(first.authUsername, second.authUsername);
std::swap(first.timestamp, second.timestamp);
std::swap(first.method, second.method);
std::swap(first.url, second.url);
std::swap(first.statusCode, second.statusCode);
std::swap(first.size, second.size);
std::swap(first.referer, second.referer);
std::swap(first.userAgent, second.userAgent);

}
