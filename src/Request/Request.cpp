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
// type Request::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Request & Request::operator = ( const Request & other )
// Algorithme :
//
{
    //TODO
    return *this;
} //----- Fin de operator =

std::istream& operator>>(std::istream& str, Request& request)
// Algorithme :
//
{
    Request tmp;
    std::string line;
    /*if (std::getline(str, line))
    {
        std::stringstream iss(line);
        if ( std::getline(iss, tmp.ipAddress, ' ')        &&
             std::getline(iss, tmp.logUsername, ' ')         &&
             std::getline(iss, tmp.authUsername, ' ')      &&
             std::getline(iss, tmp.timestamp, '[') &&
             std::getline(iss, tmp.type, ']') &&
             std::getline(iss, tmp.url, '"') &&
             std::getline(iss, tmp.statusCode, ' ') &&
             std::getline(iss, tmp.length, ' ') &&
             std::getline(iss, tmp.referer, '"') &&
             std::getline(iss, tmp.userAgent, '"'))
        {
            data.swap(tmp);
        }
        else
        {
            str.setstate(std::ios::failbit);
        }
    } */
    return str;

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
