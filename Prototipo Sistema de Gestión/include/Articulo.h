#ifndef ARTICULO_H
#define ARTICULO_H

#include "Articulo.h"


class Articulo
{
public:
    void setTipoArticulo(char *);
    void setCaracteristicas(char *);
    void setIDArticulo(int);
    void setNombreArticulo(char *);
    void setPrecioVenta(float);
    void setPrecioArticulo(float);
    void setStock(int);

    int getStock();
    char *getTipoArticulo();
    char *getCaracteristicas();
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

protected:

    int _IDarticulo;
    char _nombreArticulo[50];
    float _precioArticulo;
    float _precioVenta;
    char _caracteristicas[100];
    char _tipoArticulo[20]; //CAMBIAR POR ATRIBUTO "CATEGORIA"
    int _stock;
    bool _estado;
};

int contarArticulos();

#endif // ARTICULO_H
