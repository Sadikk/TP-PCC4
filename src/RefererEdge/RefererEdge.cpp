/*************************************************************************
                           RefererEdge  -  description
                             -------------------
    début                : 09/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <RefererEdge> (fichier RefererEdge.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "RefererEdge.h"
#include "../StringCache/StringCache.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void RefererEdge::Hit() const
// Algorithme :
//
{
    hitCount++;
}

std::string RefererEdge::GetLabel() const
// Algorithme :
//
{
    if (referer)
    {
        return std::to_string(hitCount);
    }
    else
    {
        return StringCache::GetInstance().Get(id);
    }
}

int RefererEdge::GetId() const
// Algorithme :
//
{
    return id;
}


//------------------------------------------------- Surcharge d'opérateurs
RefererEdge& RefererEdge::operator=(RefererEdge other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
RefererEdge::RefererEdge(const RefererEdge &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <RefererEdge>" << endl;
#endif
    hitCount = other.hitCount;
    referer = other.referer;
    id = other.id;
} //----- Fin de RefererEdge (constructeur de copie)


RefererEdge::RefererEdge(int identifier, bool isReferer) : id(identifier), referer(isReferer), hitCount(1)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <RefererEdge>" << endl;
#endif
} //----- Fin de RefererEdge


RefererEdge::~RefererEdge()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <RefererEdge>" << endl;
#endif
} //----- Fin de ~RefererEdge


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void swap(RefererEdge& first, RefererEdge& second)
{
    using std::swap;

    std::swap(first.hitCount, second.hitCount);
    std::swap(first.referer, second.referer);
    std::swap(first.id, second.id);
}

std::ostream& operator<<(std::ostream& os, const RefererEdge& node)
{
    os << "\tnode" << node.GetId() << " [label=\"" << node.GetLabel() << "\"]";
    return os;
}
