#include <iostream>
#include <cstring>
#include "Articulo.h"
using namespace std;

void Articulo::setIDArticulo(int idarticulo)
{
    _IDarticulo = idarticulo;
}
void Articulo::setNombreArticulo(char *nombrearticulo)
{
    strcpy(_nombreArticulo, nombrearticulo);
}
void Articulo::setPrecioVenta(float precioventa)
{
    _precioVenta = precioventa;
}
void Articulo::setPrecioArticulo(float precioarticulo)
{
    _precioArticulo = precioarticulo;
}

int   Articulo::getIDArticulo()
{
    return _IDarticulo;
}
char *Articulo::getNombreArticulo()
{
    return  _nombreArticulo;
}
float Articulo::getPrecioVenta()
{
    return _precioVenta;
}
float Articulo::getPrecioArticulo()
{
    return _precioArticulo;
}


void Articulo::setEstado(bool estado)
{
    _estado = estado;
}
bool Articulo::getEstado()
{
    return _estado;
}

void Articulo::setStock(int stock)
{
    _stock = stock;
}

int Articulo::getStock()
{
    return _stock;
}

void Articulo::cargar()
{
    cout << "CODIGO DE ARTICULO : ";
    cin >> _IDarticulo;
    cout << "NOMBRE DEL ARTICULO: ";
    cin.ignore();
    cin.getline(_nombreArticulo, 50);
    cout << "STOCK: ";
    cin >> _stock;
    cout << "PRECIO DEL ARTICULO: $";
    cin >> _precioArticulo;
    cout << "PRECIO DE VENTA DEL ARTICULO: $";
    cin >> _precioVenta;
    _estado = true;

}
void Articulo::mostrar()
{
    if(_estado==true)
    {
        /*cout << "CODIGO DE ARTICULO : " << _IDarticulo << endl;
        cout << "NOMBRE DEL ARTICULO: " << _nombreArticulo << endl;
        cout << "PRECIO DEL ARTICULO: $" << _precioArticulo << endl;
        cout << "PRECIO DE VENTA DEL ARTICULO: $" << _precioVenta << endl;
        cout << "STOCK ACTUAL: " << _stock;*/

        cout << _IDarticulo << ", " << _nombreArticulo << ", $" << _precioArticulo << ", $" << _precioVenta << ", " << _stock << endl;
    }
}


bool Articulo::escribirEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("articulos.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Articulo), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}

bool Articulo::escribirEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("articulos.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Articulo)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Articulo), 1, p);
    fclose(p);
    return guardo;

}

bool Articulo::leerEnDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("articulos.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Articulo)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Articulo), 1, p);
    fclose(p);
    return lectura;
}

int contarArticulos(){
     int bytes, cr;
    FILE *p;
    p=fopen("articulos.dat", "rb");
    if(p==NULL)
    {
        return 0; //EL ARCHIVO EXISTE PERO NO TIENE REGISTROS
    }

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Articulo);
    fclose(p);
    return cr;
}
