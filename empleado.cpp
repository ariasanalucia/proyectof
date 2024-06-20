#include <iostream>
using namespace std;
#include "empleado.h"
#include "funcionesGlobales.h"

//Constructor con param
Empleado::Empleado(int id, int dni, const char *nombre, const char *apellido, int telefono, bool estado){
    _id = id;
    _dni = dni;
    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    _telefono = telefono;
    _estado = true;
   //Nro de empleado?
}

Empleado::Empleado(){
    _id = 0;
    _dni = 0;
    strcpy(_nombre, "S/N");
    strcpy(_apellido, "S/A");
    _telefono = 0;
    _estado = true;
}

//SETS
void Empleado::setId(int id){_id = id;}
void Empleado::setDni(int dni){_dni = dni;}
void Empleado::setNombre(const char *nombre){strcpy(_nombre, nombre);}
void Empleado::setApellido(const char *apellido){strcpy(_apellido, apellido);}
void Empleado::setTelefono(int telefono){_telefono = telefono;}
void Empleado::setEstado(bool estado){_estado = estado;}

//GETS
int Empleado::getId(){return _id;}
int Empleado::getDni(){return _dni;}
const char* Empleado::getNombre(){return _nombre;}
const char* Empleado::getApellido(){return _apellido;}
int Empleado::getTelefono(){return _telefono;}
bool Empleado::getEstado(){return _estado;}
