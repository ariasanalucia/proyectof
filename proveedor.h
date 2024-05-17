#pragma once
#include <cstring>

class proveedor
{
    protected:
        int telefono,idProveedor;
        char nombreProveedor;
        bool estado;
    public:
        void setTelefono(int telefonoNuevo){telefono = telefonoNuevo;}
        void setId(int idNuevo){idProveedor = idNuevo;}
        void setNombre(const char* nombre){strcpy(nombreProveedor,Nombre);}
        void setEstado(bool estadoNuevo){estado = estadoNuevo;}
        int getTelefono(){return telefono;}
        int getId(){return idProveedor;}
        char getNombre(){return nombreProveedor;}
        bool getEstado(){return estado;}

};
