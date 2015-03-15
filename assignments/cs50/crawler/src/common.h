/* ========================================================================== */
/* File: common.h
 *
 * Project name: CS50 Tiny Search Engine
 * Component name: Crawler
 *
 * This file contains the common defines and data structures.
 *
 */
/* ========================================================================== */
#ifndef COMMON_H
#define COMMON_H

// ---------------- Prerequisites e.g., Requires "math.h"
#include <stdlib.h>
#include <stddef.h> 
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <curl/curl.h>                       // curl functionality
#include <unistd.h>
#include "list.h"                         // size_t
#include "hashtable.h"
#include "web.h"

// ---------------- Constants
#define INTERVAL_PER_FETCH 1                 // seconds between fetches

#define MAX_DEPTH 4                          // don't want to go too far do

// limit crawling to only this domain
#define URL_PREFIX "http://old-www.cs.dartmouth.edu/~cs50/tse"

// ---------------- Structures/Types

typedef struct WebPage {
    char *url;                               // url of the page
    char *html;                              // html code of the page
    size_t html_len;                         // length of html code
    int depth;                               // depth of crawl
} WebPage;

// ---------------- Public Variables

// ---------------- Prototypes/Macros

#endif // COMMON_H
