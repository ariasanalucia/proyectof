#include <iostream>
using namespace std;
#include <cstring>
#include "funcionesGlobales.h"
#include "producto.h"
#include "productoManager.h"
#include "consultas.h"

 //CARGAR
 Producto ProductoManager::Cargar()
 {
    Producto aux;
    ProductoArchivo obj_archivo_producto("producto.dat");
    int id, Proveedor, stock, cantidad;
    char marca[30], droga[30], categoria[30], presentacion[30];
    Fecha venci;
    float importe;

    id = obj_archivo_producto.contarRegistros()+1;
    aux.setId(id);

   cout << "Marca del medicameto: ";
   cargarCadena(marca, 29);
   aux.setMarca(marca);

   cout << "Droga del medicamento: ";
   cargarCadena(droga, 29);
   aux.setDroga(droga);

   cout << "Categoria de medicamento: ";
   cargarCadena(categoria, 29);
   aux.setCategoria(categoria);

   cout << "Proveedor: " << endl;
   cout << "[1 - Disval | 2 - Suizo]" << endl;
   cin >> Proveedor;
   validar_proveedor(&Proveedor);
   aux.setProveedor(Proveedor);

   cout << "Fecha de vencimiento: " << endl;
   venci.Cargar();
   aux.setVencimiento(venci);

   cout << "Presentacion: ";
   cargarCadena(presentacion,29);
   aux.setPresentacion(presentacion);

   cout << "Cantidad: ";
   cin >> cantidad;
   aux.setCantidad(cantidad);

   cout << "Importe: ";
   cin >> importe;
   aux.setImporte(importe);

   stock += cantidad;
   aux.setStock(stock);

   return aux;
 }

