/*
 *    Just the basics. For this improved version,
 *    I am going to make sure that
 *    I'm breaking everything down into basic components.
 *
 *    Author: D. Halden
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//include header file from parse for parsing cmds, and ioredirction
#include "parse.h"

#define KB 1024
#define MAX_CLEN 2097152
#define EXITS "exit"
#define CD "cd"
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main()
{
    char input[MAX_CLEN];
    char cwd[MAX_CLEN];
    char hostname[KB];
    if(gethostname(hostname, sizeof(hostname)) == -1)
    {
        fprintf(stderr, "ERROR: Could not 'gethostname'\n");
        exit(1);
    }
    if(getcwd(cwd, sizeof(cwd)) != NULL);
    {
    //    fprintf(stderr, "ERROR: Could not 'getcwd'\n");
    //    exit(1);
    }
    struct cmdin *cmd;
    while(!strcmp(input, EXITS))
    {
        printf("%s@dish:%s$ ", hostname, cwd);
        parse_cmd(STDIN, cmd);
    }
    return 0;
}
