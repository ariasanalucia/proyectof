#pragma once

 class Proveedor
 {
   private:
    int _telefono,_idProveedor;
    char _nombre[30];
    bool _estado;

   public:
    Proveedor();
    Proveedor(int telefono, int idProveedor, const char *nombre);
    //SET
    void setTelefono(int telefonoNuevo);
    void setId(int idNuevo);
    void setNombre(const char *nombre);
    void setEstado(bool estadoNuevo);
    //GET
    int getTelefono();
    int getId();
    const char *getNombre();
    bool getEstado();
    //MOSTRAR
    void Mostrar();
 };
