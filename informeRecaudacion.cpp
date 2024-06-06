#include <iostream>
using namespace std;
#include "fecha.h"
#include "informeRecaudacion.h"
#include "funcionesGlobales.h"

void InformeRecaudacion::porAnio(){
  Venta reg;
  VentaArchivo archiVenta("venta.dat");
  int cant = archiVenta.contarRegistros();

  float mes[12]={};

  int anio;
  cout << "INGRESE EL ANIO:" << endl;
  cin >> anio;

  for (int i = 0; i < cant; i++) {
    reg = archiVenta.leer(i);
    if (reg.getFecha().getAnio()==anio) {
      mes[reg.getFecha().getMes()-1] += reg.getImporte();
    }
  }

  clear();

  cout << "Recaudacion " << anio << ":" << endl;
  cout << "---------------------------" << endl;
  cout << "Enero      |$" << mes[0] << endl;
  cout << "Febrero    |$" << mes[1] << endl;
  cout << "Marzo      |$" << mes[2] << endl;
  cout << "Abril      |$" << mes[3] << endl;
  cout << "Mayo       |$" << mes[4] << endl;
  cout << "Junio      |$" << mes[5] << endl;
  cout << "Julio      |$" << mes[6] << endl;
  cout << "Agosto     |$" << mes[7] << endl;
  cout << "Septiembre |$" << mes[8] << endl;
  cout << "Octubre    |$" << mes[9] << endl;
  cout << "Noviembre  |$" << mes[10] << endl;
  cout << "Diciembre  |$" << mes[11] << endl;
  pausa();
}

//void porEmpleado(){}
//void porProducto(){}

void InformeRecaudacion::menuInformeRecaudacion()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "     VENTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - POR ANIO" << endl;
      cout << "2 - POR EMPLEADO" << endl;
      cout << "3 - POR PRODUCTO" << endl;
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
         porAnio();
        }
        break;
       case 2:
        {
        //void porEmpleado(){}
        }
        break;
       case 3:
        {
        //void porProducto(){}
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
