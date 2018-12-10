/*************************************************************************
                           ResourceNode  -  description
                             -------------------
    début                : 09/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ResourceNode> (fichier ResourceNode.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "ResourceNode.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ResourceNode::Hit() const
// Algorithme :
//
{
    hitCount++;
}

std::string ResourceNode::GetLabel() const
// Algorithme :
//
{
    if (referer)
    {
        return std::to_string(hitCount);
    }
    else
    {
        //TODO use cache to get string associated with identifier
        return std::to_string(id);
    }
}

int ResourceNode::GetId() const
// Algorithme :
//
{
    return id;
}


//------------------------------------------------- Surcharge d'opérateurs
ResourceNode& ResourceNode::operator=(ResourceNode other)
// Algorithme :
//
{
    swap(*this, other);
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
ResourceNode::ResourceNode(const ResourceNode &other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ResourceNode>" << endl;
#endif
    hitCount = other.hitCount;
    referer = other.referer;
    id = other.id;
} //----- Fin de ResourceNode (constructeur de copie)


ResourceNode::ResourceNode(int identifier, bool isReferer) : id(identifier), referer(isReferer), hitCount(1)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ResourceNode>" << endl;
#endif
} //----- Fin de ResourceNode


ResourceNode::~ResourceNode()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ResourceNode>" << endl;
#endif
} //----- Fin de ~ResourceNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void swap(ResourceNode& first, ResourceNode& second)
{
    using std::swap;

    std::swap(first.hitCount, second.hitCount);
    std::swap(first.referer, second.referer);
    std::swap(first.id, second.id);
}

std::ostream& operator<<(std::ostream& os, const ResourceNode& node)
{
    os << "\tnode" << node.GetId() << " [label=\"" << node.GetLabel() << "\"]";
    return os;
}
