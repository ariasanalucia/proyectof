#pragma once
#include "ventaArchivo.h"
#include "venta.h"

 class VentaManager
 {
   private:
    VentaArchivo _archiVenta = VentaArchivo("venta.dat");
    void mostrarTodos();
    void modificar();
    void reiniciarVentasPorMes();
    Venta Cargar();
    void Mostrar (Venta venta);
    void baja();

   public:
    void menuVentas();
    void MostrarPorFechaDeCompra();
    void MostrarPorIdDeEmpleado();
 };
