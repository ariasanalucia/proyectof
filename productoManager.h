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
    void validar_proveedor(int *Proveedor);
    bool es_proveedor(int Proveedor);
    void validarDroga();

//    bool validarFechaVencimiento(int id);
//    void esFechaValida();
   public:
    void menuProducto();
    Producto Cargar();
    void mostrarPorId();
    void Mostrar(Producto producto);
    void baja();
    void mostrarPorProveedor();
    void mostrarPorCategoria();
    bool mostrarPorDroga();
    void solicitarProducto();
    void mostrarPorPrecio();
 };
