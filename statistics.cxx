#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillarray(double* p, const int N);

void calculate(double* p, const int N, double& mean, double& var); //für Arrays nimmt man Pointer (weil ein Array quasi ein Pointer ist); aber für Variablen nimmt man Referenzen. Es geht zwar auch mit Pointern, aber dann muss man immer einen Stern (*mean) mitschleppen und man muss in main bei der Übergabe die Adresse (&mean) übergeben)


int main(){
srand(time(NULL));
   const int N = 100;
   double p[N];
   double mean, var;

   fillarray(p, N);
   calculate(p, N, mean, var);
   
   
   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}

void fillarray(double* p, const int N){
    for(int i=0; i<N; i++){
        p[i]=rand()/double(RAND_MAX); //RAND_MAX in einen double Typ umwandeln, sonst wird int/int <1 nur 0 ausgegeben
        cout<< p[i] <<endl; // Ausgabe der Zufallszahlen
  }
}

void calculate(double* p, const int N, double& mean, double& var){

    mean=0;
    var=0;
    
    for(int i=0; i<N; i++){
        mean=mean+p[i];
    };
    
    mean=mean/N;     // weil N ein int ist, darf man hier nicht (1/N)*mean rechnen und wir können aus N keinen double Wert machen, weil die Länge des Arrays immer ein Integer sein muss
    
    for(int i=0; i<N; i++){
        var=pow((var-mean),2);
    }

    var=var/N;
}