/*
 *   Runs a while loop.
 *   while input != exit, run every other command I input
 *
 *   Author: D. Halden
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_SIZE 2048
#define MAX_CLEN 2097152
struct cmdin
{
    char *cmd;
    char **args;
    int nargs;
    int pipeflag;
};
struct backlog
{
    struct cmdin *cmd;
};
//check if the last argument of the command passed to it is a pipe.
//if so, return the position of the pipe, otherwise, return 0
//if it has already found a pipe, it will return the position of that pipe
int conpipe(struct cmdin * cmd)
{
    //printf("arg[]: >%s<\n", cmd->args[cmd->nargs]);
    if(!cmd->pipeflag)
    {
        if(!strcmp(cmd->args[cmd->nargs], "|"))
        {
            //printf("PIPE\n");
            return cmd->nargs;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        //printf("pipeflag: %d\n", cmd->pipeflag);
        return (cmd->pipeflag);
    }
}

//free the command after each runthrough
int freeze(struct cmdin *cmd)
{
    int i;
    for(i=0; i <= (cmd->nargs); i++)
    {
        free(cmd->args[i]);
    }
    free(cmd->args);
    free(cmd);
    return 0;
}

//parse input, and add a null to the end
struct cmdin * parse(char *cmd)
{
    //allocate space for the command 
    struct cmdin *ped = malloc(sizeof(struct cmdin)); 
    //declare pipeflag, and nargs as 0
    ped->pipeflag = 0;
    ped->nargs = 0;
    //allocate space for the array of strings, and for the string cmd.
    ped->args =  malloc(sizeof(char*) * MAX_SIZE);
    ped->cmd = malloc(sizeof(char) * MAX_SIZE);
    //scan the input, and put the first argument into the cmd string
    sscanf(cmd, "%s %[^\n]", ped->cmd, cmd);
    //allocate space for the next string, and then copy cmd to it.
    ped->args[ped->nargs] =  malloc(sizeof(char) * MAX_SIZE);
    strcpy(ped->args[ped->nargs], ped->cmd);
    ped->pipeflag = conpipe(ped);
    ped->nargs++;
    ped->args[ped->nargs] =  malloc(sizeof(char) * MAX_SIZE);
    //loop that allocates space for a command, and then assigns
    //the next arg to it.
    while(sscanf(cmd, " %s %[^\n]", ped->args[ped->nargs], cmd) == 2)
     {
        ped->pipeflag = conpipe(ped);
        ped->nargs++;
        ped->args[ped->nargs] = malloc(sizeof(char) * MAX_SIZE);
     }
 
    strncpy(ped->args[ped->nargs], cmd, strlen(cmd)-1);
    ped->nargs++;
    ped->args[ped->nargs] = malloc(sizeof(char) * MAX_SIZE);
    ped->args[ped->nargs] = NULL;

    return ped;

}

int main()
{
    char cwd[MAX_CLEN];
    getcwd(cwd, sizeof(cwd));
    char input[MAX_CLEN]; 
    char *exit  = "exit\n";
    char *cd = "cd";

    //Command to take input
    printf("tosh$ ");
    fgets(input, sizeof input, stdin);    
 
    while(strcmp(input, exit))
    {
        //Command to parse input
        struct cmdin *cmd;
        cmd = parse(input);
        //if there is not a pipeflag
        if(!cmd->pipeflag)
        {
            //Change directories
            if(!strcmp(cd, cmd->args[0]))
            {
                chdir(cmd->args[1]); 
                getcwd(cwd, sizeof(cwd));
            }
            else if(strcmp(input, exit))
            {
                //command to run input
                int child_pid;
                child_pid = fork();
                if(child_pid == 0)
                {
                    if(strcmp(cmd->args[1],cmd->args[0]))
                    {
                        execvp(cmd->cmd, cmd->args);
                    }
                    else
                    {
                        cmd->args[1] = NULL;
                        execvp(cmd->cmd, cmd->args);
                    }
                }
                else
                {
                    wait(&child_pid);
                }
            }
        }
        else
        {
            //piped commands
            struct cmdin pcmd[2]; 
            pcmd[1].cmd = malloc(sizeof(char) * MAX_SIZE);
            pcmd[1].args = malloc(sizeof(char*) * MAX_SIZE);
            pcmd[1].nargs = 0;
            int i;
            int j = 0;
            pcmd[1].cmd = cmd->args[(cmd->pipeflag + 1)];
            for(i = (cmd->pipeflag + 1); i < cmd->nargs; i++)
            {
               pcmd[1].args[j] = malloc(sizeof(char) * MAX_SIZE);
               pcmd[1].args[j] = cmd->args[i];
               pcmd[1].nargs++;
               j++; 
            }
            pcmd[0] = *cmd;
            for(i = cmd->pipeflag; i < cmd->nargs; i++)
            {
                pcmd[0].args[i] = NULL;
            }



        }
        //Command to take input
        printf("tosh$ ");
        freeze(cmd);
        fgets(input, sizeof input, stdin);
    }
    return 0;
}

