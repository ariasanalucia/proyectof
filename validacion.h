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
        void validarId(int &id);
        void validarNumero(int &numero);
};

class validacionTelefono{
    public:
        void validarTelefono(int &telefono);
};

class validacionEmpleado{
    public:
        void validarDni(int &dni);
        void validarTelefono(int &telefono);
};

#endif // VALIDACION_H_INCLUDED
