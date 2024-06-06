#include <iostream>
using namespace std;
#include <cstring>
#include <ctype.h>
#include "funcionesGlobales.h"
#include "productoManager.h"
#include "consultas.h"

 //CARGAR
 Producto ProductoManager::Cargar()
 {
   Producto aux;
   ProductoArchivo archiProducto("producto.dat");
   int id, Proveedor;
   char marca[30], droga[30], categoria[30], presentacion[30];
   Fecha venci;
   float precioUnitario, miligramos;

   id = archiProducto.contarRegistros()+1;
   aux.setId(id);

   cout << "Marca: ";
   cargarCadena(marca, 29);
   aux.setMarca(marca);

   cout << "Droga: ";
   cargarCadena(droga, 29);
   aux.setDroga(droga);

   cout << "Miligramos: ";
   cin >> miligramos;
   aux.setMiligramos(miligramos);

   cout << "Accion terapeutica: ";
   cargarCadena(categoria, 29);
   aux.setCategoria(categoria);

   cout << "Proveedor: " << endl;
   cout << "[1 - Disval | 2 - Suizo]" << endl;
   cin >> Proveedor;
   validar_proveedor(&Proveedor);
   aux.setProveedor(Proveedor);

   cout << "Fecha de vto: " << endl;
   venci.Cargar();
//   esFechaValida();
   aux.setVencimiento(venci);

   cout << "Presentacion: ";
   cargarCadena(presentacion,29);
   aux.setPresentacion(presentacion);

   cout << "Precio: $";
   cin >> precioUnitario;
   aux.setPrecioUnitario(precioUnitario);

   aux.setStock(0);

   return aux;
 }

//MOSTRAR
 void ProductoManager::Mostrar(Producto producto)
 {
   if (producto.getEstado())
   {
     cout << "ID de medicamento: " << producto.getId() << endl;
     cout << "Marca: " << producto.getMarca() << endl;
     cout << "Droga:" << producto.getDroga() << endl;
     cout << "Miligramos: " << producto.getMiligramos() << endl;
     cout << "Accion terapeutica: " << producto.getCategoria() << endl;
     cout << "Proveedor(1 - Disval / 2 - Suizo): " << producto.getProveedor() << endl;
     cout << "Fecha de vto: " << producto.getVenciemiento().toString() << endl;
     cout << "Presentacion: " << producto.getPresentacion() << endl;
     cout << "Stock disponible: " << producto.getStock() << endl;
     cout << "Precio: $" << producto.getPrecioUnitario() << endl;
     cout << endl;
     cout << "-------------------------------" << endl;
   }
 }

 bool ProductoManager::es_proveedor(int Proveedor){
    return (Proveedor == 1 || Proveedor == 2);
 }

 void ProductoManager::validar_proveedor(int *Proveedor){
    while(!es_proveedor(*Proveedor)){
        cout<<"Ingrese correctamente el provedor 1 o 2:";
        cin>>*Proveedor;
    }
 }

