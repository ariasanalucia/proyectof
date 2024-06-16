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

