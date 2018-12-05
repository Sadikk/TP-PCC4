### Specs

--- 

#### Main

Cas normaux :
- On peut mettre les options dans n'importe quelle ordre (comme une commande linux classique)
- Options possibles : 
 - g nomFichier.dot : génére un fichier GraphViz
 - e : exclut documents images/css/js
 - t heure : filtre sur les heures
- Afficher les 10 documents les plus consultés (= étant le plus de fois "cible") par ordre décroissant de popularité
 
Cas limites : 
 - Si nomFichier.dot est déjà existant, on demande confirmation 
 - Option inconnue : warning ?
 - Pas d'argument nom de fichier : afficher l'aide
 
Cas d'erreurs : 
 - on doit avoir 0 <= t <= 23 sinon erreur, avec t entier
 - heure et nomFichier.dot sont des arguments obligatoires : si absence -> erreur

#### Log analyzer

Cas normaux :
 -  Pour chaque ligne de log, on ajoute la requete à la structure de donnéees
 - On doit pouvoir exclure tous les documents images/css/javascript
 - Chaque requête est identifiée par le triplet (Referer;Cible;DateTime)
 
Cas limites : 
 - La requete existe déjà : on ajoute une nouvelle fois la requête : la structure de données doit donc supporter les doublons

Cas d'erreurs :
  - Ligne de log mal formée = n'est pas censé arriver. 

#### GraphViz gen
 
 Cas normaux :
 - Pouvoir passer de la structure de données des logs analysées à un graphe bien formé GraphViz
  
Cas limites : 
 - pas de requetes à exporter:  générer un graphe vide (à définir selon syntaxe GraphViz)

Cas d'erreurs :
- 
####

