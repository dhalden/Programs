// Modifier: Derek Halden
// Due Date: 11/26/13 2:00 PM
#include <assert.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// include header files from the dictionary and word_list
#include "processes.h"

#define MAX_JOBS 100
// Soooo there was a bug that was fixed by making my MLQ arrays for the 2nd and
// 3rd processes larger.  So I made them larger! I chose YA at random though.
#define YA 10000

//Maintains order, and data for all of the algorithms
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

// actual 3-tiered priority queue for  MLQ
typedef struct Mlq{
    int lvl1[MAX_JOBS];
    int lvl2[YA];
    int lvl3[YA];
    //current end 1st queue
    int ce1;
    int ce2;
    int ce3;
    int cb1;
    int cb2;
    int cb3;
} Mlq;
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
    int mttf = 0;
	printf("**********  SUMMARY ***********\n");
	printf("\tStart\tend\trun\tblocks\tutil percent\n");
	for(i = 0; i <= num_jobs; i++)
	{
        int s = q->start_times[i];
        int b = q->blocks[i];
        int r = q->run_times[i];
        int e = q->end_times[i];
        float up =((float)r)/((float)e-(float)s);
        mttf += e;
		printf("PID%d:\t%d\t%d\t%d\t%d\t%1.3f\n", i, s, e, r, b, up);
	}
    mttf = mttf/(num_jobs+1);
    printf("Mean Time to Finish: \t%d\n", mttf);
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
   int finish = 0;
   int time_waited = 0;
   int time_left = 0;
   int tr = 0;
   int proc_arrival;
   int arrival;
   q->somethingIsBlocked = 0;
   q->start_times[0] = 0;
   q->end_times[0] = 0;
   q->run_times[0] = 0;
   q->blocked[0] = 0;
   q->blocks[0] = 0;
   q->begin = 0;
   q->end = 0;
   if((algorithm == 0))
   {
        //Shortest Remaining Time
        int curr_proc = -1;
        arrival = 0;
        proc_arrival = q->end + 1;
        int total_finished = 0;
        while(total_finished <= q->end)
        {
            int min_id = -1;
            int min = INT_MAX;
            for(i=q->begin; i <= q->end; i++)
            {
                if(q->blocked[i] <= 0)
                {
                    int temp = proc_time_remaining(proc, i);
                    if(temp > 0)
                     {
                         if(temp < min)
                         {
                            min = temp;
                            min_id = i;
                         }
                     }
                }
            }
            if(curr_proc == min_id)
            {
                time_left = time_step - tr;
            }
            else
            {
                time_left = time_step;
            }
            curr_proc = -1;
            if(min_id == -1)
            {
                tr = proc_norun_check_arrival(proc, time_left, current_time,
                                               &arrival, &proc_arrival); 
                time_waited += tr;
            }
            else
            {
                tr = run_proc(proc, min_id, time_left, &block, &finish,
                              current_time, &arrival, &proc_arrival);
            }
            if(tr > 0)
            {
                if(q->somethingIsBlocked)
                {
                    int p;
                    int num_blocked = 0;
                    for(p=q->begin; p <= q->end; p++)
                    {
                        q->blocked[p] -=tr;
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
                        q->somethingIsBlocked = 0; 
                    }
                }
                current_time += tr;
                q->run_times[min_id] += tr;
                if(block)
                {
                    q->blocks[min_id]++;
                    q->blocked[min_id] = 200;
                    q->somethingIsBlocked = 1;
                    block = 0;
                }
                if(finish)
                {
                    q->end_times[min_id] = current_time;
                    total_finished++;
                    finish = 0;
                }
                if(arrival)
                {
                    q->end++;
                    proc_arrival = q->end + 1;
                    q->blocked[q->end] = 0;
                    q->blocks[q->end] = 0;
                    q->run_times[q->end] = 0;
                    q->start_times[q->end] = current_time;
                    q->end_times[q->end] = 0;
                    curr_proc = min_id;
                    arrival = 0;
                }
                else
                {
                    curr_proc = -1;
                }
            }
        }
   }
   else if((algorithm == 1))
   {
   //First Come First Serve
   while((q->end >= q->begin) && q->end_times[q->end] == 0)
   {
       proc_print(proc);
       printf("\ntime left: %d\n", time_left);
       printf("current_time: %d\n", current_time);
       if(!arrival)
       { 
           time_left = time_step;
       } 
       finish = 0;
       proc_arrival = q->end + 1;
       arrival = 0;

       if(q->blocked[i] <= 0)  
       {
           //time ran
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
	     	    printf("This totally happens");
                    time_left -= tr;
                    q->run_times[i] += tr;
                    q->end_times[i] = current_time;
                    current_time += tr;
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
             
        printf("i %d tr %d block %d finish %d current_time %d arrival %d\n",
                                 i, tr, block, finish, current_time, arrival); 
        printf("q->end: %d q->begin: %d i: %d\n", q->end, q->begin, i);
       }
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
                      printf("blocked[%d]: %d\n", p, q->blocked[p]);
                      printf("tr = %d\n", tr);
                      printf("time Left1 = %d\n", time_left);
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
                      printf("time Left2 = %d\n", time_left);
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
        printf("k %d tr %d block %d finish %d current_time %d arrival %d\n",
        k, tr, block, finish, current_time, arrival); 

            goto pastblock; 
       }
       if(q->somethingIsBlocked && tr > 0)
       {
          int p;
          int num_blocked = 0;
          for(p=q->end; p >= 0; p--)
          {
              printf("blocked2[%d]: %d\n", p, q->blocked[p]);
              printf("tr = %d\n", tr);
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
        printf("i %d tr %d block %d finish %d current_time %d arrival %d\n",
                                 i, tr, block, finish, current_time, arrival); 
        printf("q->end: %d q->begin: %d i: %d\n", q->end, q->begin, i);
   }
   else if (algorithm == 2)
   {
       //round-robin
        int total_finished = 0; 
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
        arrival = 0;
        proc_arrival = q->end + 1;
        //new multi-level queue
        Mlq * m = malloc(sizeof(Mlq));
        int total_finished = 0;
        m->ce1 = 0;
        m->ce2 = 0;
        m->ce3 = 0;
        m->cb1 = 0;
        m->cb2 = 0;
        m->cb3 = 0;
        // Just to keep things simple, non-occupied slots in the MLQ
        // are -1. That way I can't try and run them.
        int j;
        for(j = 0; j < MAX_JOBS; j++)
        {
            m->lvl1[j] = -1;
            m->lvl2[j] = -1;
            m->lvl3[j] = -1;
        }
        m->lvl1[m->ce1] = q->begin;
        m->ce1++;
        while (total_finished <= q->end)
        {
            //printf("Total_finished: %d\n", total_finished);
          //  printf("Current_time: %d\n", current_time);
            //proc_print(proc);
            int mark = 0;
            // because m->lvl1[m->cb1] was super easy to type,
            // and also very clear about what it was.
            int check1 = m->lvl1[m->cb1];
            if(abs(m->ce1 - m->cb1) > 0 && (check1 >= 0))
            {
                if(q->blocked[check1] <= 0)
                {
                    
                    i = check1;
                    m->lvl1[m->cb1] = -1;
                    m->cb1 = (m->cb1 + 1) % MAX_JOBS;
                    mark = 1;
                    //printf("%d This happens\n", m->cb1);
                    // I was going to do a while statement,
                    // with 4 breaks, but then I realized I could use a goto!
                    goto ready; 
                }
            }
            int check2 = m->lvl2[m->cb2];
            if(abs(m->ce2 - m->cb2) > 0 && (check2 >= 0))
            {
                if(q->blocked[check2] <= 0)
                {
                    i = check2;
                    m->lvl2[m->cb2] = -1;
                    m->cb2 = (m->cb2 + 1) % YA;
                    mark = 2;
                    //printf("%d This happens2\n", m->cb2);
                    goto ready; 
                }
            }
            int check3 = m->lvl3[m->cb3];
            if(abs(m->ce3 - m->cb3) > 0 && (check3 >= 0))
            {
                if(q->blocked[check3] <= 0)
                {
                    i = check3;
                    m->lvl3[m->cb3] = -1;
                    m->cb3 = (m->cb3 + 1) % YA;
                    //printf("%d This happens3\n", m->cb3);
                    mark = 3;
                    goto ready;
                }
            }
            ready:
        //    printf("mark: %d, i: %d\n", mark, i);
            if(!mark)
            {
               time_left = time_step;
               tr = proc_norun_check_arrival(proc, time_left, current_time,
                                             &arrival, &proc_arrival);
               time_waited += tr;
                
            }
            else
            {
                if (mark == 1)
                {
                    time_left = 100;
                }
                if (mark == 2)
                {
                    time_left = 200;
                }
                if (mark == 3)
                {
                    time_left = 400;
                }
                tr = run_proc(proc, i, time_left, &block, &finish, current_time,
                                                    &arrival, &proc_arrival);
                if(tr > 0)
                {
                    q->run_times[i] += tr;
                }
            }
      //      printf("tr = %d\n", tr);
            if(tr > 0)
            {
                current_time += tr;
                if(arrival)
                {
                    //mark the new process as having arrived
                    //initialize everything in the master queue
                    q->end++;
                    proc_arrival = q->end + 1;
                    q->blocked[q->end] = 0; 
                    q->blocks[q->end] = 0; 
                    q->run_times[q->end] = 0; 
                    q->start_times[q->end] = current_time; 
                    q->end_times[q->end] = 0; 
                    //add the disrupted job to the front of queue lvl 1
                    if(mark)
                    {
                        m->cb1 = ((m->cb1 + MAX_JOBS)  - 1) % MAX_JOBS;
                        m->lvl1[m->cb1] = i;
                    }
                    //add the new job in front of the disrupted job
                    m->cb1 = ((m->cb1 + MAX_JOBS) - 1) % MAX_JOBS;
                    m->lvl1[m->cb1] = q->end;
                    arrival = 0;
                }
                if(q->somethingIsBlocked)
                {
                    //Same process I use for RR, and SRT
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
                        q->somethingIsBlocked = 1;
                    }
                }
                if(block)
                {
                    // It was confusing to me what I should do here, so 
                    // I'll tell you what I did do! 
                    // (I wrote this part 2:00 AM the night before. I know this
                    // is shameful)
                    // If the process blocked, I added it to the end of the
                    // highest priority queue.
                    // if I get to the process, and it hasn't unblocked, I know
                    // that every process after it (in that queue) is blocked,
                    // So I move on to the first process in the next queue 
                    q->blocked[i] = 200;
                    q->blocks[i]++;
                    q->somethingIsBlocked = 1;
                    m->lvl1[m->ce1] = i;
                    m->ce1 = (m->ce1 + 1) % MAX_JOBS;
                    block = 0;
                }
                if(finish)
                {
                    q->end_times[i] = current_time;
                    total_finished++;
                    finish = 0;
                }
                if((mark == 1) && (tr == time_left))
                {
                    //printf("This is advancing job %d to queue 2\n", i);
                    m->lvl2[m->ce2] = i;
                    m->ce2 = (m->ce2 + 1) % YA;
                }
                if((mark == 2) && (tr == time_left))
                {
                    //printf("This is advancing job %d to queue 3\n", i);
                    m->lvl3[m->ce3] = i;
                    m->ce3 = (m->ce3 + 1) % YA;
                }
                if((mark == 3) && (tr == time_left))
                {
                    //printf("This is advancing job %d to queue 4\n", i);
                    m->lvl3[m->ce3] = i;
                    m->ce3 = (m->ce3 + 1) % YA;
                }
//               printf("m->cb1: %d m->ce1: %d\n", m->cb1, m->ce1);
  //             printf("m->cb2: %d m->ce2: %d\n", m->cb2, m->ce2);
    //           printf("m->cb3: %d m->ce3: %d\n", m->cb3, m->ce3);
            }
        }
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

