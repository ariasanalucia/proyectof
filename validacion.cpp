#include <iostream>
using namespace std;
#include <cstring>
#include "validacion.h"
#include <ctime>

void validacionProducto::validarProveedor(int &proveedor){
    while((proveedor != 1 && proveedor != 2) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"ingrese correctamente el proveedor siendo 1 o 2:";
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
        cout<<"ingrese un año mayor al actual: ";
        cin>>a;
        vencimiento.setAnio(a);
    }
    while((_mes >= vencimiento.getMes() && _anio == vencimiento.getAnio()) || (vencimiento.getMes() < 0 || vencimiento.getMes() > 12) && cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"ingrese un mes mayor al actual: ";
        cin>>m;
        vencimiento.setMes(m);
    }
    while(_dia >= vencimiento.getDia() && _mes == vencimiento.getMes() && _anio == vencimiento.getAnio() || (vencimiento.getDia() < 0 || vencimiento.getDia() >31 && cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"ingrese un dia mayor al actual:";
        cin>>d;
        vencimiento.setDia(d);
    }
}

void validacionProducto::valdiarMiligramo(float &miligramo){
    while((miligramo < 0) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"ingrese correctamente los miligramos:";
        cin>>miligramo;
    }
}

void validacionProducto::validarPrecio(float &precio){
    while((precio< 0) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"ingrese correctamente el precio:";
        cin>>precio;
    }
}

void validacionTelefono::validarTelefono(int &telefono){
    while((telefono < 1100000000) || (cin.fail())){
        cin.clear();
        cin.ignore();
        cout<<"ingrese correctamente el telefono:";
        cin>>telefono;
    }
}


void validacionEmpleado::validarDni(int &dni){
    while(dni < 0 || cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"ingrese correctamente el dni:";
        cin>>dni;
    }
}


void validacionVenta::validarId(int &id){
    while(dni < 0 || cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"ingrese correctamente el dni:";
        cin>>dni;
    }
}
