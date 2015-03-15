/* ========================================================================== */
/* File: indexer.c 
 *
 * Project name: CS50 Tiny Search Engine
 * Component name: Indexer
 *
 * This will index all of the files created in the previous assignment.
 */
/* ========================================================================== */

#include <stdio.h>	
#include <stdlib.h>                          // free, calloc
#include <string.h>                          // strlen, strcpy
#include <unistd.h>
#include "indexer.h"

#define MAX_LINE 2050


 int main(int argc, char *argv[])
 {
 	if(argc < 3){
 		fprintf(stderr, "Error: not enough arguments provided\n");
 		return 1;
 	}

 	if(!IsDir(argv[1])){
 		fprintf(stderr, "Error: Could not resolve input to a directory\n");
 		return 1;
 	}


 	int docId;
	int pos;
	char *word;
	char *doc;
	//alphabetical list of words, and their hashes
	WordList *alpha;
	WordTable *index;
	index = calloc(1, sizeof(WordTable));
	alpha = calloc(1, sizeof(WordList));

	char *dir=argv[1];
	char **filenames = NULL;
	int len = GetFilenamesInDir(dir, &filenames);
	char *name;

	name =malloc(MAX_LINE*sizeof(char));
	if(len <= 0){
		fprintf(stderr, "Error: Files Not Found in provided directory\n");
		return 1;
	}

	int i;
	for (i=0; i < len; i++) {
		sprintf(name, "./%s/%s", argv[1], filenames[i]);
	    docId = GetDocumentId(filenames[i]);
	    doc = LoadDocument(name);

	    pos = 0;
	    while ((pos = GetNextWord(doc, pos, &word)) > 0){
	    	NormalizeWord(word);
	    	UpdateIndex(word, docId, index, alpha);
	    }
	    free(doc);
	    free(filenames[i]);
	}

 	FILE *wfile;
 	wfile = fopen(argv[2], "w");
	SaveIndexToFile(index, wfile, alpha);
	fclose(wfile);
	//printf("this happens\n");
	free(filenames);
	free(index);
	free(name);
	free(alpha->head);
	free(alpha);

	if(argc == 5){
		WordList *nalpha;
		nalpha = calloc(1, sizeof(WordList));
		char *rfile=calloc(MAX_LINE, sizeof(char));
		strcpy(rfile, argv[3]);
		WordTable *nindex = RemakeIndex(rfile, nalpha);
	 	FILE *nwfile;
	 	nwfile = fopen(argv[4], "w");
		SaveIndexToFile(nindex, nwfile, nalpha);
		fclose(nwfile);		
		free(nindex);
		free(rfile);
		free(nalpha->head);
		free(nalpha);
	}
	else if(!((argc == 3) || (argc == 5))){
		fprintf(stderr, "Error: Invalid number of arguments greater than 3\n");
		return 1;
	}

	return 0;
 }

//assumes the name given is a document that exists
 char* LoadDocument(char *name){
 	FILE *rfile;
 	rfile = fopen(name, "r");
 	fseek(rfile, 0, SEEK_END);
 	int size = ftell(rfile);
 	fseek(rfile, 0, SEEK_SET);
 	if (rfile == NULL){
 		fprintf(stderr, "Error: can't open input file!\n");
 		exit(1);
 	}
 	char *strfile=calloc(1, size+1);
 	if(!strfile){
 		fclose(rfile);
 		fprintf(stderr, "Error: memory alloc failed");
 		exit(1);
 	}
 	fread(strfile, 1, size, rfile);
 	char *url = calloc(MAX_LINE, sizeof(char));
 	sscanf(strfile, "%s\n%[^\a]", url, strfile);
 	fclose(rfile);
 	free(url);
 	return strfile;
 }

