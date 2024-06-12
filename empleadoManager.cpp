#include <iostream>
using namespace std;
#include <cstring>
#include "funcionesGlobales.h"
#include "empleado.h"
#include "empleadoManager.h"
#include "consultas.h"

 //CARGAR
 Empleado EmpleadoManager::Cargar()
 {
   Empleado aux;
   EmpleadoArchivo archiEmpleado("empleado.dat");
   int dni, id;
   char nombre[30], apellido[30], telefono[30];

   id = archiEmpleado.contarRegistros()+1;
   aux.setId(id);

   cout << "DNI: ";
   cin >> dni;
   aux.setDni(dni);

   cout << "Nombre: ";
   cargarCadena(nombre, 29);
   aux.setNombre(nombre);

   cout << "Apellido: ";
   cargarCadena(apellido, 29);
   aux.setApellido(apellido);

   cout << "Telefono: ";
   cargarCadena(telefono,29);
   aux.setTelefono(telefono);

   return aux;
 }

//MOSTRAR
 void EmpleadoManager::Mostrar(Empleado empleado)
 {
   if (empleado.getEstado())
   {
     cout << "DNI: " << empleado.getDni() << endl;
     cout << "Nombre: " << empleado.getNombre() << endl;
     cout << "Apellido: " << empleado.getApellido() << endl;
     cout << "Telefono: " << empleado.getTelefono() << endl;
     cout << endl;
     cout << "-------------------------------" << endl;
   }
 }


 void EmpleadoManager::mostrarTodos()
 {
   for (int i=0; i<_archivo.contarRegistros(); i++)
   {
     Mostrar(_archivo.leer(i));
   }
   pausa();
 }

 void EmpleadoManager::mostrarPorDni()
 {
   Empleado aux;
   int dni;

   cout << "Ingresar el DNI: ";
   cin >> dni;
   cout << endl;

   int posicion = _archivo.buscar(dni);
   if (posicion >= 0)
   {
     aux = _archivo.leer(posicion);
     if (aux.getDni() == 0)
     {
       cout << "ESTE REGISTRO NO PUEDE SER LISTADO" << endl;
       cout << "Sugerencia: ir al apartado de [LISTAR EMPLEADOS A MODIFICAR POR X ERROR DE CARGA]" << endl;
       return;
     }
     Mostrar(aux);
   }else
   {
     cout << "NO EXISTE EL NUMERO DE DNI INGRESADO" << endl;
   }
 }

 void EmpleadoManager::baja()
 {
   Empleado empleado;
   int dni;
   cout << "Ingresar el DNI: ";
   cin >> dni;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(dni);
   if (posicion >= 0 && empleado.getDni() != 0)
   {
     Empleado aux = _archivo.leer(posicion);
     Mostrar(aux);
     pausa();
   }else
   {
     cout << "NO EXISTE EL NUMERO DE DNI INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE ELIMINAR EL REGISTRO?" << endl;
   cout << "(1 - SI / 0 - NO)" << endl;
   cin >> respuesta;
   cout << endl;

   if (respuesta == 1)
   {
     empleado.setEstado(false);
     if (_archivo.modificar(empleado, posicion))
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

 void EmpleadoManager::modificar()
 {
   Empleado empleado;
   int dni;
   cout << "INGRESAR EL DNI: ";
   cin >> dni;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(dni);
   if (posicion >= 0)
   {
     Empleado aux = _archivo.leer(posicion);
     Mostrar(aux);
   }else
   {
     cout << "NO EXISTE EL NUMERO DE DNI INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "¿ESTA SEGURO QUE QUIERE MODIFICAR EL REGISTRO?" << endl;
   cout << "(1 - SI / 0 - NO)" << endl;
   cin >> respuesta;
   cout << endl;

   int _dni;
   char _nombre[30], _apellido[30], _telefono[30];

   if (respuesta == 1)
   {
     cout << "INGRESE NUEVAMENTE LOS CAMPOS DEL EMPLEADO A MODIFICAR..." << endl;

     cout << "DNI de empleado: ";
     cin >> _dni;
     empleado.setDni(_dni);

     cout << "Nombre de empleado: ";
     cargarCadena(_nombre, 29);
     empleado.setNombre(_nombre);

     cout << "Apellido de empleado: ";
     cargarCadena(_apellido, 29);
     empleado.setApellido(_apellido);

     cout << "Telefono: ";
     cargarCadena(_telefono,29);
     empleado.setTelefono(_telefono);

     if (_archivo.modificar(empleado, posicion))
     {
       cout << "REGISTRO MODIFICADO CON EXITO!" << endl;
     }else
     {
       cout << "NO SE PUDO MODIFICAR EL REGISTRO!" << endl;
     }
   }
 }


 void EmpleadoManager::menuEmpleado()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "   EMPLEADOS" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA" << endl;
      cout << "2 - BAJA" << endl;
      cout << "3 - LISTAR" << endl;
      cout << "4 - EDITAR" << endl;
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
          Empleado aux = Cargar();
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
      clear();
    }
   return;
 }
