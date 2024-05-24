#include <iostream>
using namespace std;
#include "ventaArchivo.h"
#include "venta.h"

VentaArchivo::VentaArchivo(const char *nombre)
 {
   strcpy(_nombre,nombre);
 }

 bool VentaArchivo::guardarArchivo(Venta reg)
 {
   FILE *p = fopen(_nombre, "ab");
   if (p==nullptr)
   {
     return false;
   }

   bool escribio = fwrite(&reg, sizeof(Venta), 1,p);

   // Guardar los vectores idProductos y cantidades
    int size = reg.getIdProductos().size(); // Obtener el tamaño del vector idProductos
    fwrite(&size, sizeof(int), 1, p); // Guardar el tamaño del vector
    fwrite(reg.getIdProductos().data(), sizeof(int), size, p); // Guardar los ID de productos

    size = reg.getCantidades().size(); // Obtener el tamaño del vector cantidades
    fwrite(&size, sizeof(int), 1, p); // Guardar el tamaño del vector
    fwrite(reg.getCantidades().data(), sizeof(int), size, p); // Guardar las cantidades

   fclose(p);

   return escribio;
 }

 int VentaArchivo::contarRegistros()
 {
   Venta reg;
   FILE *p = fopen(_nombre, "rb");
   if (p==nullptr)
   {
     return false;
   }
   int contador = 0;
   while (fread (&reg, sizeof(Venta), 1,p)==1)
   {
     contador++;
   }
   fclose(p);
   return contador;
 }

 Venta VentaArchivo::leer(int numero)
{
    FILE *p = fopen(_nombre, "rb");
    if (p == nullptr)
    {
      return Venta(); // Devuelve una venta vacía si no se puede abrir el archivo
    }

    // Mover el puntero al registro específico en el archivo
    fseek(p, numero * sizeof(Venta), SEEK_SET);

    // Leer los datos de la venta principal
    Venta reg;
    fread(&reg, sizeof(Venta), 1, p);

    // Leer los tamaños de los vectores idProductos y cantidades
    int size_idProductos, size_cantidades;
    fread(&size_idProductos, sizeof(int), 1, p);
    fread(&size_cantidades, sizeof(int), 1, p);

    // Leer los datos de los vectores idProductos y cantidades
    vector<int> idProductos(size_idProductos); // Crear un vector temporal para ajustar su tamaño
    fread(idProductos.data(), sizeof(int), size_idProductos, p); // Leer los ID de productos
    reg.setIdProductos(idProductos); // Asignar el vector de ID de productos a la venta

    vector<int> cantidades(size_cantidades); // Crear un vector temporal para ajustar su tamaño
    fread(cantidades.data(), sizeof(int), size_cantidades, p); // Leer las cantidades
    reg.setCantidades(cantidades); // Asignar el vector de cantidades a la venta

    fclose(p);

    return reg;
}

 int VentaArchivo::buscar(int id)
 {
   int cantidad = contarRegistros();
   for (int i=0; i<cantidad; i++)
   {
     Venta aux = leer(i);
     if (id == aux.getNumero())
     {
       return i;
     }
   }
   return -1;
 }

 bool VentaArchivo::modificar(Venta reg, int pos)
 {
   FILE *p = fopen(_nombre, "rb+");
   if (p==nullptr)
   {
     return false;
   }
   fseek(p,pos*sizeof(Venta), 0);
   bool escribio = fwrite(&reg, sizeof(Venta), 1,p);
   fclose(p);
   return escribio;
 }

