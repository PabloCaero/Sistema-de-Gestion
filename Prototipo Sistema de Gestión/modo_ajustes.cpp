#include <iostream>
#include <cstring>
#include "Articulo.h"
#include "Proveedor.h"
#include "Usuario.h"
#include "rlutil.h"
#include "modo_ajustes.h"

using namespace rlutil;
using namespace std;

void recuadro4(short x, short y, short ancho, short alto);
bool soloNumeros(const char *cadena);

void modoAjustes()
{
    saveDefaultColor();

    int opcion;
    do
    {
        setBackgroundColor(BLACK);
        recuadro4(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro4(25, 5, 62, 20);
        setColor(BLACK);
        gotoxy(26,7);
        cout<<"                     SISTEMA DE GESTION               "<<endl;
        gotoxy(26,8);
        cout<<"                    -[nombre del local]-              "<<endl;
        gotoxy(26,9);
        cout<<"                                                      "<<endl;
        gotoxy(26,10);
        cout<<" AJUSTES                                              "<<endl;
        gotoxy(26,11);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,12);
        cout<<" 1. ARTICULOS                                         "<<endl;
        gotoxy(26,13);
        cout<<" 2. PROVEEDORES                                       "<<endl;
        gotoxy(26,14);
        cout<<" 3. VENDEDORES                                        "<<endl;
        gotoxy(26,15);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,16);
        cout<<" 0. VOLVER AL MENU PRINCIPAL                          "<<endl;
        gotoxy(26,17);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,18);
        cout<<"->                                                   "<<endl;
        gotoxy(29,18);
        cin >> opcion;

        resetColor();
        cls();


        switch(opcion)
        {

        case 1:
            ajustesArticulos();
            break;
        case 2:
            ajustesProveedores();
            break;
        case 3:
            ajustesVendedores();
            break;

        case 0:
            return;
            break;
        default:
            setColor(RED);
            gotoxy(26,7);
            cout << "                   >>OPCION INCORRECTA<<" << endl;
            setColor(BLACK);
            resetColor();
            anykey();

            break;
        }
        cls();

    }
    while(opcion != 0);

    return;
}

/*AJUSTES ARTICULOS*/
int buscarArticuloxID(int IDArticulo)
{
    Articulo reg;
    int i=0;
    while(reg.leerEnDisco(i))
    {
        if(IDArticulo == reg.getIDArticulo())
        {
            return i;
        }
        i++;
    }
    return -1;//NUNCA ENCONTRO EL REGISTRO
}

void agregarStock()
{
    Articulo articulo;
    int opcion;
    int pos;
    int IDArticulo;
    int sumarstock;
    gotoxy(26,9);
    cout << "INGRESE EL CODIGO DE ARTICULO: ";
    cin >> IDArticulo;
    pos = buscarArticuloxID(IDArticulo);
    if(pos >= 0)
    {
        articulo.leerEnDisco(pos);
        if(articulo.getEstado())
        {
            gotoxy(26,10);
            cout << "ARTICULO    : " << articulo.getNombreArticulo() << endl;
            gotoxy(26,11);
            cout << "STOCK       : " << articulo.getStock() << endl;
            int actual = articulo.getStock();
            gotoxy(26,12);
            cout << "DESEA AGREGAR STOCK?(1: SI / 0: NO): ";
            bool eleccion;
            cin >> eleccion;
            if(eleccion)
            {
                gotoxy(26,13);
                cout << "INGRESE LA CANTIDAD QUE DESEA AGREGAR: ";
                cin >> sumarstock;
                actual += sumarstock;
                articulo.setStock(actual);
                if(articulo.escribirEnDisco(pos))
                {
                    gotoxy(26,14);
                    cout << "-------------------------------------------------------------" << endl;
                    gotoxy(26,15);
                    cout << "STOCK AGREGADO CORRECTAMENTE" << endl;
                    gotoxy(26,16);
                    cout << "STOCK ACTUAL: " << articulo.getStock() << endl;
                }
                else
                {
                    gotoxy(26,14);
                    cout << "-------------------------------------------------------------" << endl;
                    gotoxy(26,15);
                    cout << "NO SE PUDO INGRESAR EL STOCK" << endl;
                }

            }
            else
            {
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "EL STOCK NO FUE MODIFICADO" << endl;
            }
        }
        else
        {
            gotoxy(26,10);
            cout << "-------------------------------------------------------------" << endl;
            gotoxy(26,11);
            cout << "     ARTICULO INACTIVO" << endl;
        }

    }
    else
    {
        gotoxy(26,10);
        cout << "-------------------------------------------------------------" << endl;
        gotoxy(26,11);
        cout << "    NO EXISTE LO BUSCADO" << endl;
    }
}

