#include <iostream>
using namespace std;
#include "listadosVentas.h"

void listadosVentas::MostrarPorFechaDeCompra()//Por Fecha y Por Empleado (ID)
 {
    //--------Por Fecha Descendente----------------------
    VentaArchivo _archiVenta("venta.dat");
    int cantReg = _archiVenta.contarRegistros();
    // Crear un arreglo de ventas dinamico
    Venta *vecOrdenados = new Venta[cantReg];
    VentaManager obj;

    // Guardo todas las ventas
    for (int i = 0; i < cantReg; i++)
    {
        vecOrdenados[i] = _archiVenta.leer(i);
    }
    // Burbujeo
    for (int i = 0; i < cantReg - 1; i++)
    {
        for (int j = 0; j < cantReg - i - 1; j++)
        {   //Se ve asqueroso, pero simplemente pase todo a minutos y compare a ambos
            int aux1 = (vecOrdenados[j].getFecha().getAnio()*525960)+(vecOrdenados[j].getFecha().getMes()*43830)+(vecOrdenados[j].getFecha().getDia()*1440);
            int aux2 = (vecOrdenados[j+1].getFecha().getAnio()*525960)+(vecOrdenados[j].getFecha().getMes()*43830)+(vecOrdenados[j+1].getFecha().getDia()*1440);
            // Comparar los minutos de cada venta
            if (aux1 < aux2)
            {
                Venta temp = vecOrdenados[j];
                vecOrdenados[j] = vecOrdenados[j+1];
                vecOrdenados[j+1] = temp;
            }
        }
    }

    // Mostrar los proveedores ordenados
    for (int i = 0; i < cantReg; i++)
    {
     obj.Mostrar(vecOrdenados[i]);
    }

    delete[] vecOrdenados;

    pausa();
 }

 void listadosVentas::MostrarPorIdDeEmpleado()//Por Empleado (ID)
 {
    //--------Por Fecha Descendente----------------------
    VentaArchivo _archiVenta("venta.dat");
    int cantReg = _archiVenta.contarRegistros();
    // Crear un arreglo de ventas dinamico
    Venta *vecOrdenados = new Venta[cantReg];
    VentaManager obj;

    // Guardo todas las ventas
    for (int i = 0; i < cantReg; i++)
    {
        vecOrdenados[i] = _archiVenta.leer(i);
    }
    // Burbujeo
    for (int i = 0; i < cantReg - 1; i++)
    {
        for (int j = 0; j < cantReg - i - 1; j++)
        {
            int aux1 = vecOrdenados[j].getIdEmpleado();
            int aux2 = vecOrdenados[j+1].getIdEmpleado();
            if (aux1 > aux2)
            {
                Venta temp = vecOrdenados[j];
                vecOrdenados[j] = vecOrdenados[j+1];
                vecOrdenados[j+1] = temp;
            }
        }
    }

    // Mostrar los proveedores ordenados
    for (int i = 0; i < cantReg; i++)
    {
        obj.Mostrar(vecOrdenados[i]);
    }

    delete[] vecOrdenados;

    pausa();
 }

void listadosVentas::menuListados()
{
   int opcion;
    while(true)
    {
      clear();
      cout << "LISTADO DE VENTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - POR FECHA" << endl;
      cout << "2 - POR EMPLEADO" << endl;
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
          MostrarPorFechaDeCompra();
        }
        break;
       case 2:
        {
         MostrarPorIdDeEmpleado();
        }
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
