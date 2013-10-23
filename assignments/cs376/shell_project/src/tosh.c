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
    char cmd[2097152];
    char args[2097152];
};
struct backlog
{
    struct cmdin *cmd;
};

struct cmdin * parse(char *cmd)
{
    struct cmdin *parsed = malloc(sizeof(struct cmdin)); 
    sscanf(cmd, "%s %s\n", parsed->cmd, parsed->args);
    return parsed;

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
        
        //Change directories
        if(!strcmp(cd, cmd->cmd))
        {
            chdir(cmd->args); 
            getcwd(cwd, sizeof(cwd));
        }
        else if(!strcmp(input, exit))
        {
            //command to run input
            //int child_pid;
            //int curr_pid;
            printf("\ncmd: >%s<", cmd->cmd);
            printf("\nargs: >%s<\n", cmd->args); 
            
            //child_pid = fork();
            //curr_pid = getpid(); 
            /*if(child_pid == 0)
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
        free(cmd);
        fgets(input, sizeof input, stdin);
        
    }
    return 0;
}

