#pragma once
#include "fecha.h"

 class Venta
 {
   protected:
    int _numero;
    Fecha _fechaDeVenta;
    float _importe;
    int _idEmpleado;
    bool _estado;

   public:
    Venta(int numero, int idEmpleado, Fecha fechaDeVenta, float importe);
    Venta();
    //SETS
    void setNumero(int numero);
    void setIdEmpleado(int idEmpleado);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setImporte(float importe);
    void setEstado(bool estado);
    //GETS
    int getNumero();
    int getIdEmpleado();
    Fecha getFechaDeVenta();
    float getImporte();
    bool getEstado();
 };

