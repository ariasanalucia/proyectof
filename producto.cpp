#include <iostream>
using namespace std;
#include "producto.h"
#include "funcionesGlobales.h"
#include "fecha.h"

//CONSTRUCTOR CON PARAMETROS
 Producto::Producto(int id,const char *marca, const char *droga, float miligramos, const char *categoria, int Proveedor, Fecha vencimiento, bool estado, const char *presentacion, int cantidad, float precioUnitario)
 {
   _id = id;
   strcpy(_marca,marca);
   strcpy(_droga, droga);
   _miligramos = miligramos;
   strcpy(_categoria,categoria);
   _proveedor = Proveedor;
   _vencimiento = Fecha();
   _estado = true;
   strcpy(_presentacion, presentacion);
   _cantidad = cantidad;
   _precioUnitario = precioUnitario;
 }

//CONSTRUCTOR SIN PARAMETROS
 Producto::Producto()
 {
   _id = 0;
   strcpy(_marca,"VACIO");
   strcpy(_droga,"VACIO");
   _miligramos = 0;
   strcpy(_categoria, "VACIO");
   _proveedor = 0;
   _vencimiento = Fecha();
   _estado = true;
   strcpy(_presentacion, "VACIO");
   _cantidad = 0;
   _precioUnitario = 0;
 }

//SETS
 void Producto::setId(int id){_id = id;}
 void Producto::setMarca(const char *marca){strcpy(_marca,marca);}
 void Producto::setDroga(const char *droga){strcpy(_droga,droga);}
 void Producto::setMiligramos(float miligramos){_miligramos = miligramos;}
 void Producto::setCategoria(const char *categoria){strcpy(_categoria, categoria);}
 void Producto::setProveedor(int Proveedor){_proveedor = Proveedor;}
 void Producto::setVencimiento(Fecha vencimiento){_vencimiento = vencimiento;}
 void Producto::setStock(int stock){_stock = stock;}
 void Producto::setEstado(bool estado){_estado = estado;}
 void Producto::setPresentacion(const char *presentacion){strcpy(_presentacion,presentacion);}
 void Producto::setCantidad(int cantidad){_cantidad = cantidad;}
 void Producto::setPrecioUnitario(float precioUnitario){_precioUnitario = precioUnitario;}
 //GETS
 int Producto::getId(){return _id;}
 float Producto::getMiligramos(){return _miligramos;}
 int Producto::getProveedor(){return _proveedor;}
 int Producto::getStock(){return _stock;}
 bool Producto::getEstado(){return _estado;}
 int Producto::getCantidad(){return _cantidad;}
 float Producto::getPrecioUnitario(){return _precioUnitario;}
