#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lecture.h"
#include "hash.h"
#include "linked_list.h"
#include "arbre_radix.h"

//PARAMETERS
//Nombre de mots a lire : -1 pour tout lire
#define N -1

// void test(char* mot, void* unused)
// {
//     unused = unused;
//     printf("%s\n", mot);
//     //getchar();
// }

int main(int argc, char *argv[])
{
    //Vérifie que le programme est bien lancé avec 2 arguments
    if(argc != 3)
    {
        printf("\nERREUR FATALE : MAUVAIS ARGUMENTS\n");
        printf("Exemple d'utilisation : ./bin/Final data/FR.txt data/a_la_recherche_du_temps_perdu.txt\n");
        return EXIT_FAILURE;
    }

    //Tente d'accéder aux 2 fichiers donnés en paramètres
    //Quitte si les fichies sont illisibles ou inexistants
    FILE *dictionnaire, *texte;
    //ouvre les fichiers en lecture uniquement
    dictionnaire = fopen(argv[1], "r"); 
    if(dictionnaire == NULL)
    {
        printf("\nERREUR FATALE : DICTIONNAIRE INTROUVABLE\n");
        printf("Essayez data/FR.txt et vérifiez que le fichier est présent dans le dossier data\n");
        return EXIT_FAILURE;
    }

    texte = fopen(argv[2], "r");
    if(texte == NULL)
    {
        printf("\nERREUR FATALE : TEXTE INTROUVABLE\n");
        printf("Essayez data/a_la_recherche_du_temps_perdu.txt et vérifiez que le fichier est présent dans le dossier data\n");
        return EXIT_FAILURE;
    }


    //********************************************TESTS********************************************

    //************* METHODE 3 : ARBRES PREFIX
    dictionnaire = fopen(argv[1], "r");
    texte = fopen(argv[2], "r");

    arbre a = NULL;

    //Lecture du dictionnaire
    lecture_dico(dictionnaire, &a, lectureArbre);


    //Vérification du texte
    lecture(texte, a, verifArbre, N);


    //Liberation mémoire
    fclose(texte);
    fclose(dictionnaire);

    // //************* METHODE 4 : ARBRE RADIX OPTIMISE

    // printf("--- DEBUT TEST RADIX\n");
    // texte = fopen(argv[2], "r");
    // begin = clock();

    // //parcours_prefixe(a);
    // transform_prefix_into_radix(&a);
    // //parcours_prefixe(a);

    // time_ms_dico += (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    // //Vérification du texte
    // begin = clock();
    // nb_error = lecture(texte, a, verifArbre, N);
    // printf("nombre d'erreurs : %d\n", nb_error);
    // time_ms_verif = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    // //Liberation mémoire
    
    // fclose(texte);
    // detruire_arbre(a);

    // printf("Temps dico (ms): %ld\nTemps verif (ms): %ld\n", time_ms_dico, time_ms_verif);
    // printf("--- FIN TEST RADIX\n");
    
    return EXIT_SUCCESS;
}