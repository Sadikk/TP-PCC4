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
bool HourFilter::Check(Request &request, int targetHour) const{
//Cette méthode vérifier si le Request request a été fait dans l'intervalle
// [targetHour, targetHour+1[
// On suppose que c'est une heure du jour courant
  #ifdef MAP
      cout << "Appel a la methode Check de <HourFilter>" << endl;
  #endif
  long timestamp = request.GetTimestamp();
  struct tm *timeinfo = localtime(&timestamp);
  int request_time = timeinfo->tm_hour;
  int hourMax = targetHour;
  int hourMin = targetHour + 1;

  return request_time > hourMin || request_time < hourMax;

}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
HourFilter::HourFilter ( const HourFilter & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <HourFilter>" << endl;
#endif
} //----- Fin de HourFilter (constructeur de copie)


HourFilter::HourFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <HourFilter>" << endl;
#endif
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
