#include <iostream>
#include <cstring>

using namespace std;

#include "Usuario.h"


void  Usuario::setIDUsuario(int IDUsuario)
{
    _IDUsuario = IDUsuario;
}
int  Usuario::getIDUsuario()
{
    return _IDUsuario;
}
void Usuario::setEstado(bool estado)
{
    _estado = estado;
}
bool Usuario::getEstado()
{
    return _estado;
}

void Usuario::cargar()
{
    Persona::cargar();
    cout << "ID: ";
    cin >> _IDUsuario;
}
void Usuario:: mostrar()
{
    if(_estado)
    {
        cout << "ID              : "   << _IDUsuario << endl;
        Persona::mostrar();
    }
}

bool Usuario::escribirEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("usuarios.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Usuario), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

bool Usuario::escribirEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("usuarios.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Usuario)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Usuario), 1, p);
    fclose(p);
    return guardo;
}

bool Usuario::leerEnDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("usuarios.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Usuario)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Usuario), 1, p);
    fclose(p);
    return lectura;
}


int contarUsuarios()
{
    int bytes, cr;
    FILE *p;
    p=fopen("usuarios.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Usuario);
    fclose(p);
    return cr;
}


