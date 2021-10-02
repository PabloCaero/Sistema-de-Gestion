#include<iostream>
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>


#include "Articulo.h"
#include "Proveedor.h"
#include "Usuario.h"
#include "Comercio.h"
#include "Fecha.h"
#include "rlutil.h"
#include "modo_ajustes.h"

using namespace rlutil;
using namespace std;

void recuadro(short x, short y, short ancho, short alto);


void modoAjustes()
{

    saveDefaultColor();
    Comercio comercio;
    char opcion[1];
    do
    {
        Fecha actual;
        setBackgroundColor(BLACK);
        recuadro(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro(25, 5, 62, 20);
        setColor(BLACK);
        gotoxy(26,8);
        if(comercio.leerEnDisco(0))
        {
            cout<<comercio.getNombrecomercio()<<endl;
        }
        else
        {
            cout<< "-comercio sin nombre asignado-"<< endl;
        }
        gotoxy(26,9);
        cout<<"-------------------------------------------------------------"<<endl;
        gotoxy(26,11);
        cout<<" \tAJUSTES                                              "<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,13);
        cout<<" \t1. ARTICULOS                                         "<<endl;
        gotoxy(26,14);
        cout<<" \t2. PROVEEDORES                                       "<<endl;
        gotoxy(26,15);
        cout<<" \t3. VENDEDORES                                        "<<endl;
        gotoxy(26,16);
        cout<<" \t4. DATOS DEL COMERCIO                                "<<endl;
        gotoxy(26,17);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,18);
        cout<<" \t0. VOLVER AL MENU PRINCIPAL                          "<<endl;
        gotoxy(26,19);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,20);
        cout<<"\t->                                                    "<<endl;
        gotoxy(35,20);
        cin >> opcion[0];

        resetColor();
        cls();


        switch(opcion[0])
        {

        case '1':
            ajustesArticulos();
            break;
        case '2':
            ajustesProveedores();
            break;
        case '3':
            ajustesVendedores();
            break;
        case '4':
            ajustesComercio();
            break;
        case '0':
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

                while(sumarstock<=0)
                {
                    gotoxy(65,13);
                    cout << "CANTIDAD INCORRECTA";
                    anykey();
                    gotoxy(65,13);
                    cout << "                   ";
                    gotoxy(65,13);
                    cin >> sumarstock;
                }
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
    int stock;
    bool estado;


    gotoxy(26,9);
    cout << "INGRESE CODIGO DE ARTICULO : ";
    cin >> IDarticulo;
    if(IDarticulo <= 0)
    {
        gotoxy(54,9);
        cout << "CODIGO INCORRECTO";
        anykey();
        return false;
    }
    if(buscarArticuloxID(IDarticulo)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        return false;
    }
    gotoxy(26,10);
    cout << "NOMBRE DE ARTICULO     : ";
    cin.ignore();
    cin.getline(nombreArticulo, 50);
    if(validarPalabra(nombreArticulo))
    {
        gotoxy(51,10);
        cout << "NOMBRE INCORRECTO";
        anykey();
        return false;
    }
    gotoxy(26,11);
    cout << "PRECIO UNITARIO        : $";
    cin >> precioArticulo;
    if(precioArticulo <=0)
    {
        gotoxy(51,11);
        cout << "PRECIO INCORRECTO";
        anykey();
        return false;
    }
    gotoxy(26,12);
    cout << "PRECIO DE VENTA        : $";
    cin >> precioVenta;
    if(precioVenta <=0)
    {
        gotoxy(51,12);
        cout << "PRECIO INCORRECTO";
        anykey();
        return false;
    }
    gotoxy(26,13);
    cout << "STOCK ACTUAL           : ";
    cin >> stock;
    if(stock <=0)
    {
        gotoxy(51,13);
        cout << "STOCK INCORRECTO";
        anykey();
        return false;
    }
    estado = true;

    Articulo nuevo;
    nuevo.setIDArticulo(IDarticulo);
    nuevo.setNombreArticulo(nombreArticulo);
    nuevo.setPrecioArticulo(precioArticulo);
    nuevo.setPrecioVenta(precioVenta);
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
        gotoxy(26,7);
        cout << "NO HAY ARTICULOS CARGADOS" << endl;
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
    recuadro(23, 4, 66, 22);
    setBackgroundColor(WHITE);
    recuadro(25, 5, 62, 20);
    setColor(BLACK);
    gotoxy(26,7);
    cout << "                   LISTADO DE ARTICULOS" << endl;
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
            cout << "$" << vec[i].getPrecioVenta();
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
    if(soloNumeros(dni)==false)
    {
        gotoxy(26,10);
        cout << "DNI CON FORMATO INCORRECTO" <<endl;
        return false;
    }
    if(buscarProveedorxDNI(dni)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        gotoxy(26,24);
        cout << "DNI DE PROVEEDOR REPETIDO" <<endl;
        return false;
    }
    gotoxy(26,10);
    cout << "NOMBRE/S          : ";
    cin.ignore();
    cin.getline(nombre, 30);
    if(validarPalabra(nombre))
    {
        gotoxy(46,10);
        cout << "NOMBRE INCORRECTO";
        anykey();
        return false;
    }
    gotoxy(26,11);
    cout << "APELLIDO/S        : ";
    cin.getline(apellido, 30);
    if(validarPalabra(apellido))
    {
        gotoxy(46,10);
        cout << "APELLIDO INCORRECTO";
        anykey();
        return false;
    }

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
    if(soloNumeros(dni)==false)
    {
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
            cout << "PROVEEDOR    : " << reg.getApellido() << ", " << reg.getNombre() << endl;
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
    recuadro(23, 4, 85, 35);
    setBackgroundColor(WHITE);
    recuadro(25, 5, 81, 33);
    setColor(BLACK);
    gotoxy(26,7);
    cout << "                           LISTADO DE PROVEEDORES" << endl;
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
    if(IDVendedor <= 0)
    {
        return false;

    }
    if(buscarVendedorxID(IDVendedor)>=0) //VALIDACION EN CASO DE SER REPETIDA
    {
        return false;
    }
    gotoxy(26,10);
    cout << "NOMBRE/S          : ";
    cin.ignore();
    cin.getline(nombre, 30);
    while(validarPalabra(nombre)!=0)
    {
        gotoxy(26,10);
        cout << "NOMBRE/S          : " ;
        cin.getline(nombre, 30);
    }
    gotoxy(26,11);
    cout << "APELLIDO/S        : ";
    cin.getline(apellido, 30);
    while(validarPalabra(apellido)!=0)
    {
        gotoxy(26,11);
        cout << "APELLIDO/S        : " ;
        cin.getline(nombre, 30);
    }
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
    recuadro(23, 4, 66, 22);
    setBackgroundColor(WHITE);
    recuadro(25, 5, 62, 20);
    setColor(BLACK);
    gotoxy(26,7);
    cout << "                   LISTADO DE VENDEDORES" << endl;
    gotoxy(26,8);
    cout << "-------------------------------------------------------------" << endl;
    gotoxy(26,9);
    cout << "ID            " << "                        " << "APELLIDO Y NOMBRE" << endl;
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
            gotoxy(66,y);
            cout << vec[i].getApellido() << ", " << vec[i].getNombre();
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



/*AJUSTES DE COMERCIO*/
bool cargarDatosComercio()
{
    char nombreComercio[50];
    char direccionComercio[50];
    char telefonoComercio[15];
    char cuit[15];

    gotoxy(26,9);
    cout << "CUIT: ";
    cin >> cuit;
    while(soloNumeros(cuit)==false)
    {
        gotoxy(32,9);
        cout << "CUIT CON FORMATO INCORRECTO, INTENTE NUEVAMENTE" <<endl;
        anykey();
        gotoxy(32,9);
        cout << "                                               " <<endl;
        gotoxy(32,9);
        cin >> cuit;
    }
    gotoxy(26,10);
    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(nombreComercio, 50);
    gotoxy(26,11);
    cout << "DIRECCION: ";
    cin.getline(direccionComercio, 50);
    gotoxy(26,12);
    cout << "TELEFONO: ";
    cin >> telefonoComercio;
    while(soloNumeros(telefonoComercio)==false)
    {
        gotoxy(36,12);
        cout << "TELEFONO CON FORMATO INCORRECTO, INTENTE NUEVAMENTE" <<endl;
        anykey();
        gotoxy(36,12);
        cout << "                                                   " <<endl;
        gotoxy(36,12);
        cin >> telefonoComercio;
    }
    //ESTA VALIDACION FUNCIONA!!!!!!!

    Comercio nuevo;
    nuevo.setCuit(cuit);
    nuevo.setNombrecomercio(nombreComercio);
    nuevo.setDireccioncomercio(direccionComercio);
    nuevo.setTelefonocomercio(telefonoComercio);
    return nuevo.escribirEnDisco(); //VA A SER TRUE SI SE GUARDA CORRECTAMENTE
}

void modificarNombreComercio()
{
    Comercio reg;
    char nombreComercio[50];
    if(reg.leerEnDisco(0)==false)
    {
        gotoxy(26,10);
        cout << "-------------------------------------------------------------" << endl;
        gotoxy(26,11);
        cout << "TODAVIA NO SE CARGARON DATOS DEL COMERCIO" << endl;
        return;
    }
    gotoxy(26,9);
    cout << "REINGRESE LA RAZON SOCIAL: " ;
    cin.ignore();
    cin.getline(nombreComercio, 50);

    reg.leerEnDisco(0);
    reg.setNombrecomercio(nombreComercio);
    reg.escribirEnDisco(0);
    gotoxy(26,10);
    cout << "-------------------------------------------------------------" << endl;
    gotoxy(26,24);
    cout << "RAZON SOCIAL MODIFICADA" << endl;

}


void modificarDireccionComercio()
{
    Comercio reg;
    char direccionComercio[50];
    if(reg.leerEnDisco(0)==false)
    {
        gotoxy(26,10);
        cout << "-------------------------------------------------------------" << endl;
        gotoxy(26,24);
        cout << "TODAVIA NO SE CARGARON DATOS DEL COMERCIO" << endl;
        return;
    }
    gotoxy(26,9);
    cout << "REINGRESE LA DIRECCION: ";
    cin.ignore();
    cin.getline(direccionComercio, 50);
    reg.leerEnDisco(0);


    reg.setDireccioncomercio(direccionComercio);
    reg.escribirEnDisco(0);
    gotoxy(26,10);
    cout << "-------------------------------------------------------------" << endl;
    gotoxy(26,24);
    cout << "DIRECCION MODIFICADA" << endl;

}

void modificarCuitComercio()
{
    Comercio reg;
    char cuit[15];
    if(reg.leerEnDisco(0)==false)
    {
        gotoxy(26,10);
        cout << "-------------------------------------------------------------" << endl;
        gotoxy(26,24);
        cout << "TODAVIA NO SE CARGARON DATOS DEL COMERCIO" << endl;
        return;
    }
    gotoxy(26,9);
    cout << "REINGRESE EL CUIT: " ;
    cin >> cuit;
    if(soloNumeros(cuit)==false)
    {
        gotoxy(26,10);
        cout << "CUIT CON FORMATO INCORRECTO" <<endl;
        return;
    }

    reg.leerEnDisco(0);
    reg.setCuit(cuit);
    reg.escribirEnDisco(0);
    gotoxy(26,10);
    cout << "-------------------------------------------------------------" << endl;
    gotoxy(26,24);
    cout << "CUIT MODIFICADO" << endl;


}
void modificarTelefonoComercio()
{
    Comercio reg;
    char telefono[15];
    if(reg.leerEnDisco(0)==false)
    {
        gotoxy(26,10);
        cout << "-------------------------------------------------------------" << endl;
        gotoxy(26,24);
        cout << "TODAVIA NO SE CARGARON DATOS DEL COMERCIO" << endl;
        return;
    }
    gotoxy(26,9);
    cout << "REINGRESE EL TELEFONO: " ;
    cin >> telefono;
    if(soloNumeros(telefono)==false)
    {
        gotoxy(26,10);
        cout << "TELEFONO CON FORMATO INCORRECTO" <<endl;
        return;
    }

    reg.leerEnDisco(0);
    reg.setTelefonocomercio(telefono);
    reg.escribirEnDisco(0);
    gotoxy(26,10);
    cout << "-------------------------------------------------------------" << endl;
    gotoxy(26,24);
    cout << "TELEFONO MODIFICADO" << endl;
}

/*FUNCION SOLO NUMEROS PARA VALIDACION*/
bool soloNumeros(const char *cadena)
{
    int i=0;
    while(cadena[i] != '\0')
    {
        if(!(cadena[i]>='0' && cadena[i] <= '9'))
        {
            return false;
        }
        i++;
    }
    return true;
}

/*FUNCION PARA VALIDAR PALABRAS CORRECTAS*/
int validarPalabra(char palabra[30])
{

    int i=0, sw=0, j;

    j=strlen(palabra);

    while(i<j && sw==0)
    {
        if(isalpha(palabra[i])!=0 || isspace(palabra[i])!=0)
        {
            i++;
        }
        else
        {
            sw=1;
        }

    }
    return sw;
}

/*FUNCION PARA RECUADRO*/
void recuadro(short x, short y, short ancho, short alto)
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



