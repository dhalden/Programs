#ifndef INDEXER_H
#define INDEXER_H

#include <stdio.h>	
#include <stdlib.h>                          // free, calloc
#include <string.h>                          // strlen, strcpy
#include <unistd.h>
#include "web.h"
#include "file.h"
#include "hashtable.h"


typedef struct Node {
	struct Node *next;
	char *word;
	long hash;
} Node;

typedef struct WordList {
	struct Node *head;
} WordList;

typedef struct DocumentNode {
  struct DocumentNode *next;         // pointer to the next member of the list.
  int doc_id;                        // document identifier
  int freq;                          // number of occurrences of the word
} DocumentNode;

typedef struct WordNode {
  struct WordNode *next;            // pointer to the next word (for collisions)
  char *word;                       // the word
  int docs;
  DocumentNode *page;               // pointer to the first element of the page list.
} WordNode;


typedef struct WordTable {
	WordNode *table[MAX_HASH_SLOT];	
} WordTable;


int addAlphaList(Node *n, WordList *alpha);
int SaveIndexToFile(WordTable *index, FILE *wfile, WordList *alpha);
int FreeIndex(WordTable *index, WordList *alpha);
int UpdateIndex(char *word, int docId, WordTable *index, WordList *alpha);
int GetDocumentId(char *name);
char* LoadDocument(char *name);
int addDocumentNode(DocumentNode *d, WordNode *w);
WordTable * RemakeIndex(char *fname, WordList * alpha);
DocumentNode * makeDocumentNode(int freq, int doc_id);
WordNode *makeWordNode(char *word, int docs);
Node * makeNode(char *word);
char * getWordIndex(char *line, int *len);

#endif //INDEXER_H
