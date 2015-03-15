#ifndef UNITS_H
#define UNITS_H

#include "../query.h"
#include <stdio.h>	
#include <stdlib.h>                          // free, calloc
#include <string.h>                          // strlen, strcpy
#include <unistd.h>
#include "../../../utils/web.h"
#include "../../../utils/file.h"
#include "../../../utils/hashtable.h"
#include "../../../utils/indexer.h"

#define QUERY1 "abc AND a OR about"
#define QUERY2 "AND a OR about"
#define QUERY3 "abc AND a about"
#define QUERY4 "abc a OR about"
#define QUERY5 "about"
#define QUERY6 "or about"
#define QUERY7 "asdfasdfasdaf"
#define INDEX_FILE "../../Indexer/index.dat"
#define DATA_FOLDER "../../crawler/data/"

#endif
