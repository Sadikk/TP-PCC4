/*************************************************************************
                           LogFileParser  -  description
                             -------------------
    début                : 12/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LogFileParser> (fichier LogFileParser.h) ----------------
#ifndef LogFileParser_H
#define LogFileParser_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>

#include "../DirectedGraph/DirectedGraph.h"
#include "../AbstractFilter/AbstractFilter.h"
#include "../ResourceNode/ResourceNode.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogFileParser>
//
// Représente la classe principale de l'application s'occupant de parser
// un fichier de logs selon des options définies
//------------------------------------------------------------------------

class LogFileParser {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    DirectedGraph<ResourceNode>* Parse() const;
    // Mode d'emploi :
    //      Génére un graphe représentant le fichier de log parsé et filtré
    // selon les options spécifiés
    // Contrat :
    //      La désallocation mémoire du graphe est laissé à la charge de
    // l'utilisateur


//------------------------------------------------- Surcharge d'opérateurs
    LogFileParser &operator=(LogFileParser other);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LogFileParser(const LogFileParser &other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogFileParser(std::string inputFile, std::vector<AbstractFilter*> filters = {});
    // Mode d'emploi :
    //
    // Contrat :
    //      inputFile doit cibler un fichier de log existant et bien formé

    virtual ~LogFileParser();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap(LogFileParser& first, LogFileParser& second);
//----------------------------------------------------- Attributs protégés
    std::string filename;
    std::vector<AbstractFilter*> options;
};

//-------------------------------- Autres définitions dépendantes de <LogFileParser>

#endif // LogFileParser_H

