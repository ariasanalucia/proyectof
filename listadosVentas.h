#pragma once
#include "funcionesGlobales.h"
#include "venta.h"
#include "ventaArchivo.h"
#include "ventaManager.h"

 class listadosVentas
 {
   private:
    void MostrarPorFechaDeCompra();
    void MostrarPorIdDeEmpleado();

   public:
    void menuListados();

 };
