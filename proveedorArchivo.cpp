#include <iostream>
using namespace std;
#include "proveedorArchivo.h"

 bool ProveedorArchivo::guardarArchivo(Proveedor reg)
 {
   FILE *p = fopen(_nombre, "ab");
   if (p==nullptr)
   {
     return false;
   }

   bool escribio = fwrite(&reg, sizeof(Proveedor), 1,p);
   fclose(p);

   return escribio;
 }

 int ProveedorArchivo::contarRegistros()
 {
   Proveedor reg;
   FILE *p = fopen(_nombre, "rb");
   if (p==nullptr)
   {
     return false;
   }
   int contador = 0;
   while (fread (&reg, sizeof(Proveedor), 1,p)==1)
   {
     contador++;
   }
   fclose(p);
   return contador;
 }

 Proveedor ProveedorArchivo::leer(int numero)
 {
   FILE *p = fopen(_nombre, "rb");
   if (p==nullptr)
   {
     return Proveedor();
   }
   Proveedor reg;
   fseek(p,numero*sizeof(Proveedor), 0);
   fread(&reg, sizeof(Proveedor), 1,p);
   fclose(p);
   return reg;
 }

 int ProveedorArchivo::buscar(int id) //Retorna ID si existe, sino -1
 {
   int cantidad = contarRegistros();
   for (int i=0; i<cantidad; i++)
   {
     Proveedor reg = leer(i);
     if (id == reg.getId())
     {
       return i;
     }
   }
   return -1;
 }

 bool ProveedorArchivo::modificar(Proveedor reg, int pos)
 {
   FILE *p = fopen(_nombre, "rb+");
   if (p==nullptr)
   {
     return false;
   }
   fseek(p,pos*sizeof(Proveedor), 0);
   bool escribio = fwrite(&reg, sizeof(Proveedor), 1,p);
   fclose(p);
   return escribio;
 }

