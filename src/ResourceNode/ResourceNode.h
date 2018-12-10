/*************************************************************************
                           ResourceNode  -  description
                             -------------------
    début                : 09/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ResourceNode> (fichier ResourceNode.h) ----------------
#ifndef ResourceNode_H
#define ResourceNode_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ResourceNode>
//
// Représente un noeud de graphe dans le contexte de l'application
//------------------------------------------------------------------------

class ResourceNode {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Hit() const;
    // Mode d'emploi :
    //      Signale que ce noeud a été rencontré
    // Contrat :
    //

    std::string GetLabel() const;
    // Mode d'emploi :
    //      Récupère le label associé au noeud
    // Contrat :
    //

    int GetId() const;
    // Mode d'emploi :
    //      Récupère l'identifiant du noeud
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    ResourceNode & operator = ( ResourceNode other );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend bool operator< (const ResourceNode& a, const ResourceNode& b)
    {
        return a.hitCount < b.hitCount || (
                !(b.hitCount < a.hitCount) && a.id < b.id
        );
    }

    bool operator ==(const ResourceNode & obj) const
    {
        return id == obj.id;
    }

    friend std::ostream& operator<<(std::ostream& os, const ResourceNode& node);

//-------------------------------------------- Constructeurs - destructeur
    ResourceNode(const ResourceNode &other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ResourceNode(int identifier, bool isReferer = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ResourceNode();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap(ResourceNode& first, ResourceNode& second);


    //----------------------------------------------------- Attributs protégés
    int id;
    bool referer;
    //non-key member, so allowed to change even when we get const_iterator
    mutable int hitCount;


};

//-------------------------------- Autres définitions dépendantes de <ResourceNode>
namespace std
{
    template<>
    struct hash<ResourceNode>
    {
        size_t operator()(const ResourceNode & obj) const
        {
            return hash<int>()(obj.GetId());
        }
    };
}
#endif // ResourceNode_H

