#include <fstream>
#include <iostream>

using namespace std;

double* read(int N);
void filter(double* f, int N);
void write(double* f, int N);


int main(){

	const int N = 237;
	double* f = read(N);

	filter(f,N);
	write(f,N);
	delete[] f;
}


double* read(int N){
	
	double* f = new double[N];
	fstream noisy;
	noisy.open("noisy.txt");

	for(int i = 0; i < N; i++){ // read data into array
		noisy >> f[i];
	}
	noisy.close();
return f;
}

void filter(double* f, int N){
	double a1, a2;
	f[N-1] = f[0]; // obtain periodicy
	a2 = f[0];
			
	for(int i = 1; i < N-1; i++){

		a1 = f[i]; 	// save the current value
		
		f[i] = (a2 + f[i] + f[i+1])/3;

		a2 = a1; // interchange values for next calculation
	}
}

void write(double* f, int N){

	ofstream result("filtered.txt");

	for(int i = 1; i < N-1; i++){
		result << f[i] << endl;
	}
	result.close();
}

	
