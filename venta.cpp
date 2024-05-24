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
   // Inicializa los vectores con los datos del primer producto
   _idProductos.push_back(idProducto);
   _cantidades.push_back(cantidad);
 }
 Venta::Venta()
 {
   _numero=0;
   _idEmpleado=0;
   _fechaDeVenta=Fecha();
   _horario = Hora();
   //No es necesario inicializar los idProducto y cantidad ya que los vectores se inicializan con sus propios constructores.
 }
//SETS
void Venta::setNumero(int numero){_numero=numero;}
void Venta::setIdEmpleado(int idEmpleado){_idEmpleado=idEmpleado;}
void Venta::setFechaDeVenta(Fecha fechaDeVenta){_fechaDeVenta=fechaDeVenta;}
void Venta::setHora(Hora horario){_horario = horario;}
void Venta::setEstado(bool estado){_estado=estado;}

//GETS
int Venta::getNumero(){return _numero;}
int Venta::getIdEmpleado(){return _idEmpleado;}
Fecha Venta::getFechaDeVenta(){return _fechaDeVenta;}
Hora Venta::getHorario(){return _horario;}
bool Venta::getEstado(){return _estado;}
