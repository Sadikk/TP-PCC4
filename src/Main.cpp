/*************************************************************************
                           Main  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
//------------------------------------------------------ Include personnel
#include "AbstractFilter/AbstractFilter.h"
#include "HourFilter/HourFilter.h"
#include "ExtensionFilter/ExtensionFilter.h"
#include "LogFileParser/LogFileParser.h"
#include "DirectedGraph/DirectedGraph.h"
#include "StringCache/StringCache.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
/* https://stackoverflow.com/questions/865668/how-to-parse-command-line-arguments-in-c */
char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

bool fileExists(const char* file)
{
    struct stat buffer;
    return (stat (file, &buffer) == 0);
}

void usage(std::string progName)
{
    std::cout << "Utilisation : " << progName << "[options] inputFile.log" << std::endl <<
         "Analyse un fichier de logs Apache/Nginx" << std::endl <<
         "Options:" << std::endl <<
         "-h                Affiche cette aide" << std::endl <<
         "-t hour           Inclus seulement les requêtes d'heures [hour; hour+1[" << std::endl <<
         "-g output.dot     Exporte le graphe au format GraphViz dans le fichier de sortie" << std::endl <<
         "-e                Exclut les requêtes css/js/images" << std::endl;
}
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ( int argc, char *argv[] )
// Algorithme :
//
{
    std::vector<AbstractFilter*> options;

    if(cmdOptionExists(argv, argv+argc, "-h") || argc == 1)
    {
        usage("analog");
        return 0;
    }

    if(cmdOptionExists(argv, argv+argc, "-e"))
    {

        //css
        options.push_back(new ExtensionFilter(".css"));

        //js
        options.push_back(new ExtensionFilter(".js"));

        //pictures
        options.push_back(new ExtensionFilter(".jpg"));
        options.push_back(new ExtensionFilter(".jpeg"));
        options.push_back(new ExtensionFilter(".jfif"));
        options.push_back(new ExtensionFilter(".jif"));
        options.push_back(new ExtensionFilter(".png"));
        options.push_back(new ExtensionFilter(".gif"));
        options.push_back(new ExtensionFilter(".webp"));
        options.push_back(new ExtensionFilter(".svg"));
        options.push_back(new ExtensionFilter(".ico"));
        options.push_back(new ExtensionFilter(".tiff"));
        options.push_back(new ExtensionFilter(".tif"));
        options.push_back(new ExtensionFilter(".jp2"));
        options.push_back(new ExtensionFilter(".jpx"));
        options.push_back(new ExtensionFilter(".j2k"));
        options.push_back(new ExtensionFilter(".fpx"));
        options.push_back(new ExtensionFilter(".pcd"));
    }


    char * hour = getCmdOption(argv, argv + argc, "-t");
    if (hour)
    {
        int intHour;
        try {
            intHour = std::stoi(hour);
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "error : Time filter should be an integer" << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "error : Time filter should be between 0 and 24" << std::endl;
        }

        if (intHour)
        {
            if (intHour < 0 || intHour > 24)
            {
                std::cerr << "error : Time filter should be between 0 and 24" << std::endl;
                throw std::out_of_range("aborting");
            } else {
                options.push_back(new HourFilter(intHour));
            }
        } else
        {
            throw std::out_of_range("aborting");
        }

    }

    std::string inputFile = argv[argc - 1];
    if (!fileExists(inputFile.c_str())) {
        std::cerr << "error : inputFile " << inputFile << " doesn't seem to exist" << std::endl;
        throw std::invalid_argument("aborting");
    }

    LogFileParser parser(inputFile, options);
    char * outputFile = getCmdOption(argv, argv + argc, "-g");
    DirectedGraph<int, ResourceNode>* graph = parser.Parse();

    for (std::pair<int, int> pair : *graph->Top(10)) {
        std::cout << StringCache::GetInstance().Get(pair.first) << " (" << pair.second << " hits)" << std::endl;
    }

    if (outputFile)
    {
        if (fileExists(outputFile))
        {
            std::cout << "Le fichier " << outputFile << " semble déjà exister, souhaitez-vous l'écraser ? (o/n) [n]" << std::endl;
            std::string answer;
            std::getline(std::cin >> std::ws, answer);
            while(std::cin.eof() || std::cin.bad() || std::cin.fail())
            {
                std::cin.clear();
                std::getline(std::cin >> std::ws, answer);
            }
            if (answer != "o")
            {
                return 0;
            }
        }
        std::ofstream os;
        os.open(outputFile);
        graph->Serialize(os);
        std::cout << "GraphViz généré avec succès et sauvegardé dans le fichier : " << outputFile << std::endl;
    }



} //----- fin de main

