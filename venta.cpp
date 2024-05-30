#include <iostream>
using namespace std;
#include "venta.h"
#include "funcionesGlobales.h"

 Venta::Venta(int numero, int idEmpleado, Fecha fechaDeVenta,Hora horario, int idProducto, int cantidad)
 {
   _numero=numero;
   _idEmpleado=idEmpleado;
   _fechaDeVenta=fechaDeVenta;
   _horario = horario;
 }
 Venta::Venta()
 {
   _numero=0;
   _idEmpleado=0;
   _fechaDeVenta=Fecha();
   _horario = Hora();

 }
//SETS
void Venta::setNumero(int numero){_numero=numero;}
void Venta::setIdEmpleado(int idEmpleado){_idEmpleado=idEmpleado;}
void Venta::setFechaDeVenta(Fecha fechaDeVenta){_fechaDeVenta=fechaDeVenta;}
 void Venta::setIdProducto(int idProducto, int pos)
 {
   for (int i=0; i<100; i++)
   {
     if (pos == i)
     {
       _idProducto[i] = idProducto;
     }
   }
 }

 void Venta::setCantidad(int cantidad, int pos)
 {
   for (int i=0; i<100; i++)
   {
     if (pos == i)
     {
       _cantidad[i] = cantidad;
     }
   }
 }
void Venta::setHora(Hora horario){_horario = horario;}
void Venta::setEstado(bool estado){_estado=estado;}

//GETS
int Venta::getNumero(){return _numero;}
int Venta::getIdEmpleado(){return _idEmpleado;}
Fecha Venta::getFechaDeVenta(){return _fechaDeVenta;}
Hora Venta::getHorario(){return _horario;}
int Venta::getIdProducto(int pos)
 {
   for (int i=0; i<100; i++)
   {
     if (pos == i)
     {
       return _idProducto[i];
     }
   }
 }
int Venta::getCantidad(int pos)
 {
   for (int i=0; i<100; i++)
   {
     if (pos == i)
     {
       return _cantidad[i];
     }
   }
 }
bool Venta::getEstado(){return _estado;}
