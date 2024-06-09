#pragma once
#include "ventaArchivo.h"
#include "productoArchivo.h"
#include "venta.h"
#include "producto.h"
#include "productoManager.h"

 class VentaManager
 {
   private:
    VentaArchivo _archiVenta = VentaArchivo("venta.dat");
    void mostrarTodos();
    void modificar();
    Venta Cargar();
    void Mostrar (Venta venta);
    void baja();
    bool restarStockDeProducto(int idProducto, int cantidad);
    ProductoManager obj;
    void validarDroga();

   public:
    void menuVentas();
    void MostrarPorFechaDeCompra();
    void MostrarPorIdDeEmpleado();
 };
