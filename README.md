# John Conway's Game of Life in Rust

Ce projet est une implémentation du **Jeu de la Vie** de John Horton Conway en **Rust**. Il utilise la bibliothèque graphique `macroquad` pour l'affichage et l'interaction utilisateur.

## Fonctionnalités

- **Grille infinie** : La grille s'étend dynamiquement au fur et à mesure que tu te déplaces.
- **Zoom et déplacement** : Utilise la molette de la souris pour zoomer/dézoomer et les touches directionnelles pour te déplacer dans la grille.
- **Ajout/suppression de cellules** : Clique sur les cellules pour en ajouter ou en supprimer.
- **Simulation** : Appuie sur `Espace` pour démarrer/arrêter la simulation.

## Prérequis

- **Rust** : Assure-toi d'avoir installé Rust sur ton système. Si ce n'est pas le cas, tu peux l'installer en suivant les instructions sur [rust-lang.org](https://www.rust-lang.org/).

- **Cargo** : L'outil de gestion de paquets de Rust est inclus avec Rust.

## Installation

1. Clone le dépôt GitLab sur ta machine locale :

    ```bash
    git clone https://gitlab.com/ton_dépôt/game_of_life.git
    ```

2. Navigue dans le répertoire du projet :

    ```bash
    cd game_of_life
    ```

3. Installe les dépendances et compile le projet :

    ```bash
    cargo build
    ```

## Utilisation

1. Lancer l'application :

    ```bash
    cargo run
    ```

Cela va démarrer l'application. Une fenêtre graphique s'ouvrira avec la grille du jeu.

2. Contrôles du jeu :

   * Clic gauche : Ajouter ou retirer une cellule vivante.
   * Espace : Démarrer ou arrêter la simulation.
   * Molette de la souris : Zoomer et dézoomer.
   * Flèches directionnelles : Déplacer la caméra dans la grille.

## Tests

Ce projet contient des tests unitaires pour s'assurer que les règles du jeu de la vie sont correctement appliquées. Pour exécuter les tests :

```bash
cargo test
```

## GitLab CI/CD

Ce projet utilise GitLab CI pour automatiser les tests. Chaque commit déclenche un pipeline qui exécute les tests définis dans le fichier .gitlab-ci.yml.

## Structure du projet

* `src/main.rs` : Point d'entrée de l'application.
* `src/lib.rs` : Expose les différents modules du projet.
* `src/game_of_life.rs` : Contient la logique principale du jeu de la vie (simulation, gestion des cellules, etc.).
* `src/cell.rs` : Définit la structure Cell pour représenter une cellule du jeu.
* `tests/` : Contient les tests unitaires pour vérifier le bon fonctionnement du jeu.

## Licence

Ce projet est sous licence MIT. Pour plus d'informations, consulte le fichier `LICENSE`.
