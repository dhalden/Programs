#include <assert.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// include header files from the dictionary and word_list
#include "processes.h"

#define MAX_JOBS 100
typedef struct Queue{
    int blocked[MAX_JOBS];
    int blocks[MAX_JOBS];
    int run_times[MAX_JOBS];
    int start_times[MAX_JOBS];
    int end_times[MAX_JOBS];
    int begin;
    int end;
    int somethingIsBlocked; //1 if something is blocked. Zero otherwise
} Queue;
int algorithm;
char * filename;

void print_usage()
{
printf("Usage: ./schedule <algorithm> <input file>\n");
printf("\tAlgorithms are\t0: Shortest Job Remaining\n");
printf("\t\t\t1: First Come First Serve\n");
printf("\t\t\t2: Round Robin\n");
printf("\t\t\t3: Multi-level queues\n");
exit(0);
}

void print_finished(Queue * q, int num_jobs, int itime)
{
	/*  Fill in with your stats!
	int i =0;
	printf("**********  SUMMARY ***********\n");
	printf("\tStart\tend\trun\tblocks\tutil percent\n");
	for(;i<num_jobs;i++)
	{
		printf("PID%d:\t%d\t%d\t%d\t%d\t%1.3f\n",XX,XX,XX,XX,XX,XX);
	}
	printf("Mean Time to Finish:\t%d\n",XX);
	printf("Total idle time:\t%d\n",XX);
	*/
	int i;
	printf("**********  SUMMARY ***********\n");
	printf("\tStart\tend\t\trun\tblocks\tutil percent\n");
	for(i = 0; i <= num_jobs; i++)
	{
        int s = q->start_times[i];
        int b = q->blocks[i];
        int r = q->run_times[i];
        int e = q->end_times[i];
		printf("PID%d:\t%d\t%d\t%d\t\t%d\n", i, s, e, r, b);//XX);
	}
	printf("Total idle time:\t%d\n", itime);
	
}

