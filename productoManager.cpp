#include <iostream>
using namespace std;
#include "funcionesGlobales.h"
#include "producto.h"
#include "productoManager.h"
#include "productoArchivo.h"

 //CARGAR
 Producto ProductoManager::Cargar()
 {
   Producto aux;
   int id,proveedor;
   char nombre[30], categoria[30];

   cout << "ID de producto: ";
   cin >> id;
   aux.setId(id);

   cout << "Nombre de producto: ";
   cargarCadena(nombre, 29);
   aux.setNombre(nombre);

   cout << "Categoria de producto: ";
   cargarCadena(categoria, 29);
   aux.setCategoria(categoria);

   cout << "proveedor: ";
   cin >> proveedor;
   aux.setProveedor(proveedor);

   return aux;
 }

//MOSTRAR
 void ProductoManager::Mostrar(Producto producto)
 {
   cout << "ID de producto: " << producto.getId() << endl;
   cout << "Nombre de producto: " << producto.getNombre() << endl;
   cout << "Categoria de producto: " << producto.getCategoria() << endl;
   cout << "proveedor: " << producto.getProveedor() << endl;
   cout << endl;
 }

 void ProductoManager::mostrarTodos()
 {
   for (int i=0; i<_archivo.contarRegistros(); i++)
   {
     Mostrar(_archivo.leer(i));
   }
 }
 void ProductoManager::menuPrincipal()
 {
   int opcion;
    while(true)
    {
      system("cls");
      cout << "MENU PRINCIPAL" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA PRODUCTO" << endl;
      cout << "2 - MOSTRAR PRODUCTOS" << endl;
      cout << "3 soy ana- " << endl;
      cout << "4 - " << endl;
      cout << "5 - " << endl;
      cout << "6 - " << endl;
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
          Producto aux = Cargar();
          _archivo.guardarArchivo(aux);
        }
        break;
       case 2:
        {
          mostrarTodos();
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
