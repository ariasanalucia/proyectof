#pragma once
#include "producto.h"
#include "productoManager.h"
#include "productoArchivo.h"
#include "funcionesGlobales.h"

 class listadosProductos
 {
   private:
    void listarPorPrecio();
//    void listarPorTipo();
    void listarPorCantStock();

   public:
    void menuListados();

 };
