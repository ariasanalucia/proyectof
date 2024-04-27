class Persona{
    protected:
        int dni;
        char nombre[30];
        char apellido[30];
        Fecha fechaNacimiento;
        char telefono[15];
    public:
        Persona(int d=0, const char *n="S/N", const char *a="S/A", Fecha f=Fecha(), const char *t="S/T");
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

Persona::Persona(int d, const char *n, const char *a, Fecha f, const char *t){
    dni=d;
    strcpy(nombre,n);
    strcpy(apellido,a);
    fechaNacimiento=f;
    strcpy(telefono,t);
}


void Persona::Cargar(){
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Cargar();
    cout<<"TELEFONO: ";
    cargarCadena(telefono,14);
}

void Persona::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
}
