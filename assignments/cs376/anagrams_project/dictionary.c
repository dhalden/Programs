/* Dictionary.c
 *
 * Stores a dictionary and handles determining anagrams of words.
 * Author: L. Porter
 * Student Modifier: D. Halden
 */

//NOTE: you need only put in the letters for a word, and this program will find
// the words associated with those letters. The letters needn't be in word form

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
#include "word_list.h"

// you may or may not want nodes in your Dictionary, you
// may be able to use the word_list instead.
struct DNode
{
    char  word[46];
    char  alphaWord[46];
    int  strLength;
};

// struct for the dictionary
struct Dictionary
{
   struct DNode *array;
   int size;
};

//creates an array of DNodes, which stores the alphabetized words,
//and the actual words that the alphabetized words correspond to.
//returns that pre-sorted array
Dictionary * dict_create(char *filename)
{
    FILE * dictFile;
    Dictionary * retval = malloc(sizeof(struct Dictionary));
    retval->array = malloc(462984*sizeof(struct DNode));
    DEBUGPRINTF("Creating Dictionary\n");
    
    dictFile = fopen(filename, "r");
    if(dictFile == NULL)
    {
        fprintf(stderr, "Error Opening File: %s\n", filename);
        return 0; 
    }
    
    //declare the dictionary length which will increment in the while loop
    //declare a "newWord", which will be added to the dictionary
    //declare a word_list, which will be used to create
    int dictLength = 0;
    char newWord[45];
    char alpWord[45];
    int lengths = 0;
    //read the words from the file. the words are in the format:
    // dorw word
    while (fscanf(dictFile, "%s %s", alpWord, newWord)!=EOF)
    {
        /*
        this was used for the lengths[] array in "dict_print_angarams"
        if(lengths < strlen(newWord))
        {
            lengths = strlen(newWord);
        }
        */
        //add the words to a DNode, in the array from the dictionary
        strcpy(retval->array[dictLength].word, newWord);
        strcpy(retval->array[dictLength].alphaWord, alpWord);
        retval->array[dictLength].strLength = strlen(newWord);
        dictLength++;
    }
    // take note of the dictionary's size, for storing in the size variable
    // of the dictionary
    retval->size = dictLength;
    // close the file when I'm done
    fclose(dictFile);
    // hint - be sure to close your input if you finish with it
    return retval;
}

void dict_print_anagrams(Dictionary *dict, char *word)
{
    // I generated these from the code in fscanf above
    // I use them to jump to the beginning of words of a certain length
    // it's set up such that lengths[8] is the first word of length 8
    int lengths[32] = {0, 0, 27, 667, 5359, 16541, 39331, 78562, 130325, 190858,
    252066, 305852, 351786, 388972, 416693, 435839, 447925, 455016, 458994,
    460994, 462046, 462552, 462791, 462894, 462944, 462963, 462972, 462974,
    462977, 462979, 462981, 462982};

    int length;

    // beyond the word of length 32 the list has one 45 letter word
    // because it's not 32 + 1 != 45, I will just set the length to 32 for
    // starting search values of words with length greater than 32
    if(strlen(word) > 32)
    {
        length = 32;
    }
    else
    {
        length = lengths[strlen(word)];
    }

    char temp[46];
    int tempholder = 0;
    int i;
    int a; 
    char alphabet = ',';
    //this does the same thing as my dict_modifier code.
    //this is just to make sure we compare apples to apples
    //Reminder: this makes 'button' into 'bnottu'
    for(a = 0; a < 15; a++)
    {
        for(i=0; i<strlen(word); i++)
        {
            if(tempholder == strlen(word))
            {
                temp[tempholder] = '\0';
                break;
            }
            if(word[i] == alphabet)
            {
                temp[tempholder] = alphabet;
                tempholder++;
            }
        }
        alphabet++;
    }
    
    alphabet = 'a';
    for(a = 0; a < 26; a++)
    {
        for(i=0; i<strlen(word); i++)
        {
            if(tempholder == strlen(word))
            {
                temp[tempholder] = '\0';
                break;
            }
            if(word[i] == alphabet)
            {
                temp[tempholder] = alphabet;
                tempholder++;
            }
        }
        alphabet++;
    }
    // This is the actual search
    // The code starts with words of length 'length', and goes until it finds a
    // match for the alphabetized word. once it finds the match, it reads 
    // down the list, until the alphabetized word no longer matches, and then
    // it breaks out of the for loop, because there will be no other words that
    // match.
    for(i = length; i < dict->size; i++)
    {
        if(strcmp(dict->array[i].alphaWord, temp) == 0)
         {
            while(strcmp(dict->array[i].alphaWord, temp) == 0)
            {
                printf("%s ", dict->array[i].word);
                i++;
            }
            break;
         }
    }

}

// deallocate the memory for the Dictionary we declared
void dict_destroy(Dictionary *dict)
{
    // clean up the data structure here.
    free(dict->array);
}
