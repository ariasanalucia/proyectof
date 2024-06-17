#include <iostream>

using namespace std;

#include <cstring>
#include <ctype.h>
#include "funcionesGlobales.h"
#include "productoManager.h"
#include "consultas.h"
#include "listadosProductos.h"
#include "validacion.h"


 //CARGAR
 Producto ProductoManager::Cargar()
 {
   validacionProducto validaciones;
   Producto aux;
   ProductoArchivo archiProducto("producto.dat");
   int id, Proveedor;
   char marca[30], droga[30], categoria[30], presentacion[30];
   Fecha venci;
   float precioUnitario, miligramos;

   id = archiProducto.contarRegistros()+1;
   aux.setId(id);

   cout << "Marca(caracteres): ";
   cargarCadena(marca, 29);
   aux.setMarca(marca);

   cout << "Droga(caracteres): ";
   cargarCadena(droga, 29);
   aux.setDroga(droga);

   cout << "Miligramos(numero con decimales): ";
   cin >> miligramos;
   validaciones.valdiarMiligramo(miligramos);
   aux.setMiligramos(miligramos);

   cout << "Accion terapeutica(caracteres): ";
   cargarCadena(categoria, 29);
   aux.setCategoria(categoria);

   cout << "Proveedor(numero entero): " << endl;
   cout << "(1 - Disval | 2 - Suizo)" << endl;
   cin >> Proveedor;
   validaciones.validarProveedor(Proveedor);
   aux.setProveedor(Proveedor);

   cout << "Fecha de vto: " << endl;
   venci.Cargar();
   validaciones.validarVencimiento(venci);
   aux.setVencimiento(venci);

   cout << "Presentacion(caracteres): ";
   cargarCadena(presentacion,29);
   aux.setPresentacion(presentacion);

   cout << "Precio(numero con decimales): $";
   cin >> precioUnitario;
   validaciones.validarPrecio(precioUnitario);
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
     cout << "Droga: " << producto.getDroga() << endl;
     cout << "Miligramos: " << producto.getMiligramos() << endl;
     cout << "Accion terapeutica: " << producto.getCategoria() << endl;
     cout << "Proveedor: (1 - Disval | 2 - Suizo):" << producto.getProveedor() << endl;
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
        cout << "Ingrese correctamente el provedor:" << endl;
        cout << "(1 - Disval | 2 - Suizo):" << endl;
        cin >> *Proveedor;
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
   cout << "(1 - SI | 0 - NO)" << endl;
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

     cout << "Marca(caracteres): ";
     cargarCadena(_marca, 29);
     producto.setMarca(_marca);

     cout << "Droga(caracteres): ";
     cargarCadena(_droga, 29);
     producto.setDroga(_droga);

     cout << "Miligramos(numero con decimales): ";
     cin >> _miligramos;
     producto.setMiligramos(_miligramos);

     cout << "Accion terapeutica(caracteres): ";
     cargarCadena(_categoria, 29);
     producto.setCategoria(_categoria);

     cout << "Proveedor(numero entero):" << endl;
     cout << "(1 - Disval | 2 - Suizo)";
     cin >> _proveedor;
     validar_proveedor(&_proveedor);
     producto.setProveedor(_proveedor);

     cout << "Fecha de Vto: " << endl;
     _vencimiento.Cargar();
     producto.setVencimiento(_vencimiento);

     cout << "Presentacion(caracteres): ";
     cargarCadena(_presentacion,29);
     producto.setPresentacion(_presentacion);

     cout << "Precio(numeros con decimales): ";
     cin >> _precioUnitario;
     producto.setPrecioUnitario(_precioUnitario);

     cout << "Stock(numero entero): ";
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
     }
   }
   cout << "NO EXISTE EL NUMERO DE PROVEEDOR INGRESADO" << endl;
   return;
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

 bool ProductoManager::mostrarPorDroga(){
    ProductoArchivo archiProducto("producto.dat");
    Producto productos;
    char drogaProducto[30];
    cout<<"INGRESE LA DROGA A BUSCAR: ";
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

    return drogaActiva;
 }

 void ProductoManager::mostrarPorCategoria(){
    ProductoArchivo archiProducto("producto.dat");
    Producto producto;
    char categoriaProducto[30];
    cout<<"INGRESE LA CATEGORIA A SOLICITAR: ";
    cargarCadena(categoriaProducto,29);
    bool existe = false;

    for(int i = 0; i < archiProducto.contarRegistros(); i++)
    {
      producto = archiProducto.leer(i);
      if(compararCaracteres(categoriaProducto,producto.getCategoria())){
        Mostrar(producto);
        existe = true;
      }
    }
    if (!existe)
    {
      cout << "ESA CATEGORIA NO SE ENCUENTRA REGISTRADA" << endl;
    }
 }

 void ProductoManager::mostrarPorPrecio(){
    ProductoArchivo archiProducto("producto.dat");
    Producto producto;

    float precio1;
    float precio2;
    cout<<"INGRESE UN RANGO DE PRECIOS " << endl;
    cout << "1er PRECIO (MAS BAJO): $";
    cin >> precio1;
    cout << endl;
    cout << "2do PRECIO (MAS ALTO): $";
    cin >> precio2;
    cout << endl;

    bool existe = false;
    for(int i = 0; i < archiProducto.contarRegistros(); i++)
    {
      producto = archiProducto.leer(i);
      if(producto.getPrecioUnitario() >= precio1 && producto.getPrecioUnitario() <= precio2){
        Mostrar(producto);
        cout << endl;
        existe = true;
      }
    }

    if (!existe) {
      cout << "NO SE ENCUENTRAN MEDICAMENTOS EN ESE RANGO DE PRECIOS" << endl;
      pausa();
    }

 }

 void ProductoManager::validarDroga()
 {
   while(!mostrarPorDroga())
   {
     if(mostrarPorDroga())
     {
       break;
     }
   }
 }

 void ProductoManager::solicitarProducto()
 {
   Producto reg;
   ProductoArchivo archivoP("producto.dat");
   int cantProductos = archivoP.contarRegistros();

   int idProducto, cantStockSolicitada;

   validarDroga();

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
       cout << "DESEA PEDIR STOCK DE ESTE MEDICAMENTO?";
       cout << "(1 - SI | 0 - NO): ";
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
      cout << "  MEDICAMENTOS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA" << endl;
      cout << "2 - BAJA" << endl;
      cout << "3 - LISTAR" << endl;
      cout << "4 - MODIFICAR" << endl;
      cout << "5 - SOLICITAR MEDICAMENTO" << endl;
      cout << "6 - CONSULTAS" << endl;
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
          listadosProductos reg;
          reg.menuListados();
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
