#pragma once
using namespace std;
#include "empleado.h"
#include <cstring>

 class EmpleadoArchivo
 {
   private:
    char _nombre[30];

   public:
    EmpleadoArchivo(const char *nombre);
    bool guardarArchivo(Empleado empleado);
    int contarRegistros();
    Empleado leer(int numero);
    int buscar(int dni);
    bool modificarEmpleado(Empleado empleado, int pos);
 };
