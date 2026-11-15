
#include <stdio.h>
#include "tic-tac-toe.h"

void afficher(char tab[])
{
    printf("\n");
    printf(" %c | %c | %c\n", tab[0], tab[1], tab[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", tab[3], tab[4], tab[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", tab[6], tab[7], tab[8]);
}

int victoire(char tab[], char symbole)
{
    if (tab[0] == symbole && tab[1] == symbole && tab[2] == symbole)
        return 1;

    if (tab[3] == symbole && tab[4] == symbole && tab[5] == symbole)
        return 1;

    if (tab[6] == symbole && tab[7] == symbole && tab[8] == symbole)
        return 1;

    if (tab[0] == symbole && tab[3] == symbole && tab[6] == symbole)
        return 1;

    if (tab[1] == symbole && tab[4] == symbole && tab[7] == symbole)
        return 1;

    if (tab[2] == symbole && tab[5] == symbole && tab[8] == symbole)
        return 1;

    if (tab[0] == symbole && tab[4] == symbole && tab[8] == symbole)
        return 1;

    if (tab[2] == symbole && tab[4] == symbole && tab[6] == symbole)
        return 1;

    return 0;
}

void jouer(void)
{
    char tab[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int choix;
    int i;

    printf("Bienvenue dans le morpion !\n");
    printf("Tu joues avec X et l'ordinateur avec O.\n");

    while (1)
    {
        afficher(tab);

        printf("Choisis une case entre 0 et 8 : ");

        if (scanf("%d", &choix) != 1)
        {
            printf("Entre un nombre valide !\n");

            while (getchar() != '\n')
                ;

            continue;
        }

        if (choix < 0 || choix > 8 || tab[choix] != ' ')
        {
            printf("Case invalide !\n");
            continue;
        }

        tab[choix] = 'X';

        if (victoire(tab, 'X'))
        {
            afficher(tab);
            printf("Bravo, tu as gagne !\n");
            break;
        }

        i = 0;

        while (i < 9 && tab[i] != ' ')
            i++;

        if (i == 9)
        {
            afficher(tab);
            printf("Match nul !\n");
            break;
        }

        tab[i] = 'O';

        printf("L'ordinateur joue dans la case %d.\n", i);

        if (victoire(tab, 'O'))
        {
            afficher(tab);
            printf("L'ordinateur a gagne !\n");
            break;
        }

        i = 0;

        while (i < 9 && tab[i] != ' ')
            i++;

        if (i == 9)
        {
            afficher(tab);
            printf("Match nul !\n");
            break;
        }
    }
}
