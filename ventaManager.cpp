#include <iostream>
using namespace std;
#include "ventaManager.h"
#include "funcionesGlobales.h"
#include "consultasVentas.h"

  //CARGAR
 Venta VentaManager::Cargar()
 {
   Venta aux;
   VentaArchivo archiVenta("venta.dat");
   int numero;
   int idEmpleado;
   int idProducto[100] = {};
   int cantidad[100] = {};
   bool estado;

   cout << "ID de empleado: ";
   cin >> idEmpleado;
   aux.setIdEmpleado(idEmpleado);

   numero = archiVenta.contarRegistros()+1;
   aux.setNumero(numero);

   aux.setFechaDeVenta(Fecha());

   aux.setHora(Hora());

   cout << endl;
   int contador = 0;
   cout << "ID de producto: ";
   cin >> idProducto[contador];
   aux.setIdProducto(idProducto[contador], contador);

   while (idProducto[contador] > 0)
   {
     cout << "Cantidad: ";
     cin >> cantidad[contador];
     aux.setCantidad(cantidad[contador], contador);
     cout << endl;

     contador++;

     cout << "ID de producto: ";
     cin >> idProducto[contador];
     aux.setIdProducto(idProducto[contador], contador);
   }

   estado = true;
   aux.setEstado(estado);

   return aux;
 }

//MOSTRAR
 void VentaManager::Mostrar(Venta reg)
 {
   if (reg.getEstado())
   {
     cout << "Numero de venta: " << reg.getNumero() << endl;
     cout << "ID de empleado: " << reg.getIdEmpleado() << endl;
     cout << "Fecha de venta: " << reg.getFechaDeVenta().toString() << endl;
     cout << "Horario: " << reg.getHorario().toString() << endl;
     cout << endl;
     for (int i=0; i<100; i++)
     {
       if (reg.getIdProducto(i) > 0)
       {
         cout << "ID Producto: " << reg.getIdProducto(i) << endl;
         cout << "Cantidad: " << reg.getCantidad(i) << endl;
         cout << endl;
       }
     }

     cout << endl;
     cout << "-------------------------------" << endl;
   }
 }


 void VentaManager::mostrarTodos()
 {
   for (int i=0; i<_archiVenta.contarRegistros(); i++)
   {
     Mostrar(_archiVenta.leer(i));
   }
   pausa();
 }

 void VentaManager::baja()
 {
   Venta reg;
   int numero;
    Fecha fechaIngresante;
   cout << "Ingresar el Numero de venta: ";
   cin >> numero;
   cout << endl;
   bool activo = false;
   int posicion;

   int cantidad = _archiVenta.contarRegistros();
   for (int i=0; i<cantidad; i++)
   {
     reg = _archiVenta.leer(i);
     if (reg.getNumero() == numero)
     {
       activo = true;
       Mostrar(reg);
       posicion = i;
     }
   }
   if (!activo)
   {
     cout << "NO EXISTE EL REGISTRO QUE ESTAS BUSCANDO" << endl;
     pausa();
     return;
   }
   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE ELIMINAR EL REGISTRO?(1 - SI / 0 - NO)" << endl;
   cin >> respuesta;
   cout << endl;

   if (respuesta == 1)
   {
     reg.setEstado(false);
     if (_archiVenta.modificar(reg, posicion))
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

 void VentaManager::modificar()
 {
   Venta reg;
   int numero;

   bool activo = false;

   cout << "Ingrese el numero de la venta a modificar: ";
   cin >> numero;
   int posicion;

   int cantidad = _archiVenta.contarRegistros();
   for (int i=0; i<cantidad; i++)
   {
     reg = _archiVenta.leer(i);
     if (reg.getNumero() == numero)
     {
       activo = true;
       Mostrar(reg);
       posicion = i;
     }
   }
   if (!activo)
   {
     cout << "NO EXISTE EL REGISTRO QUE ESTAS BUSCANDO" << endl;
     pausa();
     return;
   }

   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE MODIFICAR EL REGISTRO?" << endl;
   cout << "(1 - SI / 0 - NO)" << endl;
   cout << "RESPUESTA: ";
   cin >> respuesta;
   cout << endl;

    int idEmpleado;
    int idProducto[100] = {};
    int cantidadP[100] = {};

   if (respuesta == 1)
   {
     cout << "INGRESE NUEVAMENTE LOS CAMPOS DEL PRODUCTO A MODIFICAR..." << endl;

     reg.setNumero(numero);

     cout << "ID de empleado: ";
     cin >> idEmpleado;
     reg.setIdEmpleado(idEmpleado);

     int contador = 0;

     cout << endl;
     cout << "ID de producto: ";
     cin >> idProducto[contador];
     reg.setIdProducto(idProducto[contador], contador);

     while (idProducto[contador] > 0)
     {
       cout << "Cantidad: ";
       cin >> cantidadP[contador];
       reg.setCantidad(cantidadP[contador], contador);
       cout << endl;

       contador++;

       cout << "ID de producto: ";
       cin >> idProducto[contador];
       reg.setIdProducto(idProducto[contador], contador);
     }

     if (_archiVenta.modificar(reg, posicion))
     {
       cout << "REGISTRO MODIFICADO CON EXITO!" << endl;
       pausa();
     }else
     {
       cout << "NO SE PUDO MODIFICAR EL REGISTRO!" << endl;
       pausa();
     }
   }
 }

 void VentaManager::MostrarPorFechaDeCompra()
 {
   Venta reg;
   VentaArchivo _archiVenta("venta.dat");
   int cantidadDeReg = _archiVenta.contarRegistros();

   bool activo = false;
   Fecha fechaAbuscar;

   cout << "INGRESE LA FECHA DE LA VENTA A BUSCAR: " << endl;
   fechaAbuscar.Cargar();
   clear();

   for(int i=0; i<cantidadDeReg; i++)
   {
     reg = _archiVenta.leer(i);
     if (reg.getEstado() && reg.getFechaDeVenta().toString() == fechaAbuscar.toString())
     {
       activo = true;

       Mostrar(reg);
     }
   }
   if (!activo)
   {
     cout << "NO SE ENCONTRO NINGUNA VENTA CON ESA FECHA" << endl;
   }
 }


  void VentaManager::MostrarPorIdDeEmpleado()
  {
    Venta reg;
    VentaArchivo _archiVenta("venta.dat");
    int cant = _archiVenta.contarRegistros();

    int idEmpleado;
    cout << "Ingrese el ID de empleado: ";
    cin >> idEmpleado;
    cout << endl;

    bool activo = false;

    for (int i=0; i<cant; i++)
    {
      reg = _archiVenta.leer(i);
      if(reg.getEstado() && reg.getIdEmpleado() == idEmpleado)
      {
        activo = true;
        Mostrar(reg);
        cout << endl;
      }
    }
    if (!activo)
    {
      cout << "NO EXISTEN VENTAS CON EL ID DE USUARIO QUE INGRESO " << endl;
    }
  }



 void VentaManager::menuVentas()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "     VENTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA VENTA" << endl;
      cout << "2 - BAJA VENTA" << endl;
      cout << "3 - LISTAR VENTAS" << endl;
      cout << "4 - MODIFICAR" << endl;
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
          Venta reg = Cargar();
          _archiVenta.guardarArchivo(reg);
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
          ConsultasVentas reg;
          reg.menuConsultasVentas();
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
