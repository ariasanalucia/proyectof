#pragma once
#include <cstring>
#include "Proveedor.h"

class ProveedorArchivo
{
    private:
        char _nombre[30];
    public:
        ProveedorArchivo(const char* nombre)
        {
          strcpy(_nombre, nombre);
        }
        bool guardarArchivo(Proveedor Proveedor);
        int contarRegistros();
        int buscar(int id);
        bool modificarProveedor(Proveedor provedor, int pos);
};
