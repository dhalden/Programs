/* ========================================================================== */
/* File: list.c
 *
 * Project name: CS50 Tiny Search Engine
 * Component name: Crawler
 *
 * This file contains the definitions for a doubly-linked list of WebPages.
 *
 */
/* ========================================================================== */

// ---------------- Prerequisites e.g., Requires "math.h"
#include "common.h"                          // common functionality

// ---------------- Constants

// ---------------- Structures/Types

// ---------------- Public Variables

// ---------------- Prototypes/Macros
List * initialize()
{
	List *list;
	list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void addToTail(List * list, struct WebPage *page)
{
	ListNode *node;
	node=malloc(sizeof(ListNode));
	node->page = page;
	node->next = NULL;
	node->prev = NULL;
	if(!list->head) {
		list->head = node;
		list->tail = node;
	}
	else {
		list->tail->next = node;
		node->prev = list->tail;
		node->next = NULL;
		list->tail = node;
	}
}

WebPage * popHead(List *list)
{

	if(!list->head) {
		return NULL;
	}
	else {
		ListNode *temp;
		temp = list->head;
		list->head = temp->next;
		WebPage *page = malloc(sizeof(WebPage));
		page = temp->page;
		free(temp);
		temp=NULL;
		return page;
	}
}
ListNode *peak(List *list)
{
	return list->head;
}

void cleanupList(List *list)
{	
	ListNode *node = list->head;
	while(node){
		free(node->page->url);
		list->head = node->next;
		free(node->page);
		free(node);
		node = list->head;
	}	
	list->tail = NULL;
	list->head = NULL;
	free(list);
	list = NULL;
}
