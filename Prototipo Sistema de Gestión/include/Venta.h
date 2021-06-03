#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"
#include "Usuario.h"
#include "Articulo.h"


class Venta:public Articulo
{
    public:
      void setFecha(Fecha);
      void setUsuario(Usuario);
      void setFormaPago(char *);
      void setCantidad(int );

      Fecha getFecha();
      Usuario getUsuario();
      char *getFormaPago();
      int getCantidad();

      void cargarVenta();
      void mostrarVenta();

      bool escribirDiscoVenta();
      bool leerDiscoVenta(int);

    private:

        Usuario _usuario;
        Fecha _fecha;
        char _formaPago[20];
        int _cantidad;
};

#endif // VENTA_H
