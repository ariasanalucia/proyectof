#include <iostream>
using namespace std;
#include "ventaManager.h"
#include "funcionesGlobales.h"

  //CARGAR
 Venta VentaManager::Cargar()
 {
    Venta aux;
    VentaArchivo archiVenta("venta.dat");
    int numero;
    Fecha fechaDeVenta;
    float importe;
    int idEmpleado;
    bool estado;

    numero = archiVenta.contarRegistros()+1;
    aux.setNumero(numero);

   cout << "Fecha de venta: " << endl;
   fechaDeVenta.Cargar();
   aux.setFechaDeVenta(fechaDeVenta);

   cout << "Importe: ";
   cin >> importe;
   aux.setImporte(importe);

   cout << "ID de empleado: ";
   cin >> idEmpleado;
   aux.setIdEmpleado(idEmpleado);

   estado = true;

   return aux;
 }

//MOSTRAR
 void VentaManager::Mostrar(Venta reg)
 {
   if (reg.getEstado())
   {
     cout << "Numero de venta: " << reg.getNumero() << endl;
     cout << "Fecha de venta: " << reg.getFechaDeVenta().toString() << endl;
     cout << "Importe: " << reg.getImporte() << endl;
     cout << "ID de empleado: " << reg.getIdEmpleado() << endl;
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


 void VentaManager::menuVentas()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "VENTAS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA VENTA" << endl;
      cout << "2 - LISTAR VENTAS" << endl;
      cout << "3 - BAJA VENTA" << endl;
      cout << "4 - MODIFICAR REGISTRO DE VENTA" << endl;
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
          mostrarTodos();
        }
        break;
       case 3:
        {
//          baja();
        }
        break;
       case 4:
        {
//         modificar();
        }
        break;
       case 5:
        {
//          Consultas consulta;
//          consulta.menuConsultas();
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
