/*	weather.c	query website for weather given a specific 4-letter code

	Project name: CS 50 lab 3
	Component name:

	This file contains ...
	
	Primary Author: Derek Halden
	Date Created:   1/29/15

	Special considerations:  
		make weather

======================================================================*/
// do not remove any of these sections, even if they are empty
//
// ---------------- Open Issues 

// ---------------- System includes e.g., <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
// ---------------- Local includes  e.g., "file.h"
#include "mycurl.h"

// ---------------- Constant definitions 
#define MAX_CLEN 2097152  // this is the max length of string I will accept
// ---------------- Macro definitions

// ---------------- Structures/Types 

// ---------------- Private variables 

// ---------------- Private prototypes 

/*====================================================================*/


/* ... */

int main(int argc, char **argv)
{
    /* local variables */
    char credit[1000];
    char location[1000];
    char station_id[1000];
    char observation_time[1000];
    char weather[1000];
    char temperature_string[1000];
    char relative_humidity[1000];
    char wind_string[1000];
    char visibility_mi[1000];

    /* curl stuff */
    CURL *curl;
    CURLcode res;
    struct string page;
    /* Here is the format string for the URL we will request */
    char APIurl[50];

    /* check args */
    if(argc < 2){
    	fprintf(stdout,"to lookup location codes, see\n");
    	fprintf(stdout, "http://w1.weather.gov/xml/current_obs/seek.php?state=ak&Find=Find\n");
    	return 0;
    }
    else if(argc > 2){
    	fprintf(stderr, "Error: Too many arguments");
    	return 0;
    }
    else if(strlen(argv[1]) != 4){
    	fprintf(stderr, "Error: Location code must be 4 characters\n");
    	return 0;
    }

    /* allocate and intiialize the output area */
    init_string(&page);

    /* create the URL from the format string */
    /* ... */
    sprintf(APIurl, "http://w1.weather.gov/xml/current_obs/%s.xml", argv[1]);
    //printf("%s\n",APIurl);

    /* initialize curl */
    curl = curl_easy_init();

    if(curl) {
        /* set the URL we want to visit */
        curl_easy_setopt(curl, CURLOPT_URL, APIurl);
        /* set the function curl should call with the result */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        /* set the buffer into which curl should place the data */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &page);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* make sure it worked */
        if(page.ptr == NULL)
        {
        	fprintf(stderr, "Error: page could not be read\n");
        	return 0;
        }
        //printf("%s\n", page.ptr);

        /* check: if the weather station code wasn't found, we get back HTML instead of XML  */
        if(strncmp(page.ptr, "<?xml", 5))
        {
        	fprintf(stderr, "Error: the station code <%s> could not be found\n", argv[1]);
        	return 0;
        }
        //printf("%s\n", page.ptr);
        /* otherwise, select the desired output from the results */
       	char * currline;
       	currline = malloc(MAX_CLEN*sizeof(char));
       	//int count = 0;

       	//parse the file on newlines (\n), and store each new line in currline
        while(sscanf(page.ptr, "%[^\n]\n%[^\a]", currline, page.ptr) == 2)
        {
        	//printf("%d %s\n", ++count, currline);
        	//reverse interpolate data via sscanf
        	if(strstr(currline,"<credit>")){
        		sscanf(currline,"<credit>%[^<>]<\\credit>", credit);
        	}
        	else if(strstr(currline,"<location>")){
        		sscanf(currline,"<location>%[^<>]<\\location>", location);
        	}
        	else if(strstr(currline,"<station_id>")){
        		sscanf(currline,"<station_id>%[^<>]<\\station_id>", station_id);
        	}
        	else if(strstr(currline,"<observation_time>")){
        		sscanf(currline,"<observation_time>%[^<>]<\\observation_time>", observation_time);
        	}
        	else if(strstr(currline,"<weather>")){
        		sscanf(currline,"<weather>%[^<>]<\\weather>", weather);
        	}
        	else if(strstr(currline,"<temperature_string>")){
        		sscanf(currline,"<temperature_string>%[^<>]<\\temperature_string>", temperature_string);
        	}
        	else if(strstr(currline,"<relative_humidity>")){
        		sscanf(currline,"<relative_humidity>%[^<>]<\\relative_humidity>", relative_humidity);
        	}
        	else if(strstr(currline,"<wind_string>")){
        		sscanf(currline,"<wind_string>%[^<>]<\\wind_string>", wind_string);
        	}
        	else if(strstr(currline,"<visibility_mi>")){
        		sscanf(currline,"<visibility_mi>%[^<>]<\\visibility_mi>", visibility_mi);
        	}

        }
		// Print the output        
    	printf("\tcredit: %s\n", credit);
		printf("\tlocation: %s\n", location);
		printf("\tstation_id: %s\n", station_id);
		printf("\tobservation_time: %s\n", observation_time);
		printf("\tweather: %s\n", weather);
		printf("\ttemperature_string: %s\n", temperature_string);
		printf("\trelative_humidity: %s\n", relative_humidity);
		printf("\twind_string: %s\n", wind_string);
		printf("\tvisibility_mi: %s\n", visibility_mi);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return 0;
}
