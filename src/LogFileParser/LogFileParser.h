/*************************************************************************
                           LogFileParser  -  description
                             -------------------
    dÃ©but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogFileParser> (fichier LogFileParser.h) ----------------
#if ! defined ( LogFileParser_H )
#define LogFileParser_H

using std::string;
//--------------------------------------------------- Interfaces utilisÃ©es
#include <vector>
#include "../AbstractFilter/AbstractFilter.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// RÃ´le de la classe <LogFileParser>
//
//
//------------------------------------------------------------------------

class LogFileParser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- MÃ©thodes publiques
    // type MÃ©thode ( liste des paramÃ¨tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opÃ©rateurs
    LogFileParser & operator = ( const LogFileParser & unLogFileParser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogFileParser ( const LogFileParser & unLogFileParser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogFileParser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogFileParser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- MÃ©thodes protÃ©gÃ©es
string filepath;
std::vector<AbstractFilter> options;

//----------------------------------------------------- Attributs protÃ©gÃ©s

};

//-------------------------------- Autres dÃ©finitions dÃ©pendantes de <LogFileParser>

#endif // LogFileParser_H
