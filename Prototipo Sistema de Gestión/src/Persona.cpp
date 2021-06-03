#include <iostream>
#include <cstring>

using namespace std;

#include "Persona.h"

void Persona::setApellido(char *apellido)
{
    strcpy(_apellido, apellido);
}
void Persona::setNombre(char *nombre)
{
    strcpy(_nombre, nombre);
}
char *Persona::getApellido()
{
    return _apellido;
}
char *Persona::getNombre()
{
    return _nombre;
}

void Persona::cargar()
{
    cout << "APELLIDO: ";
    cin.ignore();
    cin.getline(_apellido, 30);
    cout << "NOMBRE  : ";
    cin.getline(_nombre, 30);
}
void Persona::mostrar()
{
    cout << "NOMBRE/S        : " << _nombre << endl;
    cout << "APELLIDO/S      : " << _apellido << endl;
}

