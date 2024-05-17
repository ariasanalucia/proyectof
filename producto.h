#pragma once
using namespace std;
#include "fecha.h"

 class Producto
 {
   protected:
    int _id;
    char _marca[30];
    char _droga[30];
    char _categoria[30];
    int _proveedor;
    Fecha _vencimiento;
    int _stock;
    bool _estado;
    char _presentacion[30];
    int _cantidad;
    float _importe;

   public:
    Producto(int id,const char *marca, const char *droga, const char *categoria, int proveedor, Fecha vencimiento, bool estado, const char *presentacion, int cantidad, float importe);
    Producto();
    //SETS
    void setId(int id);
    void setMarca(const char *marca);
    void setDroga(const char *droga);
    void setCategoria(const char *categoria);
    void setProveedor(int proveedor);
    void setVencimiento(Fecha vencimiento);
    void setStock(int stock);
    void setEstado(bool estado);
    void setPresentacion(const char *presentacion);
    void setCantidad(int cantidad);
    void setImporte(float importe);
    //GETS
    int getId();
    const char *getMarca(){return _marca;}
    const char *getDroga(){return _droga;}
    const char *getCategoria(){return _categoria;}
    int getProveedor();
    Fecha getVenciemiento(){return _vencimiento;}
    int getStock();
    bool getEstado();
    const char *getPresentacion(){return _presentacion;}
    int getCantidad();
    float getImporte();
 };
