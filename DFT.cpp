#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
//#define N 8
using namespace std;
int N =0;
main(){
	float tmp =0;
	FILE *file = fopen("pontos.txt", "r");
	if (file == NULL){
		cout<<"Erro na abertura\n";
		exit(1);
	}
	fscanf(file,"%i",&N);
	float xn[N];
	for(int i=0; i< N; i++){
		fscanf(file,"%f",&tmp);
		xn[i] = tmp;
	}

	float ts = 1.0/8000, real, img;

	for (int m = 0; m < N; m++)
	{
		real = 0; img = 0;
		for (int n = 0; n < N; n++)
		{
			real += xn[n] * cos(2*M_PI*n*m/N);
			img += -1 * xn[n] * sin(2*M_PI*n*m/N);
		}

	}
}
