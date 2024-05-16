#pragma once
#include "proveedorArchivo.h"
#include "proveedor.h"

class proveedorManager
{
    private:
        ProveedorArchivo _archivo = ProveedorArchivo(“proveedores.dat)
    public:
        void menuProveedor
        proveedor Cargar();
        void Mostrar (proveedor proveedores);
        void mostrarPorId();
        void bajaPoducto();
};
