#pragma once
using namespace std;

 class Producto
 {
   protected:
    int _id;
    char _nombre[30];
    char _categoria[30];
    int _proveedor;
   public:
    Producto(int id, const char *nombre, const char *categoria, int proveedor);
    Producto();
    //SETS
    void setId(int id);
    void setNombre(const char *nombre);
    void setCategoria(const char *categoria);
    void setProveedor(int proveedor);
    //GETS
    int getId();
    const char *getNombre(){return _nombre;}
    const char *getCategoria(){return _categoria;}
    int getProveedor();
 };