//Assumes that the second line of the file contains only the number
// needs to be tested
 int GetDocumentId(char *name){
 	int docid = 0;
 	sscanf(name, "%d", &docid);
 	return docid;	
 }


 int UpdateIndex(char *word, int docId, WordTable *index, WordList *alpha){
 	long hash = JenkinsHash(word, MAX_HASH_SLOT);	
 	WordNode *w = makeWordNode(word, 1);
 	DocumentNode *d = makeDocumentNode(1, docId);

    //printf("word: %s\n", word);
 	WordNode *wtemp=NULL;
 	wtemp = index->table[hash];
 	if(!wtemp){
 		w->page = d;
 		index->table[hash]=w;
		goto addAlpha;
 	}
 	if(!wtemp->next && strcmp(wtemp->word, word)){
 		if(strcmp(wtemp->word, word)){
	 		w->page = d;
 			index->table[hash]->next=w;
			goto addAlpha;

 		}
 		else{
 			goto check_dtemps;	
 		}

 	}

 	//Deal with collisions in word table
 	while(wtemp->next && strcmp(wtemp->word, word)){
 		wtemp = wtemp->next;
 	}
 	if(wtemp->word && !strcmp(wtemp->word, word)){
		// deal with collisions in Document list
		check_dtemps: printf("");
 		DocumentNode *dtemp=NULL;
 		dtemp = wtemp->page;
		while(dtemp->next && dtemp->doc_id != docId){
 			dtemp = dtemp->next;
 		}
 		if(dtemp->doc_id == docId){
	 		dtemp->freq++;		
	 		free(d->next);
	 		free(d);
 		}
 		else {
 			dtemp->next = d;
 			wtemp->docs++;
 		}

 		free(w->next);
 		free(w->word);
 		free(w);
 		return 1;
 	} 
 	else if(!wtemp) {
 		w->page = d;
 		wtemp = w;
 	}
 	else{
 		w->page = d;
 		wtemp->next = w;
 	}
	addAlpha: printf("");
	Node *n = makeNode(word);
 	//The word hasn't been added to the hashtable
 	return addAlphaList(n, alpha);
 }

int addAlphaList(Node *n, WordList *alpha)
{
	if(!alpha->head){
		alpha->head = n;
		return 1;
	}
	if(!alpha->head->next){
		if(strcmp(alpha->head->word, n->word) < 0) {
			alpha->head->next = n;
			return 1;
		}
		else {
			n->next = alpha->head;
			alpha->head = n;
			return 1;
		}
	}

	Node *temp;
	temp = alpha->head;
	if(strcmp(temp->word, n->word) > 0){
		alpha->head = n;
		alpha->head->next = temp;
		return 1;
	}
	while(temp->next && strcmp(temp->next->word, n->word) < 0){
		temp = temp->next;
	}

	if(temp->next && strcmp(temp->next->word, n->word) == 0)
	{
		if(temp->next){
			fprintf(stderr, "ERROR: DUPLICATE WORD %s\n", n->word);
			free(temp);
			exit(1);
		}
		else{
			temp->next = n;
			return 1;
		}
	}

	n->next = temp->next;
	temp->next = n;
	return 1;
}

// Receives as input the index of words, as well as the file to write to.
// Lastly, receives the alphabetical list of words that I have created
// Also cleans up all of the allocated space that we have created
int SaveIndexToFile(WordTable *index, FILE *wfile, WordList *alpha){
	while(alpha->head != NULL){
		long h = alpha->head->hash;
		fprintf(wfile, "%s", alpha->head->word);
		//printf("%s", alpha->head->word);
		//printf("next: %s \n", alpha->head->next->word);
		WordNode *temp;
		temp = index->table[h];

		//word is found at the head of the Linked List;
		fflush(stdout);
	    //printf("freq: %d\n", temp->docs);
		if(temp && !strcmp(temp->word, alpha->head->word)){
			DocumentNode *dtemp;
			dtemp = temp->page;
			//printf(" %d", temp->docs);
			//printf("word: %s\n", temp->word);
			fprintf(wfile, " %d", temp->docs);
			do
			{
				DocumentNode *curr;
				fprintf(wfile, " %d %d", dtemp->doc_id, dtemp->freq);
				//printf("docs: %d\n", temp->docs);
				//printf("doc_id: %d freq: %d\n", dtemp->doc_id, dtemp->freq);
				curr = dtemp->next;
				free(dtemp);
				dtemp = curr;
				curr = NULL;
			} while(dtemp);
			free(dtemp);
			index->table[h] = temp->next;
			free(temp->word);
			free(temp);
		}
		else {
			//If the Node is somewhere in the middle of the Linked list
			while(temp->next && strcmp(temp->next->word, alpha->head->word)){
				temp = temp->next;
			}
			fprintf(wfile, " %d", temp->next->docs);
			DocumentNode *dtemp;

			dtemp = temp->next->page;
			//printf(" %d ", temp->next->docs);
			//printf("word: %s\n", temp->next->word);
			do
			{
				DocumentNode *curr;
				fprintf(wfile, " %d %d", dtemp->doc_id, dtemp->freq);
				///printf(" %d %d", dtemp->doc_id, dtemp->freq);
				curr = dtemp->next;
				free(dtemp);
				dtemp = curr;
				curr = NULL;
			} while(dtemp);
			free(dtemp);
			WordNode *wtemp= temp->next;
			temp->next = wtemp->next;
			free(wtemp->word);
			free(wtemp);
		}
		fprintf(wfile, "\n");
		//printf("\n");
		Node *newHead = alpha->head->next;
		free(alpha->head);
		alpha->head = newHead;
	}
	return 1;
}

