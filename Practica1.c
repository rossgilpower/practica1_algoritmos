/* Realizado por Rosselin Gil Soto 1272606 
   Algoritmos y Estructuras de Datos 2023-1 Grupo 551
   Universidad Autonoma de Baja California*/

#include <stdio.h>
#include <stdlib.h> //Para el calculo de g
#include <string.h> //Para la comparacion de las cadenas
#include <time.h> //Agregue esta libreria para mostrar el tiempo

//Prototipos de las funciones iterativas
int Bus_Binaria_I(char arreglo[][50],int izq, int der, char x[]);
int Bus_Interpolada_I(char arreglo [][50], int izq, int der, char x[]);

//Prototipos de las funciones recursivas
int Bus_Binaria_R(char arreglo[][50], int izq, int der,char x []);
int Bus_Interpolada_R(char arreglo[][50], int izq, int der, char x []);

//Contador de iteraciones
int cont_Bin_I = 0;
int cont_Int_I = 0;
int cont_Bin_R = 0;
int cont_Int_R = 0;


int main(){

    //Practica 1: Busqueda binaria e interpolada
    char animales[][50] = {"abeja","becerro","caballo","delfin","elefante","foca","gato","hamster","iguana","lobo"};
    int longitud_animales = sizeof(animales)/sizeof(animales[0]); //se calcula el tamano del arreglo
    char x [] = "lobo"; //valor a buscar

    printf("\n------ BUSQUEDA BINARIA ITERATIVA -------");
    int resultado_Bin_I = Bus_Binaria_I(animales, 0, longitud_animales-1, x);
    if(resultado_Bin_I == -1){
        printf("\nNo se ha encontrado la cadena mediante busqueda binaria iterativa");
    }else{
        printf("\nEl indice donde se encontro %s es: %d",x,resultado_Bin_I);
    }
    printf("\n");
    printf("\n---- BUSQUEDA BINARIA RECURSIVA -----");
    int resultado_Bin = Bus_Binaria_R(animales,0,longitud_animales-1,x); //asignacion del resultado a una variable para facilidad de impresion
    if(resultado_Bin == -1){
        printf("\nNo se ha encontrado la cadena deseada mediante busqueda binaria recursiva");
    }else{
        printf("\nEl indice donde se encontro %s es: %d",x,resultado_Bin); //impresion final
    }

    printf("\n");
    printf("\n---- BUSQUEDA INTERPOLADA ITERATIVA -----");
    int resultado_Int_I = Bus_Interpolada_I(animales,0,longitud_animales-1,x); //asignacion del resultado a una variable para facilidad de impresion
    if(resultado_Int_I == -1){
        printf("\nNo se ha encontrado la cadena deseada mediante busqueda interpolada iterativa");
    }else{
       printf("\nEl indice donde se encontro %s es: %d",x,resultado_Int_I); //impresion final
    }
    printf("\n");
    printf("\n---- BUSQUEDA INTERPOLADA RECURSIVA -----");
    int resultado_Int = Bus_Interpolada_R(animales,0,longitud_animales-1,x); //asignacion del resultado a una variable para facilidad de impresion
    if(resultado_Int == -1){
        printf("\nNo se ha encontrado la cadena deseada mediante busqueda interpolada recursiva");
    }else{
       printf("\nEl indice donde se encontro %s es: %d",x,resultado_Int); //impresion final
    }
    printf("\n----------------------------");




    return 0;
}

// ------------------ ITERATIVAS ------------------------------

int Bus_Binaria_I(char arreglo[][50],int izq, int der, char x[]){
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
    while(izq<=der){
        cont_Bin_I ++;
        printf("\n# de busqueda: %d",cont_Bin_I);
        int centro = (izq+der)/2;
        if(strcmp(x,arreglo[centro]) == 0){
            printf("\nComparando %s con %s ...",x,arreglo[centro]);
            clock_t fin = clock();
            tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
            printf("Tiempo: %f",tiempo);
            return centro; // <---- Aqui termina la busqueda
        }
        else if(strcmp(x, arreglo[centro]) == 1){ //El valor buscado está a la derecha, == 1 x > arreglo[centro]
            printf("\nComparando %s con %s ...",x,arreglo[centro]);
            izq = centro + 1;
            clock_t fin = clock();
            tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
            printf("Tiempo: %f",tiempo);
        }
        else{
            printf("\nComparando %s con %s ... ",x,arreglo[centro]);
            der = centro - 1;   // El valor buscado está a la izq
            clock_t fin = clock();
            tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
            printf("Tiempo: %f",tiempo);
        }
    }
   return -1; //No encontró el valor
}

