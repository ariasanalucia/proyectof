#include <iostream>
using namespace std;
#include "proveedor.h"
#include "funcionesGlobales.h"
#include <cstring>

//CONSTRUCTORES
Proveedor::Proveedor(int telefono, int idProveedor, const char *nombre){
  _telefono=telefono;
  _idProveedor=idProveedor;
}
Proveedor::Proveedor(){
  _telefono=0;
  _idProveedor=0;
  _estado=false;
}

//SET
void Proveedor::setTelefono(int telefonoNuevo){_telefono = telefonoNuevo;}
void Proveedor::setId(int idNuevo){_idProveedor = idNuevo;}
//void Proveedor::setNombre(const char *nombre){strcpy(_nombreProveedor, nombre);}
void Proveedor::setEstado(bool estadoNuevo){_estado = estadoNuevo;}

//GET
int Proveedor::getTelefono(){return _telefono;}
int Proveedor::getId(){return _idProveedor;}
char Proveedor::getNombre(){return _nombreProveedor;}
bool Proveedor::getEstado(){return _estado;}
