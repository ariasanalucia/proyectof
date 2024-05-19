#pragma once
#include <cstring>

class proveedor
{
    private:
        int _telefono,_idProveedor;
        char _nombreProveedor;
        bool _estado;
    public:
        void setTelefono(int telefonoNuevo){_telefono = telefonoNuevo;}
        void setId(int idNuevo){_idProveedor = idNuevo;}
//        void setNombre(const char *nombre){strcpy(_nombreProveedor, nombre);}
        void setEstado(bool estadoNuevo){_estado = estadoNuevo;}
        int getTelefono(){return _telefono;}
        int getId(){return _idProveedor;}
        char getNombre(){return _nombreProveedor;}
        bool getEstado(){return _estado;}

};
