/*************************************************************************
                           TRequest  -  description
                             -------------------
    début                : 11/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <TRequest> (fichier TRequest.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
//------------------------------------------------------ Include personnel
#include "TRequest.h"
#include "../../src/Request/Request.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

static void testIsError()
{
    cout << "testIsError..." << "\r\n";

    Request r("", "", "", 0, GET, "", 200);
    assert(r.IsError() == false);

    Request r2("", "", "", 0, GET, "", 404);
    assert(r2.IsError() == true);

    Request r3("", "", "", 0, GET, "", 301);
    assert(r3.IsError() == false);

    Request r4("", "", "", 0, GET, "", 302);
    assert(r4.IsError() == false);

    Request r5("", "", "", 0, GET, "", 401);
    assert(r5.IsError() == true);

    Request r6("", "", "", 0, GET, "", 400);
    assert(r6.IsError() == true);

    Request r7("", "", "", 0, GET, "", 500);
    assert(r7.IsError() == true);
    cout << "ok" << "\r\n";
}

static void testParsing()
{
    cout << "testParsing..." << "\r\n";
    std::stringstream out;

    std::vector<std::string> lines = {
            "192.168.0.4 - - [08/Sep/2012:11:19:17 +0200] \"GET /stages/Listestage.php HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"",
            "192.168.0.5 - - [08/Sep/2012:11:19:21 +0200] \"GET /temps/3IF1.ics HTTP/1.1\" 304 - \"-\" \"DataAccess/1.0 (8C148)\"",
            "192.168.0.8 - - [08/Sep/2012:11:23:46 +0200] \"GET /notesif/ HTTP/1.1\" 302 - \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows; U; Windows NT 6.1; fr; rv:1.9.2.10) Gecko/20100914 Firefox/3.6.10\""
    };

    for (std::string line : lines)
    {
        Request r;
        std::stringstream out;
        std::istringstream iss(line);
        iss >> r;
        out << r;
        assert(out.str() == line);
    }

    cout << "ok" << "\r\n";
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main()
// Algorithme :
//
{
    testIsError();
    testParsing();
} //----- fin de main