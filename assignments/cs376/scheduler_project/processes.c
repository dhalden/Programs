/* Processes.c
 *
 * Stores a list of processes.
 * Author: L. Porter
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "processes.h"

#define INIT_SIZE 1024


// represents a single job
struct Proc{
    int start_time; // start time

    // array of time intervals to run between blocking events
    int array[INIT_SIZE];

    int num_events;	// how many elements are in the array
    int curr_event;	// which "event" (index into array) is currently running
    int progress;   // how much progress you've made in that event
                    // progress<= array[curr_event]

    int done;       // if this process is done this is 1, else 0
    int announced;	// if you've announced this process to the parent, mark as 1

    // total time required to finish this job (just the sum of array)
    int total_time;

    int total_progress;	// total time you've run this job

 // total_time - total_progress is needed to report time remaining efficiently
};

// struct for all the jobs
struct Processes{
   struct Proc *array;      // array of Processes
   int internal_size;       // how big the array is total
   int size;                // how many valid Procs in the array
};

Processes * proc_create(char *filename)
{
   // This function is provided for you.
   // You will need to read through it to 
   // better understand how this is setup and
   // how to write the missing functions.
   Processes * retval = malloc(sizeof(Processes));

   int i =0,j=0,total_time=0;
   DEBUGPRINTF("Creating Processes\n");
   retval->array = malloc(sizeof(struct Proc)*INIT_SIZE);
   retval->internal_size = INIT_SIZE;
   retval->size = 0;

   // fill the array, walk 1 by 1

   FILE * istream;
   istream = fopen(filename, "r");
   
   char id[55];
   char time[55];
   
   i=-1;  // needed for this next step
   j = 0;
   while (fscanf(istream, "%s\t%s",id, time)!=EOF && i<INIT_SIZE-1)
   {
	int proc_id =atoi(id);
	if(proc_id == i)
	{
		if(j>=INIT_SIZE)
		{
			fprintf(stderr,"ERROR - too many time_steps %d\n",i);
			fflush(0);
			exit(1);

		}
		//found match, just add this word
		DEBUGPRINTF("SAME PROC ID: %d\n",proc_id);
		fflush(0);
		retval->array[i].array[j] = atoi(time);
		total_time+=atoi(time);
		retval->array[i].num_events++;
		retval->array[i].total_time = total_time;
		j++;
	}
	else
	{
		i++;
		if(i>=INIT_SIZE)
		{
			fprintf(stderr,"ERROR - too many jobs %d\n",i);
			fflush(0);
			exit(1);
		}
		retval->array[i].start_time = atoi(time);
		retval->array[i].num_events = 0;
		retval->array[i].curr_event = 0;
		retval->array[i].progress = 0;
		retval->array[i].total_progress = 0;
		retval->array[i].done = 0;
		if(i==0)
		{
			retval->array[i].announced = 1;
		}
		else
		{
			retval->array[i].announced = 0;
		}
		j=0;
		total_time = 0;
	}
	DEBUGPRINTF("Added %s\t%d\n",id, atoi(time));
   }
   DEBUGPRINTF("Total time required to run all%d\n",total_time);
   retval->size=i;
   fclose(istream);
   return retval;
}

void proc_print(Processes *proc)
{
   // this function is provided to you and may help you with debugging
   // and/or understanding your programs.
   int i,j, end;
   for(i = 0;i<=proc->size;i++)
   {
	   if(proc->array[i].announced)
	   {
		   if(proc->array[i].done)
		   {
			   printf("* ");
		   }
		   printf("PID: %d\t",i);
		   end = proc->array[i].num_events;
		   for(j=0;j<end;j++)
		   {
			   printf("%d\t",proc->array[i].array[j]);
		   }
		   printf("\n");
		   printf("Curr Event = %d. ",end = proc->array[i].curr_event);
		   printf("Curr Progress = %d. ",end = proc->array[i].progress);
		   printf("Total Progress = %d. ",end = proc->array[i].total_progress);
		   printf("Total Runtime = %d.\n",end = proc->array[i].total_time);
	   }
   }
   printf("\n\n\n");
}

int proc_norun_check_arrival(Processes *proc, int time_interval,
                             int current_time, int *arrival, int *proc_arrival)
{
	// YOU NEED TO COMPLETE THIS
	// See run_proc for directions.  
    // In this case, you aren't running any processes, but you need to report if
	// a process arrives during this time interval
    //printf("\n\nThis totally happens\n\n");
    int start_time = proc->array[*proc_arrival].start_time;
    //printf("start_time %d, current_time %d, proc_arrival %d\n",
     //start_time, current_time, *proc_arrival);
    if(*proc_arrival <= proc->size)
    {
        if(time_interval+current_time > start_time)
        {
            if(!proc->array[*proc_arrival].announced)
            {
            //printf("start_time %d, current_time %d, proc_arrival %d\n",
            // start_time, current_time, *proc_arrival);
            proc->array[*proc_arrival].announced++;
            *arrival = 1;
            return ((start_time) - current_time);
            }
        }
    }
    return time_interval;
	/*int i;
    for(i = 0; i < time_interval; i++)
    {
        
        if((i + current_time) == proc->array[*proc_arrival].start_time)
        {
            proc->array[i].announced++;
            *arrival = 1;
            current_time += i; 
            return i;
        }
    }
    *arrival = 0;
    return time_interval;
*/
}

