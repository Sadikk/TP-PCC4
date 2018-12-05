### Data Structures
---

#### RequestCollection 
HashTable
Structure de données utilisée pour la génération du graphe.

Type : unordered_map<int, TargetValue>

Key : identifiant de la string cible (voir ci-dessous)
Value : RefererSet

Justification : accès en temps en O(1), insertion en O(1)

#### TargetValue (à renommer)

Set ?
Structure de données utilisées pour stocker les referer
Classe avec un Set<int> et un attribut nb_hits int

Justification : 

#### Conteneur des identifiants

HashTable
Contient une correspondance  <int, string>