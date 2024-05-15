#pragma once
using namespace std;

class Empleado{
    protected:
        int dni;
        char nombre[30];
        char apellido[30];
        Fecha fechaNacimiento;
        char telefono[15];
    public:
        Empleado(int d=0, const char *n="S/N", const char *a="S/A", Fecha f=Fecha(), const char *t="S/T");
        void setDni(int d){dni=d;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setApellido(const char *a){strcpy(apellido, a);}
        void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
        void setTelefono(const char *t){strcpy(telefono, t);}
        void setDiaNacimiento(int d){fechaNacimiento.setDia(d);}

        int getDni(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        int getDiaNacimiento(){return fechaNacimiento.getDia();}
        int getMesNacimiento(){return fechaNacimiento.getMes();}
        int getAnioNacimiento(){return fechaNacimiento.getAnio();}
        const char *getTelefono(){return telefono;}
        void Cargar();
        void Mostrar();
};
