#include <stdio.h>
#include <stdlib.h> //Para el calculo de g
#include <time.h> //Agregue esta libreria para mostrar el tiempo

int Bin_It(float arreglo[10], float izq, float der, float x);
int Bin_Rec();
int Int_It();
int Int_Rec();

//Contador de iteraciones
int cont_Bin_I = 0;
int cont_Int_I = 0;
int cont_Bin_R = 0;
int cont_Int_R = 0;

int main (){

    float floats [10] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    int longitud_floats = sizeof(floats)/sizeof(floats[0]);
    float x = 0.6;

    int resultado_Bin_I = Bin_It(floats, 0, longitud_floats-1, x);
    if(resultado_Bin_I == -1){
        printf("\nNo se ha encontrado la cadena mediante busqueda binaria iterativa");
    }else{
        printf("\nEl indice donde se encontro %f es: %d",x,resultado_Bin_I);
    }

    return 0;
}

int Bin_It(float arreglo[10],float izq, float der, float x){
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
    while(izq<=der){
        cont_Bin_I ++;
        printf("\n# de busqueda: %d",cont_Bin_I);
        int centro = (izq+der)/2;
        if(x == arreglo[centro]){
            printf("\nComparando %f con %f ...",x,arreglo[centro]);
            clock_t fin = clock();
            tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
            printf("Tiempo: %f",tiempo);
            return centro; // <---- Aqui termina la busqueda
        }
        else if(x > arreglo[centro]){ //El valor buscado está a la derecha, == 1 x > arreglo[centro]
            printf("\nComparando %f con %f ...",x,arreglo[centro]);
            izq = centro + 1;
            clock_t fin = clock();
            tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
            printf("Tiempo: %f",tiempo);
        }
        else{
            printf("\nComparando %f con %f ... ",x,arreglo[centro]);
            der = centro - 1;   // El valor buscado está a la izq
            clock_t fin = clock();
            tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
            printf("Tiempo: %f",tiempo);
        }
    }
   return -1; //No encontró el valor
}