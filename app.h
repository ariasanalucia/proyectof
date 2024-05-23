#pragma once
#include "productoManager.h"
#include "empleadoManager.h"
#include "ventaManager.h"
#include "proveedorManager.h"
#include "informe.h"

 class App
 {
   private:
    ProductoManager subMenuP;
    EmpleadoManager subMenuE;
    VentaManager subMenuV;
    ProveedorManager subMenuProveedor;
    Informe subMenuInforme;

   public:
    void MenuPrincipal();
 };
