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
            "64.242.88.10 - - [07/Mar/2004:16:05:49 -0800] \"GET /twiki/bin/edit/Main/Double_bounce_sender?topicparent=Main.ConfigurationVariables HTTP/1.1\" 401 12846",
            "64.242.88.10 - - [07/Mar/2004:17:42:15 -0800] \"GET /twiki/bin/oops/TWiki/RichardDonkin?template=oopsmore¶m1=1.2¶m2=1.2 HTTP/1.1\" 200 11281",
            "lj1090.inktomisearch.com - - [07/Mar/2004:17:18:41 -0800] \"GET /twiki/bin/view/Main/LondonOffice HTTP/1.0\" 200 3860",
            "64.242.88.10 - - [07/Mar/2004:16:52:35 -0800] \"POST /twiki/bin/edit/Main/Flush_service_name?topicparent=Main.ConfigurationVariables HTTP/1.1\" 401 12851"
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