int Bus_Interpolada_I(char arreglo[][50],int izq, int der, char x []){
    int valor = -1; // Por si no lo encuentra
    int g = 0;
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
   
    while(izq<=der){
        cont_Int_I++;
        printf("\n# de busqueda: %d",cont_Int_I);
         //  g   =   i + (((j-i)*(x-A[i]))/(A[j]-A[i]))
        g = izq + ((der - izq) * (strcmp(x, arreglo[izq])) / (strcmp(arreglo[der], arreglo[izq])));

        /*printf("\n IZQ: %d",izq);
        printf("\n DER: %d",der);
        printf("\nValor de g: %d",g);
        printf("\nValor que da la comparacion: %d",strcmp(x,arreglo[g])); */

        if(strcmp(arreglo[g],x) == 0){ // Son iguales
            printf("\nComparando %s con %s ...",x,arreglo[g]);
            clock_t fin = clock();
            tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
            printf("Tiempo: %f",tiempo);
            valor = g;
            break; //<----- Salida si lo encuentra
        }else{
            if(strcmp(arreglo[g],x) < 0){ //El valor que busco es menor
                printf("\nComparando %s con %s ...",x,arreglo[g]);
                izq = g + 1;
                clock_t fin = clock();
                tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
                printf("Tiempo: %f",tiempo);
            }else{    //El valor que busco es mayor
                printf("\nComparando %s con %s ...",x, arreglo[g]);
                der = g - 1;
                clock_t fin = clock();
                tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC;
                printf("Tiempo: %f",tiempo);
            }
        }
    }
    return valor; //<---- Salida si no lo encuentra
}


// ------------------ RECURSIVAS ------------------------------

int Bus_Binaria_R(char arreglo[][50], int izq, int der,char x []){
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
    cont_Bin_R ++;
    printf("\n# de busqueda: %d",cont_Bin_R);

    if(izq>der){    //No encontro el valor asi que regresa el valor -1
        return -1;
    }
    int centro = ((izq+der)/2); //1. calcular el centro
    if(strcmp(x,arreglo[centro]) == 0){  //2. comparar si el valor del centro es el que busco, == 0 indica que son iguales
        printf("\nComparando %s con %s ...",x,arreglo[centro]);
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
        return centro; //Aqui se envia el valor de indice que contiene el valor buscado como resultado <<<<----SALIDA
    }
    //Ya que la busqueda binaria solo funciona si el arreglo esta ordenado:
    if(strcmp(x,arreglo[centro]) == -1){   //si el valor que busco es menor que el del centro, entonces esta a la izquierda, == -1 indica que x < valor_centro
        printf("\nComparando %s con %s ...",x,arreglo[centro]);
        der = centro - 1;
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
    }else{
        printf("\nComparando %s con %s ...",x,arreglo[centro]);
        izq = centro + 1;   //si no, entonces a la derecha
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
    }
    return Bus_Binaria_R(arreglo,izq,der,x); //se aplica recursion para continuar con la busqueda

}

//--------------------------------------------------------------------------------

int Bus_Interpolada_R(char arreglo[][50],int izq, int der, char x []){
    //La diferencia entre ambas busquedas es la manera en que se calcula el centro, lo demas queda practicamente igual
    clock_t inicio = clock();   //Inicio del tiempo de las busquedas
    double tiempo = 0.0;
    cont_Int_R ++;
    printf("\n# de busqueda: %d",cont_Int_R);
    if(izq <= der && x>=arreglo[izq] && x<=arreglo[der]){
        int g = izq + ((x - arreglo[izq]) * (der - izq))/(arreglo[der] - arreglo[izq]); //Aqui se usa la formula de  la interpolacion para aproximar la posición
        if(strcmp(x,arreglo[g])== 0){ // == 0 indica que las cadenas son iguales
        printf("\nComparando %s con %s ...",x,arreglo[g]);
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
        return g; //Se retorna el valor que tiene el indice donde se encontró X <<<<<------- SALIDA
    }
    if(strcmp(x,arreglo[g]) == -1){ //Si esta a la izq
        printf("\nComparando %s con %s ...",x,arreglo[g]); 
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
        return Bus_Interpolada_R(arreglo,izq,g-1,x);

    }else{
        printf("\nComparando %s con %s ...",x,arreglo[g]);
        clock_t fin = clock();
        tiempo += (double)(fin-inicio)/CLOCKS_PER_SEC; //se calcula el tiempo que tomo esta busqueda
        printf("Tiempo: %f",tiempo);
        return Bus_Interpolada_R(arreglo,g+1,der,x);
        }
    }
    return -1;
}