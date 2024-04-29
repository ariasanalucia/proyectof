
#include "clsCliente.h"
#include <string.h>
#include <iostream>

       clsCliente::clsCliente()
        {

        }
        clsCliente::clsCliente(char nombre[], int DNI, int edad, int numMesa)
        {
            strcpy(_nombre, nombre);
            _DNI=DNI;
            _edad=edad;
            _numMesa=numMesa;
        }
        char* clsCliente::getNombre()
        {
            return _nombre;
        }
        int clsCliente::getDNI()
        {
            return _DNI;
        }
        int clsCliente::getEdad()
        {
            return _edad;
        }
        int clsCliente::getNumMesa()
        {
            return _numMesa;
        }
        void clsCliente::setNombre (char nombre[])
        {
            strcpy(_nombre, nombre);
        }
        void clsCliente::SetDNI(int DNI)
        {
            _DNI=DNI;
        }
        void clsCliente::setEdad(int edad)
        {
            _edad=edad;
        }


