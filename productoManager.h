#pragma once
using namespace std;
#include "productoArchivo.h"
#include "producto.h"

 class ProductoManager
 {
   private:
    ProductoArchivo _archivo = ProductoArchivo("producto.dat");
    void mostrarTodos();
    void modificar();
   public:
    void menuProducto();
    Producto Cargar();
    void Mostrar (Producto producto);
    void mostrarPorId();
    void baja();
    void mostrarPorProveedor();
    void mostrarPorCategoria();
    void mostrarPorDroga();
    void solicitarProducto();
 };
