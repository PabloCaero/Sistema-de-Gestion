#ifndef MODO_AJUSTES_H_INCLUDED
#define MODO_AJUSTES_H_INCLUDED
#include "funciones.h"
#include "Articulo.h"
#include "Proveedor.h"
#include "Usuario.h"

void ajustesArticulos();
void ajustesProveedores();
void ajustesVendedores();

/*AJUSTES ARTICULOS*/
bool cargarNuevoArticulo();
void agregarStock();
void altabajaArticulo();
int buscarArticuloxID(int);
void listadoArticulosxID();
void leerArticulos(Articulo *vec, int tam);

/*AJUSTES PROVEEDORES*/
bool cargarNuevoProveedor();
int buscarProveedorxDNI(char *);
void altabajaProveedor();
void listadoProveedores();
void leerProveedores(Proveedor *vec, int tam);


/*AJUSTES VENDEDORES*/
bool cargarNuevoVendedor();
int buscarVendedorxID(int);
void altabajaVendedor();
void listadoVendedoresxID();
void leerVendedores(Usuario *vec, int tam);






#endif // MODO_AJUSTES_H_INCLUDED
