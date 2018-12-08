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
bool ExtensionFilter::Check(Request &request) const{

  #ifdef MAP
      cout << "Appel a la methode Check de <ExtensionFilter>" << endl;
  #endif

  std::string url = request.GetUrl();
  std::string imageExtension = ".jpg";
  std::string javascriptExtension = ".js";
  std::string cssExtension = ".css";
  int hasImageExtension = url.find(imageExtension);
  int hasJavascriptExtension = url.find(javascriptExtension);
  int hasCssExtension = url.find(cssExtension);
  // La méthode find renvoye -1 dans le cas ou elle ne trouve rien
  if(hasImageExtension!= -1 || hasJavascriptExtension!= -1 || hasCssExtension!= -1){
    return true;
  }
  else{
    return false;
  }

}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
ExtensionFilter::ExtensionFilter ( const ExtensionFilter & other )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ExtensionFilter>" << endl;
#endif
} //----- Fin de ExtensionFilter (constructeur de copie)


ExtensionFilter::ExtensionFilter ( )
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
