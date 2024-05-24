#pragma once
#include "fecha.h"
#include "hora.h"

 class Venta
 {
   private:
    int _numero;
    Fecha _fechaDeVenta;
    int _idEmpleado;
    int _idProducto;
    int _cantidad;
    Hora _horario;
    bool _estado;

   public:
    Venta(int numero, int idEmpleado, Fecha fechaDeVenta,Hora horario, int idProducuto, int cantidad);
    Venta();
    //SETS
    void setNumero(int numero);
    void setIdEmpleado(int idEmpleado);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setHora(Hora horario);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setEstado(bool estado);
    //GETS
    int getNumero();
    int getIdEmpleado();
    Fecha getFechaDeVenta();
    Hora getHorario();
    int getIdProducto();
    int getCantidad();
    bool getEstado();
 };

