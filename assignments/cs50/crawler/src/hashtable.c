/* ========================================================================== */
/* File: hashtable.c
 *
 * Project name: CS50 Tiny Search Engine
 * Component name: Crawler
 *
 * Author:
 * Date:
 *
 * You should include in this file your functionality for the hashtable as
 * described in the assignment and lecture.
 */
/* ========================================================================== */

// ---------------- Open Issues

// ---------------- System includes e.g., <stdio.h>
#include <string.h>                          // strlen

// ---------------- Local includes  e.g., "file.h"
#include "../../crawler/src/common.h"                          // common functionality
#include "hashtable.h"                       // hashtable functionality

// ---------------- Constant definitions

// ---------------- Macro definitions

// ---------------- Structures/Types

// ---------------- Private variables

// ---------------- Private prototypes

unsigned long JenkinsHash(const char *str, unsigned long mod)
{
    size_t len = strlen(str);
    unsigned long hash, i;

    for(hash = i = 0; i < len; ++i)
    {
        hash += str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % mod;
}


//Create a new HashTable and initialize all of the heads of linked lists.
HashTable * initializeTable()
{
    HashTable *list;
    if(!(list = calloc(sizeof(HashTable), 1))){
        perror("Memory");
    }
    return list;
}

//Add HashTable Node to head of array of Linked-Lists
int addNode(HashTable *list, char *url)
{
    printf("this happens\n");
    int hash = JenkinsHash(url, MAX_HASH_SLOT);
    if(!list->table[hash])
    {
        HashTableNode *htn = makehtn(url);
        list->table[hash] = htn;
        list->in++;
        return list->in;
    }
    HashTableNode *temp = list->table[hash];
    while(temp->next && !strcmp(temp->url, url)){
        temp = temp->next;
    }
    if(!strcmp(temp->url, url))
    {
        return 0;
    }
    else
    {
        HashTableNode *htn = makehtn(url);
        temp->next = htn;
        list->in++;
        return list->in;
    }
}

HashTableNode *makehtn(char *url)
{ 
    HashTableNode *htn = calloc(sizeof(HashTableNode), 1);
    htn->url = calloc(MAX_URL*sizeof(char), 1);
    strcpy(htn->url, url);
    htn->next = NULL;
    return htn;
}

//Free all of the Memory Allocated by the HashTable
void cleanupTable(HashTable *urls)
{
    HashTableNode *temp;
    HashTableNode *curr;
    int i;
    for(i = 0; i < MAX_HASH_SLOT; i++)
    {
        curr = urls->table[i];
        if(curr){

            while(curr->next)
            {
                temp= curr->next;
                free(curr->url);
                free(curr);
                curr = temp;
            }
            free(curr->url);
            free(curr);
        }
    } 
    free(urls);
}

