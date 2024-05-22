#pragma once
#include "productoManager.h"
#include "empleadoManager.h"
#include "ventaManager.h"
#include "proveedorManager.h"

 class App
 {
   private:
    ProductoManager subMenuP;
    EmpleadoManager subMenuE;
    VentaManager subMenuV;
    ProveedorManager subMenuProveedor;


   public:
    void MenuPrincipal();
 };
