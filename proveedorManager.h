#pragma once
#include "proveedorArchivo.h"
#include "proveedor.h"

class ProveedorManager
{
   private:
    ProveedorArchivo _archivo = ProveedorArchivo("proveedores.dat");
    Proveedor Cargar();
    void Mostrar (Proveedor proveedores);
    void mostrarPorId();
    void mostrarTodos();
    void baja();
    void modificar();
    void listar();
   public:
    void menuProveedor();
};
