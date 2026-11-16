

#include <stdio.h> // Permet d'utiliser printf et scanf
#include "tic-tac-toe.h" // Importe les declarations des fonctions

// affiche le plateau de jeu
void afficher(char tab[])
{
    printf("\n"); // Ajoute une ligne vide

    // Affiche les 3 cases de la premiere ligne
    printf(" %c | %c | %c\n", tab[0], tab[1], tab[2]);

    printf("-----------\n"); // Separe les lignes

    // Affiche les 3 cases de la deuxieme ligne
    printf(" %c | %c | %c\n", tab[3], tab[4], tab[5]);

    printf("-----------\n"); // Separe les lignes

    // Affiche les 3 cases de la troisieme ligne
    printf(" %c | %c | %c\n", tab[6], tab[7], tab[8]);
}

// verifie si un joueur a gagné
int victoire(char tab[], char symbole)
{
    // Verifie les 3 lignes horizontales
    if (tab[0] == symbole && tab[1] == symbole && tab[2] == symbole)
        return 1;

    if (tab[3] == symbole && tab[4] == symbole && tab[5] == symbole)
        return 1;

    if (tab[6] == symbole && tab[7] == symbole && tab[8] == symbole)
        return 1;

    // Verifie les 3 colonnes verticales
    if (tab[0] == symbole && tab[3] == symbole && tab[6] == symbole)
        return 1;

    if (tab[1] == symbole && tab[4] == symbole && tab[7] == symbole)
        return 1;

    if (tab[2] == symbole && tab[5] == symbole && tab[8] == symbole)
        return 1;

    // Verifie les 2 diagonales
    if (tab[0] == symbole && tab[4] == symbole && tab[8] == symbole)
        return 1;

    if (tab[2] == symbole && tab[4] == symbole && tab[6] == symbole)
        return 1;

    return 0; // Aucun alignement gagnant trouve
}

// gere le deroulement de la partie
void jouer(void)
{
    // Cree un tableau de 9 cases vides
    char tab[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    int choix; // Stocke la case choisie par le joueur
    int i; // Variable utilisée pour parcourir le tableau

    printf("Bienvenue dans le morpion !\n");
    printf("Tu joues avec X et l'ordinateur avec O.\n");

    // Repete le jeu jusqu'a ce qu'un joueur gagne ou fasse match nul
    while (1)
    {
        afficher(tab); // Affiche le plateau

        printf("Choisis une case entre 0 et 8 : ");

        // Verifie que le joueur a bien entré un nombre
        if (scanf("%d", &choix) != 1)
        {
            printf("Entre un nombre valide !\n");

            // Vide les caracteres incorrects dans le clavier
            while (getchar() != '\n')
                ;

            continue; // Recommence le tour
        }

        // Verifie que la case existe et qu'elle est libre
        if (choix < 0 || choix > 8 || tab[choix] != ' ')
        {
            printf("Case invalide !\n");
            continue; // Demande une nouvelle case
        }

        // Place le symbole X dans la case choisie
        tab[choix] = 'X';

        // Verifie si le joueur a gagne
        if (victoire(tab, 'X'))
        {
            afficher(tab);
            printf("Bravo, tu as gagne !\n");
            break; // Arrete la partie
        }

        // Cherche la premiere case libre pour l'ordinateur
        i = 0;

        while (i < 9 && tab[i] != ' ')
            i++;

        // Verifie si toutes les cases sont occupees
        if (i == 9)
        {
            afficher(tab);
            printf("Match nul !\n");
            break; // Arrete la partie
        }

        // Place le symbole O dans la premiere case libre
        tab[i] = 'O';

        // Affiche la case choisie par l'ordinateur
        printf("L'ordinateur joue dans la case %d.\n", i);

        // Verifie si l'ordinateur a gagne
        if (victoire(tab, 'O'))
        {
            afficher(tab);
            printf("L'ordinateur a gagne !\n");
            break; // Arrete la partie
        }

        // Recherche s'il reste une case libre
        i = 0;

        while (i < 9 && tab[i] != ' ')
            i++;

        // Si aucune case n'est libre, la partie est nulle
        if (i == 9)
        {
            afficher(tab);
            printf("Match nul !\n");
            break; // Arrete la partie
        }
    }
}

