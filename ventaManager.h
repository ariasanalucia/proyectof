#pragma once
#include "ventaArchivo.h"
#include "productoArchivo.h"
#include "venta.h"
#include "producto.h"

 class VentaManager
 {
   private:
    VentaArchivo _archiVenta = VentaArchivo("venta.dat");
    void mostrarTodos();
    void modificar();
    Venta Cargar();
    void Mostrar (Venta venta);
    void baja();

   public:
    void menuVentas();
    void MostrarPorFechaDeCompra();
    void MostrarPorIdDeEmpleado();
 };
