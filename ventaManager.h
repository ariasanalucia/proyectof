#pragma once
#include "listadosVentas.h"
#include "ventaArchivo.h"
#include "productoArchivo.h"
#include "venta.h"
#include "producto.h"
#include "productoManager.h"

 class VentaManager
 {
   private:
    VentaArchivo _archiVenta = VentaArchivo("venta.dat");
    void modificar();
    Venta Cargar();
    void baja();
    bool restarStockDeProducto(int idProducto, int cantidad);
    ProductoManager obj;
    void validarDroga();

   public:
    void Mostrar (Venta venta);
    void menuVentas();
    void MostrarPorFechaDeCompra();
    void MostrarPorIdDeEmpleado();
 };
