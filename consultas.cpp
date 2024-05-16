#include <iostream>
using namespace std;
#include "consultas.h"
#include "funcionesGlobales.h"
#include "productoManager.h"

 void Consultas::menuConsultas()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "MENU DE CONSULTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - POR ID" << endl;
      cout << "2 - POR PROVEEDOR" << endl;
      cout << "3 - POR CATEGORIA" << endl;
      cout << endl;
      cout << "0 - PARA SALIR" << endl;
      cout << "----------------" << endl;

      cout << "INGRESE UNA OPCION: ";
      cin >> opcion;
      clear();
      switch (opcion)
      {
       case 1:
        {
         pm.mostrarPorId();
        }
        break;
       case 2:
        {
         pm.mostrarPorProveedor();
        }
        break;
       case 3:
        {
         pm.mostrarPorCategoria();
        }
        break;
       case 0:
        {
          return;
        }
        break;
       default:
        {
          cout << "OPCION INCORRECTA" << endl;
        }
      }
      pausa();
      clear();
    }
   return;
 }