// bool ProductoManager::validarFechaVencimiento(int idProducto)
// {
//   Producto reg;
//   ProductoArchivo archiP("producto.dat");
//   int cant = archiP.contarRegistros();
//
//   Fecha fechaActual();
//
//   for (int i=0; i<cant; i++)
//   {
//     reg = archiP.leer(i);
//     if(reg.getId() == idProducto)
//     {
//       if (reg.getVenciemiento().getAnio() < fechaActual().getAnio())
//       {
//         return false;
//       }
//     }
//   }
//   return true;
// }
//
// void ProductoManager::esFechaValida()
// {
//   Fecha venci;
//   while (!validarFechaVencimiento(id))
//   {
//     cout << "Ingrese una fecha de vto valida: ";
//     venci.Cargar();
//   }
// }


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
     pausa();
     if (aux.getStock() == 0)
     {
       cout << "REPONER STOCK!" << endl;
       pausa();
     }
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     pausa();
   }
 }

 void ProductoManager::baja()
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
   cout << "¿ESTA SEGURO QUE QUIERE ELIMINAR EL REGISTRO?" << endl;
   cout << "(1 - SI / 0 - NO)" << endl;
   cout << "RESPUESTA: ";
   cin >> respuesta;
   cout << endl;

   if (respuesta == 1)
   {
     producto.setEstado(false);
     if (_archivo.modificar(producto, posicion))
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

 void ProductoManager::modificar()
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

   int _id,_proveedor, _stock;
   char _marca[30], _droga[30], _categoria[30], _presentacion[30];
   Fecha _vencimiento;
   float _precioUnitario, _miligramos;

   if (respuesta == 1)
   {
     cout << "INGRESE NUEVAMENTE LOS CAMPOS DEL PRODUCTO A MODIFICAR..." << endl;

     cout << "ID de medicamento: ";
     cin >> _id;
     producto.setId(_id);

     cout << "Marca: ";
     cargarCadena(_marca, 29);
     producto.setMarca(_marca);

     cout << "Droga: ";
     cargarCadena(_droga, 29);
     producto.setDroga(_droga);

     cout << "Miligramos: ";
     cin >> _miligramos;
     producto.setMiligramos(_miligramos);

     cout << "Accion terapeutica: ";
     cargarCadena(_categoria, 29);
     producto.setCategoria(_categoria);

     cout << "Proveedor:" << endl;
     cout << "(1 - Disval / 2 - Suizo)";
     cin >> _proveedor;
     validar_proveedor(&_proveedor);
     producto.setProveedor(_proveedor);

     cout << "Fecha de vto: " << endl;
     _vencimiento.Cargar();
     producto.setVencimiento(_vencimiento);

     cout << "Presentacion: ";
     cargarCadena(_presentacion,29);
     producto.setPresentacion(_presentacion);

     cout << "Precio: ";
     cin >> _precioUnitario;
     producto.setPrecioUnitario(_precioUnitario);

     cout << "Stock: ";
     cin >> _stock;
     producto.setStock(_stock);

     if (_archivo.modificar(producto, posicion))
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


 bool compararCaracteres(char palabraSolicitada[30],const char* palabraExistente){
    int cont = 0;
    int largo1 = strlen(palabraExistente);
    int largo2 = strlen(palabraSolicitada);
    if(largo2 > largo1)
   {
     return false;
   }else
    {
      for(int i = 0; i < largo1; i++)
      {
        if(tolower(palabraSolicitada[cont]) == tolower(palabraExistente[i]))
        {
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
      if(compararCaracteres(drogaProducto,productos.getDroga())){
        Mostrar(productos);
        drogaActiva = true;
      }
    }
    if (!drogaActiva)
    {
      cout << "ESA DROGA NO SE ENCUENTRA REGISTRADA" << endl;
    }
    pausa();
 }

 void ProductoManager::mostrarPorCategoria(){
    ProductoArchivo archiProducto("producto.dat");
    Producto productos;
    char categoriaProducto[30];
    cout<<"INGRESE LA CATEGORIA SOLICITADA: ";
    cargarCadena(categoriaProducto,29);
    bool categoriaActiva = false;

    for(int i = 0; i < archiProducto.contarRegistros(); i++)
    {
      productos = archiProducto.leer(i);
      if(compararCaracteres(categoriaProducto,productos.getCategoria())){
        Mostrar(productos);
        categoriaActiva = true;
      }
    }
    if (!categoriaActiva)
    {
      cout << "ESA CATEGORIA NO SE ENCUENTRA REGISTRADA" << endl;
    }
 }


// void ProductoManager::solicitarProducto(){
//
//    mostrarPorDroga();
//
//    ProductoArchivo archiProducto("producto.dat");
//    Producto productos;
//    int idProducto,cantStockSolicitada;
//
//    cout<<"INGRESE EL ID DEL PRODUCTO QUE QUIERE PEDIRLE AL PROVEEDOR:";
//    cin>>idProducto;
//    if(idProducto <= archiProducto.contarRegistros()){
//        cout<<"Ingrese la cantidad de dicho producto que desea:";
//        cin>>cantStockSolicitada;
//        productos = archiProducto.leer(idProducto-1);
//        cout<<"El stock anterior es:"<<productos.getId()<<endl;
//        productos.setStock(productos.getStock() + cantStockSolicitada);
//        _archivo.modificar(productos,idProducto-1);
//        pausa();
//    }else{
//        cout<<"no se encontro dicho producto";
//        pausa();
//    }
//    fclose(f_leer_producto);
//}

 void ProductoManager::solicitarProducto()
 {
   Producto reg;
   ProductoArchivo archivoP("producto.dat");
   int cantProductos = archivoP.contarRegistros();

   int idProducto, cantStockSolicitada;

   mostrarPorDroga();

   cout << "INGRESE EL ID DEL PRODUCTO A SOLICITAR: ";
   cin >> idProducto;
   cout << endl;

   if (idProducto <= cantProductos)
   {
     cout << "INGRESE LA CANTIDAD DEL PRODUCTO A SOLICITAR: ";
     cin >> cantStockSolicitada;
     cout << endl;
     int respuesta;

     reg = archivoP.leer(idProducto-1);
     if (reg.getEstado() && reg.getId() == idProducto)
     {
       Mostrar(reg);
       cout << "DESEA PEDIR STOCK DE ESTE MEDICAMENTO(1-si, 0-no): ";
       cin >> respuesta;
       cout << endl;
       if (respuesta == 1)
       {
         reg.setStock(reg.getStock()+cantStockSolicitada);
         if (archivoP.modificar(reg,idProducto-1))
         {
           cout << "STOCK AGREGARDO CORRECTAMENTE" << endl;
           cout << endl;
           pausa();
           cout << "PRODUCTO ACTUALIZADO: " << endl;
           cout << endl;
           Mostrar(reg);
           pausa();
         }else
         {
           cout << "NO SE PUDO AGREGAR EL STOCK SOLICITADO" << endl;
           pausa();
         }
       }else
       {
         return;
       }
     }
   }else
   {
     cout << "NO EXISTE EL PRODUCTO SOLICITADO" << endl;
     pausa();
   }
 }

 void ProductoManager::menuProducto()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "    PRODUCTOS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA" << endl;
      cout << "2 - BAJA" << endl;
      cout << "3 - LISTAR" << endl;
      cout << "4 - MODIFICAR" << endl;
      cout << "5 - SOLICITAR PRODUCTO" << endl;
      cout << "6 - CONSULTAS" << endl;
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
          baja();
        }
        break;
       case 3:
        {
          mostrarTodos();
        }
        break;
       case 4:
        {
         modificar();
        }
        break;
       case 5:
        {
         solicitarProducto();
        }
        break;
        case 6:
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
