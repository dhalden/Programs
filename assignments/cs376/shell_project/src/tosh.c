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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_SIZE 1024
#define MAX_CLEN 2097152
#define READ_END 0
#define WRITE_END 1
#define CHILD_STATUS 0
struct cmdin
{
    char *cmd;
    char **args;
    int nargs;
    int pipeflag;
    int iored[3];
    int iocount;
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
    if(!cmd->pipeflag)
    {
        if(!strcmp(cmd->args[cmd->nargs], "|"))
        {
            return cmd->nargs;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return (cmd->pipeflag);
    }
}
//check if the last argument passed in was an io redirect
//if it was, return the position of the ioredirect
//otherwise, return 0
int coniored(struct cmdin * cmd)
{
    if(cmd->iored[cmd->iocount] == 0)
    {
        if(!strcmp(cmd->args[cmd->nargs], "<"))
        {
            return cmd->nargs;
        }
        else if(!strcmp(cmd->args[cmd->nargs], "1>"))
        {
            return cmd->nargs;
        }
        else if(!strcmp(cmd->args[cmd->nargs], "2>"))
        {
            return cmd->nargs;
        }
        /*else if(strcmp(cmd->args[cmd->nargs], "0>"))
        {
            return cmd->nargs;
        }*/
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}
//free the command after each runthrough
int freeze(struct cmdin cmd)
{
    int i;
    for(i=0; i <= (cmd.nargs); i++)
    {
        free(cmd.args[i]);
    }
    free(cmd.args);
    free(cmd.cmd);
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
    ped->iocount = 0;
    ped->iored[ped->iocount] = 0;
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
        if(coniored(ped))
        {
           ped->iored[ped->iocount] = coniored(ped);
           ped->iocount++;
        }
        ped->pipeflag = conpipe(ped);
        ped->nargs++;
        ped->args[ped->nargs] = malloc(sizeof(char) * MAX_SIZE);
     }
 
    strncpy(ped->args[ped->nargs], cmd, strlen(cmd)-1);
    ped->nargs++;
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
        if(cmd->iocount == 0)
        {
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
                            free(cmd->args[1]);
                            cmd->args[1] = NULL;
                            cmd->nargs--;
                            execvp(cmd->cmd, cmd->args);
    
                        }
                    }
                }
                freeze(*cmd);
                free(cmd);
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
                strcpy(pcmd[1].cmd, cmd->args[(cmd->pipeflag + 1)]);
                for(i = (cmd->pipeflag + 1); i < cmd->nargs; i++)
                {
                   pcmd[1].args[j] = malloc(sizeof(char) * MAX_SIZE);
                   strcpy(pcmd[1].args[j], cmd->args[i]);
                   pcmd[1].nargs++;
                   j++; 
                }
                pcmd[0] = *cmd;
                for(i = cmd->pipeflag; i < cmd->nargs; i++)
                {
                    free(pcmd[0].args[i]);
                    pcmd[0].args[i] = NULL;
                    pcmd[0].nargs--;
                }

                //run the pipe commands.
                int fd[2];
                if (pipe(fd) == -1)
                {
                    fprintf(stderr, "Pipe Failed");
                }
    
                if(fork() == 0)
                {
                    //child process
                    close(1);
                    dup(fd[WRITE_END]);
                    close(fd[READ_END]);
                    close(fd[WRITE_END]);
                    execvp(pcmd[0].cmd, pcmd[0].args);
                }
                if(fork() == 0)
                {
                    //child process2
                    close(fd[WRITE_END]);
                    close(0);
                    dup(fd[READ_END]);
                    close(fd[WRITE_END]);
                    close(fd[READ_END]);                    
                    execvp(pcmd[1].cmd, pcmd[1].args);

                }
            
            
                 //parent parent process
                 wait(CHILD_STATUS);
                 close(fd[READ_END]);
                 close(fd[WRITE_END]);

                //free cmds.
                freeze(pcmd[0]);
                freeze(pcmd[1]);
                free(cmd);
            }
        } 
        else
        {
            int io0 = -1;
            int io1 = -1;
            int io2 = -1;
            char file1[MAX_SIZE];
            char file2[MAX_SIZE];
            char file3[MAX_SIZE];
            int i;
            for(i = 0; i < cmd->iocount; i++)
            {
                if(!strcmp(cmd->args[cmd->iored[i]], "<"))
                {
                    io0 = 0;
                    strcpy(file1, cmd->args[cmd->iored[i] + 1]);
                }
                else if(!strcmp(cmd->args[cmd->iored[i]], "1>"))
                {
                    io1 = 1;
                    strcpy(file2, cmd->args[cmd->iored[i] + 1]);
                }
                else if(!strcmp(cmd->args[cmd->iored[i]], "2>"))
                {
                    io2 = 2;
                    strcpy(file3, cmd->args[cmd->iored[i] + 1]);
                }
            }
            for(i = cmd->iored[0]; i <= cmd->nargs; i++)
            {
                free(cmd->args[i]);
                cmd->args[i] = NULL;
                cmd->nargs--;
            }
            
            int child_id = fork();
            if(child_id < 0)
            {
            fprintf(stderr, "Pipe Failed");
            }
            else if(child_id == 0)
            {
                if(io0 != -1)
                {
                    int fid = open(file1, O_RDONLY, 0666);
                    close(io0);
                    dup(fid);
                    close(fid);
                }
                if(io1 != -1)
                {
                    int fid =  open(file2, O_WRONLY | O_CREAT, 0666);
                    close(io1);
                    dup(fid);
                    close(fid);
                }
                if(io2 != -1)
                {
                    int fid =  open(file2, O_WRONLY | O_CREAT, 0666);
                    close(io2);
                    dup(fid);
                    close(fid);
                }
                execvp(cmd->cmd, cmd->args);
            }
            freeze(*cmd);
            free(cmd);
            

        }
        wait(CHILD_STATUS);
        //Command to take input
        printf("tosh$ ");
        fgets(input, sizeof input, stdin);
    }
    return 0;
}

