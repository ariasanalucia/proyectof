#include <iostream>
using namespace std;
#include <cstring>
#include "proveedor.h"

//CONSTRUCTORES
Proveedor::Proveedor(int telefono, int idProveedor, const char *nombre){
  _telefono=telefono;
  _idProveedor=idProveedor;
  strcpy(_nombre,nombre);
}
Proveedor::Proveedor(){
  _telefono=0;
  _idProveedor=0;
  strcpy(_nombre,"vacio");
}

//SET
void Proveedor::setTelefono(int telefonoNuevo){_telefono = telefonoNuevo;}
void Proveedor::setId(int idNuevo){_idProveedor = idNuevo;}
void Proveedor::setNombre(const char *nombre){strcpy(_nombre,nombre);}
void Proveedor::setEstado(bool estadoNuevo){_estado = estadoNuevo;}

//GET
int Proveedor::getTelefono(){return _telefono;}
int Proveedor::getId(){return _idProveedor;}
const char *Proveedor::getNombre(){return _nombre;}
bool Proveedor::getEstado(){return _estado;}
