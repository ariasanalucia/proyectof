#include <iostream>
using namespace std;
#include "funcionesGlobales.h"
#include "informes.h"

 void Informes::MenuInforme()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "    INFORMES" << endl;
      cout << "----------------" << endl;
      cout << "1 - RECAUDACION" << endl;
      cout << "2 - MEDICAMENTOS SIN STOCK" << endl;
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
         SubMenuRecaudacion.menuInformeRecaudacion();
        }
        break;
       case 2:
        {
          subMenuReponerStock.faltantesDeStock();
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
      clear();
    }
   return;
 }
