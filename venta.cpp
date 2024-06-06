#include <iostream>
using namespace std;
#include "venta.h"
#include "funcionesGlobales.h"

 Venta::Venta(int numero, int idEmpleado, Fecha fecha,Hora horario, int idProducto, int cantidad, bool estado, float importe)
 {
   _numero = numero;
   _idEmpleado = idEmpleado;
   _fecha = fecha;
   _horario = horario;
   for (int i=0; i<10; i++)
   {
     _idProducto[i] = idProducto;
     _cantidad[i] = cantidad;
   }
   _estado = true;
   _importe = importe;
 }
 Venta::Venta()
 {
   _numero = 0;
   _idEmpleado = 0;
   _fecha= Fecha();
   _horario = Hora();
   for (int i=0; i<10; i++)
   {
     _idProducto[i] = 0;
     _cantidad[i] = 0;
   }
   _estado = true;
   _importe = 0;
 }
//SETS
void Venta::setNumero(int numero){_numero=numero;}
void Venta::setIdEmpleado(int idEmpleado){_idEmpleado=idEmpleado;}
void Venta::setFecha(Fecha fecha){_fecha=fecha;}
void Venta::setHora(Hora horario){_horario = horario;}
void Venta::setIdProducto(int idProducto, int pos)
 {
   for (int i=0; i<10; i++)
   {
     if (pos == i)
     {
       _idProducto[i] = idProducto;
     }
   }
 }

void Venta::setCantidad(int cantidad, int pos)
 {
   for (int i=0; i<10; i++)
   {
     if (pos == i)
     {
       _cantidad[i] = cantidad;
     }
   }
 }
void Venta::setEstado(bool estado){_estado=estado;}
void Venta::setImporte(float importe){_importe=importe;}

//GETS
int Venta::getNumero(){return _numero;}
int Venta::getIdEmpleado(){return _idEmpleado;}
Fecha Venta::getFecha(){return _fecha;}
Hora Venta::getHora(){return _horario;}
int Venta::getIdProducto(int pos)
 {
   for (int i=0; i<10; i++)
   {
     if (pos == i)
     {
       return _idProducto[i];
     }
   }
  return -1;
 }
int Venta::getCantidad(int pos)
 {
   for (int i=0; i<10; i++)
   {
     if (pos == i)
     {
       return _cantidad[i];
     }
   }
  return -1;
 }
bool Venta::getEstado(){return _estado;}
float Venta::getImporte(){return _importe;}
