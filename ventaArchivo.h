#pragma once
#include <cstring>
#include "venta.h"

 class VentaArchivo
 {
   private:
    char _nombre[30];

   public:
    VentaArchivo(const char *nombre)
    {
      strcpy(_nombre,nombre);
    }
    bool guardarArchivo(Venta venta);
    int contarRegistros();
    Venta leer(int numero);
    int buscar(int id);
    bool modificar(Venta venta, int pos);
 };
