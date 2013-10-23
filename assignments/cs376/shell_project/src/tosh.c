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

struct cmdin
{
    char **args;
    int nargs;
};
struct backlog
{
    struct cmdin *cmd;
};

struct cmdin * parse(char *cmd)
{
    
    struct cmdin *ped = malloc(sizeof(struct cmdin)); 
    ped->nargs = 1;
    ped->args =  malloc(sizeof(char*) * 2048);
    sscanf(cmd, "%s %[^\n]", ped->args[0], cmd);

    while(sscanf(cmd, "%s %[^\n]", ped->args[ped->nargs], cmd))
     {
        ped->nargs++;
     }
     ped->nargs++;
    ped->args[ped->nargs] = NULL;
    return ped;

}


int main()
{
    char cwd[2097152];
    getcwd(cwd, sizeof(cwd));

    char input[2097152]; 
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
        
        printf("this happens");
        //Change directories
        if(!strcmp(cd, cmd->args[0]))
        {
            chdir(cmd->args[1]); 
            getcwd(cwd, sizeof(cwd));
        }
        else if(!strcmp(input, exit))
        {
            //command to run input
            //int child_pid;
            //int curr_pid;
            int i;
            for(i=0; i<cmd->nargs;i++)
            {
                printf("\nargs[%d]: >%s<\n",i, cmd->args[i]); 
            }
           /* 
            child_pid = fork();
            //curr_pid = getpid(); 
            if(child_pid == 0)
            {
                execvp(input, NULL);
            }
            else
            {
                wait(child_pid);
            }
            //Command to take input
            */
        }
        printf("tosh$ ");
        free(cmd->args);
        free(cmd);
        fgets(input, sizeof input, stdin);
        
    }
    return 0;
}

