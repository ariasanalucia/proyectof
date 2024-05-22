#include <iostream>
using namespace std;
#include "ProveedorManager.h"
#include "funcionesGlobales.h"

void ProveedorManager::menuProveedor()
 {
   int opcion;
    while(true)
    {
      clear();
      cout << "PROVEEDOR" << endl;
      cout << "----------------" << endl;
      cout << "1 - ALTA PROVEEDOR" << endl;
      cout << "2 - BAJA PROVEEDOR" << endl;
      cout << "4 - MODIFICAR REGISTRO DE PROVEEDOR" << endl;
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
//          Product aux = Cargar();
//          _archivo.guardarArchivo(aux);
        }
        break;
       case 2:
        {
//          mostrarTodos();
        }
        break;
       case 3:
        {
//          bajaPoducto();
        }
        break;
       case 4:
        {
//         modificarRegistro();
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


