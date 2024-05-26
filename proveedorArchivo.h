#pragma once
#include <cstring>
#include "proveedor.h"

class ProveedorArchivo
{
   private:
    char _nombre[30];
   public:
    ProveedorArchivo(const char* nombre)
    {
      strcpy(_nombre, nombre);
    }
    Proveedor leer(int numero);
    bool guardarArchivo(Proveedor Proveedor);
    int contarRegistros();
    int buscar(int id);
    bool modificar(Proveedor provedor, int pos);
};
