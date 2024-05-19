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
    proveedorManager subMenuProveedor;


   public:
    void MenuPrincipal();
 };
