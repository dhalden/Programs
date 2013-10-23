/* dict_modifier.c 
 *
 * Modifies the dicionary in the following ways
 *  1. Stores the words ordered alphabetically by length
 *  2. Stores a word in alphabetical order next to the word ex. button bnottu
 *  3. Has no duplicates (all lowercase)
 * 
 *  Author: D. Halden
 *
 */
// NOTE: THIS TAKES 2 HOURS TO RUN

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct dictList{
    char word[46];
};


int main()
{
    /* 
        I used the code from the anagrams.c file, for opening files.
    */

    FILE * dict_file;
    char * dict_filename = "dict.txt";

    //declare and allocate space for an array of strings
    struct dictList *alpdictionary = malloc(479829*sizeof(struct dictList));
    struct dictList *actdictionary = malloc(479829*sizeof(struct dictList));

    dict_file = fopen(dict_filename, "r");
    
    if(dict_file == NULL)
    {
        fprintf(stderr, "Error Opening File:%s\n",dict_filename);
        return 0;
    }
    char input[46];
    int count;
    count = 0;
    // reads input from file.
    while (fscanf(dict_file, "%s",input)!=EOF)
    {
        char tempword[46];
        strcpy(tempword, input);
        int i;
        // Make every word lower case for comparison
        for(i = 0; i < strlen(input); i++)
        {
            input[i] = tolower(input[i]);
        }

        // declare the necessary ints and chars for the next for-loop
        char alphabet = 'a';
        char extraneous = ',';
        int a;
        int tempholder;
        tempholder = 0;

        // alphabetize each word, and add it to a list, so that it can be
        // sorted
        //this loop is specifically for the characters ",-./0123456789:;"
        for(a = 0; a < 15; a++)
        {
            for(i = 0; i < strlen(input); i++)
            {
                if(tempholder == (strlen(input)))
                {
                        tempword[tempholder] = '\0';
                        goto out ;
                }
                if (input[i] == extraneous)
                {
                    tempword[tempholder] = input[i];
                    tempholder++;
                }

            }
             extraneous++;
        }

        // this loop checks for all of the letters in the alphabet.
        // if it reaches the end of the word, it appends '\0', and then
        // breaks out of the loop.
        for(a = 0; a < 26; a++)
        {
            for(i = 0; i < strlen(input); i++)
            {
                if(tempholder == (strlen(input)))
                {
                        tempword[tempholder] = '\0';
                        goto out ;
                }
                if(input[i] == alphabet)
                {
                    tempword[tempholder] = alphabet;
                    tempholder++;
                
                }
            }
            alphabet++;
        }

        out :
        //store the modified word e.g. bnottu in alpdictionary
        strcpy(alpdictionary[count].word, tempword);
        //store the original word e.g. button in actdictionary
        strcpy(actdictionary[count].word, input);
        count++;
    }
    fclose(dict_file);
    //had to redeclare i because it was declared inside the while loop before
    int i;

    for(i = 0; i < 479829; i++)
    {
        int a;
        for(a = 0; a < 479829; a++)
        {
            // sort the list here.
            // I'm going to do a bubble sort, because it's simple to implement
            // and this part is not being judged based on time.
            // also, this was the simplest way to also sort by length
            if(strcmp(alpdictionary[a].word, alpdictionary[a+1].word) > 0) 
            {
              // sorting using the alphabetized dictionary, but making the same
              // changes to both dictionaries.
              char temp[46];
              strcpy(temp, alpdictionary[a].word);
              strcpy(alpdictionary[a].word, alpdictionary[(a+1)].word);
              strcpy(alpdictionary[(a+1)].word, temp);
              
              
              strcpy(temp, actdictionary[a].word);
              strcpy(actdictionary[a].word, actdictionary[(a+1)].word);
              strcpy(actdictionary[(a+1)].word, temp);

            }
            // this sort includes the length of the words, as a criteria for 
            // sorting the dictionary
             if(strlen(alpdictionary[a].word) > strlen(alpdictionary[a+1].word))
            {
              char temp[46];
              strcpy(temp, alpdictionary[a].word);
              strcpy(alpdictionary[a].word, alpdictionary[(a+1)].word);
              strcpy(alpdictionary[(a+1)].word, temp);
              
              
              strcpy(temp, actdictionary[a].word);
              strcpy(actdictionary[a].word, actdictionary[(a+1)].word);
              strcpy(actdictionary[(a+1)].word, temp);


            }
        }
    }
    //open file for writing the dictionary which the anagrams.c code will use
    FILE *sort_file = fopen("new_dict.txt", "w");
    if (sort_file == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }

    // this prints all of the words to the file 'newdict.txt' it also, checks
    // to make sure it only prints one of each actual word.
    int j;
    for(j = 0; j < 479829; j++)
    {
        // if two words are the same, they will be next to each other in the 
        // dictionary       
        if(strcmp(actdictionary[j].word, actdictionary[(j+1)].word) != 0)
        { 
        fprintf(sort_file ,"%s %s \n",
                alpdictionary[j].word,
                actdictionary[j].word);
        }
    }
    //close the files, and deallocate all of the memory I used
    fclose(sort_file);
    free(alpdictionary);
    free(actdictionary);
    //exit main
    return 0;
}