bool cargarNuevoArticulo()
{
    int  IDarticulo;
    char nombreArticulo[50];
    float precioArticulo;
    float precioVenta;
    char caracteristicas[100];
    char tipoArticulo[20];
    int stock;
    bool estado;


    gotoxy(26,9);
    cout << "INGRESE CODIGO DE ARTICULO : ";
    cin >> IDarticulo;
    if(buscarArticuloxID(IDarticulo)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        return false;
    }
    gotoxy(26,10);
    cout << "NOMBRE DE ARTICULO     : ";
    cin.ignore();
    cin.getline(nombreArticulo, 50);
    gotoxy(26,11);
    cout << "PRECIO UNITARIO        : $";
    cin >> precioArticulo;
    gotoxy(26,12);
    cout << "PRECIO DE VENTA        : $";
    cin >> precioVenta;
    gotoxy(26,13);
    cout << "TIPO DE ARTICULO       : ";
    cin.ignore();
    cin.getline(tipoArticulo, 20);
    gotoxy(26,14);
    cout << "CARACTERISTICAS        : ";
    cin.getline(caracteristicas, 100);
    gotoxy(26,15);
    cout << "STOCK ACTUAL           : ";
    cin >> stock;
    estado = true;
    Articulo nuevo;
    nuevo.setIDArticulo(IDarticulo);
    nuevo.setNombreArticulo(nombreArticulo);
    nuevo.setPrecioArticulo(precioArticulo);
    nuevo.setPrecioVenta(precioVenta);
    nuevo.setTipoArticulo(tipoArticulo);
    nuevo.setCaracteristicas(caracteristicas);
    nuevo.setStock(stock);
    nuevo.setEstado(estado);



    return nuevo.escribirEnDisco(); //VA A SER TRUE SI SE GUARDA CORRECTAMENTE*/
}

void altabajaArticulo()
{
    Articulo reg;
    int IDarticulo;
    int pos;
    bool estado;
    gotoxy(26,9);
    cout << "INGRESE EL CODIGO DEL ARTICULO: " ;
    cin >> IDarticulo;
    pos = buscarArticuloxID(IDarticulo);
    if(pos >= 0)
    {
        reg.leerEnDisco(pos);
        if(reg.getEstado()==true)
        {
            gotoxy(26,10);
            cout << "ARTICULO     : " << reg.getNombreArticulo() << endl;
            gotoxy(26,11);
            cout << "ESTADO ACTUAL: ACTIVO" << endl;
            gotoxy(26,12);
            cout << "DESEA DARLO DE BAJA? (1: NO/0: SI): ";
            cin >> estado;
            if(estado==false)
            {
                reg.setEstado(estado);
                reg.escribirEnDisco(pos);
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "ARTICULO DADO DE BAJA" << endl;
            }
            else
            {
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "EL ARTICULO NO FUE MODIFICADO" << endl;
            }
        }
        else
        {
            gotoxy(26,10);
            cout << "ARTICULO     : " << reg.getNombreArticulo() << endl;
            gotoxy(26,11);
            cout << "ESTADO ACTUAL: INACTIVO" << endl;
            gotoxy(26,12);
            cout << "DESEA DARLO DE ALTA? (1: SI/0: NO): ";
            cin >> estado;
            if(estado==true)
            {
                reg.setEstado(estado);
                reg.escribirEnDisco(pos);
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "ARTICULO DADO DE ALTA" << endl;
            }
            else
            {
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "EL ARTICULO NO FUE MODIFICADO" << endl;
            }
        }
    }
    else
    {
        gotoxy(26,10);
        cout << "NO EXISTE LO BUSCADO" << endl;
    }
}

