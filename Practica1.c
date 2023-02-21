/* Realizado por Rosselin Gil Soto 1272606 
   Algoritmos y Estructuras de Datos 2023-1 Grupo 551
   Universidad Autonoma de Baja California*/

#include <stdio.h>
#include <time.h> //Agregue esta libreria para mostrar el tiempo

//Prototipos de las funciones
int Bus_Binaria(char arreglo[], int izq, int der,char x);
int Bus_Interpolada(char arreglo[], int izq, int der, char x);

//Contador de iteraciones
int cont_Bin = 0;
int cont_Int = 0;

int main(){

    //Practica 1: Busqueda binaria e interpolada
    char abc[] = {'a','b','c','d','e','f','g','h','i','j'};
    int longitud_abc = sizeof(abc)/sizeof(abc[0]); //se calcula el tamano del arreglo
    char x = 'e'; //valor a buscar
    printf("\n----BUSQUEDA BINARIA-----");
    int resultado_Bin = Bus_Binaria(abc,0,longitud_abc,x); //asignacion del resultado a una variable para facilidad de impresion
    if(resultado_Bin == -1){
        printf("\nNo se ha encontrado el caracter deseado mediante busqueda binaria");
    }else{
        printf("\nEl indice donde se encontro %c es: %d",x,resultado_Bin); //impresion final
    }
    printf("\n");
    printf("\n----BUSQUEDA INTERPOLADA-----");
    int resultado_Int = Bus_Interpolada(abc,0,longitud_abc,x); //asignacion del resultado a una variable para facilidad de impresion
    if(resultado_Int == -1){
        printf("\nNo se ha encontrado el caracter deseado mediante busqueda interpolada");
    }else{
        printf("\nEl indice donde se encontro %c es: %d",x,resultado_Int); //impresion final
    }
    printf("\n----------------------------");

    return 0;
}

int Bus_Binaria(char arreglo[], int izq, int der,char x){
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
    cont_Bin ++;
    printf("\n# de busqueda: %d",cont_Bin);

    if(izq>der){    //No encontro el valor asi que regresa el valor -1
        return -1;
    }
    int centro = ((izq+der)/2); //1. calcular el centro
    int valor_centro = arreglo[centro]; //asignar el valor del centro a una variable para comparacion
    if(x == valor_centro){  //2. comparar si el valor del centro es el que busco
        printf("\nComparando %c con %c ...",x,valor_centro);
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
        return centro; //Aqui se envia el valor de indice que contiene el valor buscado como resultado <<<<----SALIDA
    }
    //Ya que la busqueda binaria solo funciona si el arreglo esta ordenado:
    if(x < valor_centro){   //si el valor que busco es menor que el del centro, entonces esta a la izquierda
        printf("\nComparando %c con %c ...",x,valor_centro);
        der = centro - 1;
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
    }else{
        printf("\nComparando %c con %c ...",x,valor_centro);
        izq = centro + 1;   //si no, entonces a la derecha
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
    }
    return Bus_Binaria(arreglo,izq,der,x); //se aplica recursion para continuar con la busqueda

}

int Bus_Interpolada(char arreglo[],int izq, int der, char x){
    //La diferencia entre ambas busquedas es la manera en que se calcula el centro, lo demas queda practicamente igual
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
    cont_Int ++;
    printf("\n# de busqueda: %d",cont_Int);
    if(izq>der){
        return -1; //No encontro el caracter
    }
    int g = izq + (((der-izq)*(x-arreglo[izq]))/(arreglo[der]-arreglo[izq])); //Aqui se usa la formula de  la interpolacion para aproximar la posición
    if(x == arreglo[g]){
        printf("\nComparando %c con %c ...",x,arreglo[g]);
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
        return g; //Se retorna el valor que tiene el indice donde se encontró X <<<<<------- SALIDA
    }
    if(x<arreglo[g]){
        printf("\nComparando %c con %c ...",x,arreglo[g]);
        der = g-1; 
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
    }else{
        printf("\nComparando %c con %c ...",x,arreglo[g]);
        izq = g+1;
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
    }
    return Bus_Interpolada(arreglo,izq,der,x); //Se aplica la recursion para continuar con la busqueda

}