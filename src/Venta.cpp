#include <iostream>
#include <cstring>

using namespace std;

#include "Venta.h"
#include "Fecha.h"


void Venta::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

Fecha Venta:: getFecha()
{
    return _fecha;
}
void Venta::setIDVenta(int IDVenta)
{
    _IDVenta = IDVenta;
}
void Venta::setIDUsuario(int IDUsuario)
{
    _IDUsuario = IDUsuario;
}
void Venta::setTotal(float total)
{
    _total = total;
}
void Venta::setEstado(bool estado)
{
    _estado = estado;
}

int Venta::getIDVenta()
{
    return _IDVenta;
}
int Venta::getIDUsuario()
{
    return _IDUsuario;
}
float Venta::getTotal()
{
    return _total;
}
bool Venta::getEstado()
{
    return _estado;
}

void Venta::setCantidadTotal(int cantidadTotal)
{
    _cantidadTotal = cantidadTotal;
}
int Venta::getCantidadTotal()
{
    return _cantidadTotal;
}


void Venta::mostrar()
{
    if(_estado)
    {
        _fecha.mostrar();
        cout << ", "<< _IDVenta << ", " << _IDUsuario << ", $" << _total << endl;
    }
}

bool Venta::escribirEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("ventas.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Venta), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

bool Venta::escribirEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("ventas.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Venta)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Venta), 1, p);
    fclose(p);
    return guardo;

}

bool Venta::leerEnDisco(int pos)
{

    bool lectura;
    FILE *p;
    p = fopen("ventas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Venta)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Venta), 1, p);
    fclose(p);
    return lectura;
}

int contarVentas()
{
    int bytes, cr;
    FILE *p;
    p=fopen("ventas.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Venta);
    fclose(p);
    return cr;
}


