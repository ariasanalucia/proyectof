#include <iostream>
using namespace std;
#include "venta.h"
#include "funcionesGlobales.h"

 Venta::Venta(int numero, int idEmpleado, Fecha fechaDeVenta, float importe)
 {
   _numero=numero;
   _idEmpleado=idEmpleado;
   _fechaDeVenta=fechaDeVenta;
   _importe=importe;
 }
 Venta::Venta()
 {
   _numero=0;
   _idEmpleado=0;
   _fechaDeVenta=Fecha();
   _importe=0;
 }
//SETS
void Venta::setNumero(int numero){_numero=numero;}
void Venta::setIdEmpleado(int idEmpleado){_idEmpleado=idEmpleado;}
void Venta::setFechaDeVenta(Fecha fechaDeVenta){_fechaDeVenta=fechaDeVenta;}
void Venta::setEstado(bool estado){_estado=estado;}
void Venta::setImporte(float importe){_importe=importe;}
//GETS
int Venta::getNumero(){return _numero;}
int Venta::getIdEmpleado(){return _idEmpleado;}
Fecha Venta::getFechaDeVenta(){return _fechaDeVenta;}
bool Venta::getEstado(){return _estado;}
float Venta::getImporte(){return _importe;}
