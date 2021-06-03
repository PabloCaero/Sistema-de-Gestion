#ifndef PERSONA_H
#define PERSONA_H


class Persona
{

    public:
        void setApellido(char *);
        void setNombre(char *);
        char *getApellido();
        char *getNombre();


        void cargar();
        void mostrar();


    protected:
        char _apellido[30];
        char _nombre[30];
        //SE TIENE QUE AGREGAR ID
};

#endif // PERSONA_H
