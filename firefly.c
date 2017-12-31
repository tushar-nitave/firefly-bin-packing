//============================================================================
// Name        : Firefly.cpp
// Version     : v1.0
// Created on  : Dec 22, 2017
//============================================================================


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>

int n = 20;
int D = 10;
int ffa[100][100];
int f[100];
int I[100];
int lb[100];
int ub[100];


//initialize the firefly population
void init_ffa()
{
	int i, j;
	double r;

	// initialize upper and lower bounds
	for (i=0;i<D;i++)
	{
		lb[i] = 0.0;
		ub[i] = 5.0;
	}

	for (i=0;i<n;i++)
	{
		for (j=0;j<D;j++)
		{
			r = (   (double)rand() / ((double)(RAND_MAX)+(double)(1)) );
			ffa[i][j]=r*(ub[j]-lb[j])+lb[j];
		}
		f[i] = 1.0;			// initialize attractiveness
		I[i] = f[i];
	}
}


int main(){

	srand(time(NULL));

	init_ffa();

	//display the population
	for(int i=0; i<n; i++){
		for(int j=0; j<D; j++){
			printf("%d ", ffa[i][j]);
		}
		printf("\n");
	}
}