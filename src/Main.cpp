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
#include <sstream>
//------------------------------------------------------ Include personnel

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

void usage(char* progName)
{
    std::cout << progName << "[options] inputFile.log" << endl <<
         "Parses Apache/Nginx log"
         "Options:" << endl <<
         "-h                Print this help" << endl <<
         "-t hour           Includes only requests between [hour; hour+1[" << endl <<
         "-g output.dot     Exports parsed graph as GraphViz format into output file" << endl <<
         "-e                Excludes pictures/css/js requests" << endl;
}
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ( int argc, char *argv[] )
// Algorithme :
//
{
    //std::vector<AbstractFilter*> options;

    if(cmdOptionExists(argv, argv+argc, "-h"))
    {
        // Do stuff
    }

    if(cmdOptionExists(argv, argv+argc, "-e"))
    {
        /*
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
        */
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
                throw std::exception("aborting");
            } else {
                //options.push_back(new HourFilter(intHour));
            }
        } else
        {
            throw std::exception("aborting");
        }

    }

    std::string inputFile = argv[argc - 1];
    struct stat buffer;
    if (stat (inputFile.c_str(), &buffer) != 0)
    {
        std::cerr << "error : inputFile " << inputFile << " doesn't seem to exist" << std::endl;
        throw std::exception("aborting");
    }

    //TODO create log File parser
    char * outputFile = getCmdOption(argv, argv + argc, "-g");

    if (outputFile)
    {
        //TODO generate graphViz
    }

} //----- fin de main

