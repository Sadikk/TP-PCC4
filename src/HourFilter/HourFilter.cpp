/*************************************************************************
                           HourFilter  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
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
bool HourFilter::Check(Request & request) const
// Algorithme :
//
{
    //TODO
    return true;
} //----- Fin de Check


//------------------------------------------------- Surcharge d'opérateurs
HourFilter& HourFilter::operator=(HourFilter other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
HourFilter::HourFilter(const HourFilter &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <HourFilter>" << endl;
#endif
    startHour = other.startHour;
    endHour = other.endHour;
} //----- Fin de HourFilter (constructeur de copie)


HourFilter::HourFilter(int startingHour, int endingHour) : startHour(startingHour), endHour(endingHour)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <HourFilter>" << endl;
#endif
} //----- Fin de HourFilter


HourFilter::~HourFilter()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <HourFilter>" << endl;
#endif
} //----- Fin de ~HourFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void swap(HourFilter& first, HourFilter& second)
{
    using std::swap;

    swap(first.startHour, second.startHour);
    swap(first.endHour, second.endHour);
}
