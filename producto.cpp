#include <iostream>
using namespace std;
#include "producto.h"
#include "funcionesGlobales.h"

//CONSTRUCTOR CON PARAMETROS
 Producto::Producto(int id, const char *nombre, const char *categoria, int proveedor)
 {
   _id = id;
   strcpy(_nombre,nombre);
   strcpy(_categoria,categoria);
   _proveedor = proveedor;
 }

//CONSTRUCTOR SIN PARAMETROS
 Producto::Producto()
 {
   _id = 0;
   strcpy(_nombre, "VACIO");
   strcpy(_categoria, "VACIO");
   _proveedor = 0;
 }

//SETS
 void Producto::setId(int id)
 {
   _id = id;
 }

 void Producto::setNombre(const char *nombre)
 {
   strcpy(_nombre, nombre);
 }

 void Producto::setCategoria(const char *categoria)
 {
   strcpy(_categoria, categoria);
 }

 void Producto::setProveedor(int proveedor)
 {
   _proveedor = proveedor;
 }

 //GETS
 int Producto::getId()
 {
   return _id;
 }

// const char Producto::*getNombre()
// {
//   return _nombre;
// }
//
// const char Producto::*getCategoria()
// {
//   return _categoria;
// }
 int Producto::getProveedor()
 {
   return _proveedor;
 }
