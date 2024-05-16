#include <iostream>
using namespace std;
#include "producto.h"
#include "funcionesGlobales.h"
#include "fecha.h"

//CONSTRUCTOR CON PARAMETROS
 Producto::Producto(int id, const char *nombre, const char *categoria, int proveedor, Fecha vencimiento, bool estado, const char *presentacion, int cantidad, float importe)
 {
   _id = id;
   strcpy(_nombre,nombre);
   strcpy(_categoria,categoria);
   _proveedor = proveedor;
   _vencimiento = Fecha();
   _estado = true;
   strcpy(_presentacion, presentacion);
   _cantidad = cantidad;
   _importe = importe;
 }

//CONSTRUCTOR SIN PARAMETROS
 Producto::Producto()
 {
   _id = 0;
   strcpy(_nombre, "S/N");
   strcpy(_categoria, "S/C");
   _proveedor = 0;
   _vencimiento = Fecha();
   _estado = true;
   strcpy(_presentacion, "S/P");
   _cantidad = 0;
   _importe = 0;
 }

//SETS
 void Producto::setId(int id){_id = id;}
 void Producto::setNombre(const char *nombre){strcpy(_nombre, nombre);}
 void Producto::setCategoria(const char *categoria){strcpy(_categoria, categoria);}
 void Producto::setProveedor(int proveedor){_proveedor = proveedor;}
 void Producto::setVencimiento(Fecha vencimiento){_vencimiento = vencimiento;}
 void Producto::setStock(int stock){_stock = stock;}
 void Producto::setEstado(bool estado){_estado = estado;}
 void Producto::setPresentacion(const char *presentacion){strcpy(_presentacion,presentacion);}
 void Producto::setCantidad(int cantidad){_cantidad = cantidad;}
 void Producto::setImporte(float importe){_importe = importe;}
 //GETS
 int Producto::getId(){return _id;}
 int Producto::getProveedor(){return _proveedor;}
 int Producto::getStock(){return _stock;}
 bool Producto::getEstado(){return _estado;}
 int Producto::getCantidad(){return _cantidad;}
 float Producto::getImporte(){return _importe;}
