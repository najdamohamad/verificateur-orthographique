#include <stdio.h>
#include <stdlib.h>
#include "arbre_prefix.h"
#include "arbre_radix.h"
int main(void)
{
    arbre a = NULL;
    
    elem e1 = element_new("coucou");
    elem e2 = element_new("salut");
    elem e3 = element_new("couture");
    elem e4 = element_new("s");
    elem e5 = element_new("boomttes");
    elem e6 = element_new("boom");
    elem e7 = element_new("couturettes");

    
    //ajout_prefix(&a, e2);
    ajout_prefix(&a, e7);
    ajout_prefix(&a, e4);
    ajout_prefix(&a, e1);
    ajout_prefix(&a, e3);
    ajout_prefix(&a, e5);
    ajout_prefix(&a, e6);

    parcours_prefixe(a); printf("\n");

    printf("\ncoucou : %d, salut : %d, couture : %d, s %d,boomttes %d, boom %d, couturette %d\n",   
                                        recherche_arbre_prefix(a , e1), 
                                        recherche_arbre_prefix(a , e2),
                                        recherche_arbre_prefix(a , e3),
                                        recherche_arbre_prefix(a , e4),
                                        recherche_arbre_prefix(a , e5),
                                        recherche_arbre_prefix(a , e6),
                                        recherche_arbre_prefix(a , e7));

    transform_prefix_into_radix(&a);
    parcours_prefixe(a); printf("\n");

    liste f = liste_create();
    liste duplic = liste_create();
    
    a = partage_prefix(a, &f, &duplic);
    liste_destroy(f, chuuuuuu);

    parcours_prefixe(a); printf("\n");

    printf("\ncoucou : %d, salut : %d, couture : %d, s %d,boomttes %d, boom %d, couturette %d\n",   
                                        recherche_arbre_prefix(a , e1), 
                                        recherche_arbre_prefix(a , e2),
                                        recherche_arbre_prefix(a , e3),
                                        recherche_arbre_prefix(a , e4),
                                        recherche_arbre_prefix(a , e5),
                                        recherche_arbre_prefix(a , e6),
                                        recherche_arbre_prefix(a , e7));

    element_delete(e1);
    element_delete(e2);
    element_delete(e3);
    element_delete(e4);
    element_delete(e5);
    element_delete(e6);
    element_delete(e7);

    
    
    detruire_arbre_radix(a, duplic);
    liste_destroy(duplic, radix_list_delete);

    return EXIT_SUCCESS;
}
