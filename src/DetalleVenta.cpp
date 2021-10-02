#include <iostream>
#include <cstring>

using namespace std;

#include "DetalleVenta.h"

DetalleVenta::DetalleVenta()
{
    //ctor
}

void DetalleVenta::setIDVenta(int IDventa)
{
    _IDventa=IDventa;
}
void DetalleVenta::setIDArticulo(int IDarticulo)
{
    _IDarticulo=IDarticulo;
}
void DetalleVenta::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}
void DetalleVenta::setPrecioVenta(float precioVenta)
{
    _precioVenta=precioVenta;
}

int DetalleVenta::getIDVenta()
{
    return _IDventa;
}
int DetalleVenta::getIDArticulo()
{
    return _IDarticulo;
}
int DetalleVenta::getCantidad()
{
    return _cantidad;
}
float DetalleVenta::getPrecioVenta()
{
    return _precioVenta;
}

void DetalleVenta::setEstado(bool estado)
{
    _estado = estado;
}

bool DetalleVenta::getEstado()
{
    return _estado;
}

void DetalleVenta::setNombreArticulo(char *nombrearticulo)
{
    strcpy(_nombreArticulo, nombrearticulo);
}

char *DetalleVenta::getNombreArticulo()
{
    return  _nombreArticulo;
}


void DetalleVenta::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

Fecha DetalleVenta:: getFecha()
{
    return _fecha;
}



void DetalleVenta::mostrar()
{

    if(_estado)
    {
        cout << _IDarticulo << ", "  << _nombreArticulo << ", " << _IDventa << ", " << _cantidad << ", " << _precioVenta << endl;
    }

}


bool DetalleVenta::escribirEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("detalleventas.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(DetalleVenta), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

bool DetalleVenta::escribirEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("detalleventas.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(DetalleVenta)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return guardo;

}

bool DetalleVenta::leerEnDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("detalleventas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(DetalleVenta)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return lectura;
}

int contarDetalleVentas()
{
    int bytes, cr;
    FILE *p;
    p=fopen("detalleventas.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(DetalleVenta);
    fclose(p);
    return cr;
}

