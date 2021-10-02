#include <iostream>
#include <cstring>
#include "Proveedor.h"

using namespace std;


void Proveedor::setDireccion(char *direccion)
{
    strcpy(_direccion, direccion);
}
char *Proveedor::getDireccion()
{
    return _direccion;
}
void Proveedor::setTelefono(int telefono)
{
    _telefono = telefono;
}
int Proveedor::getTelefono()
{
    return _telefono;
}
void Proveedor::setEstado(bool estado)
{
    _estado = estado;
}
bool Proveedor::getEstado()
{
    return _estado;
}

void Proveedor::setDni(char *dni)
{
    strcpy(_dni, dni);
}

char *Proveedor::getDni()
{
    return _dni;
}



void Proveedor::cargar()
{

    Persona::cargar();
    cout << "DNI             : ";
    cin >> _dni;
    cout << "DIRECCION       : ";
    cin.ignore();
    cin.getline(_direccion, 50);
    cout << "TELEFONO        : ";
    cin >> _telefono;

}

void Proveedor::mostrar()
{
    if(_estado)
    {

        Persona::mostrar();
        cout << "DNI             : " << _dni << endl;
        cout << "DIRECCION       : " << _direccion << endl;
        cout << "TELEFONO        : " << _telefono << endl;

    }
}



bool Proveedor::escribirEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("proveedores.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Proveedor), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

bool Proveedor::escribirEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("proveedores.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Proveedor)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return guardo;
}

bool Proveedor::leerEnDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("proveedores.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Proveedor)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Proveedor), 1, p);
    fclose(p);
    return lectura;
}




int contarProveedores()
{
    int bytes, cr;
    FILE *p;
    p=fopen("proveedores.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Proveedor);
    fclose(p);
    return cr;
}
