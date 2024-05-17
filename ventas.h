#pragma once
#include "fecha.h"

 class Ventas
 {
   protected:
    int _numero;
    Fecha _fechaDeVenta;
    float _importe;
    int _idEmpleado;
    bool _estado;

   public:
    Ventas(int numero, int idEmpleado, Fecha fechaDeVenta, float importe);
    Ventas();
    //SETS
    void setNumero(int numero);
    void setIdEmpleado(int idEmpleado);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setEstado(bool estado);
    void setImporte(float importe);
    //GETS
    int getNumero();
    int getIdEmpleado();
    Fecha getFechaDeVenta();
    bool getEstado();
    float getImporte();
 };

