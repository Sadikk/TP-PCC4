/*************************************************************************
                           GraphvizSerializer  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GraphvizSerializer> (fichier GraphvizSerializer.h) ----------------
#if ! defined ( GRAPHVIZ_SERIALIZER_H )
#define GRAPHVIZ_SERIALIZER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphvizSerializer>
//
//
//------------------------------------------------------------------------

class GraphvizSerializer : public AbstractSerializer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    GraphvizSerializer & operator = ( const GraphvizSerializer & other );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GraphvizSerializer ( const GraphvizSerializer & other );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GraphvizSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GraphvizSerializer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GraphvizSerializer>

#endif // GRAPHVIZ_SERIALIZER_H

