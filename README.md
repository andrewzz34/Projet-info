README pour CY FISH:

À propos de CY FISH
CY FISH est un jeu stratégique en C où les joueurs contrôlent des pingouins sur un plateau de jeu hexagonal. Le jeu demande aux joueurs de collecter des poissons tout en déplaçant astucieusement leurs pingouins sur le plateau pour maximiser leur score et bloquer leurs adversaires. La dynamique unique du jeu réside dans la gestion des déplacements et la récolte des ressources tout en anticipant les mouvements des adversaires.

-Description du Jeu
Déroulement du Jeu:
Nombre de Joueurs : CY FISH peut être joué par 2 à 6 joueurs.
Placement des Pingouins : Au début du jeu, les pingouins sont placés aléatoirement sur le plateau. Le nombre de pingouins par joueur varie selon le nombre de joueurs :
2 joueurs : 4 pingouins chacun.
3 joueurs : 3 pingouins chacun.
4 joueurs : 2 pingouins chacun.
5 ou 6 joueurs : 1 pingouin chacun.
Taille du Plateau : Le plateau est limité à un maximum de 9 lignes et 9 colonnes.

Règles:

Début de la Partie : Les joueurs débutent avec un certain nombre de pingouins placés sur des cases contenant un seul poisson.
Tour de Jeu : À chaque tour, un joueur doit choisir un de ses pingouins et le déplacer d'au moins une case en suivant les règles de déplacement hexagonal (six directions possibles).
Collecte de Poissons : Lorsqu'un pingouin se déplace sur une nouvelle case, le nombre de poissons sur cette case est ajouté au score du joueur. La case de départ devient ensuite inutilisable pour le reste de la partie.
Fin de Tour : Si un joueur ne peut pas effectuer un déplacement valide, son tour est automatiquement passé.
Fin de Jeu : Le jeu se termine lorsque plus aucun joueur ne peut se déplacer. Le joueur avec le plus grand nombre de poissons est déclaré vainqueur.

Interface Utilisateur:
Affichage : Le plateau est représenté graphiquement dans le terminal avec des cases hexagonales. Chaque case affiche le nombre de poissons présents et, si applicable, le pingouin présent.
Scores et Joueurs : Les scores et les noms des joueurs sont affichés en continu pour permettre le suivi de la progression de la partie.
Objectif du Jeu:

L'objectif pour chaque joueur est de naviguer stratégiquement sur le plateau pour collecter autant de poissons que possible tout en bloquant les mouvements des adversaires. Une planification prudente et une anticipation des mouvements des autres joueurs sont essentielles pour remporter la partie.
