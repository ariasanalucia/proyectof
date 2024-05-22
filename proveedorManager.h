#pragma once
#include "ProveedorArchivo.h"
#include "Proveedor.h"

class ProveedorManager
{
    private:
        ProveedorArchivo _archivo = ProveedorArchivo("proveedores.dat");
    public:
        void menuProveedor();
        Proveedor Cargar();
        void Mostrar (Proveedor proveedores);
        void mostrarPorId();
        void bajaPoducto();
};
