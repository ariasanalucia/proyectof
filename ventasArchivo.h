#pragma once
#include "ventas.h"

 class ventasArchivo
 {
   private:
    char _nombre[30];

   public:
    ventasArchivo(const char *nombre);
    bool guardarArchivo(Ventas venta);
    int contarRegistros();
    Ventas leer(int numero);
    int buscar(int id);
    bool modificarProducto(Ventas venta, int pos);
 };
