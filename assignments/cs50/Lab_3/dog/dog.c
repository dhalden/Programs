/* dog.c acts like bash command cat, but also includes 	

	Project name: Lab_3
	Component name: Main

	All of the code, structs, and functions used by the dog program that I wrote.
	
	Primary Author:	Derek Halden
	Date Created: 1/28/2015

	Special considerations:  
		make dog	
======================================================================*/
// ---------------- Open Issues 

// ---------------- System includes e.g., <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// ---------------- Local includes  e.g., "file.h"
#include "dog.h"
// ---------------- Constant definitions 
#define MAX_CLEN 2097152  // this is the max length of string I will accept
// ---------------- Macro definitions

// ---------------- Structures/Types 
struct Encrypt{
	int letters[128];
};

//See dog.h for a description of each of these functions
void int_flags(int *nflag, int *mflag, int *Mflag, int *dflag, char *mfile[], char *Mfile[], int argc, char * argv[]);

void set_mflag(int *mflag, char *mfile[], int i, int argc, char * argv[]);

int check_files(char *mfile[], char *Mfile[], char *files[], int argc, char *argv[]);

void read_files(char *files[], int nfiles, int nflag, int mflag, int Mflag,  Encrypt *enc, Encrypt *dec);

struct Encrypt * init_enc(char *mfile[], int decrypt);


int main(int argc, char * argv[])
{
	// ---------------- Private variables 
	int nflag=0;
	int mflag=0;
	int Mflag=0;
	int dflag=0;  // '-' dash flag
	int fflag=0;
	char *mfile;
	char *Mfile;
	char *files[1024];
	mfile=malloc(1024*(sizeof(char)));
	Mfile=malloc(1024*(sizeof(char)));
	mfile = NULL;
	Mfile = NULL;
	Encrypt *enc=malloc(sizeof(Encrypt));
	Encrypt *dec=malloc(sizeof(Encrypt));

	// Ensure that all of the arguments are correct
	int_flags(&nflag, &mflag, &Mflag, &dflag, &mfile, &Mfile, argc, argv);
	// Check to make sure that all files mentioned exist
	fflag = check_files(&mfile, &Mfile, files, argc, argv);

	//if there is a -m flag, make an encryption mapfile
	if(mflag){
		enc = init_enc(&mfile, 0);
	}

	//if there is a -M flag, make an decryption mapfile
	if(Mflag){
		dec = init_enc(&Mfile, 1);
	}

	//read the files specified
	read_files(files, fflag, nflag, mflag, Mflag, enc, dec);
	free(enc);
	free(dec);
	return 0;
}

void int_flags(int *nflag, int *mflag, int *Mflag, int *dflag, char *mfile[], char *Mfile[], int argc, char * argv[])
{
	int i;
	for(i=0; i < argc; i++){
		//verify each flag is acceptable
		if(argv[i][0] == '-') {
			if(!strcmp(argv[i], "-n")) {
				*nflag = 1;	
			}
			else if(!strcmp(argv[i], "-m")) {
				set_mflag(mflag, mfile, i, argc, argv);
			}	
			else if(!strcmp(argv[i], "-M")) {
				set_mflag(Mflag, Mfile, i, argc, argv);
			}
			else if(!strcmp(argv[i], "--help")){
				printf("dog: works like cat, (but is clearly superior in every way)\n");
				printf("It can be called as: \n$ dog <file> <flags>");
				printf("\n the order of the files is unimportant, unless it is a mapfile");
				printf("flags: \n -m <mapfile> : encrypt the input with given mapfile \
					    \n -M <mapfile> : decrypt the input with given mapfile \
						\n -n : number each line of output	 \
						\n - : move into an interactive mode, where it"\
						" will output what you type. Can be closed with control-d\n");
				printf("If you are seeing this text, it means you typed"\
						" '--help' if you don't want to see this text retype"\
						" your command without '--help'\n");
				exit(0);
			}
			else if(!strcmp(argv[i], "-")){
				*dflag = 1;
			}
			else{
				fprintf(stderr, "Error: Invalid option '%s'", argv[i]);
				exit(0);
			}
		}
	}
}
void set_mflag(int *mflag, char *mfile[], int i, int argc, char * argv[])
{
			//Deal with -m/-M flags
			*mflag = 1;
			if(argc > i+1){
				*mfile = argv[i+1];
				if(argv[i+1][0] == '-'){
					fprintf(stderr, "Error: no mapfile provided\n");
					exit(0);
				}
			}
			else {
				fprintf(stderr, "Error: no mapfile provided\n");
				exit(0);
			}
}

