#pragma once
#include "fecha.h"

 class Venta
 {
   private:
    int _numero;
    Fecha _fechaDeVenta;
    int _idEmpleado;
    int _idProducto;
    int _cantidad;
//    Hora _horario;
    bool _estado;

   public:
    Venta(int numero, int idEmpleado, Fecha fechaDeVenta, int idProducuto, int cantidad);
    Venta();
    //SETS
    void setNumero(int numero);
    void setIdEmpleado(int idEmpleado);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setEstado(bool estado);
    //GETS
    int getNumero();
    int getIdEmpleado();
    Fecha getFechaDeVenta();
    int getIdProducto();
    int getCantidad();
    bool getEstado();
 };

