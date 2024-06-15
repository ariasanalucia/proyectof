#include <iostream>
using namespace std;
#include "ventaManager.h"
#include "funcionesGlobales.h"
#include "consultasVentas.h"
#include "productoManager.h"
#include "venta.h"


  //CARGAR
 Venta VentaManager::Cargar()
 {
   Venta aux;
   VentaArchivo archiVenta("venta.dat");
   Producto prod;
   ProductoArchivo archiProducto("producto.dat");
   int numero, idEmpleado;
   int idProducto[10] = {};
   int cantidad[10] = {};
   bool estado;
   float importe;

   cout << "ID de empleado: ";
   cin >> idEmpleado;
   aux.setIdEmpleado(idEmpleado);
   cout << "(Ingrese 0 para detener la carga)" << endl;
   cout << "------------------------------------" << endl;

   numero = archiVenta.contarRegistros()+1;
   aux.setNumero(numero);

   aux.setFecha(Fecha());

   aux.setHora(Hora());

   int respuesta = 1;
   int contador = 0;
   while (contador < 10) //Carga productos hasta recibir 0
   {
     if (respuesta == 1)
     {
       validarDroga();
       cout << endl << endl;
       cout << "ID de producto: ";
       cin >> idProducto[contador];
       if (idProducto[contador]<=0) {break;}
       aux.setIdProducto(idProducto[contador], contador);

       cout << "Cantidad: ";
       cin >> cantidad[contador];
       if (cantidad[contador]<=0) {break;}
       aux.setCantidad(cantidad[contador], contador);

       if(!restarStockDeProducto(idProducto[contador], cantidad[contador]))
       {
         break;
         return Venta();
       }

       //Calculo del importe:
       for (int i = 0; i < archiProducto.contarRegistros(); i++) {
         prod=archiProducto.leer(i);
         if (prod.getId()==idProducto[contador]) {
           importe += prod.getPrecioUnitario()*cantidad[contador];
           break;
         }
       }

     }else
     {
       break;
     }

     contador++;
     cout << "QUIERE SEGUIR CARGANDO PRODUCTOS?";
     cout << "(1 - SI | 0 - NO)" << endl;
     cin >> respuesta;
   }

   cout << "------------------------------------" << endl;
   cout << "TOTAL: $" << importe;
   pausa();

   aux.setImporte(importe);

   estado = true;
   aux.setEstado(estado);

   return aux;
 }

//MOSTRAR
 void VentaManager::Mostrar(Venta reg)
 {
   if (reg.getEstado() && reg.getImporte() > 0)
   {
     cout << "Numero de venta: " << reg.getNumero() << endl;
     cout << "ID de empleado: " << reg.getIdEmpleado() << endl;
     cout << "Fecha: " << reg.getFecha().toString() << endl;
     cout << "Hora: " << reg.getHora().toString() << endl;
     cout << endl;
     for (int i=0; i<10; i++)
     {
       if (reg.getIdProducto(i) > 0)
       {
         cout << "ID Producto: " << reg.getIdProducto(i) << endl;
         cout << "Cantidad: " << reg.getCantidad(i) << endl;
         cout << endl;
       }
     }
     cout << "Importe: $" << reg.getImporte() << endl;
     cout << "-------------------------------" << endl;
   }
 }

 void VentaManager::validarDroga()
 {
   while(!obj.mostrarPorDroga())
   {
     if(obj.mostrarPorDroga())
     {
       break;
     }
   }
 }

 bool VentaManager::restarStockDeProducto(int idProducto,int cantidad)
 {
   Producto reg;
   ProductoArchivo archiP("producto.dat");
   int cantidadDeProd = archiP.contarRegistros();

   bool ventaExistosa = false;

   for (int i=0; i<cantidadDeProd; i++)
   {
     reg = archiP.leer(i);
     if (reg.getId() == idProducto && reg.getEstado())
     {
       if (cantidad > reg.getStock())
       {
         cout << "STOCK INSUFICIENTE!" << endl;
         cout << "CANTIDAD DISPONIBLE: " << reg.getStock() << endl;
         pausa();
       }else
       {
         reg.setStock(reg.getStock()-cantidad);
         archiP.modificar(reg, i);
         ventaExistosa = true;
       }
     }
   }
   return ventaExistosa;
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
   cout << "ESTA SEGURO QUE QUIERE ELIMINAR EL REGISTRO?" << endl;
   cout << "(1 - SI | 0 - NO)" << endl;
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
   cout << "ESTA SEGURO QUE QUIERE MODIFICAR EL REGISTRO?" << endl;
   cout << "(1 - SI | 0 - NO)" << endl;
   cout << "RESPUESTA: ";
   cin >> respuesta;
   cout << endl;

    int idEmpleado;
    int idProducto[10] = {};
    int cantidadP[10] = {};

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
   Fecha fechaAbuscar1, fechaAbuscar2;

   cout << "INGRESE UN RAGO DE FECHAS: " << endl;
   cout << "PRIMER FECHA(fecha mas antigua): " << endl;
   fechaAbuscar1.Cargar();
   int aux1 = (fechaAbuscar1.getAnio()*525960)+(fechaAbuscar1.getMes()*43830)+(fechaAbuscar1.getDia()*1440);
   cout << endl;

   cout << "SEGUNDA FECHA(fecha mas reciente): " << endl;
   fechaAbuscar2.Cargar();
   int aux2 = (fechaAbuscar2.getAnio()*525960)+(fechaAbuscar2.getMes()*43830)+(fechaAbuscar2.getDia()*1440);

   clear();

   for(int i=0; i<cantidadDeReg; i++)
   {
     reg = _archiVenta.leer(i);
     int fechaDeVenta = (reg.getFecha().getAnio()*525960)+(reg.getFecha().getMes()*43830)+(reg.getFecha().getDia()*1440);

     if (fechaDeVenta >= aux1 && fechaDeVenta <= aux2)
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
      cout << "NO EXISTEN VENTAS CON EL ID DE USUARIO QUE INGRESO" << endl;
    }
  }

  void VentaManager::MostrarPorProducto()
  {
   Producto reg;
   ProductoArchivo archivoP("producto.dat");
   int cantProductos = archivoP.contarRegistros();

   Venta regVenta;
   VentaArchivo _archiVenta("venta.dat");
   int cantVentas = _archiVenta.contarRegistros();

   validarDroga();

   int idProducto;
   cout << "INGRESE EL ID DEL PRODUCTO: ";
   cin >> idProducto;
   cout << endl;
   clear();

   if (idProducto <= cantProductos)
   {
     reg = archivoP.leer(idProducto-1);
     for (int i=0; i<cantVentas; i++)
     {
       regVenta = _archiVenta.leer(i);

       if (reg.getId() == regVenta.getIdProducto(idProducto-1) && reg.getEstado())
       {
         Mostrar(regVenta);
         cout << endl;
       }
     }
   }
   pausa();
  }



 void VentaManager::menuVentas()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "     VENTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA" << endl;
      cout << "2 - BAJA -> Nota de Credito?" << endl;
      cout << "3 - LISTAR" << endl;
      cout << "4 - MODIFICAR" << endl;
      cout << "5 - CONSULTAS" << endl;
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
          listadosVentas listado;
          listado.menuListados();
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

