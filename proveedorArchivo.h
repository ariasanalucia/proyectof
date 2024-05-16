#pragma once
using namespace std;

class proveedorArchivo
{
    private:
        char _nombre[30];
    public:
        proveedorManager(const char* nombre);
        bool guardarArchivo(Producto producto);
        int contarRegistros();
        int buscar(int id);
        bool modificarProveedor(Producto producto, int pos);
};
