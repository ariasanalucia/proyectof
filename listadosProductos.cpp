#include <iostream>
using namespace std;
#include "listadosProductos.h"

 void listadosProductos::listarPorPrecio()
 {
    Producto reg;
    ProductoArchivo archiP("producto.dat");
    int cantReg = archiP.contarRegistros();

    Producto *vecOrdenados = new Producto[cantReg];
    ProductoManager obj;


    for (int i = 0; i < cantReg; i++)
    {
        vecOrdenados[i] = archiP.leer(i);
    }

    int respuesta;
    cout << "COMO DESEA ORDENARLOS(1 - Ascendente || 2 - Descendente): ";
    cin >> respuesta;
    // Burbujeo
    if (respuesta == 2)
    {
     for (int i = 0; i < cantReg - 1; i++)
     {
         for (int j = 0; j < cantReg - i - 1; j++)
         {
             int aux1 = vecOrdenados[j].getPrecioUnitario();
             int aux2 = vecOrdenados[j+1].getPrecioUnitario();
             if (aux1 < aux2)
             {
                 Producto temp = vecOrdenados[j];
                 vecOrdenados[j] = vecOrdenados[j+1];
                 vecOrdenados[j+1] = temp;
             }
         }
     }
    }else if (respuesta == 1)
    {
      for (int i = 0; i < cantReg - 1; i++)
     {
       for (int j = 0; j < cantReg - i - 1; j++)
       {
          int aux1 = vecOrdenados[j].getPrecioUnitario();
          int aux2 = vecOrdenados[j+1].getPrecioUnitario();
          if (aux1 > aux2)
          {
            Producto temp = vecOrdenados[j];
            vecOrdenados[j] = vecOrdenados[j+1];
            vecOrdenados[j+1] = temp;
          }
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

 void listadosProductos::listarPorCantStock()
 {
   Producto reg;
    ProductoArchivo archiP("producto.dat");
    int cantReg = archiP.contarRegistros();

    Producto *vecOrdenados = new Producto[cantReg];
    ProductoManager obj;


    for (int i = 0; i < cantReg; i++)
    {
        vecOrdenados[i] = archiP.leer(i);
    }

    int respuesta;
    cout << "COMO DESEA ORDENARLOS(1 - Ascendente || 2 - Descendente): ";
    cin >> respuesta;
    // Burbujeo
    if (respuesta == 2)
    {
     for (int i = 0; i < cantReg - 1; i++)
     {
         for (int j = 0; j < cantReg - i - 1; j++)
         {
             int aux1 = vecOrdenados[j].getStock();
             int aux2 = vecOrdenados[j+1].getStock();
             if (aux1 < aux2)
             {
                 Producto temp = vecOrdenados[j];
                 vecOrdenados[j] = vecOrdenados[j+1];
                 vecOrdenados[j+1] = temp;
             }
         }
     }
    }else if (respuesta == 1)
    {
      for (int i = 0; i < cantReg - 1; i++)
     {
       for (int j = 0; j < cantReg - i - 1; j++)
       {
          int aux1 = vecOrdenados[j].getStock();
          int aux2 = vecOrdenados[j+1].getStock();
          if (aux1 > aux2)
          {
            Producto temp = vecOrdenados[j];
            vecOrdenados[j] = vecOrdenados[j+1];
            vecOrdenados[j+1] = temp;
          }
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

 void listadosProductos::menuListados()
{
   int opcion;
    while(true)
    {
      clear();
      cout << "LISTADO DE MEDICAMENTOS" << endl;
      cout << "----------------" << endl;
      cout << "1 - POR PRECIO UNITARIO" << endl;
      cout << "2 - POR TIPO/DROGA" << endl;
      cout << "3 - POR CANTIDAD DE STOCK" << endl;
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
         listarPorPrecio();
        }
        break;
       case 2:
        {

        }
        break;
       case 3:
        {
         listarPorCantStock();
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

