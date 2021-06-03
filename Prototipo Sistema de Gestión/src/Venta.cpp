#include <iostream>
#include <cstring>

using namespace std;

#include "Venta.h"
#include "Fecha.h"
#include "Usuario.h"
#include "Articulo.h"

void Venta::setFecha(Fecha fecha)
{
    _fecha = fecha;
}
void Venta::setUsuario(Usuario usuario)
{
    _usuario = usuario;
}
void Venta::setFormaPago(char *formaPago)
{
    strcpy(_formaPago, formaPago);
}
void Venta::setCantidad(int cantidad)
{
   _cantidad = cantidad;
}

Fecha Venta:: getFecha()
{
    return _fecha;
}
Usuario Venta:: getUsuario()
{
    return _usuario;
}
char  *Venta::getFormaPago()
{
    return _formaPago;
}
int Venta::getCantidad()
{
    return _cantidad;
}

void Venta::cargarVenta()
{
    cout << "FORMA DE PAGO: ";
    cin.ignore();
    cin.getline(_formaPago, 20);
    cout << "CANTIDAD: ";
    cin >> _cantidad;
}
void Venta::mostrarVenta()
{
    Articulo::mostrar();
    cout << "FORMA DE PAGO: " << _formaPago << endl;
    cout << "CANTIDAD: " << _cantidad << endl;
}

bool Venta::escribirDiscoVenta()
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
bool Venta::leerDiscoVenta(int pos)
{
    ///Articulo::leerDisco();
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
