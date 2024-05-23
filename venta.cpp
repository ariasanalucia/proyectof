#include <iostream>
using namespace std;
#include "venta.h"
#include "funcionesGlobales.h"

 Venta::Venta(int numero, int idEmpleado, Fecha fechaDeVenta, int idProducto, int cantidad)
 {
   _numero=numero;
   _idEmpleado=idEmpleado;
   _fechaDeVenta=fechaDeVenta;
   _idProducto = idProducto;
   _cantidad = cantidad;
 }
 Venta::Venta()
 {
   _numero=0;
   _idEmpleado=0;
   _fechaDeVenta=Fecha();
   _idProducto = 0;
   _cantidad = 0;
 }
//SETS
void Venta::setNumero(int numero){_numero=numero;}
void Venta::setIdEmpleado(int idEmpleado){_idEmpleado=idEmpleado;}
void Venta::setFechaDeVenta(Fecha fechaDeVenta){_fechaDeVenta=fechaDeVenta;}
void Venta::setEstado(bool estado){_estado=estado;}
void Venta::setIdProducto(int idProducto){_idProducto = idProducto;}
void Venta::setCantidad(int cantidad){_cantidad = cantidad;}
//GETS
int Venta::getNumero(){return _numero;}
int Venta::getIdEmpleado(){return _idEmpleado;}
Fecha Venta::getFechaDeVenta(){return _fechaDeVenta;}
int Venta::getIdProducto(){return _idProducto;}
int Venta::getCantidad(){return _cantidad;}
bool Venta::getEstado(){return _estado;}
