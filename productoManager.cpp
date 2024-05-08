#include <iostream>
using namespace std;
#include "rlutil.h"
#include "funcionesGlobales.h"
#include "producto.h"
#include "productoManager.h"

 //CARGAR
 Producto ProductoManager::Cargar()
 {
   Producto aux;
   Fecha vencimiento;
   int id,proveedor, stock, cantidad;
   char nombre[30], categoria[30], presentacion[30];
   Fecha venci;

   cout << "ID de producto: ";
   cin >> id;
   aux.setId(id);

   cout << "Nombre de producto: ";
   cargarCadena(nombre, 29);
   aux.setNombre(nombre);

   cout << "Categoria de producto: ";
   cargarCadena(categoria, 29);
   aux.setCategoria(categoria);

   cout << "Proveedor: ";
   cin >> proveedor;
   aux.setProveedor(proveedor);

   cout << "Fecha de vencimiento: ";
   venci.Cargar();
   aux.setVencimiento(venci);

   cout << "Stock: ";
   cin >> stock;
   aux.setStock(stock);

   cout << "Presentacion: ";
   cargarCadena(presentacion,29);
   aux.setPresentacion(presentacion);

   cout << "Cantidad: ";
   cin >> cantidad;
   aux.setCantidad(cantidad);

   return aux;
 }

//MOSTRAR
 void ProductoManager::Mostrar(Producto producto)
 {
   cout << "ID de producto: " << producto.getId() << endl;
   cout << "Nombre de producto: " << producto.getNombre() << endl;
   cout << "Categoria de producto: " << producto.getCategoria() << endl;
   cout << "proveedor: " << producto.getProveedor() << endl;
   cout << "Fecha de vencimiento: " << producto.getVenciemiento().toString() << endl;
   cout << "Stock: " << producto.getStock() << endl;
   cout << "Presentacion: " << producto.getPresentacion() << endl;
   cout << "Cantidad: " << producto.getCantidad() << endl;
   cout << endl;
 }

 void ProductoManager::mostrarTodos()
 {
   for (int i=0; i<_archivo.contarRegistros(); i++)
   {
     Mostrar(_archivo.leer(i));
   }
   pausa();
 }

 void ProductoManager::mostrarPorId()
 {
   int id;

   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int posicion = _archivo.buscar(id);
   if (posicion >= 0)
   {
     Producto aux = _archivo.leer(posicion);
     Mostrar(aux);
     pausa();
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     pausa();
   }
 }

 void ProductoManager::menuProducto()
 {
   int opcion;
    while(true)
    {
      rlutil::cls();
      cout << "PRODUCTOS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA PRODUCTO" << endl;
      cout << "2 - MOSTRAR PRODUCTOS" << endl;
      cout << "3 - MOSTRAR POR ID DE PRODUCTO" << endl;
      cout << "4 - " << endl;
      cout << "5 - " << endl;
      cout << "6 - " << endl;
      cout << endl;
      cout << "0 - PARA SALIR" << endl;
      cout << "----------------" << endl;

      cout << "INGRESE UNA OPCION: ";
      cin >> opcion;
      rlutil::cls();
      switch (opcion)
      {
       case 1:
        {
          Producto aux = Cargar();
          _archivo.guardarArchivo(aux);
        }
        break;
       case 2:
        {
          mostrarTodos();
          break;
        }
       case 3:
        {
          mostrarPorId();
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
      pausa();
      rlutil::cls();
    }
   return;
 }