int check_files(char *mfile[], char *Mfile[], char *files[], int argc, char *argv[])
{
	int i;
	int count = 0;
	//check that each file exists
	for(i=1; i < argc; i++){
		if(argv[i][0] != '-'){
			if(*mfile == argv[i]){
				if(access(*mfile,F_OK) == -1){
					fprintf(stderr, "Error: mapfile '%s' doesn't exist\n", *mfile);
					exit(0);
				}
			}
			else if (*Mfile == argv[i]){
				if(access(*Mfile,F_OK) == -1){
					fprintf(stderr, "Error: mapfile '%s' doesn't exist\n", *Mfile);
					exit(0);
				}
			}
			else{
				if(access(argv[i],F_OK) == -1){
					fprintf(stderr, "Error: mapfile '%s' doesn't exist\n", argv[i]);
					exit(0);
				}
				else {
					// if the file exists, but isn't a mapfile, add it to the
					// list of files to be read
					files[count++]=argv[i];
				}
			}
		}
	}
	return count;
}
void read_files(char *files[], int nfiles, int nflag, int mflag, int Mflag,  Encrypt *enc, Encrypt *dec)
{
	int i;
	//make a buffer
	//for each file in the list of files
	for(i=0; i <= nfiles; i++){
		int c;
		FILE *read_file;
		//determine if we are reading from a file, or from stdin
		if(nfiles != 0){
			read_file = fopen(files[i], "r");
		}
		else{
			read_file = stdin;
		}
		//if there is a flag to write the line numbers
		if(read_file){
			if(nflag){
				char buffer[MAX_CLEN];
				int line;
				line = 1;
					int ccount=0;
					//read all of the letters into a buffer, then output on 
					//each new line, until end of file is reached
					while((c = getc(read_file)) != EOF){
						if(c != '\n')
						{
							if(mflag){
								c = enc->letters[c];
							}
							if(Mflag){
								c = dec->letters[c];
							}
							buffer[ccount++] = (char)c;
						}
						else{
							buffer[ccount++] = '\0';
							ccount = 0;
							printf("\t%d %s\n", line++, buffer);
						}
					}
					fclose(read_file);
			}
			else{
					//print each character as it comes to us
					//uses kernals inherent buffer, when reading from stdin
					while((c = getc(read_file)) != EOF){
						if(mflag){
							c = enc->letters[c];
						}
						if(Mflag){
							c = dec->letters[c];
						}
						putchar(c);
					}
				fclose(read_file);
			}
		}
	}
}

struct Encrypt * init_enc(char *mfile[], int decrypt)
{
	int i;
	struct Encrypt *enc = malloc(sizeof(struct Encrypt));
	for(i = 0; i < 128; i++){
		enc->letters[i] = i;
	}
	int c;
	int count = 0;
	FILE *file;
	file = fopen(*mfile, "r");
	if(file){
		char first = '\0';
		char second = '\0';
		while((c = getc(file)) != EOF){
			if(c == '\n'){
				first = '\0';
				second = '\0';
				continue;
			}
			if((c != ' ') && (!first)){
				first = (char)c;
				if(decrypt){
					enc->letters[(int)second] = (int)first;
				}
				else{
					enc->letters[(int)first] = (int)second;
				}
			}
			else if((c != ' ') && (!second)){
				second = (char)c;
				if(decrypt){
					enc->letters[(int)second] = (int)first;
				}
				else{
					enc->letters[(int)first] = (int)second;
				}
				count++;
			}
			else if(c != ' '){
				fprintf(stderr, "ERROR: Mapfile follows an incorrect format\n");
				exit(0);
			}
		}
		fclose(file);
	}
	if(count < 26){
		fprintf(stderr, "ERROR: Mapfile has %d mappings\n", count);
		exit(0);
	}
	return enc;
}
// ---------------- Private prototypes 

/*====================================================================*/
