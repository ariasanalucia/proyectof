#pragma once
#include "proveedorArchivo.h"
#include "proveedor.h"

class proveedorManager
{
    private:
        proveedorArchivo _archivo = proveedorArchivo("proveedores.dat");
    public:
        void menuProveedor();
        proveedor Cargar();
        void Mostrar (proveedor proveedores);
        void mostrarPorId();
        void bajaPoducto();
};
