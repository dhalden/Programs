#ifndef PROCESSES_H
#define PROCESSES_H

// Macro.  if(1) disables printing, if(0) turns it on.
#define DEBUGPRINTF if(1){}else printf
typedef struct Proc{
    int start_time; // start time

    // array of time intervals to run between blocking events
    int array[1024];

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
} Proc;

typedef struct Processes
{
   struct Proc *array;      // array of Processes
   int internal_size;       // how big the array is total
   int size;                // how many valid Procs in the array
} Processes;
// Create your Processes struct using the filename of a schedule.txt
Processes * proc_create(char *filename);

// print state of the processes
void proc_print(Processes * proc);

// returns -1 if the process already finished or other problems
// returns amount of time it runs before either time_interval,
// a blocking event, or a new arrival
// block will be 1 if a blocking event occurs
// zero otherwise
// finish will be 1 if the job finishes
// arrival will be 1 if a new arrival shows up and the proc_arrival
// variable will be the proc_id of the new arrival
int  run_proc(Processes * proc, int proc_id, int time_interval, int * block, 
             int * finish, int current_time, int *arrival, int *proc_arrival);

// returns -1 if  invalid inputs
// return 0 if the job is already done
// return remaining time
int  proc_time_remaining(Processes *proc, int proc_id);

// use this instead of run_proc if not running a process
// it will tell you if you have an event arriving during an empty time interval
// returns time interval until the process arrival
// occurs or the provided time interval
// returns -1 if proc is invalid
int  proc_norun_check_arrival(Processes *proc, int time_interval, 
                             int current_time, int *arrival, int *proc_arrival);

// Function to clean up the data structure
void proc_destroy();

#endif // PROCESSES_H
