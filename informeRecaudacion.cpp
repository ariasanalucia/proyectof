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

  float totalRecaudado = 0;

  int anio;
  cout << "INGRESE EL ANIO:" << endl;
  cin >> anio;

  for (int i = 0; i < cant; i++) {
    reg = archiVenta.leer(i);
    if (reg.getFecha().getAnio()==anio) {
      mes[reg.getFecha().getMes()-1] += reg.getImporte();
      totalRecaudado += reg.getImporte();
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

  cout << endl << endl;
  cout << "-----------------------------" << endl;
  cout << "TOTAL RECAUDADO: $" << totalRecaudado << endl;
  pausa();
}

 void InformeRecaudacion::porEmpleado()
 {
   Venta regVenta;
   VentaArchivo archiVenta("venta.dat");
   int cantV = archiVenta.contarRegistros();

   Empleado regEmpleado;
   EmpleadoArchivo archiEmp("empleado.dat");
   int cantE = archiEmp.contarRegistros();

   int maximoEmpleado;
   float maximo = -1;
   char nombre[30];
   char apellido[30];

   int maximoVentas;

   for (int i=0; i<cantE; i++)
   {
     float acumulador = 0;
     int contador = 0;
     regEmpleado = archiEmp.leer(i);
     for (int j=0; j<cantV; j++)
     {
       regVenta = archiVenta.leer(j);
       if (regEmpleado.getId() == regVenta.getIdEmpleado())
       {
         acumulador += regVenta.getImporte();
         contador++;
       }
     }
     cout << "EL EMPLEADO CON ID: " << regEmpleado.getId() << " RECAUDO: $" << acumulador << endl;
     if (maximo == -1 || acumulador > maximo)
     {
       maximo = acumulador;
       maximoEmpleado = regEmpleado.getId();
       strcpy(nombre,regEmpleado.getNombre());
       strcpy(apellido,regEmpleado.getApellido());
       maximoVentas = contador;
     }
   }
   cout << endl << endl;
   cout << "EL EMPLEADO CON MAS RECAUDACION ES " << endl;
   cout << "ID: " << maximoEmpleado << endl;
   cout << "NOMBRE: " << nombre << endl;
   cout << "APELLIDO: " << apellido << endl;
   cout << "CANTIDAD DE VENTAS REALIZADAS: " << maximoVentas << endl;
   pausa();
 }
 void InformeRecaudacion::porProducto()
 {
   Producto regP;
   ProductoArchivo archiP("producto.dat");
   int cantProductos = archiP.contarRegistros();

   Venta regVenta;
   VentaArchivo archiVenta("venta.dat");
   int cantVentas = archiVenta.contarRegistros();

   for (int i=0; i<cantProductos; i++)
   {
     float acumulador = 0;
     regP = archiP.leer(i);

     for (int j=0; j<cantVentas; j++)
     {
       regVenta = archiVenta.leer(j);

       if (regP.getId() == regVenta.getIdProducto(i) && regP.getEstado())
       {
         acumulador += regVenta.getImporte();
       }
     }
     cout << "NOMBRE MEDICAMENTO: " << regP.getMarca() << "\t" << " | ";
     cout << "RECAUDACION: $" << acumulador << endl;
     cout << endl;
   }

   pausa();
 }

void InformeRecaudacion::menuInformeRecaudacion()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "  RECAUDACION" << endl;
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
         porEmpleado();
        }
        break;
       case 3:
        {
         porProducto();
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
