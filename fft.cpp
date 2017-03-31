#include <iostream>
#include <math.h>
#include <iomanip>
#include <limits>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
//#define N 8
using namespace std;
int N =0;

void FFT(float *real, float *imag, int NPuntos)
{
  int Fases, Grupos;
  int fase, grupo, NumDatosGrupo, dual;
  int i, j, grupoini, pos, pos_dual,aux;
  float real_i, imag_i, real_dual, imag_dual;
  float coseno, seno,PI=3.141592654;
  Fases = log(NPuntos)/log(2.0F)+1;
  Grupos = 1;
  for(fase=0; fase< Fases; fase++)
  {
    NumDatosGrupo = NPuntos/Grupos ;
    dual = NumDatosGrupo/2;
    grupoini = 0;
    for(grupo = 0; grupo < Grupos; grupo++)
    {
      for(i=0; i< dual; i++)
      {
  pos = i + grupoini;
  pos_dual = pos + dual;
  real_i = real[pos] + real[pos_dual];
  imag_i = imag[pos] + imag[pos_dual];
  real_dual = real[pos] - real[pos_dual];
  imag_dual = imag[pos] - imag[pos_dual];
  coseno = cos(2*PI*i/NumDatosGrupo);
  seno = sin(2*PI*i/NumDatosGrupo);
  real[pos_dual] = real_dual*coseno + imag_dual*seno;
  imag[pos_dual] = imag_dual*coseno - real_dual*seno ;
  real[pos] = real_i;
  imag[pos] = imag_i;
      }
      grupoini += NumDatosGrupo;
    }
    Grupos *= 2;
  }

// Bit reversal
  pos = 0;
  for(i=0; i < NPuntos; i++)
  {
    pos = i;
    dual = 0;
    aux = NPuntos/2;
    for(j=0 ; j <= Fases ; j++)
    {
      dual = dual + (pos %2) * aux;
      pos = pos/2;
      aux = aux/2;
    }
    if(dual > i)
    {
      real_i = real[i];
      imag_i = imag[i];
      real[i] = real[dual];
      imag[i] = imag[dual];
      real[dual] = real_i;
      imag[dual] = imag_i;
    }
  }
}

int main()
{
  
   float tmp =0;
  FILE *file = fopen("pontos.txt", "r");
  if (file == NULL){
    cout<<"Erro na abertura\n";
    exit(1);
  }
  fscanf(file,"%i",&N);
  float real[N], imag[N];
  for(int i=0; i< N; i++){
    fscanf(file,"%f",&tmp);
    real[i] = tmp;
    imag[i] = 0;
  }

  system("clear");
  FFT(real,imag,N);
   return 0;
}