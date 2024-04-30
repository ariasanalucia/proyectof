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
    void menuPrincipal();
    Producto Cargar();
    void Mostrar (Producto producto);
    void bajaPoducto(Producto producto);
 };
