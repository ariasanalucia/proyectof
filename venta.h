#pragma once
using namespace std;
#include "fecha.h"
#include "hora.h"

 class Venta
 {
   private:
    int _numero;
    Fecha _fecha;
    int _idEmpleado;
    Hora _horario;
    int _idProducto[10] = {};
    int _cantidad[10] = {};
    bool _estado;
    float _importe;

   public:
    Venta(int numero, int idEmpleado, Fecha fecha,Hora horario, int idProducuto, int cantidad, bool estado, float importe);
    Venta();

    //SETS
    void setNumero(int numero);
    void setIdEmpleado(int idEmpleado);
    void setFecha(Fecha fecha);
    void setHora(Hora horario);
    void setIdProducto(int idProducto, int pos);
    void setCantidad(int cantidad, int pos);
    void setEstado(bool estado);
    void setImporte(float importe);

    //GETS
    int getNumero();
    int getIdEmpleado();
    Fecha getFecha();
    Hora getHora();
    int getIdProducto(int pos);
    int getCantidad(int pos);
    bool getEstado();
    float getImporte();

    //MOSTRAR
    void Mostrar(Venta reg);
 };

