#include <iostream>
using namespace std;
#include "funcionesGlobales.h"
#include <iostream>
#include <cstdlib>

//Clear usado en vez de system("pause")
#ifdef _WIN32
    // Windows-specific code
    #define CLEAR_COMMAND "cls"
#else
    // Linux-specific code
    #define CLEAR_COMMAND "clear"
#endif

void clear() {
    system(CLEAR_COMMAND);
}

//Pausa usada en vez de system("pause")

#ifdef _WIN32
    // Windows-specific code
    #define PAUSE_COMMAND "pause > nul"
#else
    // Linux-specific code
    #define PAUSE_COMMAND "read"
#endif

void pausa() {
    system(PAUSE_COMMAND);
}

//CARGAR CADENA
 void cargarCadena(char *palabra, int tamano)
 {
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++)
   {
     palabra[i]=cin.get();
     if (palabra[i]=='\n')
     {
        break;
     }
   }
    palabra[i]='\0';
    fflush(stdin);
 }

 bool es_proveedor(int Proveedor){
    return (Proveedor == 1 || Proveedor == 2);
 }

 void validar_proveedor(int *Proveedor){
    while(!es_proveedor(*Proveedor)){
        cout<<"Ingrese correctamente el provedor 1 o 2:";
        cin>>*Proveedor;
    }
 }
