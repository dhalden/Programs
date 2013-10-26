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
};
struct backlog
{
    struct cmdin *cmd;
};

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
    
    struct cmdin *ped = malloc(sizeof(struct cmdin)); 
    ped->nargs = 0;
    ped->args =  malloc(sizeof(char*) * MAX_SIZE);
    ped->cmd = malloc(sizeof(char) * MAX_SIZE);

    sscanf(cmd, "%s %[^\n]", ped->cmd, cmd);
    ped->args[ped->nargs] =  malloc(sizeof(char) * MAX_SIZE);
    strcpy(ped->args[ped->nargs], ped->cmd);
    ped->nargs++;
    ped->args[ped->nargs] =  malloc(sizeof(char) * MAX_SIZE);
    while(sscanf(cmd, " %s %[^\n]", ped->args[ped->nargs], cmd) == 2)
     {
        
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

        //Command to take input
        printf("tosh$ ");
        freeze(cmd);
        fgets(input, sizeof input, stdin);
        
    }
    return 0;
}

