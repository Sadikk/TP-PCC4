/*************************************************************************
                           TExtensionFilter  -  description
                             -------------------
    dÃ©but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- RÃ©alisation de la classe <TExtensionFilter> (fichier TExtensionFilter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systÃ¨me
#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
//------------------------------------------------------ Include personnel
#include "TExtensionFilter.h"
#include "../../src/Request/Request.h"
#include "../../src/ExtensionFilter/ExtensionFilter.h"

static void shouldFilterJpg(){
  std::cout << "Testing Filter Jpg" << std::endl;
  string lineWithJpg = "192.168.0.4 - - [08/Sep/2012:11:19:17 +0200] \"GET /stages/Listestage.jpg HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"" ;
  ExtensionFilter jpgFilter(".jpg");
  Request r;
  std::istringstream iss(lineWithJpg);
  iss >> r;
  assert(jpgFilter.Check(r) == true);
  std::cout << "Test completed" <<std::endl;
}

static void shouldFilterJs(){
  std::cout << "Testing Filter Js" << std::endl;
  string lineWithJs = "192.168.0.4 - - [08/Sep/2012:11:19:17 +0200] \"GET /stages/Listestage.js HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"" ;
  ExtensionFilter jsFilter(".js");
  Request r;
  std::istringstream iss(lineWithJs);
  iss >> r;
  assert(jsFilter.Check(r) == true);
  std::cout << "Test completed" <<std::endl;
}

static void shouldFilterCss(){
  std::cout << "Testing Css Filter" << std::endl;
  string lineWithCss = "192.168.0.4 - - [08/Sep/2012:11:19:17 +0200] \"GET /stages/Listestage.css HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"" ;
  ExtensionFilter cssFilter(".css");
  Request r;
  std::istringstream iss(lineWithCss);
  iss >> r;
  assert(cssFilter.Check(r) == true);
  std::cout << "Test completed" <<std::endl;
}

static void shouldNotFilter(){
  std::cout << "Testing Filter" << std::endl;
  string lineWithCss = "192.168.0.4 - - [08/Sep/2012:11:19:17 +0200] \"GET /stages/Listestage.php HTTP/1.1\" 200 74694 \"http://intranet-if.insa-lyon.fr/SiteWebIF/Intranet-etudiant.php\" \"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1\"" ;
  ExtensionFilter cssFilter(".css");
  ExtensionFilter jsFilter(".js");
  ExtensionFilter jpgFilter(".jpg");
  Request r;
  std::istringstream iss(lineWithCss);
  iss >> r;
  assert(cssFilter.Check(r) == false && jsFilter.Check(r) == false && jpgFilter.Check(r) == false);
  std::cout << "Test completed" <<std::endl;
}


int main(){
  shouldFilterJpg();
  shouldFilterJs();
  shouldFilterCss();
  shouldNotFilter();

}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- MÃ©thodes protÃ©gÃ©es
