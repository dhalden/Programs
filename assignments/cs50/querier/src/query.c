/* ========================================================================== */
/* * File: query.c 
 * Author: Derek Halden
 *
 * Project name: CS50 Tiny Search Engine
 * Component name: Querier 
 *
 * This will search for given search terms
 * Example input:
 * ./querier ../../crawler/data/ ../../indexer/index.dat
 */
/* ========================================================================== */
#define MAX_CLEN 2049
 
 #include "query.h"

 int main(int argc, char *argv[]){
 	//check for correct args
 	if (argc != 3){
 		fprintf(stderr, "Error: Incorrect number of arguments\n");
 		return 1;
 	}
 	if (!IsFile(argv[1])){
 		fprintf(stderr, "Error: file not found for index data\n");
 		return 1;
 	}
 	if(!IsDir(argv[2])){
 		fprintf(stderr, "Error: Directory not found for crawler data\n");
 		return 1;
 	}

 	//rebuild sorted version of index.dat
 	WordList *alpha = malloc(sizeof(WordList));
 	alpha->head=NULL;
 	WordTable *wt = RemakeIndex(argv[1], alpha);
 	char input[2048];
	printf("\nQUERY:>");
	fgets(input, sizeof(input), stdin);
	// This was given as the input for the last output in the example
	// I'm assuming that you meant control+z, but I decided to make it
	// the exit function 
 	while((strcmp(input, "^Z\n"))){
	 	InputQueries *iq = parseInput(input);
	 	InputQueries *next;
 		QueryList *ql2= malloc(sizeof(QueryList));	
 		ql2->head = NULL;
 		ql2->len = 0;
 		next = iq;
 		// Each run through this loop is the equivolent of an "OR"
 		// everything run inside the loop is the equivolent of an "AND"
	 	while(next){
	 		QueryList *ql1= malloc(sizeof(QueryList));	
	 		ql1->head = NULL;
	 		ql1->len = 0;
	 		//add each url containing the first word in it, to the list.
	 		ql1->len += addURLS(next->ands[0], wt, ql1, argv[2]);

	 		//An "AND" is just an intersection, so we can choose a word at 
	 		//random, and have that be the total set, then remove from that
	 		//set anything that's not in the other sets.
	 		int i;
	 		for(i=1; i < next->queries; i++){
		 		ql1 = filterURLS(next->ands[i], wt, ql1);
	 		}
	 		next = next->or;
	 		//add each url not already in the print list into the print list.
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
		 		//printf("this happens\n");
		 		//fflush(stdout);
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
	 	printf("\nQUERY:>");
	 	fgets(input, sizeof(input), stdin);
 	}
 	FreeIndex(wt, alpha);
 	free(alpha);
 	free(wt);

 }

