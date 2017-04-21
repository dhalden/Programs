#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printarray(int *arr, int len) {
  printf("[%d", *arr);
  for(int i = 1; i < len; i++) {
    printf(", %d", arr[i]);
  }
  printf("]\n");
}

int swap (int *array, int i1, int i2) {
  if(i1 != i2) {
    array[i1] ^= array[i2];
    array[i2] ^= array[i1];
    array[i1] ^= array[i2];
  }
  return array[i2];
}


int partition(int *array, int low, int high) {
  srand(time(NULL));
  int pivot = ((rand()) % (high-low)) + low; 
  pivot = swap(array, pivot, high); // move random value to end. 
  printarray(array, 14);
  int i = low;
  for(int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      swap(array, j, i);
      i++;
    }
  }
  swap(array, i, high);
  return i;
}


void quicksort(int *array, int low, int high) {
  if (high > low) { 
    int p = partition(array, low, high);
    quicksort(array, low, p-1);
    quicksort(array, p+1, high);
  }
}



int main(int argc, char **argv) {
  int arr[14] = {213, 4, 36, 2, 8, 4, 6, 12, 5, 3, 111, 0, -4, -9};
  int len = sizeof(arr)/sizeof(int);
  printarray(arr, len);
  quicksort(arr, 0, len-1);
  printarray(arr, len);
}



