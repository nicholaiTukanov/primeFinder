#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Usage
	Compile as a normal c file. 
	Name the exe whatever you want but for example sake I will use the name primes
	Type  "./primes <p>" where p is integer that is in between [1,6]
	*/
int main(int argc, char **argv){

	/* Create a text file named primes to store all the numbers */
	FILE *file = fopen("primes.txt", "w+");
	
	/* Ignore 1 as prime */
	int i = 2;
	
	/* Index for prime number */
	int p_i = 0;
	
	/* 10^p will be the limit 
		NOTE: the runtime is LONG. It is O(10^p * k) where k is the dependent on the growth of lenP.
		Do not put in arguments that are greater than 6 or else you'll be stuck waiting for a long time.
		Will be looking to do more research into speeding it up in my free time. 
	*/
	int p = atoi(*(argv+1));
	long long int x = pow(10,p);
	
	/* 10^p will be the size of prime array
		NOTE: this means space O(10^p) so be careful if you decide to run background with large p.
	*/
	long long int *primes = (long long int *)malloc(sizeof(long long int)*x);
	
	/* Holds next free index in prime array, also represents the size of prime array during any given
		iteration 
	*/
	int lenP = 0;
	
	/* Set to false when a factor of the number is found in the prime array */
	int primeflag = 1;

	/* Compute prime array */
	for(;i <= x; i++){

		/* Init the flag */
		primeflag = 1;

		/* If number can be divided evenly by a prime, then it is not a prime number. 
			NOTE: runtime is always O(lenP) but lenP will grow over the iterations of the outer loop.
		*/ 
		for(p_i = 0 ;p_i < lenP; ++p_i){
			int curPrime = primes[p_i];
			if(i%curPrime == 0)	
				primefalg = 0;
		}

		/* When flag is set, then number i is prime and needs to be added to the prime array. Increase lenP. */
		if(primeflag){
			fprintf(file,"%d\n", i);	
			primes[lenP] = i;
			++lenP;
		}
	}

	fclose(file);
}
