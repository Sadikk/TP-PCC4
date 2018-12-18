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
const std::string INTERNAL_URI = "http://intranet-if.insa-lyon.fr";
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
DirectedGraph<int, RefererEdge>* LogFileParser::Parse() const
// Algorithme :
//
{
    std::ifstream file(filename);
    DirectedGraph<int, RefererEdge>* graph = new DirectedGraph<int, RefererEdge>;
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
                std::string referer = request.GetReferer();
                if (referer.find(INTERNAL_URI) != std::string::npos)
                {
                    referer = referer.erase(0, INTERNAL_URI.size());
                }
                int refererIdentifier = StringCache::GetInstance().Put(referer);
                RefererEdge sourceNode(refererIdentifier, true);

                graph->Add(sourceNode, uriIdentifier);
            }
        }
        if (file.fail() && !file.eof())
        {
            throw std::range_error( "file corrupted ");
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
