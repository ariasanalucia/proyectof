#include <iostream>
using namespace std;
#include "funcionesGlobales.h"

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

 bool es_proveedor(int proveedor){
    return (proveedor == 1 || proveedor == 2);
 }


 void validar_proveedor(int *proveedor){
    while(!es_proveedor(*proveedor)){
        cout<<"ingrese correctamente el provedor 1 o 2:";
        cin>>*proveedor;
    }
 }

 void pausa(){
    std::cin.ignore();
    std::cin.get();
    return;
 }
