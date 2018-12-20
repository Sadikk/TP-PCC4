/*************************************************************************
                           THourFilter  -  description
                             -------------------
    dÃ©but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- RÃ©alisation de la classe <THourFilter> (fichier THourFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systÃ¨me
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
//------------------------------------------------------ Include personnel
#include "THourFilter.h"
#include "../../src/Request/Request.h"
#include "../../src/HourFilter/HourFilter.h"

static void shouldLetRequestPass() {
    std::cout << "Testing Filter" << std::endl;
    std::stringstream out;

    string test1 = "192.168.0.4 - - [08/Sep/2012:11:19:17 +0200] \"GET /stages/Listestage.php HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"";
    string test2 = "192.168.0.5 - - [08/Sep/2012:11:19:21 +0200] \"GET /temps/3IF1.ics HTTP/1.1\" 304 - \"-\" \"DataAccess/1.0 (8C148)\"";
    string test3 = "192.168.0.8 - - [08/Sep/2012:11:23:46 +0200] \"GET /notesif/ HTTP/1.1\" 302 - \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows; U; Windows NT 6.1; fr; rv:1.9.2.10) Gecko/20100914 Firefox/3.6.10\"";
    string lines[3];
    lines[0] = test1;
    lines[1] = test2;
    lines[2] = test3;

    HourFilter hourFilter(11);
    for (std::string line : lines) {
        Request r;
        std::stringstream out;
        std::istringstream iss(line);
        iss >> r;
        assert(hourFilter.Check(r) == true);
    }
    std::cout << "Test completed" << std::endl;
}

static void shouldNotLetRequestPass() {
    std::cout << "Testing Filter" << std::endl;
    std::stringstream out;

    string test1 = "192.168.0.4 - - [08/Sep/2012:11:19:17 +0200] \"GET /stages/Listestage.php HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"";
    string test2 = "192.168.0.5 - - [08/Sep/2012:11:19:21 +0200] \"GET /temps/3IF1.ics HTTP/1.1\" 304 - \"-\" \"DataAccess/1.0 (8C148)\"";
    string test3 = "192.168.0.8 - - [08/Sep/2012:11:23:46 +0200] \"GET /notesif/ HTTP/1.1\" 302 - \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows; U; Windows NT 6.1; fr; rv:1.9.2.10) Gecko/20100914 Firefox/3.6.10\"";

    string lines[3];
    lines[0] = test1;
    lines[1] = test2;
    lines[2] = test3;

    HourFilter hourFilter(13);
    for (std::string line : lines) {
        Request r;
        std::stringstream out;
        std::istringstream iss(line);
        iss >> r;
        assert(hourFilter.Check(r) == false);
    }
    std::cout << "Test completed" << std::endl;
}

static void midnightTest() {
  std::cout << "Testing Midnight Filter" << std::endl;
  std::stringstream out;

  string test1 = "192.168.0.4 - - [08/Sep/2012:00:19:17 +0200] \"GET /stages/Listestage.php HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"";
  string test2 = "192.168.0.5 - - [08/Sep/2012:00:42:21 +0200] \"GET /temps/3IF1.ics HTTP/1.1\" 304 - \"-\" \"DataAccess/1.0 (8C148)\"";
  string test3 = "192.168.0.8 - - [08/Sep/2012:00:52:46 +0200] \"GET /notesif/ HTTP/1.1\" 302 - \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows; U; Windows NT 6.1; fr; rv:1.9.2.10) Gecko/20100914 Firefox/3.6.10\"";

  string lines[3];
  lines[0] = test1;
  lines[1] = test2;
  lines[2] = test3;

  HourFilter hourFilter(0);
  for (std::string line : lines) {
      Request r;
      std::stringstream out;
      std::istringstream iss(line);
      iss >> r;
      assert(hourFilter.Check(r) == true);
  }
  std::cout << "Test completed" << std::endl;

}

int main() {
    shouldLetRequestPass();
    shouldNotLetRequestPass();
    midnightTest();
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- MÃ©thodes protÃ©gÃ©es
