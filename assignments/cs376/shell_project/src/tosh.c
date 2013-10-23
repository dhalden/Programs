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
    if(getcwd(cwd, sizeof(cwd)) != NULL)
    {
        fprintf(stdout, "Current working dir: %s\n", cwd);
       
    }
    else
        printf("getcwd() error");

    char input[2097152]; 
    char *exit  = "exit\n";
    //Command to take input
    printf("tosh$ ");
    fgets(input, sizeof input, stdin);    
    while(strcmp(input, exit))
    {
    //Command to parse input
    struct cmdin *cmd;
    cmd = parse(input);
    if(strcmp(cmd->cmd, "cd"))
     {
      cwd = chdir(cmd->args); 
     }
    //command to run input
    int child_pid();

    printf("\ncmd: %s", cmd->cmd);
    printf("\nargs: %s\n", cmd->args); 
    //child_pid = fork();

    //if(child_pid == 0)
    //{
    //    execvp(command, arg_extensions);
    //}

    //Command to take input
    printf("tosh$ ");
    free(cmd);
    fgets(input, sizeof input, stdin);
    }
    return 0;
}