void listadoArticulosxID()
{
    int cant = contarArticulos(); //TENGO CUANTOS DOCENTES SON
    if(cant == 0)
    {
        return;
    }
    Articulo *vec;
    vec = new Articulo[cant] ;
    if(vec == NULL)
    {
        return;
    }
    leerArticulos(vec, cant);

    int i=0;
    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro4(23, 4, 66, 22);
    setBackgroundColor(WHITE);
    recuadro4(25, 5, 62, 20);
    setColor(BLACK);
    gotoxy(26,7);
    cout << "                    ARTICULOS ACTIVOS" << endl;
    gotoxy(26,8);
    cout << "-------------------------------------------------------------" << endl;
    gotoxy(26,9);
    cout << "ID            " << "ARTICULO          " << "$VENTA          " << "STOCK ACTUAL" << endl;
    gotoxy(26,10);
    cout << "-------------------------------------------------------------" << endl;

    int y = 11;
    for(i=0; i<cant; i++)
    {
        if(vec[i].getEstado() == true)
        {
            y++;
            gotoxy(26,y);
            cout << vec[i].getIDArticulo();
            gotoxy(40,y);
            cout << vec[i].getNombreArticulo();
            gotoxy(58,y);
            cout << "$" << vec[i].getPrecioArticulo();
            gotoxy(74,y);
            cout << vec[i].getStock();
        }
    }
    resetColor();
    delete vec;
}

void leerArticulos(Articulo *vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerEnDisco(i);
    }
}


/*AJUSTES PROVEEDORES*/
bool cargarNuevoProveedor()
{
    char nombre[30];
    char apellido[30];
    char direccion[50];
    int telefono;
    bool estado;
    char dni[11];
    ///DEBERIA AGREGARSE EL ATRIBUTO "TIPO DE ARTICULO" PERO POR ALGUN MOTIVO NO ESTA COMPILANDO - VER CON ANDY
     gotoxy(26,9);
    cout << "DNI DEL PROVEEDOR : ";
    cin >> dni;
     if(soloNumeros(dni)==false) {
        gotoxy(26,10);
        cout << "DNI CON FORMATO INCORRECTO" <<endl;
        return false;
    }
    if(buscarProveedorxDNI(dni)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        return false;
    }
    gotoxy(26,10);
    cout << "NOMBRE/S          : ";
    cin.ignore();
    cin.getline(nombre, 30);
    gotoxy(26,11);
    cout << "APELLIDO/S        : ";
    cin.getline(apellido, 30);
    gotoxy(26,12);
    cout << "DIRECCION         : ";
    cin.getline(direccion, 50);
    gotoxy(26,13);
    cout << "TELEFONO          : ";
    cin >> telefono;
    estado = true;

    Proveedor nuevo;
    nuevo.setDni(dni);
    nuevo.setNombre(nombre);
    nuevo.setDireccion(direccion);
    nuevo.setApellido(apellido);
    nuevo.setTelefono(telefono);
    nuevo.setEstado(estado);


    return nuevo.escribirEnDisco(); //VA A SER TRUE SI SE GUARDA CORRECTAMENTE
}

int buscarProveedorxDNI(char *dni)
{

    Proveedor reg;
    int i=0;
    while(reg.leerEnDisco(i))
    {
        if(strcmp(dni, reg.getDni())==0)
        {
            return i;
        }
        i++;
    }
    return -1;//NUNCA ENCONTRO EL REGISTRO
}


void altabajaProveedor()
{
    Proveedor reg;
    char dni[11];
    int pos;
    bool estado;
    gotoxy(26,9);
    cout << "INGRESE EL DNI DEL PROVEEDOR: " ;
    cin >> dni;
    if(soloNumeros(dni)==false) {
        gotoxy(26,10);
        cout << "DNI CON FORMATO INCORRECTO" <<endl;
        return;
    }
    pos = buscarProveedorxDNI(dni);
    if(pos >= 0)
    {
        reg.leerEnDisco(pos);
        if(reg.getEstado()==true)
        {
            gotoxy(26,10);
            cout << "PROVEEDOR     : " << reg.getApellido() << ", " << reg.getNombre() << endl;
            gotoxy(26,11);
            cout << "ESTADO ACTUAL: ACTIVO" << endl;
            gotoxy(26,12);
            cout << "DESEA DARLO DE BAJA? (1: NO/0: SI) ";
            cin >> estado;
            if(estado==false)
            {
                reg.setEstado(estado);
                reg.escribirEnDisco(pos);
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "PROVEEDOR DADO DE BAJA" << endl;
            }
            else
            {
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "EL PROVEEDOR NO FUE MODIFICADO" << endl;
            }
        }
        else
        {
            gotoxy(26,10);
            cout << "PROVEEDOR     : " << reg.getApellido() << ", " << reg.getNombre() << endl;
             gotoxy(26,11);
            cout << "ESTADO ACTUAL: INACTIVO" << endl;
            gotoxy(26,12);
            cout << "DESEA DARLO DE ALTA? (1: SI/0: NO) ";
            cin >> estado;
            if(estado==true)
            {
                reg.setEstado(estado);
                reg.escribirEnDisco(pos);
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "PROVEEDOR DADO DE ALTA" << endl;
            }
            else
            {
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "EL PROVEEDOR NO FUE MODIFICADO" << endl;
            }
        }
    }
    else
    {
        gotoxy(26,10);
        cout << "NO EXISTE LO BUSCADO" << endl;

    }
}

