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
    int andflag;
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
    printf("cmd->iored[cmd->iocount +1] = %d cmd->args[cmd->nargs] = %s\n\n",
            cmd->iored[cmd->iocount +1],       cmd->args[cmd->nargs]);
    if(cmd->iored[cmd->iocount + 1] == 0)
    {
        if(!strcmp(cmd->args[cmd->nargs], "<"))
        {
            return cmd->nargs;
        }
        else if(!strcmp(cmd->args[cmd->nargs], "1>"))
        {
            printf("\nThis is happening\n");
            printf("\ncmd->nargs = %d\n\n", cmd->nargs);
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
        return cmd->iored[cmd->iocount];
    }

}
//free the command after each runthrough
int freeze(struct cmdin cmd)
{
    int i;
    for(i=0; i <= (cmd.nargs); i++)
    {
        if(i < 3)
        {
            cmd.iored[cmd.iocount] = 0;
            cmd.iocount--;
        }
        free(cmd.args[i]);
        cmd.args[i] = NULL;
    }
    free(cmd.args);
    free(cmd.cmd);
    
    return 0;
}
int printcmd(struct cmdin cmd)
{
    int i;
    for(i=0; i<=cmd.nargs; i++)
    {
        if(i < 3)
        {
            printf("cmd.iored[%d]: %d\n", i, cmd.iored[i]);
        }
        printf("cmd.args[%d]: %s\n", i, cmd.args[i]);
    }
    printf("cmd.cmd: %s\n", cmd.cmd);
    return 0;
}

//parse input, and add a null to the end
struct cmdin * parse(char *cmd)
{
    //allocate space for the command 
    struct cmdin *ped;
    if(!(ped = malloc(sizeof(struct cmdin))))
    {
        fprintf(stderr, "Memory Error: failed to Malloc\n");
        exit(1);
    }
    //declare pipeflag, and nargs as 0
    ped->pipeflag = 0;
    ped->nargs = 0;
    ped->iocount = -1;
    ped->iored[0] = 0;
    ped->iored[1] = 0;
    ped->iored[2] = 0;
    ped->andflag = 0;
    //allocate space for the array of strings, and for the string cmd.
    if(!(ped->args =  malloc(sizeof(char*) * MAX_SIZE)))
    {
       fprintf(stderr, "Memory Error: failed to Malloc\n");
       exit(1);
    }
    if(!(ped->cmd = malloc(sizeof(char) * MAX_SIZE)))
    {
       fprintf(stderr, "Memory Error: failed to Malloc\n");
       exit(1);
    }
    //scan the input, and put the first argument into the cmd string
    sscanf(cmd, "%s %[^\n]", ped->cmd, cmd);
    //allocate space for the next string, and then copy cmd to it.
    if(!(ped->args[ped->nargs] =  malloc(sizeof(char) * MAX_SIZE)))
    {
        fprintf(stderr, "Memory Error: failed to Malloc\n");
        exit(1);
    }
    strcpy(ped->args[ped->nargs], ped->cmd);
    ped->pipeflag = conpipe(ped);
    ped->nargs++;
    if(!(ped->args[ped->nargs] =  malloc(sizeof(char) * MAX_SIZE)))
    {
        fprintf(stderr, "Memory Error: failed to Malloc\n");
        exit(1);
    }
    //loop that allocates space for a command, and then assigns
    //the next arg to it.
    while(sscanf(cmd, " %s %[^\n]", ped->args[ped->nargs], cmd) == 2)
    {
        ped->pipeflag = conpipe(ped);
        if(coniored(ped))
        {
           ped->iocount++;
           ped->iored[ped->iocount] = coniored(ped);
        }
        ped->nargs++;
        if(!(ped->args[ped->nargs] = malloc(sizeof(char) * MAX_SIZE)))
        {
            fprintf(stderr, "Memory Error: failed to Malloc\n");
            exit(1);
        }
    }
    strncpy(ped->args[ped->nargs], cmd, strlen(cmd)-1);
    if(!strcmp(ped->args[ped->nargs], "&"))
    {
        //free(ped->args[ped->nargs]);
        //ped->args[ped->nargs] = NULL;
        ped->andflag = 1;
    }
    ped->nargs++;
    ped->args[ped->nargs] = NULL;
    return ped;
}

