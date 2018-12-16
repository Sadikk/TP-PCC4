/*************************************************************************
                           RefererEdge  -  description
                             -------------------
    début                : 09/12/18
    copyright            : (C) 2018$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <RefererEdge> (fichier RefererEdge.h) ----------------
#ifndef RefererEdge_H
#define RefererEdge_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <RefererEdge>
//
// Représente un noeud de graphe dans le contexte de l'application
//------------------------------------------------------------------------

class RefererEdge {
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
    RefererEdge & operator = ( RefererEdge other );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend bool operator< (const RefererEdge& a, const RefererEdge& b)
    {
        return a.hitCount < b.hitCount || (
                !(b.hitCount < a.hitCount) && a.id < b.id
        );
    }

    bool operator ==(const RefererEdge & obj) const
    {
        return id == obj.id;
    }

    friend std::ostream& operator<<(std::ostream& os, const RefererEdge& node);

//-------------------------------------------- Constructeurs - destructeur
    RefererEdge(const RefererEdge &other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    RefererEdge(int identifier, bool isReferer = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~RefererEdge();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    friend void swap(RefererEdge& first, RefererEdge& second);


    //----------------------------------------------------- Attributs protégés
    int id;
    bool referer;
    //non-key member, so allowed to change even when we get const_iterator
    mutable int hitCount;


};

//-------------------------------- Autres définitions dépendantes de <RefererEdge>
namespace std
{
    template<>
    struct hash<RefererEdge>
    {
        size_t operator()(const RefererEdge & obj) const
        {
            return hash<int>()(obj.GetId());
        }
    };
}
#endif // RefererEdge_H

