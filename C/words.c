#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define KB 1024
#define MAX_CLEN 2097152
#define STDIN 0
#define STDOUT 1
#define STDERR 2
struct dictionary{
	char word[15];
	char aword[15];
};


char * sortWord(char * input, int start, int stop, int length)
{
    int a;
    char * temp;
    char * b;
    strcpy(temp, input);
    if (length < 2)
    {
        return temp;
    }
    else
    {
        a = (stop - start)/2;
        b = sortWord(input, start, a, length/2);
        strcpy(input, b);
        b = sortWord(input, a+1, stop, length/2);
        strcpy(input, b);
    }

    int i; int Ai; int Bi;
    char t;
    Ai = start;
    Bi = a+1;
    for(i = start; i < stop; i++)
    {
        if(Bi < stop || input[Ai] < input[Bi])
        {
            temp[i] = input[Ai];
            Ai++;
        }
        else if(Ai > a || input[Ai] >= input[Bi])
        {
            temp[i] = input[Bi];
            Bi++;
        }
    }
    return temp;
}


int main()
{
    FILE * dict_file;
    char * dict_filename = "dict.txt";
    struct dictionary *dict = malloc(178691*sizeof(struct dictionary));
    dict_file = fopen(dict_filename,"r");
    if (dict_file == NULL)
    {
        fprintf(stderr, "Error Opening File:%s\n", dict_filename);
        return 0;
    }
    char input[15];
    int count;
    count = 0;

    while(fscanf(dict_file, "%s", input) != EOF)
    {
        char tempword[15];
        strcpy(tempword, input);
        int a = strlen(tempword);
        strcpy(dict[count].word, input);
        strcpy(dict[count].aword, sortWord(tempword, 0, a, a));

    }
}

