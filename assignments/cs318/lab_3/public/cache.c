#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <math.h>

int associativity = 2;          // Associativity of cache
int blocksize_bytes = 32;       // Cache Block size in bytes
int cachesize_kb = 64;          // Cache size in KB
int miss_penalty = 30;




void
print_usage ()
{
  printf ("Usage: gunzip2 -c <tracefile> | ./cache -a assoc -l blksz -s size -mp mispen\n");
  printf ("  tracefile : The memory trace file\n");
  printf ("  -a assoc : The associativity of the cache\n");
  printf ("  -l blksz : The blocksize (in bytes) of the cache\n");
  printf ("  -s size : The size (in KB) of the cache\n");
  printf ("  -mp mispen: The miss penalty (in cycles) of a miss\n");
  exit (0);
}

int main(int argc, char * argv []) {

  long address;
  int loadstore, icount;
  char marker;
  
  int i = 0;
  int j = 1;
  // Process the command line arguments
 // Process the command line arguments
  while (j < argc) {
    if (strcmp ("-a", argv [j]) == 0) {
      j++;
      if (j >= argc)
        print_usage ();
      associativity = atoi (argv [j]);
      j++;
    } else if (strcmp ("-l", argv [j]) == 0) {
      j++;
      if (j >= argc)
        print_usage ();
      blocksize_bytes = atoi (argv [j]);
      j++;
    } else if (strcmp ("-s", argv [j]) == 0) {
      j++;
      if (j >= argc)
        print_usage ();
      cachesize_kb = atoi (argv [j]);
      j++;
    } else if (strcmp ("-mp", argv [j]) == 0) {
      j++;
      if (j >= argc)
        print_usage ();
      miss_penalty = atoi (argv [j]);
      j++;
    } else {
      print_usage ();
    }
  }

  // print out cache configuration
  printf("Cache parameters:\n");
  printf ("Cache Size (KB)\t\t\t%d\n", cachesize_kb);
  printf ("Cache Associativity\t\t%d\n", associativity);
  printf ("Cache Block Size (bytes)\t%d\n", blocksize_bytes);
  printf ("Miss penalty (cyc)\t\t%d\n",miss_penalty);
  printf ("\n");



    int bs_bits;
    int tag_bits;
    int index_bits;

  
    bs_bits = log(blocksize_bytes)/log(2);
    tag_bits = 32 - (log(cachesize_kb*1024/associativity)/log(2));
    index_bits = log(cachesize_kb*1024/(associativity*blocksize_bytes))/log(2);

    printf("bs_bits: %d\ntag_bits: %d\nindex_bits: %d\n\n", bs_bits, tag_bits, index_bits);

    int bo_mask;
    int tag_mask;
    int index_mask;
    index_mask = ((1 << index_bits) - 1) << bs_bits;
    tag_mask = ((1 << tag_bits) - 1) << (bs_bits + index_bits);
    
    printf("tagmask: %x\nindexmask: %x\n", tag_mask, index_mask);

    int cash = (cachesize_kb * 1024/blocksize_bytes)/associativity; 

    printf("cash = \t%d\n\n", cash);

    int tdArray[cash][associativity];
    int lru[cash][associativity];
    int dirty[cash][associativity];
    int valid[cash][associativity];
    int s;
    for (s = 0; s < cash; s++)
    {
        int t;
        for(t = 0; t < associativity; t++)
        {
            lru[s][t] = 0;
            tdArray[s][t] = 0;
            dirty[s][t] = 0;
            valid[s][t] = 0;
        }
    }


    //usage variables
    //int etime;
    long inst = 0;
    long mem_axe = 0;
    //int tot_mr;
    //int read_mr;
    //int mem_cpi;
    //int tot_cpi;
    //int avg_mat;
    int dirty_evicts = 0;
    int load_miss = 0;
    int store_miss = 0;
    int load_hit = 0;
    int store_hit = 0;
    int miss_cycles = 0;

  while (scanf("%c %d %lx %d\n",&marker,&loadstore,&address,&icount) != EOF) {
    // Code to print out just the first 10 addresses.  You'll want to delete
    // this part once you get things going.

    //here is where you will want to process your memory accesses
    //printf("loadstore: %d\n", loadstore);
    inst += icount;
    if(loadstore == 0) //load
    {
        mem_axe++;
        //printf("load: %x, marker: %x\n", icount, marker);
        unsigned int temp_ib;
        unsigned int temp_tb;
        temp_ib = index_mask & address;
        temp_tb = tag_mask & address;

        //Works for direct mapped
        int a;
        int hit; 
        hit = 0;
        //first check if it's in the array
        for(a = 0; a < associativity; a++)
        {
            if(tdArray[(temp_ib >> bs_bits)][a] == temp_tb
                        && (valid[(temp_ib >> bs_bits)][a]))
            {
                lru[(temp_ib >> bs_bits)][a] = i;
                load_hit++;
                hit = 1;
                break;
            }

        }
        if(!hit){
            load_miss++;
            //if it's not in the array, find the lru and evict it.
            int la = 0;
            for(a = 0; a < associativity; a++)
            {
                   if(lru[(temp_ib >> bs_bits)][a] < lru[(temp_ib >> bs_bits)][la])
                   {
                        la = a;
                   }
            }
            if(dirty[(temp_ib >> bs_bits)][la])
            {
                //dirty
                //write-back to memory
                miss_cycles = miss_cycles + miss_penalty + 2;
                dirty_evicts++;
                dirty[(temp_ib >> bs_bits)][la] = 0;
            }
            else
            {
                //clean
                miss_cycles = miss_cycles + miss_penalty;
            }
            tdArray[(temp_ib >> bs_bits)][la] = temp_tb;
            lru[(temp_ib >> bs_bits)][la] = i;
            valid[(temp_ib >> bs_bits)][la] = 1;
        }
    }
    else if(loadstore == 1) //store
    {
        mem_axe++;
        unsigned int temp_ib;
        unsigned int temp_tb;
        temp_ib = index_mask & address;
        temp_tb = tag_mask & address;
        int a;
        int hit; 
        hit = 0;
        for(a = 0; a < associativity; a++)
        {
            if(tdArray[(temp_ib >> bs_bits)][a] == temp_tb 
                    && (valid[(temp_ib >> bs_bits)][a] = 1)) //hit
            {
                lru[(temp_ib >> bs_bits)][a] = i;
                dirty[(temp_ib >> bs_bits)][a] = 1;
                hit = 1;
                store_hit++;
                break;
            }
        }
        if(!hit)
        {
            store_miss++;
            //if it's not in the array, find the lru and evict it.
            int la = 0;
            for(a = 0; a < associativity; a++)
            {
                   if(lru[(temp_ib >> bs_bits)][a] < lru[(temp_ib >> bs_bits)][la])
                   {
                        la = a;
                   }
            }
            if(dirty[(temp_ib >> bs_bits)][la])
            {
                //dirty
                //write-back to memory
                miss_cycles = miss_cycles + miss_penalty + 2;
                dirty_evicts++;
            }
            else
            {
                //clean
                miss_cycles = miss_cycles + miss_penalty;
            }
            lru[(temp_ib >> bs_bits)][la] = i;
            tdArray[(temp_ib >> bs_bits)][la] = temp_tb;
            dirty[(temp_ib >> bs_bits)][la] = 1;
            valid[(temp_ib >> bs_bits)][la] = 1;
        }
    }
	i++;
  }
  // Here is where you want to print out stats
  //printf("Lines found = %i \n",i);
  printf("Simulation results:\n");
  //  Use your simulator to output the following statistics.  The 
  //  print statements are provided, just replace the question marks with
  //  your calcuations.
  
  
  printf("\texecution time %ld cycles\n",(long)(inst + miss_cycles));
  printf("\tinstructions %ld\n", inst);
  printf("\tmemory accesses %ld\n", mem_axe);
  printf("\toverall miss rate %.2f\n", (float)(load_miss + store_miss)/mem_axe);
  printf("\tread miss rate %.2f\n", (float)(load_miss)/(load_miss + load_hit));
  printf("\tmemory CPI %.2f\n", (float)(miss_cycles)/inst);
  printf("\ttotal CPI %.2f\n",(float)(inst+miss_cycles)/inst);
  printf("\taverage memory access time %.2f cycles\n", (float)(miss_cycles)/mem_axe);
  printf("dirty evictions %d\n", dirty_evicts);
  printf("load_misses %d\n", load_miss);
  printf("store_misses %d\n", store_miss);
  printf("load_hits %d\n", load_hit);
  printf("store_hits %d\n", store_hit);
  

}
