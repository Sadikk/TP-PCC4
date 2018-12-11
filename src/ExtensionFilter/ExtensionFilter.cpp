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
//Renvoie true si l'extension a été trouvé
  #ifdef MAP
      cout << "Appel a la methode Check de <ExtensionFilter>" << endl;
  #endif

  std::string url = request.GetUrl();
  int hasExtension = url.find(extension);
  // La méthode find renvoye -1 dans le cas ou elle ne trouve rien
  if(hasExtension != -1){
    return true;
  }
  return false;

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

ExtensionFilter::ExtensionFilter (string extension )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ExtensionFilter>" << endl;
#endif

this->extension = extension;
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
