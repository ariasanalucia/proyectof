#pragma once
using namespace std;
#include "empleadoArchivo.h"

 class EmpleadoManager
 {
   private:
    EmpleadoArchivo _archivo = EmpleadoArchivo("empleado.dat");
    void mostrarTodos();
    void modificarRegistro();
   public:
    void menuEmpleado();
    Empleado Cargar();
    void Mostrar (Empleado empleado);
    void mostrarPorDni();
    void bajaEmpleado();
 };
