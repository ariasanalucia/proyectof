#pragma once
#include "ventasArchivo.h"

 class VentasManager
 {
   private:
    ventasArchivo _archivo = ventasArchivo("ventas.dat");
    void mostrarTodos();
    void modificarRegistro();
   public:
    void menuVentas();
    Ventas Cargar();
    void Mostrar (Ventas venta);
    void bajaVenta();
    void MostrarPorNumCompra();
 };
