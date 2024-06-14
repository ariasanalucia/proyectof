#include <iostream>
using namespace std;
#include "consultas.h"
#include "funcionesGlobales.h"

 void Consultas::menuConsultas()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "   CONSULTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - POR ID" << endl;
      cout << "2 - POR PROVEEDOR" << endl;
      cout << "3 - POR ACCION TERAPEUTICA" << endl;
      cout << "4 - POR DROGA" << endl;
      cout << "5 - POR PRECIO UNITARIO" << endl;
      cout << endl;
      cout << "0 - PARA SALIR" << endl;
      cout << "----------------" << endl;

      cout << "INGRESE UNA OPCION: ";
      //cin >> opcion;
      opcion = ingresoEntero();
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
       case 4:
        {
         pm.mostrarPorDroga();
        }
        break;
       case 5:
        {
          pm.mostrarPorPrecio();
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
