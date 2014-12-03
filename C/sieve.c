#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2000000000
int main()
{
	char primes[MAX]; 
	int i;
	for(i = 0; i < MAX; i++) {
		primes[i] = 'a';
		printf("%d", primes[i]);
	}
	return 0;
}
