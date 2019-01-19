//
// Created by amichai on 19/01/19.
//

#ifndef MARATHON_MATAM_ITAI_LIBRARY_H
#define MARATHON_MATAM_ITAI_LIBRARY_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* part a */
typedef struct library* Library;

Library LibraryCreate(void*(*copy)(void*), void(*freeElement)(void*), const char* (*getName)(void*));
void LibraryDestroy(Library l);
bool LibraryAddElement(Library l, void *element);
bool LibraryRemoveElement(Library l, const char *name);
void* LibraryGetElement(Library l, const char *name);
void LibrarySortPrintByField(Library l, bool(*isBigger)(void*)(void*));
int LibraryGetNumberOfElements(Library l);

#endif //MARATHON_MATAM_ITAI_LIBRARY_H


/* part b */
#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector* Vector;
typedef void* VElement;
Vector VectorCreate(int vector_size);
void VectorDestroy(Vector v);
void VectorPut(Vector v, int index, VElement velement);
VElement VectorGet(Vector v, int index); // Get the element but do not remove
VElement VectorRemove(Vector v, int index);// Get the element and remove from v
int VectorSize(Vector v);
void VectorResize(Vector v, int newSize);

#endif


struct library {
    Vector library;
    void* (*copy)(void*);
    void (*freeElement)(void*);
    const char* (*getName)(void*);
};


Library LibraryCreate(void*(*copy)(void*), void(*freeElement)(void*), const char* (*getName)(void*)) {
    Library l = (Library) malloc (sizeof(Library));
    l->library = VectorCreate(0);
    l->copy = copy;
    l->freeElement = freeElement;
    l->getName = getName;
    return l;
}


bool LibraryAddElement(Library l, void *element) {
    int i;
    for (i=0; i<VectorSize(l->library); i++) {
        if (strcmp(VectorGet(l->library, i), l->getName(element)) == 0) {
            return false;
        }
    }
    VectorResize(l->library, VectorSize(l->library)+1);
    VectorPut(l->library, VectorSize(l->library), element);
    return true;
}
