#include "parse.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fnctl.h>
#define KB 1024
#define MAX_CLEN 2097152
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int parse_cmd(int io, cmdin * cmds)
{
    if(!(cmds = malloc(sizeof(cmdin))))
        {
            fprintf(stderr, "Memory Error: failed to Malloc\n");
            exit(1);
        }
    char *line = readline("");
    while sscanf((line, " %s %[^\n]", cmds.args[cmds.len], line) == 2)
    {
        printf(" %s \n", cmd.args[cmds.len]);
        cmds.len++;
    }
    return cmds;


}
void free_cmd(struct cmdin cmd)
{

}

void assign_io(struct cmdin cmd)
{

}
