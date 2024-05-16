#include <iostream>
using namespace std;
#include "empleadoArchivo.h"
#include "empleado.h"

EmpleadoArchivo::EmpleadoArchivo(const char *nombre)
 {
   strcpy(_nombre,nombre);
 }

 bool EmpleadoArchivo::guardarArchivo(Empleado empleado)
 {
   FILE *p = fopen(_nombre, "ab");
   if (p==nullptr)
   {
     return false;
   }

   bool escribio = fwrite(&empleado, sizeof(empleado), 1,p);
   fclose(p);

   return escribio;
 }

 int EmpleadoArchivo::contarRegistros()
 {
   Empleado empleado;
   FILE *p = fopen(_nombre, "rb");
   if (p==nullptr)
   {
     return false;
   }
   int contador = 0;
   while (fread (&empleado, sizeof(Empleado), 1,p)==1)
   {
     contador++;
   }
   fclose(p);
   return contador;
 }

 Empleado EmpleadoArchivo::leer(int numero)
 {
   FILE *p = fopen(_nombre, "rb");
   if (p==nullptr)
   {
     return Empleado();
   }
   Empleado aux;
   fseek(p,numero*sizeof(Empleado), 0);
   fread(&aux, sizeof(Empleado), 1,p);
   fclose(p);
   return aux;
 }

 int EmpleadoArchivo::buscar(int dni) //Retorna DNI si existe, sino -1
 {
   int cantidad = contarRegistros();
   for (int i=0; i<cantidad; i++)
   {
     Empleado aux = leer(i);
     if (dni == aux.getDni())
     {
       return i;
     }
   }
   return -1;
 }

 bool EmpleadoArchivo::modificarEmpleado(Empleado empleado, int pos)
 {
   FILE *p = fopen(_nombre, "rb+");
   if (p==nullptr)
   {
     return false;
   }
   fseek(p,pos*sizeof(empleado), 0);
   bool escribio = fwrite(&empleado, sizeof(empleado), 1,p);
   fclose(p);
   return escribio;
 }

