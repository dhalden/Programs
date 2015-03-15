#include "units.h"
int main(){

 	WordList *alpha = malloc(sizeof(WordList));
 	alpha->head=NULL;
 	WordTable *wt = RemakeIndex(INDEX_FILE, alpha);

	int j;
 	for(j=0; j < 4; j++){
	 	char msg[80];
 		if(j == 0) strcpy(msg, QUERY1);
 		if(j == 1) strcpy(msg, QUERY2);
 		if(j == 2) strcpy(msg, QUERY3);
 		if(j == 3) strcpy(msg, QUERY4);
 		if(j == 4) strcpy(msg, QUERY5);
 		if(j == 5) strcpy(msg, QUERY6);
 		if(j == 6) strcpy(msg, QUERY7);
 		InputQueries *iq = parseInput(msg);
 		InputQueries *next;
		QueryList *ql2= malloc(sizeof(QueryList));	
		ql2->head = NULL;
 		ql2->len = 0;
 		next = iq;
		while(next){
			QueryList *ql1= malloc(sizeof(QueryList));	
			ql1->head = NULL;
			ql1->len = 0;
			//add each url containing the first word in it, to the list.
			ql1->len += addURLS(next->ands[0], wt, ql1, DATA_FOLDER);
	 		//if not the first word, remove each item that doesn't contain
			int i;
	 		for(i=1; i < next->queries; i++){
		 		ql1 = filterURLS(next->ands[i], wt, ql1);
	 		}
	 		next = next->or;
	 		if(ql1->len > 0){
	 			QueryNode *qn;
		 		qn = ql1->head;
		 		while(qn){
		 			QueryNode *qn2;
		 			qn2 = ql2->head;
		 			int check=0;
		 			while(qn2){
		 				if(qn2->docId == qn->docId){
		 					qn2->rank += qn->rank;
		 					check = 1;
		 					break;
		 				}
		 				qn2 = qn2->next;
		 			}
		 			if(!check){
			 			addQL(ql2, qn->url, qn->rank, qn->docId);
		 			}
		 			//sleep(1);
	 				qn = qn->next;
		 		}
		 		ql2->len += ql1->len;
		 		printQL(ql1, 0);
 			}	
 			free(ql1);
 		}
 	//remake querylist;

 	if(ql2->len > 0){
	 	// print the accumulated information
	 	// also release the query list
	 	printQL(ql2, 1);
 	}
 	else{
 		printf("\nNo results found.\n");
 	}
 	free(ql2);
	 	//release memory for iq
 	releaseMem(iq);
 	}

	FreeIndex(wt, alpha);
	free(alpha);
 	free(wt);	
}
