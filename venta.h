#pragma once
using namespace std;
#include "fecha.h"
#include "hora.h"
#include <vector>

 class Venta
 {
   protected:
    int _numero;
    Fecha _fechaDeVenta;
    int _idEmpleado;
    Hora _horario;
    bool _estado;

   public:
    vector<int> _idProductos;
    vector<int> _cantidades;
    Venta(int numero, int idEmpleado, Fecha fechaDeVenta,Hora horario, int idProducuto, int cantidad);
    Venta();
    //SETS
    void setNumero(int numero);
    void setIdEmpleado(int idEmpleado);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setHora(Hora horario);
    void setEstado(bool estado);
    // el método push_back de los vectores agrega los elementos dados al final del vector.
    void setIdProductos(const vector<int>& idProductos)
    {
      _idProductos = idProductos;
    }

    void setCantidades(const vector<int>& cantidades)
    {
      _cantidades = cantidades;
    }

   void guardarCantidadesYidProductos(int idProductos, int cantidades)
   {
     _idProductos.push_back(idProductos);
     _cantidades.push_back(cantidades);

   }
    //GETS
    int getNumero();
    int getIdEmpleado();
    Fecha getFechaDeVenta();
    Hora getHorario();
    const vector<int>& getIdProductos() const { return _idProductos; }
    const vector<int>& getCantidades() const { return _cantidades; }
    bool getEstado();

 };