WordTable * RemakeIndex(char *fname, WordList * alpha){
	if(!IsFile(fname)){
		fprintf(stderr, "Error: invalid data file\n");
		exit(1);
	}

	WordTable *index = calloc(1, sizeof(WordTable));

	//open file
	FILE *rfile = fopen(fname, "r");
	//declare variables
	char line[MAX_LINE];
	int len=0;
	int doc_id=0;
	int freq=0;

	while(fgets(line, sizeof(line), rfile)){
		char *word = getWordIndex(line, &len);
		if(len == 0){
			fprintf(stderr, "Error: File is in incorrect format\n");
			exit(1);
		}
		Node *temp = makeNode(word);
		addAlphaList(temp, alpha);

		WordNode *w = makeWordNode(word, len); 
		DocumentNode *d;
		sscanf(line, "%d %d %[^\n]\n", &doc_id, &freq, line);
		d = makeDocumentNode(freq, doc_id); 
		addDocumentNode(d, w);

		WordNode *newwn = index->table[temp->hash];
		if(newwn){
			while(newwn->next){
				newwn = newwn->next;	
			}
			newwn->next = w;
		}
		else {
			index->table[temp->hash] = w;
		}

		int i;
		for(i=1; i < len; i++){
			sscanf(line, "%d %d %[^\n]\n", &doc_id, &freq, line);
			DocumentNode *nextDN = makeDocumentNode(freq, doc_id);
			addDocumentNode(nextDN, w);
		}

	}
	fclose(rfile);

	return index;
}
int addDocumentNode(DocumentNode *d, WordNode *w){

	if(!w->page){
		w->page = d;
		return 1;
	}
	if(!w->page->next){
		if(w->page->freq > d->freq) {
			w->page->next = d;
			return 1;
		}
		else {
			d->next = w->page;
			w->page = d;
			return 1;
		}
	}

	DocumentNode *temp;
	temp = w->page;
	printf("temp->freq: %d, d->freq: %d\n", temp->freq, d->freq);
	if(temp->freq < d->freq){
		d->next = temp;
		w->page = d;
		return 1;
	}
	while(temp->next && temp->next->freq > d->freq){
		temp = temp->next;
	}
	if(!temp->next){
		temp->next = d;
		return 1;
	}
	else{
		d->next = temp->next;
		temp->next = d;
	}
	return 1;	
}

DocumentNode * makeDocumentNode(int freq, int doc_id)
{
			DocumentNode *dtemp = malloc(sizeof(DocumentNode));
			dtemp->freq = freq;
			dtemp->doc_id = doc_id;
			dtemp->next = NULL;
			return dtemp;
}

WordNode * makeWordNode(char *word, int docs)
{
		WordNode *w= calloc(1, sizeof(WordNode));
		w->word = word;
		w->docs = docs;
		w->next = NULL;
		w->page = NULL;
		return w;
}

Node * makeNode(char *word)
{
	Node *head = malloc(sizeof(Node));
	head->word = word;
	head->hash = JenkinsHash(word, MAX_HASH_SLOT);
	head->next = NULL;	
	return head;
}

char * getWordIndex(char *line, int *len)
{
	char *word=calloc(1, 200*sizeof(char));
	sscanf(line, "%s %d %[^\n]\n", word, len, line);
	return word;
}

