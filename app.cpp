#include <iostream>
#include "funcionesGlobales.h"
using namespace std;
#include "app.h"

 void App::MenuPrincipal()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "MENU PRINCIPAL" << endl;
      cout << "----------------" << endl;
      cout << "1 - PRODUCTO" << endl;
      cout << "2 - VENTAS" << endl;
      cout << "3 - EMPLEADOS" << endl;
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
          subMenuP.menuProducto();
        }
        break;
       case 2:
        {

          break;
        }
       case 3:
        {
          subMenuE.menuEmpleado();
          break;
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
          pausa();
        }
      }
      clear();
    }
   return;
 }
