#pragma once
using namespace std;
#include "fecha.h"
#include "hora.h"
#include <vector>

 class Venta
 {
   private:
    int _numero;
    Fecha _fechaDeVenta;
    int _idEmpleado;
    Hora _horario;
    int _idProducto[10] = {};
    int _cantidad[10] = {};
    bool _estado;

   public:
    Venta(int numero, int idEmpleado, Fecha fechaDeVenta,Hora horario, int idProducuto, int cantidad);
    Venta();
    //SETS
    void setNumero(int numero);
    void setIdEmpleado(int idEmpleado);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setHora(Hora horario);
    void setIdProducto(int idProducto, int pos);
    void setCantidad(int cantidad, int pos);
    void setEstado(bool estado);


    //GETS
    int getNumero();
    int getIdEmpleado();
    Fecha getFechaDeVenta();
    Hora getHorario();
    int getIdProducto(int pos);
    int getCantidad(int pos);
    bool getEstado();

 };

