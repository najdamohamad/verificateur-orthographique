#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <assert.h>

typedef struct mot {
  char* mot;
} *elem;

elem element_new(char* mot);
int element_compare_n_to_m(elem e1, elem e2, int n, int m);
int element_compare(void* e1, void* e2);
void element_print(elem e);
char element_get(elem e, int i);
void element_delete(void* e);
int element_length(elem e);
void* element_copy(void* e);
elem element_copy_n(elem e, int n);

#endif