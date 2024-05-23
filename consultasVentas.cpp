#include <iostream>
using namespace std;
#include "consultasVentas.h"
#include "funcionesGlobales.h"

  void ConsultasVentas::menuConsultasVentas()
  {
    int opcion;
    while(true)
    {
      clear();
      cout << "CONSULTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - BUSCAR POR FECHA DE VENTA" << endl;
      cout << "2 -" << endl;
      cout << "3 - " << endl;
      cout << "4 - " << endl;
      cout << "5 - " << endl;
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
          Vm.MostrarPorFechaDeCompra();
        }
        break;
       case 2:
        {

        }
        break;
       case 3:
        {

        }
        break;
       case 4:
        {

        }
        break;
       case 5:
        {

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
