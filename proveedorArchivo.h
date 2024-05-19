#pragma once
#include <cstring>
#include "proveedor.h"

class proveedorArchivo
{
    private:
        char _nombre[30];
    public:
        proveedorArchivo(const char* nombre)
        {
          strcpy(_nombre, nombre);
        }
        bool guardarArchivo(proveedor proveedor);
        int contarRegistros();
        int buscar(int id);
        bool modificarProveedor(proveedor provedor, int pos);
};
