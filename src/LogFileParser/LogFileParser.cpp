/*************************************************************************
                           LogFileParser  -  description
                             -------------------
    dÃ©but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- RÃ©alisation de la classe <LogFileParser> (fichier LogFileParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systÃ¨me
#include <iostream>
//------------------------------------------------------ Include personnel
#include "LogFileParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- MÃ©thodes publiques
// type LogFileParser::MÃ©thode ( liste des paramÃ¨tres )
// Algorithme :
//
//{
//} //----- Fin de MÃ©thode


//------------------------------------------------- Surcharge d'opÃ©rateurs
LogFileParser & LogFileParser::operator = ( const LogFileParser & unLogFileParser )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogFileParser::LogFileParser ( const LogFileParser & unLogFileParser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogFileParser>" << endl;
#endif
} //----- Fin de LogFileParser (constructeur de copie)


LogFileParser::LogFileParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogFileParser>" << endl;
#endif
} //----- Fin de LogFileParser


LogFileParser::~LogFileParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogFileParser>" << endl;
#endif
} //----- Fin de ~LogFileParser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- MÃ©thodes protÃ©gÃ©es
