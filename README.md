Rapport du Projet de Développement de Jeu : "Pingouins sur l'Iceberg"
Configuration de l'environnement de développement

•	Installation de Linux via VirtualBox 
Nous avons choisi d'utiliser Linux pour sa compatibilité avec divers outils de développement. L'installation via VirtualBox a posé quelques défis, notamment des problèmes de réseau et de partage de fichiers entre hôte et invité. Ces problèmes ont été résolus après quelques sessions de débogage et d'ajustements des paramètres de VirtualBox.

Introduction

•	Description du projet 
Le but de ce projet est de développer un jeu interactif de stratégie pour terminal, où les joueurs contrôlent des pingouins sur une grille hexagonale. Les joueurs doivent naviguer leurs pingouins pour collecter des poissons, avec des cases qui "fondent" après chaque déplacement, rendant la stratégie et la planification essentielles pour gagner.

•	Composition de l'équipe

1.	Cyprien : Chef du projet.
Responsable de la logique globale du jeu, incluant la gestion des tours, les règles de mouvement des pingouins, et la collecte des poissons.

2.	Andrew : Designer.
En charge de la robustesse du code, de l'initialisation des joueurs, de l’implémentation des couleurs dans le terminal pour une meilleure expérience visuelle et en charge du README et du Rapport

3.	Zakaria : Vérification du code.

Développement du jeu

•	Conception graphique
Modélisation de la grille hexagonale :
Calculs et représentation :
La transformation des coordonnées hexagonales en coordonnées matricielles a été un défi. Nous avons utilisé une formule mathématique pour calculer les déplacements possibles et vérifier les collisions.

Affichage des éléments de jeu :
Les poissons et les pingouins sont affichés via des symboles ASCII distincts. Nous avons opté pour une représentation simple mais claire, permettant aux joueurs de facilement identifier les éléments sur la grille.
Les poissons sont représentés par l'emoji 🐟 pour indiquer leur présence sur une case.
Les pingouins sont représentés par l'emoji 🐧 pour une identification facile par les joueurs.
Les cases fondantes sont marquées par des vagues (🌊) pour indiquer que la case n'est plus utilisable

•	Gestion des pingouins

Placement initial et mouvement :
Nous avons tenté de placer les pingouins aléatoirement sur des cases contenant un seul poisson au début de chaque partie. Ce fut un défi majeur en raison de la nécessité de respecter les règles de mouvement strictes, qui interdisent le passage à travers les cases déjà occupées ou celles marquées comme fondantes. Pour réussir, nous avons utilisé une approche similaire à celle adoptée pour le positionnement des poissons, en comptant le centre de chaque case hexagonale comme une coordonnée. Nous avons désigné ces coordonnées par "row" pour les lignes et "col" pour les colonnes. Cette méthode nous a permis de mettre en place un système de validation robuste, impliquant des boucles répétitives pour s'assurer que chaque mouvement respecte les règles du jeu.

Visualisation des changements :
Lorsqu'un pingouin se déplace, la case qu'il quitte est marquée comme fondue. Nous avons utilisé des caractères spéciaux pour représenter ces cases, afin de les distinguer clairement des autres sur le terminal.

•	Gestion du score et des tours
Suivi du score :
Chaque poisson collecté par un pingouin ajoute des points au score du joueur. Nous avons intégré une variante où certains poissons pouvaient être "avariés", déduisant des points, ce qui ajoutait un élément de risque et de stratégie au jeu.

Changement de tour :
Le système gère automatiquement le passage au joueur suivant lorsque des mouvements ne sont plus possibles. Nous avons inclus une vérification systématique pour s'assurer qu'il reste toujours au moins un déplacement légal avant de passer au tour suivant.
Gestion de la logique de jeu

•	Placement initial et mouvement des pingouins 
La mise en place initiale des pingouins sur le plateau et leur déplacement selon les règles hexagonales ont été programmés pour permettre des déplacements stratégiques et éviter les cases bloquées ou fondantes.

•	Interface utilisateur et expérience de jeu 
Les couleurs dans le terminal sont utilisées pour différencier les pingouins de chaque joueur, améliorant ainsi la lisibilité de l'état du jeu.
L'interface affiche également les scores en temps réel et les noms des joueurs pour garder un aspect compétitif clair et engageant.

Tests et robustesse

•	Tests de gameplay 
Nous avons effectué de multiples rounds de tests pour s'assurer que les règles sont appliquées correctement et que les déplacements invalides sont correctement gérés sans crash du programme.
Les scénarios de bord de grille et de cases entièrement entourées de cases fondantes ont été particulièrement scrutés pour tester la stabilité du jeu.






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
