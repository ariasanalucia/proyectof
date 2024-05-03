#pragma once
using namespace std;
#include "productoArchivo.h"

 class ProductoManager
 {
   private:
    ProductoArchivo _archivo = ProductoArchivo("producto.dat");
    void mostrarTodos();
    void mostrarPorId();

   public:
    void menuProducto();
    Producto Cargar();
    void Mostrar (Producto producto);
    void bajaPoducto(Producto producto);
 };
