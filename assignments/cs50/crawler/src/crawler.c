/* ========================================================================== */
/* File: crawler.c - Tiny Search Engine web crawler
 *
 * Author: Derek Halden
 * Date: 2/13/15
 *
 * Input: <starting webpage> <depth> <target folder>
 *
 * Output: all webpages above specified depth. They will be stored in the target folder.
 *
 * Error Conditions:
 *
 * Special Considerations:
 *
 */
/* ========================================================================== */
// ---------------- Open Issues

// ---------------- System includes e.g., <stdio.h>
#include <stdio.h>                           // printf

#include <curl/curl.h>                       // curl functionality

// ---------------- Local includes  e.g., "file.h"
#include "hashtable.h"                       // hashtable functionality
#include "crawler.h"
#include "common.h"                          // common functionality
#include "web.h"                             // curl and html functionality
#include "list.h"                            // webpage list functionality
#include "utils.h"                           // utility stuffs

// ---------------- Constant definitions
#define MAX_FOLDER 256
#define MAX_URL 2049

// ---------------- Macro definitions

// ---------------- Structures/Types

// ---------------- Private variables

// ---------------- Private prototypes

/* ========================================================================== */

int main(int argc, char* argv[])
{
    int max_depth=0;
    char seed_url[MAX_URL];
    char str[10];
    char str2[10];
    DIR *dir;
    // check command line arguments
    if(argc != 4){
        fprintf(stderr, "Error: incorrect number of arguments given\n");
        return 1;
    }

    sscanf(argv[2], "%d", &max_depth);
    sscanf(argv[2], "%s", str);
    sprintf(str2, "%d", max_depth);
    int len;
    len = strlen(str);
    str2[len] = '\0';

    if(strcmp(str, str2)){
        fprintf(stderr, "Error: you entered a non-numeric entry for Max Webpage depth\n");
        return 1;
    }
    else if(max_depth > 3) {
        fprintf(stderr, "Error: Maximum Depth exceeded");
        return 1;
    }

    char folder[MAX_FOLDER];
    sscanf(argv[3], "%s", folder);
    dir = opendir(folder);

    if(dir == NULL){
        fprintf(stderr, "Error: directory cannot be found\n");
        return 1;
    }

    closedir(dir);
    // init curl
    curl_global_init(CURL_GLOBAL_ALL);

    // setup seed page
    sscanf(argv[1],"%s",seed_url);

    // get seed webpage
    struct WebPage *seed_wp;
    struct WebPage *new_wp;

    seed_wp = malloc(sizeof(WebPage));
    seed_wp->url = calloc(MAX_URL*sizeof(char),1);
    strcpy(seed_wp->url, seed_url);

    NormalizeURL(seed_wp->url);
    seed_wp->depth = 0;
    GetWebPage(seed_wp);

    // write seed file
    int file_count = 0;

    // add seed page to hashtable

    // Make the HashTable
    // Make the Queue
    HashTable *urls = initializeTable();
    addNode(urls, seed_url);
    List *q;
    q = initialize();
    int curr_depth;
    if(!fileNotFound(seed_wp)){
        fprintf(stderr, "Error: Seed_Url not found");
        return 1;
    }
    else
    {
        goto start;
    }

    // add seed_wp to queue
    // while there are urls to crawl
    // crawl web
    do
    {
        GetWebPage(seed_wp);
        if(!fileNotFound(seed_wp)){
            goto next_webpage;
        }
        start:

        curr_depth = seed_wp->depth + 1;
        char **result=calloc(MAX_URL*sizeof(char*), 1);
        writeToFile(++file_count, seed_wp, folder);
        //printf("%s\n", seed_wp->url);

        int pos = 0;
        int new_pos = 0;
        // get next url from list
        new_pos=GetNextURL(seed_wp->html, pos, seed_wp->url, result);
        //printf("[crawler]: Parser found link - %s", *result);
        while(pos < new_pos){
            char* str = calloc(MAX_URL*sizeof(char), 1);
            strcpy(str, *result);
            // add seed page to hashtable
            if(!strstr(str, "http://shop.tcgplayer.com/magic/")){
                //printf("wp: %s\n", *result);
                goto url_exists;
            }

            if(strstr(str, "#")){
                sscanf(str, "%[^#]#%[^#]", *result, seed_url);
            }

            if(!addNode(urls, str))
            {
                goto url_exists;
            }
            new_wp = makeWebPage(str, curr_depth);
            addToTail(q, new_wp);

            url_exists:
            // get next url from list
            pos = new_pos;
            // extract urls from webpage
            free(str);
            str = NULL;
            new_pos=GetNextURL(seed_wp->html, pos, seed_wp->url, result);
        } 
        next_webpage:
        free(seed_wp->url);
        free(seed_wp->html);
        free(seed_wp);
        seed_wp = NULL;
        // get webpage for url
        //sleep(1);
        seed_wp = popHead(q);
        if (result) {
            free(result);
            result = NULL;
        }
        fflush(stdout);
        if(!strstr(seed_wp->url, "http://old-www.cs.dartmouth.edu/~cs50/tse")){
            goto next_webpage;
        }
    } while(seed_wp->depth <= max_depth && peak(q));
    // cleanup curl
    curl_global_cleanup();
    cleanupTable(urls);
    cleanupList(q);
    return 0;
}

void writeToFile(int file_count, WebPage * seed_wp, char *folder)
{
    char fname[MAX_FOLDER];
    sprintf(fname, "%s/%d", folder, file_count);
    FILE *wfile;
    wfile=fopen(fname, "w");
    fputs(seed_wp->url, wfile);
    fprintf(wfile, "\n%d\n", file_count);
    fputs(seed_wp->html, wfile);
    fclose(wfile);
}
int fileNotFound(WebPage *seed_wp)
{
    if(seed_wp->html == NULL || strstr(seed_wp->html, "<title>404 Invalid URL</title>")){
        return 0;
    }
    else if(seed_wp->html == NULL || strstr(seed_wp->html, "<title>403 Forbidden</title>")){
        return 0;
    }
    else if(seed_wp->html == NULL || strstr(seed_wp->html, "<TITLE>404 Invalid URL</TITLE>")){
        return 0;
    }
    else if(seed_wp->html == NULL || strstr(seed_wp->html, "<TITLE>403 Forbidden</TITLE>")){
        return 0;
    }
    return 1;
}



WebPage * makeWebPage(char *url, int depth)
{
    struct WebPage *new_wp;
    new_wp = malloc(sizeof(WebPage));
    new_wp->url = malloc(MAX_URL*sizeof(char));
    NormalizeURL(url);
    strcpy(new_wp->url, url);
    new_wp->depth = depth;
    return new_wp;

}
