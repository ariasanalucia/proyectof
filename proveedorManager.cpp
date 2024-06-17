#include <iostream>
using namespace std;
#include "proveedorManager.h"
#include "funcionesGlobales.h"
#include "validacion.h"
#include <algorithm> //Para transform()
 //CARGAR
 Proveedor ProveedorManager::Cargar()
 {
    validacionVenta validarVenta;
    Proveedor aux;
    ProveedorArchivo archiProveedor("proveedores.dat");
    int telefono,idProveedor;
    char nombre[30];

    idProveedor = archiProveedor.contarRegistros()+1;
    aux.setId(idProveedor);

   cout << "Nombre: ";
   cargarCadena(nombre, 29);
   aux.setNombre(nombre);

   cout << "Telefono: ";
   cin >> telefono;
   validarVenta.validarTelefono(telefono);
   aux.setTelefono(telefono);

   aux.setEstado(true);

   return aux;
 }

//MOSTRAR
 void ProveedorManager::Mostrar(Proveedor reg)
 {
   if (reg.getEstado())
   {
     cout << "ID: " << reg.getId() << endl;
     cout << "Nombre: " << reg.getNombre() << endl;
     cout << "Telefono: " << reg.getTelefono() << endl;
     cout << endl;
     cout << "-------------------------------" << endl;
   }
 }

 void ProveedorManager::mostrarTodos() //Ordenados por Nombre
 {
    int cantReg = _archivo.contarRegistros();

    //Crear un arreglo de punteros a Proveedor
    Proveedor* vecOrdenados = new Proveedor[cantReg];

    // Guardo todos los proveedores
    for (int i = 0; i < cantReg; i++)
    {
        vecOrdenados[i] = _archivo.leer(i);
    }
    //Ordenar los proveedores por nombre usando el algoritmo de burbuja
    for (int i = 0; i < cantReg - 1; i++)
    {
        for (int j = 0; j < cantReg - i - 1; j++)
        {
            string aux1 = vecOrdenados[j].getNombre();
            string aux2 = vecOrdenados[j+1].getNombre();
            transform(aux1.begin(), aux1.end(), aux1.begin(), ::tolower); //Aplico tolower() a cada caracter del string
            transform(aux2.begin(), aux2.end(), aux2.begin(), ::tolower);

            //Si est�n desordenados, intercambiar
            if (strcmp(aux1.c_str(), aux2.c_str()) > 0) //Sera valido (aux1 > aux2) para comparar?
            {
                Proveedor temp = vecOrdenados[j];
                vecOrdenados[j] = vecOrdenados[j+1];
                vecOrdenados[j+1] = temp;
            }
        }
    }

    //Mostrar 
    for (int i = 0; i < cantReg; i++)
    {
        //vecOrdenados[i]->Mostrar();
        Mostrar(vecOrdenados[i]);
    }

    delete[] vecOrdenados;

    pausa();
 }


 void ProveedorManager::baja()
 {
   Proveedor aux;
   int id;
   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(id);
   if (posicion >= 0)
   {
     Proveedor aux = _archivo.leer(posicion);
     Mostrar(aux);
     pausa();
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "ESTA SEGURO QUE QUIERE ELIMINAR EL REGISTRO?" << endl;
   cout << "(1 - SI | 0 - NO)" << endl;
   cin >> respuesta;
   cout << endl;

   if (respuesta == 1)
   {
     aux.setEstado(false);
     if (_archivo.modificar(aux, posicion))
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

 void ProveedorManager::modificar()
 {
   Proveedor reg;
   int id;
   cout << "Ingresar el ID: ";
   cin >> id;
   cout << endl;

   int cantidad = _archivo.contarRegistros();
   int posicion = _archivo.buscar(id);
   if (posicion >= 0)
   {
     Proveedor aux = _archivo.leer(posicion);
     Mostrar(aux);
   }else
   {
     cout << "NO EXISTE EL NUMERO DE ID INGRESADO" << endl;
     return;
   }
   int respuesta;
   cout << "ESTA SEGURO QUE QUIERE MODIFICAR EL REGISTRO?" << endl;
   cout << "(1 - SI | 0 - NO)" << endl;
   cout << "RESPUESTA: ";
   cin >> respuesta;
   cout << endl;

   int idPro, telefono;
   char nombre[30];
   bool estado;

   if (respuesta == 1)
   {
     cout << "INGRESE NUEVAMENTE LOS CAMPOS A MODIFICAR..." << endl;

     cout << "ID: ";
     cin >> idPro;
     reg.setId(idPro);

     cout << "Nombre: ";
     cargarCadena(nombre,29);
     reg.setNombre(nombre);

     cout << "Telefono: ";
     cin >> telefono;
     reg.setTelefono(telefono);

     estado = true;
     reg.setEstado(estado);

     if (_archivo.modificar(reg, posicion))
     {
       cout << "REGISTRO MODIFICADO CON EXITO!" << endl;
     }else
     {
       cout << "NO SE PUDO MODIFICAR EL REGISTRO!" << endl;
     }
   }
 }



void ProveedorManager::menuProveedor()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "   PROVEEDORES" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA" << endl;
      cout << "2 - BAJA" << endl;
      cout << "3 - LISTAR" << endl;
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
          Proveedor aux = Cargar();
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


