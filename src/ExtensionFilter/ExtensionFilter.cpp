/*************************************************************************
                           ExtensionFilter  -  description
                             -------------------
    début                : 05/12/18
    copyright            : (C) $YEAR$ par $AUTHOR$
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
bool ExtensionFilter::Check(const Request &request) const
// Algorithme :
//
{
  std::string url = request.GetUrl();
  int hasExtension = url.find(extension);
  // La méthode find renvoye -1 dans le cas ou elle ne trouve rien
  return hasExtension == -1;
}
//------------------------------------------------- Surcharge d'opérateurs
ExtensionFilter & ExtensionFilter::operator = (  ExtensionFilter other )
// Algorithme :
//
{
  swap(*this, other);
  return *this;
}


//-------------------------------------------- Constructeurs - destructeur
ExtensionFilter::ExtensionFilter ( const ExtensionFilter & other )
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au constructeur de copie de <ExtensionFilter>" << endl;
#endif
  extension = other.extension;
} //----- Fin de ExtensionFilter (constructeur de copie)

ExtensionFilter::ExtensionFilter (string ext) : extension(ext)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ExtensionFilter>" << endl;
#endif
} //----- Fin de ExtensionFilter



ExtensionFilter::~ExtensionFilter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ExtensionFilter>" << endl;
#endif
} //----- Fin de ~ExtensionFilter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void swap(ExtensionFilter & first, ExtensionFilter & second) {
  using std::swap;

  swap(first.extension, second.extension);
}