void listadoProveedores()
{
    int cant = contarProveedores(); //TENGO CUANTOS DOCENTES SON
    if(cant == 0)
    {
        return;
    }
    Proveedor *vec;
    vec = new Proveedor[cant] ;
    if(vec == NULL)
    {
        return;
    }
    leerProveedores(vec, cant);

    int i=0;
    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro4(23, 4, 85, 35);
    setBackgroundColor(WHITE);
    recuadro4(25, 5, 81, 33);
    setColor(BLACK);
    gotoxy(26,7);
    cout << "                            PROVEEDORES ACTIVOS" << endl;
    gotoxy(26,8);
    cout << "--------------------------------------------------------------------------------" << endl;
    gotoxy(26,9);
    cout << "DNI          " << "APELLIDO Y NOMBRE            " << "DIRECCION                 " << "TELEFONO" << endl;
    gotoxy(26,10);
    cout << "--------------------------------------------------------------------------------" << endl;

    int y = 11;
    for(i=0; i<cant; i++)
    {
        if(vec[i].getEstado() == true)
        {
            y++;
            gotoxy(26,y);
            cout << vec[i].getDni();
            gotoxy(39,y);
            cout << vec[i].getApellido() << ", " << vec[i].getNombre();
            gotoxy(68,y);
            cout << vec[i].getDireccion();
            gotoxy(94,y);
            cout << vec[i].getTelefono();
        }
    }
    resetColor();
    delete vec;
}

void leerProveedores(Proveedor *vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerEnDisco(i);
    }
}


/*AJUSTES VENDEDORES*/
bool cargarNuevoVendedor()
{
    char nombre[30];
    char apellido[30];
    bool estado;
    int IDVendedor;
    gotoxy(26,9);
    cout << "ID USUARIO        : ";
    cin >> IDVendedor;
    if(buscarVendedorxID(IDVendedor)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        return false;
    }
    gotoxy(26,10);
    cout << "NOMBRE/S          : ";
    cin.ignore();
    cin.getline(nombre, 30);
    gotoxy(26,11);
    cout << "APELLIDO/S        : ";
    cin.getline(apellido, 30);
    estado = true;

    Usuario nuevo;
    nuevo.setIDUsuario(IDVendedor);
    nuevo.setNombre(nombre);
    nuevo.setApellido(apellido);
    nuevo.setEstado(estado);



    return nuevo.escribirEnDisco(); //VA A SER TRUE SI SE GUARDA CORRECTAMENTE*/
}

int buscarVendedorxID(int id)
{
    Usuario reg;
    int i=0;
    while(reg.leerEnDisco(i))
    {
        if(id == reg.getIDUsuario())
        {
            return i;
        }
        i++;
    }
    return -1;//NUNCA ENCONTRO EL REGISTRO
}


