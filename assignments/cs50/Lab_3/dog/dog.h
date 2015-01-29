#ifndef DOG_H
#define DOG_H
//This struct is just a 128 character array
typedef struct Encrypt Encrypt;
//Function that determines which flags have been put into the command.
void int_flags(int *nflag, int *mflag, int *Mflag, int *dflag, char *mfile[], char *Mfile[], int argc, char * argv[]);

//Function that ensures m-type-flags are called properly
void set_mflag(int *mflag, char *mfile[], int i, int argc, char * argv[]);

//Function that checks to see if any files have been inputted
//Returns an int of how many files were found
int check_files(char *mfile[], char *Mfile[], char *files[], int argc, char *argv[]);

//reads, and then outputs the files, with the correct encryptions
void read_files(char *files[], int nfiles, int nflag, int mflag, int Mflag,  Encrypt *enc, Encrypt *dec);

//Creates the struct that allows for encryption
Encrypt * init_enc(char *mfile[], int decrypt);

#endif
