/*************************************************************************
                           ExtensionFilter  -  description
                             -------------------
    début                : 08/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ExtensionFilter> (fichier ExtensionFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ExtensionFilter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool ExtensionFilter::Check(Request & request) const
// Algorithme :
//
{
    //TODO
    return true;
} //----- Fin de Check


//------------------------------------------------- Surcharge d'opérateurs
ExtensionFilter& ExtensionFilter::operator=(ExtensionFilter other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ExtensionFilter::ExtensionFilter(const ExtensionFilter &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ExtensionFilter>" << endl;
#endif
    extension = other.extension;
} //----- Fin de ExtensionFilter (constructeur de copie)


ExtensionFilter::ExtensionFilter(string filteredExtension) ; extension(filteredExtension)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ExtensionFilter>" << endl;
#endif
} //----- Fin de ExtensionFilter


ExtensionFilter::~ExtensionFilter()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ExtensionFilter>" << endl;
#endif
} //----- Fin de ~ExtensionFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void swap(ExtensionFilter& first, ExtensionFilter& second)
{
    using std::swap;

    swap(first.extension, second.extension);
}