void altabajaVendedor()
{
    Usuario reg;
    int id;
    int pos;
    bool estado;
    gotoxy(26,9);
    cout << "INGRESE EL ID DEL VENDEDOR: " ;
    cin >> id;
    pos = buscarVendedorxID(id);
    if(pos >= 0)
    {
        reg.leerEnDisco(pos);
        if(reg.getEstado()==true)
        {
            gotoxy(26,10);
            cout << reg.getApellido() << ", " << reg.getNombre() << endl;
            gotoxy(26,11);
            cout << "ESTADO ACTUAL: ACTIVO" << endl;
            gotoxy(26,12);
            cout << "DESEA DARLO DE BAJA? (1: NO/0: SI): ";
            cin >> estado;
            if(estado==false)
            {
                reg.setEstado(estado);
                reg.escribirEnDisco(pos);
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "VENDEDOR DADO DE BAJA" << endl;
            }
            else
            {
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "EL VENDEDOR NO FUE MODIFICADO" << endl;
            }
        }
        else
        {
            gotoxy(26,10);
            cout << reg.getApellido() << ", " << reg.getNombre() << endl;
            gotoxy(26,11);
            cout << "ESTADO ACTUAL: INACTIVO" << endl;
            gotoxy(26,12);
            cout << "DESEA DARLO DE ALTA? (1: SI/0: NO): ";
            cin >> estado;
            if(estado==true)
            {
                reg.setEstado(estado);
                reg.escribirEnDisco(pos);
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "VENDEDOR DADO DE ALTA" << endl;
            }
            else
            {
                gotoxy(26,13);
                cout << "-------------------------------------------------------------" << endl;
                gotoxy(26,14);
                cout << "EL VENDEDOR NO FUE MODIFICADO" << endl;
            }
        }
    }
    else
    {
        gotoxy(26,10);
        cout << "NO EXISTE LO BUSCADO" << endl;
    }
}

void listadoVendedoresxID()
{
    int cant = contarUsuarios(); //TENGO CUANTOS DOCENTES SON
    if(cant == 0)
    {
        return;
    }
    Usuario *vec;
    vec = new Usuario[cant] ;
    if(vec == NULL)
    {
        return;
    }
    leerVendedores(vec, cant);

    int i=0;
    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro4(23, 4, 66, 22);
    setBackgroundColor(WHITE);
    recuadro4(25, 5, 62, 20);
    setColor(BLACK);
    gotoxy(26,7);
    cout << "                     VENDEDORES ACTIVOS" << endl;
    gotoxy(26,8);
    cout << "-------------------------------------------------------------" << endl;
    gotoxy(26,9);
    cout << "ID            " << "APELLIDO Y NOMBRE         " << "TRANSACCIONES TOTALES" << endl;
    gotoxy(26,10);
    cout << "-------------------------------------------------------------" << endl;

    int y = 11;
    for(i=0; i<cant; i++)
    {
        if(vec[i].getEstado() == true)
        {
            y++;
            gotoxy(26,y);
            cout << vec[i].getIDUsuario();
            gotoxy(40,y);
            cout << vec[i].getApellido() << ", " << vec[i].getNombre();
            gotoxy(66,y);
            //cout << vec[i].getTransacciones(); //FALTA REALIZAR EN CLASE "USUARIO"
            cout << "--";

        }
    }
    resetColor();
    delete vec;
}

void leerVendedores(Usuario *vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerEnDisco(i);
    }
}


/*FUNCION PARA RECUADRO*/
void recuadro4(short x, short y, short ancho, short alto)
{
    int i, j;
    for(i=x; i<=x+ancho; i++)
    {
        for(j=y; j<=y+alto; j++)
        {
            gotoxy(i, j);
            if(i==x && j==y)
            {
                cout << (char) 201;   ///ARRIBA  - IZQUIERDA
            }
            else if(i==x+ancho && j==y)
            {
                cout << (char) 187;   ///ARRIBA  - DERECHA
            }
            else if(i==x && j==y+alto)
            {
                cout << (char) 200;   ///ABAJO   - IZQUIERDA
            }
            else if(i==x+ancho && j==y+alto)
            {
                cout << (char) 188;   ///ABAJO   - DERECHA
            }
            else if(j==y || j==y+alto)
            {
                cout << (char) 205;   ///ARRIBA  - ABAJO
            }
            else if(i==x || i==x+ancho)
            {
                cout << (char) 186;   ///DERECHA - IZQUIERDA
            }
            else
            {
                cout << " ";   ///DENTRO DEL RECUADRO
            }
        }
    }

}

/*FUNCION SOLO NUMEROS PARA VALIDACION*/
bool soloNumeros(const char *cadena)
{
    int i=0;
    while(cadena[i] != '\0')
    {
        if(!(cadena[i]>='\0' && cadena[i] <= '9'))
        {
            return false;
        }
        i++;
    }
    return true;
}