int run_proc(Processes * proc, int proc_id, int time_interval, int * block,
             int * finish, int current_time, int * arrival, int * proc_arrival)
{
	// YOU NEED TO COMPLETE THIS
	// return -1 if proc is invalid or proc_id is invalid.
    // THIS MAY NOT BE CORRECT!!! CHECK THIS LATER!
    if((proc->array[proc_id].array[0] == 0))
    {
        return -1;
    }

	// return -1 if this job is already done
    // (you shouldn't be trying to run finished jobs)
    //
    if(proc->array[proc_id].done)
    {
        return -2;
    }

    int tr;
    int count;
    for(count = 1; count <= time_interval; count++)
    {
        if(time_interval < 0)
            {
                //printf("Time Interval is Negative: %d", time_interval);
            }
    	// check to see if anyone arrives during this time interval
	    //
        tr = (proc->array[proc_id].total_time -
             (proc->array[proc_id].total_progress + count));
        if((count + current_time) == (proc->array[*proc_arrival].start_time))
        {
            proc->array[*proc_arrival].announced++;
            proc->array[proc_id].total_progress += count;
            proc->array[proc_id].progress += count;
            *arrival = 1;
            current_time += count;
            if(tr <= 0)
            {
                proc->array[proc_id].done++;
                *finish = 1;
            }
            //printf("This is the exit1\n");
            return count;   
        }
    	// See if the process blocks during this time interval
	    //
        if((count + proc->array[proc_id].progress) ==
            proc->array[proc_id].array[proc->array[proc_id].curr_event])
        {
            proc->array[proc_id].curr_event++;
            proc->array[proc_id].progress = 0;
            proc->array[proc_id].total_progress += count;
            current_time += count; 
            *arrival = 0;
            if(tr <= 0)
            {
                proc->array[proc_id].done++;
                *finish = 1;
            }
            else
            {
                *block = 1;
            }
            //printf("This is the exit2\n");
            return count;   
        }
	    // run to the shortest of (someone arriving,
        //                         someone blocking, time_interval).
	    //

        //finished early
        if(tr <= 0)
        {
            proc->array[proc_id].total_progress += count;
            proc->array[proc_id].progress += count;
            current_time += count; 
            *arrival = 0;
            if(tr == 0)
            {
                proc->array[proc_id].done++;
                *finish = 1;
            }
            //printf("This is the exit3\n\n");
            return count;   
        }
    	// if you ran the whole time interval without an event. You are done.
	    // if you blocked, be sure to set the variables properly to notify the 
    	// parent that a blocking event occurred
	    //
    	// if you encountered a new process,
        // be sure to mark that process as having 
	    // been announced and be sure to set the
        // variables properly to notify the 
	    // parent that a new process arrived.
        // return how long you ran.
	}
    proc->array[proc_id].total_progress += time_interval;
    proc->array[proc_id].progress += time_interval;
    current_time += time_interval; 
    *arrival = 0;
    if(tr <= 0)
    {
         proc->array[proc_id].done++;
         *finish = 1;
    }
    //printf("This is the exit4\n");
    return time_interval;   
}

int proc_time_remaining(Processes *proc, int proc_id)
{
	// this function is provided to you for your
    // shortest_remaining_time schedule
	if(proc == 0)
	{
		return -1;
	}
	if(proc_id <0 || proc_id > proc->size)
	{
		return -1;
	}
	if(proc->array[proc_id].done == 1)
	{
		return 0;
	}
	return proc->array[proc_id].total_time -
           proc->array[proc_id].total_progress;
}

void proc_destroy(Processes *proc)
{
  // clean up the data structure here.
  free(proc->array);
}
