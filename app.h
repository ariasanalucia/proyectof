#pragma once
#include "productoManager.h"
#include "empleadoManager.h"
#include "ventaManager.h"
#include "proveedorManager.h"
#include "informeRecaudacion.h"

 class App
 {
   private:
    ProductoManager subMenuP;
    EmpleadoManager subMenuE;
    VentaManager subMenuV;
    ProveedorManager subMenuProveedor;
    InformeRecaudacion subMenuInforme;

   public:
    void MenuPrincipal();
 };
