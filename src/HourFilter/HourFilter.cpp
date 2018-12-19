/*************************************************************************
                           HourFilter  -  description
                             -------------------
    début                : 05/12/18
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <HourFilter> (fichier HourFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "HourFilter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool HourFilter::Check(const Request &request) const
// Algorithme :
//
{
  long timestamp = request.GetTimestamp();
  struct tm *timeinfo = localtime(&timestamp);
  int request_hour = timeinfo->tm_hour;
  return request_hour >= startHour && request_hour < endHour;

}
//------------------------------------------------- Surcharge d'opérateurs
HourFilter & HourFilter::operator = (  HourFilter other )
// Algorithme :
//
{
    swap(*this, other);
    return *this;
}
//-------------------------------------------- Constructeurs - destructeur
HourFilter::HourFilter ( const HourFilter & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <HourFilter>" << endl;
#endif
    startHour = other.startHour;
    endHour = other.endHour;
} //----- Fin de HourFilter (constructeur de copie)


HourFilter::HourFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <HourFilter>" << endl;
#endif
} //----- Fin de HourFilter

HourFilter::HourFilter ( int start, int end ) : startHour(start)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <HourFilter>" << endl;
#endif

(end == -1) ? (endHour = startHour+1) : (endHour = end);
} //----- Fin de HourFilter


HourFilter::~HourFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <HourFilter>" << endl;
#endif
} //----- Fin de ~HourFilter


//------------------------------------------------------------------ PRIVE



//----------------------------------------------------- Méthodes protégées
void swap(HourFilter & first, HourFilter & second)
{
    using std::swap;

    swap(first.startHour, second.startHour);
    swap(first.endHour, second.endHour);
}