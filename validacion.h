#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED
#include "fecha.h"

class validacionProducto{
    public:
        void validarProveedor(int &proveedor);
        void validarVencimiento(Fecha &vencimiento);
        void valdiarMiligramo(float &miligramo);
        void validarPrecio(float &precio);
};

class validacionVenta{
    public:
        void validarTelefono(int &telefono);
};

class validacionEmpleado{
    public:

};

#endif // VALIDACION_H_INCLUDED
