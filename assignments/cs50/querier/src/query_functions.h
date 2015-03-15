#ifndef QUERY_FUNCTIONS_H
#define QUERY_FUNCTIONS_H

#include <stdio.h>	
#include <stdlib.h>                          // free, calloc
#include <string.h>                          // strlen, strcpy
#include <unistd.h>
#include "../../utils/web.h"
#include "../../utils/file.h"
#include "../../utils/hashtable.h"
#include "../../utils/indexer.h"

#define MAX_CLEN 2049
typedef struct InputQueries{
 	char *ands[MAX_CLEN];
 	int queries;
 	struct InputQueries *or;
 }InputQueries;
 typedef struct QueryNode{
 	int docId;
 	int rank;
 	char url[MAX_CLEN];
 	struct QueryNode *next;
 }QueryNode;

 typedef struct QueryList{
 	struct QueryNode *head;
 	int len;
 }QueryList;



InputQueries * parseInput(char *input);
int releaseMem(InputQueries *iq);
int printQL(QueryList *ql, int print);
int addURLS(char *word, WordTable *wt, QueryList *ql, char *file_name);
QueryList * filterURLS(char *word, WordTable *wt, QueryList *ql);
int addQL(QueryList *ql, char *url, int freq, int docId);
QueryNode *MakeQN(int freq, char* url, int docId);
#endif // QUERY_H
