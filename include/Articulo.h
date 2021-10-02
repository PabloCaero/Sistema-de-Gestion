#ifndef ARTICULO_H
#define ARTICULO_H

#include "Articulo.h"


class Articulo
{
public:

    void setIDArticulo(int);
    void setNombreArticulo(char *);
    void setPrecioVenta(float);
    void setPrecioArticulo(float);
    void setStock(int);

    int getStock();
    int   getIDArticulo();
    char *getNombreArticulo();
    float getPrecioVenta();
    float getPrecioArticulo();


    void cargar();
    void mostrar();

    void setEstado(bool);
    bool getEstado();

    bool escribirEnDisco();
    bool escribirEnDisco(int);
    bool leerEnDisco(int);

private:

    int _IDarticulo;
    char _nombreArticulo[50];
    float _precioArticulo;
    float _precioVenta;
    int _stock;
    bool _estado;
};

int contarArticulos();

#endif // ARTICULO_H
