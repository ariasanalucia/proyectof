#include <iostream>
using namespace std;
#include "app.h"

 void App::MenuPrincipal()
 {
   int opcion;
    while(true)
    {
      system("cls");
      cout << "MENU PRINCIPAL" << endl;
      cout << "----------------" << endl;
      cout << "1 - MENU PRODUCTO" << endl;
      cout << "2 - MENU VENTAS" << endl;
      cout << "3 - MENU EMPLEADOS" << endl;
      cout << endl;
      cout << "0 - PARA SALIR" << endl;
      cout << "----------------" << endl;

      cout << "INGRESE UNA OPCION: ";
      cin >> opcion;
      system("cls");
      switch (opcion)
      {
       case 1:
        {
          subMenu.menuProducto();
        }
        break;
       case 2:
        {

          break;
        }
       case 3:
        {

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
        }
      }
      system("pause");
      system("cls");
    }
   return;
 }