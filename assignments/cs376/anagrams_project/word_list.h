#ifndef WORD_LIST_H
#define WORD_LIST_H

typedef struct WordList WordList;
typedef struct Node Node;

// Create a list of words
WordList *wlist_create();

// Insert an element (currently at the tail)
int wlist_insert(WordList *wlist, char *word);

// Request the size of the list
int wlist_size(WordList *wlist);

// Retrieve the word at that index
char * wlist_index(WordList *wlist, int i);

// Print the words in the list
void wlist_print(WordList *wlist);

#endif // WORD_LIST_H
