//
// Created by amichai on 21/01/19.
//

#ifndef MARATHON_MATAM_ITAI_DOUBLE_LINKED_LIST_H
#define MARATHON_MATAM_ITAI_DOUBLE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

/* a */
typedef struct linked_list* LinkedList;
typedef void* Elem;

LinkedList LinkedListCreate(int(*compare)(Elem,Elem), Elem(*clone)(Elem), void(*fre)(Elem));
void LinkedListDestroy(LinkedList list);
bool LinkedListAdd(LinkedList list, Elem elem);
bool LinkedListFind(LinkedList list, Elem elem);
bool LinkedListRemove(LinkedList list, Elem elem);
int LinkedListSize(LinkedList list);
Elem LinkedListGet(LinkedList list, int n);

/* b */

typedef struct node {
    struct node* next;
    struct node* prev;
    Elem key;
} Node;

struct linked_list{
    Node *head;
    int(*compare)(Elem, Elem);
    Elem(*clone)(Elem);
    void(*fre)(Elem);
};

LinkedList LinkedListCreate(int(*compare)(Elem,Elem), Elem(*clone)(Elem), void(*fre)(Elem)) {
    LinkedList l = (LinkedList) malloc (sizeof(LinkedList));
    l->head = NULL;
    l->compare = compare;
    l->clone = clone;
    l->fre = fre;
}


/* c */

bool LinkedListRemove(LinkedList list, Elem elem) {
    Node* cur;
    Node* to_remove;

    if (list->compare(list->head->key, elem) == 0) {
        to_remove = list->head;
        list->head = to_remove->next;
        list->head->prev = NULL;
        list->fre(to_remove->key);
        free(to_remove);
        return true;
    }

    for (cur=list->head; cur->next && cur->next != NULL; cur=cur->next) {
        if (list->compare(cur->next->key, elem) == 0) {
            to_remove = cur->next;
            cur->next = to_remove->next;
            to_remove->next->prev = cur;
            list->fre(to_remove->key);
            free(to_remove);
            return true;
        }
    }
    return false;

}

#endif //MARATHON_MATAM_ITAI_DOUBLE_LINKED_LIST_H
