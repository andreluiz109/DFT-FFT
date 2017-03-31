#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
//------Variaveis-------------
double xn=0,ts = 1.0/8000;
double N = 0;
int n=0;
//-------Gerador de Xn--------
int main(){
	cout << "Digite o valor de n obs: N=2^n :\n";
	cin >> n;
	N = pow(2,n);
	ofstream file;
	file.open("pontos.txt");
	if (file.is_open()){
		file << N << "\n";
		for(double i=0; i< N; i++){
			xn = sin(2*M_PI*1000*i*ts) + 0.5*sin(2*M_PI*2000*i*ts + 3*M_PI/4);
			file << xn <<"\n";
		}
	}
	file.close();
	return 0;
}
