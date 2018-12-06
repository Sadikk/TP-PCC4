
### Data Structures

---

#### Matrice d'adjacences (adjacencyMap)


Structure de données utilisée pour représenter un graphe

Type : Arbre binaire de recherche (rouge et noir). 

Justification : L'insertion et la recherche se font en temps quasi-constant (O(log n)). Cela
le rend bien adapté à nos besoins d'ajout et de recherche rapide. De plus, c'est un arbre balancé, 
ainsi on a directement l'ordre des documents les plus visités (par exemple pour le top 10) sans devoir 
appliquer un algorithme de tri qui pourrait s'avérer coûteux dans le cas de données volumineuses.

Type STL : `map<AbstractNode, unordered_set<AbstractNode>>`

Key : UriNode 

Value : Collection de RefererNode associée

#### Values de l'adjacencyMap

Structure de données utilisée pour stocker les couples referer;nb_hits associés aux URI

Type : Table de hachage (HashTable). 

Justification : Nous n'avons pas besoin de maintenir l'ordre ou d'accéder à des
                éléments, simplement de pouvoir ajouter et rechercher très rapidement. La HashTable fait ça en temps
                constant (O(1)) est donc un choix privilégié

Type STL : `unordered_set<AbstractNode>`

#### Cache des strings

Afin de gagner en espace mémoire, chaque string URI/referer est associée à un identifiant entier unique.
Ainsi le graphe manipule des entiers qui sont moins coûteux en mémoire et ne récupère la
valeur de la chaînes de caractères que si nécessaires (affichage ou export)

Type : Table de hachage (HashTable)

Justification : Nous n'avons pas besoin de maintenir l'ordre ou d'accéder à des
                éléments, simplement de pouvoir ajouter et rechercher très rapidement. La HashTable fait ça en temps
                constant (O(1)) est donc un choix privilégié
                
Type STL : `unordered_map<int, string>`