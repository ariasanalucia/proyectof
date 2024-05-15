#include <iostream>
using namespace std;
#include "fecha.h"

Empleado::Empleado(int d, const char *n, const char *a, Fecha f, const char *t){
    dni=d;
    strcpy(nombre,n);
    strcpy(apellido,a);
    fechaNacimiento=f;
    strcpy(telefono,t);
}

void Empleado::Cargar(){
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Cargar();
    cout<<"TELEFONO: ";
    cargarCadena(telefono,14);
}

void Empleado::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
}
