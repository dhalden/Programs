#ifndef CRAWLER_H
#define CRAWLER_H
#include <stdio.h>                           // printf

#include <curl/curl.h>                       // curl functionality

// ---------------- Local includes  e.g., "file.h"
#include "common.h"                          // common functionality
#include "web.h"                             // curl and html functionality
#include "list.h"                            // webpage list functionality
#include "hashtable.h"                       // hashtable functionality
#include "utils.h"                           // utility stuffs
int main(int argc, char* argv[]);
void writeToFile(int file_count, WebPage * seed_wp, char *folder);
void cleanupTable(HashTable *urls);
int fileNotFound(WebPage *seed_wp);
WebPage * makeWebPage(char *url, int depth);

#endif //CRAWLER_H