int main()
{
    char cwd[MAX_CLEN];
    getcwd(cwd, sizeof(cwd));
    char input[MAX_CLEN]; 
    char *exits  = "exit\n";
    char *cd = "cd";

    //Command to take input
    printf("dash$ ");
    fgets(input, sizeof input, stdin);    
 
    while(strcmp(input, exits))
    {
        pid_t child_pid; 
        //Command to parse input
        struct cmdin *cmd;
        cmd = parse(input);

        if(!strcmp(cmd->args[(cmd->nargs-1)], "|"))
        {
            fprintf(stderr, "tosh: syntax error near unexpected token '|'\n");
            goto ifeof;
        }
        if(!strcmp(cmd->args[cmd->nargs-1], "<"))
        {
            fprintf(stderr, "tosh: syntax error near unexpected token '<'\n");
            goto ifeof;
        }
        if(!strcmp(cmd->args[cmd->nargs-1], "1>"))
        {
            fprintf(stderr, "tosh: syntax error near unexpected token '1>'\n");
            goto ifeof;
        }
        if(!strcmp(cmd->args[cmd->nargs-1], "2>"))
        {
            fprintf(stderr, "tosh: syntax error near unexpected token '2>'\n");
            goto ifeof;
        }
        if(cmd->iocount == -1)
        {
            //if there is not a pipeflag
            if(!cmd->pipeflag)
            {
                //Change directories
                if(!strcmp(cd, cmd->args[0]))
                {
                    if(strcmp(cmd->args[1], "cd"))
                    {
                        chdir(cmd->args[1]); 
                    }
                    else
                    {
                        chdir("/home");
                    }
                    getcwd(cwd, sizeof(cwd));
                }
                else if(strcmp(input, exits))
                {
                    //command to run input
                    child_pid = fork();
                    if(child_pid == 0)
                    {
                        if(!(strcmp(cmd->args[1],cmd->args[0])))
                        {
                            if(cmd->args[1] != NULL)
                            {
                                free(cmd->args[1]);
                                cmd->args[1] = NULL;
                                cmd->nargs--;
                            }
                            execvp(cmd->cmd, cmd->args);
                        }
                        else
                        {
    
                            if(cmd->andflag)
                            {
                                cmd->args[cmd->nargs -1] = NULL;
                            }
                            execvp(cmd->cmd, cmd->args);
                        }
                    }
                    else if (child_pid < 0)
                    {
                        fprintf(stderr, "Fork Failed\n");
                    }
                }
                else if(!strcmp(input, exits))
                {
                    goto ifeof;
                }
                freeze(*cmd);
                free(cmd);
            }
            else
            {
                pid_t pid2;
                //piped commands
                struct cmdin pcmd[2]; 
                if(!(pcmd[1].cmd = malloc(sizeof(char) * MAX_SIZE)))
                {
                    fprintf(stderr, "Memory Error: failed to Malloc\n");
                    exit(1);
                }
                if(!(pcmd[1].args = malloc(sizeof(char*) * MAX_SIZE)))
                {
                    fprintf(stderr, "Memory Error: failed to Malloc\n");
                    exit(1);
                }
                pcmd[1].nargs = 0;
                int i;
                int j = 0;
                //check the commands here.
                strcpy(pcmd[1].cmd, cmd->args[(cmd->pipeflag + 1)]);
                for(i = (cmd->pipeflag + 1); i < cmd->nargs; i++)
                {
                   if(!(pcmd[1].args[j] = malloc(sizeof(char) * MAX_SIZE)))
                   {
                        fprintf(stderr, "Memory Error: failed to Malloc\n");
                        exit(1);
                   }
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
                    fprintf(stderr, "Pipe Failed\n");
                }
                
                if(!(pid2 = fork()))
                {
                    //child process
                    close(1);
                    dup(fd[WRITE_END]);
                    close(fd[READ_END]);
                    close(fd[WRITE_END]);
                    execvp(pcmd[0].cmd, pcmd[0].args);
                }
                else if (pid2 < 0)
                {
                    fprintf(stderr, "Fork Failed\n");
                }
                if(!(child_pid = fork()))
                {
                    //child process2
                    close(fd[WRITE_END]);
                    close(0);
                    dup(fd[READ_END]);
                    close(fd[WRITE_END]);
                    close(fd[READ_END]);                    
                    execvp(pcmd[1].cmd, pcmd[1].args);
                }
                else if (child_pid < 0)
                {
                    fprintf(stderr, "Fork Failed\n");
                }
            
            
                 //parent parent process
                 waitpid(pid2, CHILD_STATUS, 0);
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
            char file0[MAX_SIZE];
            char file1[MAX_SIZE];
            char file2[MAX_SIZE];
            int i;
            for(i = 0; i <= cmd->iocount; i++)
            {
                if(!strcmp(cmd->args[cmd->iored[i]], "<"))
                {
                  io0 = 0;
                  strcpy(file0, cmd->args[cmd->iored[i] + 1]);
                  if(!strcmp(cmd->args[cmd->iored[0] - 1], file1))
                  {
                    goto ifeof;
                    fprintf(stderr, "cat: tosh.c: input file is output file\n");
                  }
                }
                if(!strcmp(cmd->args[cmd->iored[i]], "1>"))
                {
                  io1 = 1;
                  strcpy(file1, cmd->args[cmd->iored[i] + 1]);
                  if(!strcmp(cmd->args[cmd->iored[0] - 1], file1))
                  {
                    goto ifeof;
                    fprintf(stderr, "cat: tosh.c: input file is output file\n");
                  }
                }
                if(!strcmp(cmd->args[cmd->iored[i]], "2>"))
                {
                  io2 = 2;
                  strcpy(file2, cmd->args[cmd->iored[i] + 1]);
                  if(!strcmp(cmd->args[cmd->iored[0] - 1], file2))
                  {
                    goto ifeof;
                    fprintf(stderr, "cat: tosh.c: input file is output file\n");
                  }
                }
            }
            //printf("%s\n", cmd->args[cmd->iored[0]]);
            for(i = cmd->iored[0]; i <= cmd->nargs; cmd->nargs--)
            {
                free(cmd->args[cmd->nargs]);
                cmd->args[cmd->nargs] = NULL;
            }
            //printf("After: ");
            //printcmd(*cmd);
            fflush(NULL);

            child_pid = fork();
            if(child_pid < 0)
            {
                fprintf(stderr, "Fork Failed\n");
                exit(1);
            }
            else if(child_pid == 0)
            {
                if(io0 == 0)
                {
                    int fid0 = open(file0, O_RDONLY, 0666);
                    if(fid0 < 0)
                    {
                        fprintf(stderr, "File Not Found\n");
                        exit(1);
                    }
                    close(io0);
                    dup(fid0);
                    close(fid0);
                }
                if(io1 == 1)
                {
                    int fid1 =  open(file1, O_WRONLY | O_CREAT, 0666);
                    if(fid1 < 0)
                    {
                        fprintf(stderr, "File Not Found\n");
                        exit(1);
                    }
                    close(io1);
                    dup(fid1);
                    close(fid1);
                }
                if(io2 == 2)
                {
                    int fid2 =  open(file2, O_WRONLY | O_CREAT, 0666);
                    if(fid2 < 0)
                    {
                        fprintf(stderr, "File Not Found\n");
                        exit(1);
                    }
                    close(io2);
                    dup(fid2);
                    close(fid2);
                }
                execvp(cmd->cmd, cmd->args);
            }
            //in file equals out file
            ifeof:
            freeze(*cmd);
            free(cmd);
            
            //printcmd(*cmd);
            //fflush(NULL);

        }
        if(cmd->andflag)
        {
            waitpid(child_pid, CHILD_STATUS, WNOHANG);
        }
        else
        {
            waitpid(child_pid, CHILD_STATUS, 0);
        }
        //Command to take input
        printf("tosh$ ");
        fgets(input, sizeof input, stdin);
    }
    return 0;
}

