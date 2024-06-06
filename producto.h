#pragma once
using namespace std;
#include "fecha.h"

 class Producto
 {
   private:
    int _id;
    char _marca[30];
    char _droga[30];
    float _miligramos;
    char _categoria[30];
    int _proveedor;
    Fecha _vencimiento;
    int _stock;
    bool _estado;
    char _presentacion[30];
    int _cantidad;
    float _precioUnitario;

   public:
    Producto(int id,const char *marca, const char *droga,float miligramos, const char *categoria, int Proveedor, Fecha vencimiento, bool estado, const char *presentacion, int cantidad, float precioUnitario);
    Producto();
    //SETS
    void setId(int id);
    void setMarca(const char *marca);
    void setDroga(const char *droga);
    void setMiligramos(float miligramos);
    void setCategoria(const char *categoria);
    void setProveedor(int Proveedor);
    void setVencimiento(Fecha vencimiento);
    void setStock(int stock);
    void setEstado(bool estado);
    void setPresentacion(const char *presentacion);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
    //GETS
    int getId();
    const char *getMarca(){return _marca;}
    const char *getDroga(){return _droga;}
    float getMiligramos();
    const char *getCategoria(){return _categoria;}
    int getProveedor();
    Fecha getVenciemiento(){return _vencimiento;}
    int getStock();
    bool getEstado();
    const char *getPresentacion(){return _presentacion;}
    int getCantidad();
    float getPrecioUnitario();
 };
