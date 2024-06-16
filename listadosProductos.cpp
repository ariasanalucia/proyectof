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

    int respuesta = -1;
    while(respuesta != 0) {
      clear();
      cout << "COMO DESEA ORDENARLOS?" << endl;
      cout << "(1 - Ascendente | 2 - Descendente | 0 - Salir): ";
      cin >> respuesta;
      //Burbujeo
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
     }else
     {
       return;
     }

      for (int i = 0; i < cantReg; i++)
      {
          obj.Mostrar(vecOrdenados[i]);
      }
      
      pausa();
      clear();
    }

    delete[] vecOrdenados;
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

    int respuesta = -1;
    while(respuesta != 0) {
      clear();
      cout << "COMO DESEA ORDENARLOS?";
      cout << "(1 - Ascendente | 2 - Descendente | 0 - Salir): ";
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
     }else
     {
       return;
     }

      // Mostrar los proveedores ordenados
      for (int i = 0; i < cantReg; i++)
      {
          obj.Mostrar(vecOrdenados[i]);
      }

      pausa();
      clear();
    }

    delete[] vecOrdenados;
 }

 void listadosProductos::menuListados()
{
   int opcion;
    while(true)
    {
      clear();
      cout << "LISTAR MEDICAMENTOS" << endl;
      cout << "-------------------" << endl;
      cout << "1 - POR PRECIO" << endl;
      cout << "2 - POR STOCK" << endl;
      cout << endl;
      cout << "0 - PARA SALIR" << endl;
      cout << "-------------------" << endl;

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