//MOSTRAR
 void ProductoManager::Mostrar(Producto producto)
 {
   if (producto.getEstado())
   {
     cout << "ID de medicamento: " << producto.getId() << endl;
     cout << "Marca del medicamento: " << producto.getMarca() << endl;
     cout << "Droga del medicamento :" << producto.getDroga() << endl;
     cout << "Categoria de medicamento: " << producto.getCategoria() << endl;
     cout << "Proveedor(1 - Disval / 2 - Suizo): " << producto.getProveedor() << endl;
     cout << "Fecha de vencimiento: " << producto.getVenciemiento().toString() << endl;
     cout << "Presentacion: " << producto.getPresentacion() << endl;
     cout << "Cantidad que ingresa: " << producto.getCantidad() << endl;
     cout << "Importe: " << producto.getImporte() << endl;
     cout << endl;
     cout << "-------------------------------" << endl;
   }
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
   Producto aux;
   int id;

   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int posicion = _archivo.buscar(id);
   if (posicion >= 0)
   {
     aux = _archivo.leer(posicion);
     Mostrar(aux);
     if (aux.getProveedor() == 0)
     {
       cout << "ESTE REGISTRO NO PUEDE SER LISTADO YA QUE SE DEBE MODIFICAR X CAMPO DE PRODUCTO" << endl;
       cout << "(Sugerencia: ir al apartado de (LISTAR PRODUCTOS A MODIFICAR POR X ERROR DE CARGA))" << endl;
       return;
     }
     cout << "STOCK ACTUAL: " << aux.getStock() << endl;
     if (aux.getStock() == 0)
     {
       cout << "REPONER STOCK!" << endl;
     }
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
   }
 }

 void ProductoManager::bajaPoducto()
 {
   Producto producto;
   int id;
   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(id);
   if (posicion >= 0 && producto.getProveedor() != 0)
   {
     Producto aux = _archivo.leer(posicion);
     Mostrar(aux);
     pausa();
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE ELIMINAR EL REGISTRO?(1 - SI / 0 - NO)" << endl;
   cin >> respuesta;
   cout << endl;

   if (respuesta == 1)
   {
     producto.setEstado(false);
     if (_archivo.modificarProducto(producto, posicion))
     {
       cout << "REGISTRO ELIMINADO CON EXITO!" << endl;
       pausa();
     }else
     {
       cout << "NO SE PUDO ELIMINAR EL REGISTRO!" << endl;
       pausa();
     }
   }
 }

 void ProductoManager::modificarRegistro()
 {
   Producto producto;
   int id;
   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(id);
   if (posicion >= 0)
   {
     Producto aux = _archivo.leer(posicion);
     Mostrar(aux);
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE MODIFICAR EL REGISTRO?" << endl;
   cout << "(1 - SI / 0 - NO)" << endl;
   cout << "RESPUESTA: ";
   cin >> respuesta;
   cout << endl;

   int _id,_proveedor, _stock, _cantidad;
   char _marca[30], _droga[30], _categoria[30], _presentacion[30];
   Fecha _venci;
   float _importe;

   if (respuesta == 1)
   {
     cout << "INGRESE NUEVAMENTE LOS CAMPOS DEL PRODUCTO A MODIFICAR..." << endl;

     cout << "ID de medicamento: ";
     cin >> _id;
     producto.setId(_id);

     cout << "Marca del medicamento: ";
     cargarCadena(_marca, 29);
     producto.setMarca(_marca);

     cout << "Droga del medicamento: ";
     cargarCadena(_droga, 29);
     producto.setDroga(_droga);

     cout << "Categoria de medicamento: ";
     cargarCadena(_categoria, 29);
     producto.setCategoria(_categoria);

     cout << "Proveedor(1 - Disval / 2 - Suizo): ";
     cin >> _proveedor;
     producto.setProveedor(_proveedor);

     cout << "Fecha de vencimiento: " << endl;
     _venci.Cargar();
     producto.setVencimiento(_venci);

     cout << "Presentacion: ";
     cargarCadena(_presentacion,29);
     producto.setPresentacion(_presentacion);

     cout << "Cantidad: ";
     cin >> _cantidad;
     producto.setCantidad(_cantidad);

     cout << "Importe: ";
     cin >> _importe;
     producto.setImporte(_importe);

     _stock += cantidad;
     producto.setStock(_stock);

     if (_archivo.modificarProducto(producto, posicion))
     {
       cout << "REGISTRO MODIFICADO CON EXITO!" << endl;
     }else
     {
       cout << "NO SE PUDO MODIFICAR EL REGISTRO!" << endl;
     }
   }
 }

 void ProductoManager::mostrarPorProveedor()
 {
   Producto aux;
   int Proveedor;
   int cantidad = _archivo.contarRegistros();

   cout << "Ingresar el proveedor: ";
   cin >> Proveedor;
   cout << endl;

   for (int i=0; i<cantidad; i++)
   {
      aux = _archivo.leer(i);
     if (Proveedor == 1 || Proveedor == 2)
     {
       if (aux.getProveedor() == Proveedor)
       {
         Mostrar(aux);
       }
     }else
     {
       cout << "NO EXISTE EL NUMERO DE PROVEEDOR INGRESADO" << endl;
       return;
     }
   }
 }

 void ProductoManager::mostrarPorCategoria()
 {
   Producto aux;
   char categoria[30];
   int cantidad = _archivo.contarRegistros();
   bool existe = false;

   cout << "Ingresar categoria: ";
   cargarCadena(categoria,29);
   cout << endl;

   for (int i=0; i<cantidad; i++)
   {
     aux = _archivo.leer(i);
     int comparacion = strcmp(aux.getCategoria(),categoria);
     if (comparacion == 0)
     {
       Mostrar(aux);
       existe = true;
     }
   }
   if (!existe)
   {
     cout << "CATEGORIA INEXISTENTE" << endl;
   }
 }

 bool compararDrogas(char drogaSolicitada[30],const char* drogaProducto){
    int cont = 0;
    int largo1 = strlen(drogaProducto);
    int largo2 = strlen(drogaSolicitada);
    if(largo2 > largo1){
        return false;
    }else{
        for(int i = 0; i < largo1; i++){
            if(drogaSolicitada[cont] == drogaProducto[i]){
                cont++;
            }
        }
    }
    if(cont > 0 && cont == largo2){
        return true;
    }else{
        return false;
    }
 }

 void ProductoManager::mostrarPorDroga(){
    ProductoArchivo archiProducto("producto.dat");
    Producto productos;
    char drogaProducto[30];
    cout<<"INGRESE LA DROGA SOLICITADA: ";
    cargarCadena(drogaProducto,29);
    bool drogaActiva = false;

    for(int i = 0; i < archiProducto.contarRegistros(); i++)
    {
      productos = archiProducto.leer(i);
      if(compararDrogas(drogaProducto,productos.getDroga())){
        Mostrar(productos);
        drogaActiva = true;
      }

    }
    if (!drogaActiva)
    {
      cout << "NO SE ENCONTRO NINGUNA DROGA CON ESE NOMBRE" << endl;
    }
 }

 void ProductoManager::menuProducto()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "PRODUCTOS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA MEDICAMENTO" << endl;
      cout << "2 - LISTAR MEDICAMENTOS A LA VENTA" << endl;
      cout << "3 - BAJA MEDICAMENTO" << endl;
      cout << "4 - MODIFICAR REGISTRO DE MEDICAMENTO" << endl;
      cout << "5 - CONSULTAS" << endl;
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
          Producto aux = Cargar();
          _archivo.guardarArchivo(aux);
        }
        break;
       case 2:
        {
          mostrarTodos();
        }
        break;
       case 3:
        {
          bajaPoducto();
        }
        break;
       case 4:
        {
         modificarRegistro();
        }
        break;
       case 5:
        {
          Consultas consulta;
          consulta.menuConsultas();
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
