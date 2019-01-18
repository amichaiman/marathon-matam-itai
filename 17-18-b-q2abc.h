//
// Created by amichai on 19/01/19.
//

#ifndef MARATHON_MATAM_ITAI_DICTIONARY_H
#define MARATHON_MATAM_ITAI_DICTIONARY_H

#include <string.h>
#include <stdlib.h>
#include "BSTree.h"
/* part a */
typedef struct dictionary* Dictionary;

Dictionary DictionaryCreate();
void DictionaryDestroy(Dictionary d);
bool DictionaryAddWord(Dictionary d, char* word, char* explanation);
void DictionaryRemoveWord(Dictionary d, char* word);
char *DictionaryGetWordExplenation(Dictionary d, char *word);
int DictionaryGetWordsThatBeginWith(Dictionary d, char *sequence, char **array);
int DictionaryGetNumberOfWords(Dictionary d);

/* part b */
struct dictionary {
    BSTree dictionary;
};

typedef struct dictionaryWord {
    char *word;
    char *explenation;
} *DictionaryWord;

bool is_greater(void* a, void* b) {
    return strcmp(((DictionaryWord)a)->word, ((DictionaryWord)b)->word) > 0;
}

Dictionary DictionaryCreate() {
    Dictionary d = (Dictionary) malloc (sizeof(Dictionary));
    d->dictionary = BSTCreate(is_greater);
    return d;
}

bool DictionaryAddWord(Dictionary d, char* word, char* explanation) {
    DictionaryWord newWord = (DictionaryWord) malloc (sizeof(DictionaryWord));
    newWord->word = (char*) malloc (sizeof(char)*strlen(word));
    newWord->explenation = (char*) malloc (sizeof(char)*strlen(explanation));
    strcpy(newWord->word, word);
    strcpy(newWord->explenation, explanation);

    if (BSTSearchNode(d->dictionary, newWord) != NULL) {
        return false;
    }
    BSTAddNode(d->dictionary, newWord);
    return true;
}

#endif //MARATHON_MATAM_ITAI_DICTIONARY_H

