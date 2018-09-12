#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printVals(long long int *primes,int lenP){
	for(int i=0;i<lenP;i++){
		printf("%d. %lld\n", i+1, primes[i]);
	}
}

int main(int argc, char **argv){

	int i = 2, p_i = 0;
	int p = atoi(*(argv+1));
	long long int x = pow(10,p);
	long long int *primes = (long long int *)malloc(sizeof(long long int)*x);
	int lenP = 0;
	int prime = 1;

	for(;i <= x; i++){

		prime = 1;

		for(p_i = 0 ;p_i < lenP; ++p_i){

			int curPrime = primes[p_i];
			if(i%curPrime == 0)	
				prime = 0;
		}

		if(prime != 0){	
			primes[lenP] = i;
			++lenP;
		}
	}

	printVals(primes,lenP);
}