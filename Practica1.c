#include <stdio.h>
#include <time.h> //Agregue esta libreria para mostrar el tiempo

//Prototipos de las funciones
int Bus_Binaria(char arreglo[], int izq, int der,char x);
int cont = 0;

int main(){

    //Practica 1: Busqueda binaria e interpolada
    char abc[] = {'a','b','c','d','e','f','g','h','i','j'};
    int longitud_abc = sizeof(abc)/sizeof(abc[0]); //se calcula el tamano del arreglo
    char x = 'e'; //valor a buscar
    int resultado = Bus_Binaria(abc,0,longitud_abc,x); //asignacion del resultado a una variable para facilidad de impresion
    if(resultado == -1){
        printf("\nNo se ha encontrado el caracter deseado");
    }else{
        printf("\nEl indice donde se encontro %c es: %d",x,resultado); //impresion final
    }
    return 0;
}

int Bus_Binaria(char arreglo[], int izq, int der,char x){
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
    cont ++;
    printf("\n# de busqueda: %d",cont);

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
        return centro; //Aqui se envia el valor de indice que contiene el valor buscado como resultado
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