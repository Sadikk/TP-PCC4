/*************************************************************************
                           LogFileParser  -  description
                             -------------------
    début                : 12/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LogFileParser> (fichier LogFileParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "LogFileParser.h"
#include "../StringCache/StringCache.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
DirectedGraph<ResourceNode>* LogFileParser::Parse() const
// Algorithme :
//
{
    std::ifstream file(filename);
    DirectedGraph<ResourceNode>* graph = new DirectedGraph<ResourceNode>;
    if(file.good())
    {
        Request request;

        while(file >> request)
        {
            bool valid = true;
            for (AbstractFilter* filter : options) {
                if (!filter->Check(request)) {
                    valid = false;
                }
            }
            if (valid) {
                int uriIdentifier = StringCache::GetInstance().Put(request.GetUrl());
                int refererIdentifier = StringCache::GetInstance().Put(request.GetReferer());

                ResourceNode targetNode(uriIdentifier);
                ResourceNode sourceNode(refererIdentifier, true);

                graph->Add(sourceNode, targetNode);
            }
        }
    }
    else {
        throw std::invalid_argument( "unable to open received file" );
    }
    return graph;
} //----- Fin de Parse


//------------------------------------------------- Surcharge d'opérateurs
LogFileParser &LogFileParser::operator=(LogFileParser other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogFileParser::LogFileParser(const LogFileParser &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogFileParser>" << endl;
#endif
    filename = other.filename;
    options = other.options;
} //----- Fin de LogFileParser (constructeur de copie)


LogFileParser::LogFileParser(std::string inputFile, std::vector<AbstractFilter*> filters) : filename(inputFile), options(filters)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogFileParser>" << endl;
#endif
} //----- Fin de LogFileParser


LogFileParser::~LogFileParser()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogFileParser>" << endl;
#endif
} //----- Fin de ~LogFileParser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void swap(LogFileParser& first, LogFileParser& second)
{
    using std::swap;

    swap(first.filename, second.filename);
    swap(first.options, second.options);
}
