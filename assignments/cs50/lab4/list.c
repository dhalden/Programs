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
/*
typedef struct ListNode {
    WebPage *page;                           // the data for a given page
    struct ListNode *prev;                   // pointer to previous node
    struct ListNode *next;                   // pointer to next node
} ListNode;

typedef struct List {
    ListNode *head;                          // "beginning" of the list
    ListNode *tail;                          // "end" of the list
} List;
*/
// ---------------- Public Variables

// ---------------- Prototypes/Macros
List * initialize()
{
	List *list;
	list.head = NULL;
	list.tail = NULL;
	return list;
}

List * addToTail(List * list, ListNode *node)
{
	if(!list.head) {
		list.head = node;
		list.tail = node;
	}
	else {
		list.tail.next = node;
		node.prev = list.tail;
		node.next = NULL;
		list.tail = node;
	}
	return list;
}

ListNode * popHead(List *list)
{

	if(!list.head) {
		return NULL;
	}
	else {
		ListNode *temp;
		temp = list.head;
		list.head = list.head.next;
		return temp;
	}
}
