#pragma once
#include "productoManager.h"
#include "empleadoManager.h"

 class App
 {
   private:
    ProductoManager subMenuP;
    EmpleadoManager subMenuE;

   public:
    void MenuPrincipal();
 };
