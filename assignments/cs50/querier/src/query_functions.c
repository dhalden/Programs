#include "query_functions.h"
//Convert each line of input into an "InputQuery" which is an easy to handle
//format for all queries.
//parses into an array for ANDs, and a linked list for ORs
 InputQueries * parseInput(char *input)
 {
 	InputQueries *iq;
 	iq = calloc(1, sizeof(InputQueries));
 	char word[MAX_CLEN];
 	char input2[MAX_CLEN];

	sscanf(input,"%s %[^\n]", word, input2);
	if(!strcmp(word, "AND") || !strcmp(word, "OR")){
		printf("Error: Incorrect placement of keyword (AND or OR)\n");
		releaseMem(iq);
		return NULL;
	}

 	if(sscanf(input, "%[^OR^\n] OR %[^\n]", word, input2) == 2){
 		//printf("input2:%s word:%s\n",input2, word);
 		iq->or = parseInput(input2);
 		strcpy(input, word);
 	}
 	else{
 		iq->or = NULL;
 	}
	int i=0;
	int and=0;
 	while (sscanf(input,"%s %[^\n]", word, input) == 2)
 	{
 		if(!strcmp(word, "AND")){
 			if(!and){
	 			and++;
	 			continue;
 			}
 			else{
 				printf("\nError: with query input, 'AND AND'\n");
 				releaseMem(iq);
 				return NULL;
 			}
 		}
 		else and = 0;
 		NormalizeWord(word);
 		iq->ands[i] = malloc(sizeof(word)+1);
 		strcpy(iq->ands[i++], word);
 	}
 	if(!strcmp(word, "AND")){
		printf("Error: Incorrect placement of keyword (AND or OR)\n");
		releaseMem(iq);
 		return NULL;
 	}
 	else{
 		NormalizeWord(word);
 		iq->ands[i] = malloc(sizeof(word)+1);
 		strcpy(iq->ands[i++], word);
 	}
	iq->queries = i;
 	return iq;
 }

//Frees everything created by an input query
 int releaseMem(InputQueries *iq)
 {
 	int i;
 	for(i=0; i < iq->queries; i++){
 		if(iq){
	 		free(iq->ands[i]);
 		}
 		else{
 			return 0;
 		}
 	}
 	if(iq->or){
	 	releaseMem(iq->or);
 	}
 	free(iq);
 	return 1;
 }

 // output everything found by the query.
 // doubles as my way of freeing the linked-list that contains the urls
 // p is a variable that determines whether or not to print output
 int printQL(QueryList *ql, int p)
 {
 	QueryNode *qn = ql->head;
 	while(qn){
 		if (p){
	 		printf("Document ID:%d URL:%s\n", qn->docId, qn->url);
 		}
 		ql->head = qn->next;
 		free(qn);
 		qn = ql->head;
 	}
 	return 1;
 }

 //add URLs in order of frequency
 int addURLS(char *word, WordTable *wt, QueryList *ql, char *file_name)
 {
 	DocumentNode *dn;
 	long hash = JenkinsHash(word, MAX_HASH_SLOT);
 	WordNode *wn = wt->table[hash];
 	int len = 0;
	while(wn){
		if(!strcmp(wn->word, word)){
			dn = wn->page;	
			while(dn){
 				//get URL from file
		 		char *fname = malloc(MAX_CLEN*sizeof(char));
		 		char url[MAX_CLEN];
 				sprintf(fname, "%s%d",file_name, dn->doc_id);
 				FILE *urlFile = fopen(fname, "r");
	 			fgets(url, sizeof(url),  urlFile);
 				fclose(urlFile);
	 			sscanf(url, "%[^\n]", url);

 				addQL(ql, url, dn->freq, dn->doc_id);
 				dn = dn->next;
 				len++;
 				free(fname);
 			}
 			return len;
		}	
		wn= wn->next;
	}
	return len;
 }

 // remove any urls not containing the given word
 QueryList * filterURLS(char *word, WordTable *wt, QueryList *ql)
 {
 	DocumentNode *dn;
 	long hash = JenkinsHash(word, MAX_HASH_SLOT);
 	WordNode *wn = wt->table[hash];
 	QueryList *nql = malloc(sizeof(QueryList));
 	nql->head = NULL;
 	if(!ql->head){
 		return 0;
 	}
 	int count = 0;
	while(wn){
		if(!strcmp(wn->word, word)){
			dn = wn->page;	
			while(dn){
 				//get URL from file
				QueryNode *search = ql->head;
 				while(search){
 					if(search->docId == dn->doc_id){
 						addQL(nql, search->url, search->rank + dn->freq, search->docId);
 						count++;
 						break;
 					}
 					search = search->next;
 				}
 				dn = dn->next;
 			}
		}	
		wn=wn->next;
	}
	printQL(ql, 0);
	free(ql);
	nql->len = count;
	return nql;

 }

 // add in order to the Query list
 int addQL(QueryList *ql, char *url,  int freq, int docId)
 {
 	QueryNode *qn = MakeQN(freq, url, docId);
 	if(!ql->head){
 		ql->head = qn;
 		return 1;
 	}

 	QueryNode *temp;
 	temp = ql->head;
 	if(!temp->next){
 		if(qn->rank > temp->rank)
 		{
	 		qn->next = temp;
 			ql->head = qn;
 			return 1;
 		}
 		else{
 			temp->next = qn;
 			return 1;
 		}
 	}
 	if(temp->rank > qn->rank){
		qn->next = temp;
		ql->head = qn;
		return 1;
	}
	while(temp->next && freq < temp->next->rank){
			temp = temp->next;
	}
	if(!temp->next){
		temp->next = qn;
		return 1;
	}
	else if(freq >= temp->next->rank){
		qn->next = temp->next;
		temp->next = qn;
		return 1;
	}
	return 0;

 }

//make a query node. I found this easier to just return;
QueryNode *MakeQN(int freq, char* url, int docId){
	//printf("this happens\n");
	QueryNode *qn = calloc(1, sizeof(QueryNode));
	qn->rank = freq;
	qn->docId = docId;
	strcpy(qn->url, url);
	qn->next = NULL;
	return qn;
}
