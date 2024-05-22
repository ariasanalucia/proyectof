#pragma once
#include "ventaArchivo.h"
#include "venta.h"

 class VentaManager
 {
   private:
    VentaArchivo _archivo = VentaArchivo("venta.dat");
    void mostrarTodos();
    void modificar();

   public:
    void menuVentas();
    Venta Cargar();
    void Mostrar (Venta venta);
    void baja();
    void MostrarPorNumCompra();
 };
