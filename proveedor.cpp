#include <iostream>
using namespace std;
#include "proveedor.h"
#include "funcionesGlobales.h"

//CONSTRUCTORES
Producto::Producto(int telefono, int idProveedor, bool estado){
  _telefono=telefono;
  _idProveedor=idProveedor;
  _estado=estado;
}
Producto::Producto(){
  _telefono=0;
  _idProveedor=0;
  _estado=true;
}

//SET
void Producto::setTelefono(int telefonoNuevo){_telefono = telefonoNuevo;}
void Producto::setId(int idNuevo){_idProveedor = idNuevo;}
//void setNombre(const char *nombre){strcpy(_nombreProveedor, nombre);}
void Producto::setEstado(bool estadoNuevo){_estado = estadoNuevo;}

//GET
int Producto::getTelefono(){return _telefono;}
int Producto::getId(){return _idProveedor;}
char Producto::getNombre(){return _nombreProveedor;}
bool Producto::getEstado(){return _estado;}
