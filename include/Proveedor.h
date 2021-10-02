#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "Persona.h"
#include "Articulo.h"
#include "Proveedor.h"


class Proveedor:public Persona
{
    public:
        void setDireccion(char *);
        char *getDireccion();
        void setTelefono(int);
        int getTelefono();
        void setEstado(bool);
        bool getEstado();
        void setDni(char *);
        char *getDni();

        void cargar();
        void mostrar();

        bool escribirEnDisco();
        bool escribirEnDisco(int);
        bool leerEnDisco(int);

    private:

        char _direccion[50];
        int _telefono;
        bool _estado;
        char _dni[11]; //VA A SER PARTE DE LA CLASE "USUARIO" Y ESTA VA A RECIBIR POR HERENCIA EL ATRIBUTO "ID" DE LA CLASE "PERSONA"
};

int contarProveedores();


#endif // PROVEEDOR_H
