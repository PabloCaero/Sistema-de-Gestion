#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#include "Fecha.h"


class DetalleVenta
{
public:
    DetalleVenta();
    void setIDVenta(int);
    void setIDArticulo(int);
    void setCantidad(int);
    void setPrecioVenta(float);
    void setEstado(bool);
    void setNombreArticulo(char *);
    void setFecha(Fecha);
    void setIDVendedor(int);

    void mostrar();

    int getIDVenta();
    int getIDArticulo();
    int getCantidad();
    float getPrecioVenta();
    bool getEstado();
    char *getNombreArticulo();
    Fecha getFecha();
    int getIDVendedor();

    bool escribirEnDisco();
    bool escribirEnDisco(int);
    bool leerEnDisco(int);

private:
    int _IDVendedor;
    int _IDventa;
    char _nombreArticulo[50];
    int _IDarticulo;
    int _cantidad;
    float _precioVenta;
    Fecha _fecha;
    bool _estado;
};

int contarDetalleVentas();


#endif // DETALLEVENTA_H
