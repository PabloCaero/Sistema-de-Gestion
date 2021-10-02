#ifndef MODO_VENTAS_H_INCLUDED
#define MODO_VENTAS_H_INCLUDED

/*FUNCIONES DEL MENU VENTAS*/
void pantallaVenta(int);
void cerrarTransaccion();
int buscarVentaxID(int);
int buscarDetalleVentaxIDArticulo(int);
void leerDetalleVentas(DetalleVenta*, int);
void plantillaTicket(int);
void ordenarDetalleVentasxIDVenta(DetalleVenta *, int);
void ordenarVentasxIDVenta(Venta *, int);
void leerVentas(Venta *, int);

#endif // MODO_VENTAS_H_INCLUDED
