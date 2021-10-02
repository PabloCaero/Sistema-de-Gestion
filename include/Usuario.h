#ifndef USUARIO_H
#define USUARIO_H
#include "Persona.h"


class Usuario:public Persona
{
    public:
       void setIDUsuario(int);
       int getIDUsuario();
       void setEstado(bool);
       bool getEstado();

       void cargar();
       void mostrar();

       bool leerEnDisco(int);
       bool escribirEnDisco();
       bool escribirEnDisco(int);


    private:
        int _IDUsuario;
        bool _estado;
};

   int contarUsuarios();


#endif // USUARIO_H
