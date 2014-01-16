#ifndef PARSE_H
#define PARSE_H

//Macro. if(1) disables printing, if(0) turns it on.
#define DEBUGPRINTF if(1){}else printf

typedef struct cmdin cmdin
{
    char *cmd;
    char **args;
    int amp;
    int len;
    struct iored;
};
//struct dedicated to whether or not io needs to be changed
typedef struct chio  
{
    int tf; // 1 if there is iored, 0 otherwise
    int pipe; // 1 if there is a pipe, 0 otherwise
    int iored[3];  // 0, 1, 2, if there is ioredirection
    int iocount; // len of iored, 0 if false
};

//parse the line for the shell
cmdin * parse_cmd(int io);

//clean up the cmdin when you are done
void free_cmd();

//redirects io as called for
void assign_io();
#endif // PARSE_H
