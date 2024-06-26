#pragma once
using namespace std;
#include <cstring>

class Empleado{
    private:
        int _id;
        int _dni;
        char _nombre[30];
        char _apellido[30];
        int _telefono;
        bool _estado;
    public:
        //CONSTRUCTORES
        Empleado(int id, int dni, const char *nombre, const char *apellido, int telefono, bool estado=true);
        Empleado();
        //SETS
        void setId(int id);
        void setDni(int dni);
        void setNombre(const char *nombre);
        void setApellido(const char *apellido);
        void setTelefono(int telefono);
        void setEstado(bool estado);
        //GETS
        int getId();
        int getDni();
        const char *getNombre();
        const char *getApellido();
        int getTelefono();
        bool getEstado();
};