int main (int argc, char * argv [])
{
	int j = 1;
	algorithm = -1;


	if(argc!=5)
	{
		print_usage();
	}
	// process command line arguments
	while (j < argc) {
		if (strcmp ("-alg", argv [j]) == 0) {
			j++;
			if (j >= argc)
				print_usage ();
			algorithm = atoi (argv [j]);
			j++;
		} else if (strcmp ("-file", argv [j]) == 0) {
			j++;
			if (j >= argc)
				print_usage ();
			filename = argv [j];
			j++;
		}
		else{
		j++;
		}
	}
	if((algorithm == -1) || (filename==NULL))
	{
		print_usage();
	}


   // we'll always assume a basic quanta is 100 time units
   int time_step = 100;
   
   // create the system emulation of processes from the file
   Processes * proc = proc_create(filename);
   Queue * q = malloc(sizeof(Queue)); 
   //setup first job
   // You may assume that there is a job 0 which arrived
   // at time 0 and is ready to go


   int current_time = 0;
   int i= 0;
   int block = 0;
   int time_waited = 0;
   int time_left = 0;
   int tr = 0;
   int proc_arrival;
   int arrival;
   q->start_times[0] = 0;
   q->end_times[0] = 0;
   q->run_times[0] = 0;
   q->blocks[0] = 0;
   q->begin = 0;
   q->end = 0;
   if((algorithm == 0))
   {

   }
   else if((algorithm == 1))
   {
   //First Come First Serve
   while((q->end >= q->begin)&& q->end_times[q->end] ==0)
   {
       //proc_print(proc);
       //printf("\ntime left: %d\n", time_left);
       //printf("current_time: %d\n", current_time);
       if(time_left == 0)
       { 
           time_left = time_step;
       } 
       int finish = 0;
       proc_arrival = q->end + 1;
       arrival = 0;

       if(q->blocked[i] <= 0)  
       {
             tr = run_proc(proc, i, time_left, &block, &finish,
                        current_time, &arrival, &proc_arrival); 
             if(tr != -1 && tr != -2 && !(finish))
             {
                time_left -= tr;
                current_time += tr;
                q->run_times[i] += tr;
             }
             else
             {
                 if(finish)
                 {
                    time_left -= tr;
                    current_time += tr;
                    q->run_times[i] += tr;
                    q->end_times[i] = current_time;
                    i++;
                    q->begin++;
                 }
                 else if(tr == -2)
                 {
                    i++;
                    q->begin++;
                 }
                 goto pastblock;
             }
             
       /* printf("i %d tr %d block %d finish %d current_time %d arrival %d\n",
                                 i, tr, block, finish, current_time, arrival); 
        printf("q->end: %d q->begin: %d i: %d\n", q->end, q->begin, i);
*/       }
       else if ((q->end - q->begin) == 0)// more than one process
       {
           tr = proc_norun_check_arrival(proc, time_left,
                                 current_time, &arrival, &proc_arrival); 
           time_left -= tr;
           time_waited += tr;
           current_time += tr;
       }
       else
       {
           int k = i+1;
           if(q->end < k)
           {
                k = q->end;
           }
           while(k <= q->end)
           {
                if(q->blocked[k] <= 0)  
                {
                    
                    tr = run_proc(proc, k, time_left, &block, &finish,
                                    current_time, &arrival, &proc_arrival); 
                    if(tr != -1 && tr != -2 && !(finish))
                    {
                        time_left -= tr;
                        current_time += tr;
                        q->run_times[k] += tr;
                    }
                    else
                    {
                        if(finish)
                        {
                           q->end_times[k] = current_time;
                           current_time += tr;
                           q->run_times[k] += tr;
                        }
                        finish = 0;
                        goto middlefinished;
                    }
                    break;
                }
                else if ((q->end - k) == 0) // if more than one process
                {
                    tr = proc_norun_check_arrival(proc, time_left,
                                current_time, &arrival, &proc_arrival);
                    time_left -= tr;
                    time_waited += tr;
                    current_time += tr;
                    break;
                }
                else
                {
                    middlefinished:
                    k++;
                }
            }
            
            if(q->somethingIsBlocked && tr > 0)
            {
                int p;
                int num_blocked = 0;
                for(p=q->end; p >= 0; p--)
                {
                      //printf("blocked[%d]: %d\n", p, q->blocked[p]);
                      /*printf("tr = %d\n", tr);
                      printf("time Left1 = %d\n", time_left);*/
                      q->blocked[p] -= (tr);
                      if(q->blocked[p] > 0)
                      {
                          num_blocked++;
                         if(q->blocked[p] <= time_left)
                          {
                              time_left = q->blocked[p];
                          }
                         else if ((q->blocked[p] < time_step) && time_left == 0)
                          {
                              time_left = q->blocked[p];
                          }
                      }
                      else
                      {
                            q->blocked[p] = 0;
                      }
                     // printf("time Left2 = %d\n", time_left);
                }
                if(!num_blocked)
                {
                   q->somethingIsBlocked = 0;
                }
            }
            if(block)
            {
                q->blocked[k] = 200;
                q->blocks[k]++;
                q->somethingIsBlocked = 1;
            }
        //printf("k %d tr %d block %d finish %d current_time %d arrival %d\n",
        //k, tr, block, finish, current_time, arrival); 

            goto pastblock; 
       }
       if(q->somethingIsBlocked && tr > 0)
       {
          int p;
          int num_blocked = 0;
          for(p=q->end; p >= 0; p--)
          {
              //printf("blocked2[%d]: %d\n", p, q->blocked[p]);
              //printf("tr = %d\n", tr);
              q->blocked[p] -= (tr);
              if(q->blocked[p] > 0)
              {
                  num_blocked++;
                  if(q->blocked[p] <= time_left)
                  {
                      time_left = q->blocked[p];
                  }
                  else if ((q->blocked[p] < time_step) && time_left == 0)
                  {
                      time_left = q->blocked[p];
                  }
              }
          }
          if(!num_blocked)
          {
             q->somethingIsBlocked = 0;
          }
       }
       if(block)
       {
          q->blocked[i] = 200;
          q->blocks[i]++;
          q->somethingIsBlocked = 1;
       }
       pastblock:
       if(arrival)
       {
           q->end++;
           q->start_times[q->end] = current_time;
           q->end_times[q->end] = 0;
           q->blocked[q->end] = 0;
           q->run_times[q->end] = 0;
           q->blocks[q->end] = 0;
       }
       block = 0;
   }
   }
   else if (algorithm == 2)
   {
       //round-robin
        int total_finished = 0; 
        int finish = 0;
        q->somethingIsBlocked = 0;
        proc_arrival = q->end+1;
        while(total_finished <= q->end)
        {
            
           //proc_print(proc); 
           int eib = 1;    // everything is blocked. 1 if true.
           for(i = q->begin; i <= q->end; i++)
           {
            if(q->blocked[i] <= 0)
            {
                if(!q->end_times[i])
                {
                    tr = run_proc(proc, i , time_left, &block, &finish,
                                  current_time, &arrival, &proc_arrival); 
                    if(tr >= 0)
                    {
                        q->run_times[i] += tr;
                        current_time += tr;
                        if(arrival)
                        {
                            i--; // run for remaining time quanta
                            time_left = time_step - tr;
                            q->end++;
                            proc_arrival = q->end+1;
                            //add the new process to the list
                            q->blocked[q->end] = 0;
                            q->blocks[q->end] = 0;
                            q->run_times[q->end] = 0;
                            q->start_times[q->end] = current_time;
                            q->end_times[q->end] = 0;
                            arrival = 0;
                        }
                        else
                        {
                            time_left = time_step;
                        }
                        if(q->somethingIsBlocked)
                        {
                            int p;
                            int num_blocked = 0;
                            for(p=q->begin; p <= q->end; p++)
                            {
                                q->blocked[p] -= tr;
                                if(q->blocked[p] > 0)
                                {
                                    num_blocked++;
                                } 
                                else
                                {
                                    q->blocked[p] = 0;
                                }
                            }
                            if(!num_blocked)
                            {
                                q->somethingIsBlocked=0;
                            }
                        }
                        if(block)
                        {
                            q->blocked[i] = 200;
                            q->blocks[i]++;
                            q->somethingIsBlocked = 1;
                            block = 0;
                        }
                        if(finish)
                        {
                            q->end_times[i] = current_time;
                            total_finished++;
                            finish = 0;
                        }
                        eib = 0;
                    }
                }
            }

           }
           if (eib)
           {
               tr = proc_norun_check_arrival(proc, time_left, current_time,
                                                    &arrival, &proc_arrival);
                current_time += tr;
                if(arrival)
                {
                    time_left = time_step;
                    time_waited += tr;
                    q->end++;
                    proc_arrival = q->end+1;
                    //add the new process to the list
                    q->blocked[q->end] = 0;
                    q->blocks[q->end] = 0;
                    q->run_times[q->end] = 0;
                    q->start_times[q->end] = current_time;
                    q->end_times[q->end] = 0;
                    arrival = 0;
                }
                else
                {
                    time_left = time_step;
                    time_waited += tr;
                }
                if(q->somethingIsBlocked)
                {
                    int p;
                    int num_blocked = 0;
                    for(p=q->begin; p <= q->end; p++)
                    {
                        q->blocked[p] -= tr;
                        if(q->blocked[p] > 0)
                        {
                            num_blocked++;
                        } 
                        else
                        {
                            q->blocked[p] = 0;
                        }
                    }
                    if(!num_blocked)
                    {
                        q->somethingIsBlocked=0;
                    }
                }
            }
        }        
    }
    else if (algorithm == 3)
    {
        //Multi-level Queue

    }

   // Here is the bulk of your work.  
   // You will need to run until you've finished running all the
   // incoming processes.  (You may assume that when you have
   // finished all the jobs you know about, you are
   // done.  Arrival times will always be early enough
   // to ensure future processes have arrived before
   // you have finished previous ones.)

   print_finished(q, q->end, time_waited);

   proc_destroy(proc);
   free(proc);
   proc=NULL;
   return 0;
}
