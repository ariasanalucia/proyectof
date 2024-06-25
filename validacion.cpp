#include <iostream>
using namespace std;
#include <cstring>
#include <ctime>
#include "empleadoArchivo.h"
#include "ventaArchivo.h"
#include "validacion.h"

void validacionProducto::validarProveedor(int &proveedor){
    while((proveedor != 1 && proveedor != 2) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese correctamente el proveedor siendo 1 o 2:";
        cin>>proveedor;
    }
}


void validacionProducto::validarVencimiento(Fecha &vencimiento){
    int a,m,d;
    Fecha fecha_valida = vencimiento;
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    int _dia = f->tm_mday;
    int _mes = f->tm_mon+1;
    int _anio = f->tm_year+1900;
    while(_anio >= vencimiento.getAnio() && cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese un año mayor al actual: ";
        cin>>a;
        vencimiento.setAnio(a);
    }
    while((_mes >= vencimiento.getMes() && _anio == vencimiento.getAnio()) || (vencimiento.getMes() < 0 || vencimiento.getMes() > 12) && cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese un mes mayor al actual: ";
        cin>>m;
        vencimiento.setMes(m);
    }
    while(_dia >= vencimiento.getDia() && _mes == vencimiento.getMes() && _anio == vencimiento.getAnio() || (vencimiento.getDia() < 0 || vencimiento.getDia() >31 && cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese un dia mayor al actual:";
        cin>>d;
        vencimiento.setDia(d);
    }
}

void validacionProducto::valdiarMiligramo(float &miligramo){
    while((miligramo < 0) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese correctamente los miligramos:";
        cin>>miligramo;
    }
}

void validacionProducto::validarPrecio(float &precio){
    while((precio< 0) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese correctamente el precio:";
        cin>>precio;
    }
}

void validacionTelefono::validarTelefono(int &telefono){
    while((telefono < 1100000000) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese correctamente el telefono:";
        cin>>telefono;
    }
}


void validacionEmpleado::validarDni(int &dni){
    while(dni < 0 || cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese correctamente el dni:";
        cin>>dni;
    }
}


void validacionVenta::validarId(int &id){
    EmpleadoArchivo archiEmpleado("empleados.dat");
    int tope = archiEmpleado.contarRegistros();
    while((id < 0 || id > tope) || cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese correctamente el id, la cantidad de empados es:"<<archiEmpleado.contarRegistros()<<" haga el ingreso:";
        cin>>id;
    }
}

void validacionVenta::validarNumero(int &numero){
    VentaArchivo archiVenta("ventas.dat");
    int tope = archiVenta.contarRegistros();
    while((numero < 0 || numero > tope) || cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Ingrese correctamente el numero, la cantidad de empados es:"<<archiVenta.contarRegistros()<<" haga el ingreso:";
        cin>>numero;
    }
}
