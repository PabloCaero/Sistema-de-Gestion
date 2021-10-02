#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"

class Venta
{
public:
    void setIDVenta(int);
    void setIDUsuario(int);
    void setFecha(Fecha);
    void setTotal(float);
    void setEstado(bool);
    void setCantidadTotal(int);

    Fecha getFecha();
    int getIDVenta();
    int getIDUsuario();
    float getTotal();
    bool getEstado();
    int getCantidadTotal();

    void cargar();
    void mostrar();

    bool escribirEnDisco(int);
    bool escribirEnDisco();
    bool leerEnDisco(int);

private:
    bool _estado;
    int _IDVenta;
    int _IDUsuario;
    Fecha _fecha;
    float _total;
    int _cantidadTotal;
};

int contarVentas();
#endif // VENTA_H
