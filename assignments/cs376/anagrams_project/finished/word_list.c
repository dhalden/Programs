#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// by including your own header, you automatically include function
// prototypes
#include "word_list.h"

// struct which makes up each node in the list
struct Node{
   char word[55];
   struct Node *next;
   int compareValue;
}; 

// struct to manage a basic linked list
struct WordList{
   struct Node *head;
   struct Node *tail;
   int size;
};

WordList * wlist_create()
{
   WordList * retval = malloc(sizeof(WordList));
   retval->head = 0;
   retval->tail = 0;
   retval->size = 0;
   return retval;
}

int wlist_insert(WordList *wlist, char * word, int *value)
{
   struct Node *current = malloc(sizeof(Node));
   current->next = 0;
   strcpy(current->word,word);
   current->compareValue = value;
   if(wlist->head == 0)
   {
	wlist->head = current;
	wlist->tail = current;
   }
   else
   {
	//Node *end = wlist->tail;
	wlist->tail->next = current;
	wlist->tail = current; 
   }
   wlist->size++;
   return 1;
}

int wlist_size(WordList *wlist)
{
	if(wlist == 0)  // testing for null pointer
	{
		return -1;
	}
	else
	{
		return wlist->size;
	}
}

void wlist_print(WordList *wlist)
{
   struct Node *current;
   if(wlist->head) // same as testing if != 0
   {
	current = wlist->head;
	while(current)
	{
	   printf("%s\t",current->word);
	   current = current->next;
	}
	printf("\n");
   }
}
