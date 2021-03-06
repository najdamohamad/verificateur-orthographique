#include "linked_list.h"
#include<stdbool.h>


liste liste_create()
{
    return NULL;
}

void liste_afficher(liste l)
{
    liste copy_l = l ; 
    while(copy_l != NULL)
    {
        printf("(") ; 
        element_print(copy_l->e) ;
        printf(")-->");

        copy_l = copy_l->next ; 
    }
    printf("\n");
}

void liste_add_last(void* e , liste* l)
{
    liste last_element = calloc(1, sizeof(*last_element)) ;
    last_element->e = e;
    liste copy_l = *l;
    
    if(*l == NULL)
    {
        *l = last_element;
        return;
    }
        
    while (copy_l->next != NULL)
    {
        copy_l = copy_l->next;
    }
    copy_l->next = last_element;

}

void* liste_element_exist( void* e , liste l, int (cmp_func) (void*, void*))
{
    liste copy_l = l ;
    while (copy_l != NULL )
    {
        if(cmp_func(copy_l->e, e) == 0)
            return copy_l->e ;
        copy_l = copy_l->next ;
    }
    return NULL ;
    
}

void liste_add_first(void* e, liste* l)
{
    liste new_element = calloc(1, sizeof(*new_element));
    new_element->e = e;
    new_element->next = *l ;
    *l = new_element ;
}

void liste_destroy(liste l, void (del_func)(void*))
{
    if(l == NULL)
    {
        return;
    }
    else
    {
        liste ptr_next, ptr = l ;

        while(ptr != NULL)
        {
            ptr_next = ptr->next;

            del_func(ptr->e);
            free(ptr);

            ptr = ptr_next;
        }
    }
}

void* liste_get_element(liste l, int indice)
{
    for(int i = 0; i < indice; i++)
    {
        l = l->next;
    }
    return l->e;
}

bool verifListe(char* mot, void* struct_donne)
{
    elem e = element_new(mot);

    if(!liste_element_exist(e, struct_donne, element_compare))
    {
        //printf("%s incorrect\n", mot);
        element_delete(e);
        return false;
    }
    element_delete(e);
    return true;
}

void lectureListe(char* mot, void* struct_donne)
{
    elem e = element_new(mot);
    liste_add_first(e, struct_donne);
}