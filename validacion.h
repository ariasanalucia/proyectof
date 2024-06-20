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
};

class validacionTelefono{
    public:
        void validarTelefono(int &telefono);
};

class validacionEmpleado{
    public:
        void validarDni(int &dni);
<<<<<<< Updated upstream
        void validarTelefono(int &telefono);
=======
>>>>>>> Stashed changes
};

#endif // VALIDACION_H_INCLUDED
