#include<iostream>
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include "Articulo.h"
#include "Proveedor.h"
#include "Usuario.h"
#include "Comercio.h"
#include "Articulo.h"
#include "Venta.h"
#include "DetalleVenta.h"
#include "Fecha.h"
#include "rlutil.h"
#include "modo_ventas.h"
#include "modo_ajustes.h"


using namespace rlutil;
using namespace std;


void modoVentas()
{
    //LOG IN DEL VENDEDOR/USUARIO
    saveDefaultColor();
    int IDUsuario;
    Usuario user;
    setBackgroundColor(BLACK);
    recuadro(23, 4, 66, 22);
    setBackgroundColor(WHITE);
    recuadro(25, 5, 62, 20);
    setColor(BLACK);
    gotoxy(26,8);
    cout << "INGRESO AL MODO VENTAS" << endl;
    gotoxy(26,9);
    cout<<"-------------------------------------------------------------"<<endl;
    gotoxy(35,15);
    cout << "INGRESE SU ID DE USUARIO: ";
    cin >> IDUsuario;
    if(buscarVendedorxID(IDUsuario) >= 0)
    {
        user.leerEnDisco(buscarVendedorxID(IDUsuario));
        gotoxy(35,16);
        cout << "BIENVENIDO/A, " << user.getNombre() << endl;
        anykey();
        resetColor();
        cls();

    }
    else
    {
        gotoxy(35,16);
        cout << "ID DE USUARIO INEXISTENTE" << endl;
        anykey();
        resetColor();
        cls();
        return;
    }

    saveDefaultColor();
    Comercio comercio;

    bool caja;
    caja = true;

    //MENU DE VENTAS

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
        if(caja)
        {
            gotoxy(58,7);
            cout << "CAJA      : ABIERTA";
        }
        else
        {
            gotoxy(58,7);
            cout << "CAJA      : CERRADA";
        }
        gotoxy(58,8);
        cout<<"VENDEDOR/A: " << user.getApellido() << ", " << user.getNombre();
        gotoxy(26,9);
        cout<<"-------------------------------------------------------------"<<endl;
        gotoxy(26,11);
        cout<<" \tVENTAS  "<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------"<<endl;
        gotoxy(26,13);
        cout<<" \t1. PANTALLA DE VENTAS"<<endl;
        gotoxy(26,14);
        cout<<" \t2. LISTADO DE ARTICULOS DISPONIBLES"<<endl;
        gotoxy(26,15);
        cout<<" \t3. CERRAR CAJA"<<endl;
        gotoxy(26,16);
        cout<<" \t-------------------------"<<endl;
        gotoxy(26,17);
        cout<<" \t0. VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(26,18);
        cout<<" \t-------------------------"<<endl;
        gotoxy(26,19);
        cout<<"\t->"<<endl;
        gotoxy(35,19);
        cin >> opcion[0];

        resetColor();
        cls();

        saveDefaultColor();
        setBackgroundColor(BLACK);
        recuadro(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro(25, 5, 62, 20);
        setColor(BLACK);

        switch(opcion[0])
        {

        case '1':
            if(caja)
            {
                pantallaVenta(IDUsuario);
            }
            else
            {
                gotoxy(26,11);
                cout << "CAJA CERRADA, REGRESE AL MENU PRINCIPAL..." << endl;
                anykey();
            }
            resetColor();
            break;
        case '2':
            listadoArticulosxID(); //REUTILIZO LA FUNCION DEL MODO JUSTES>ARTICULOS
            anykey();
            resetColor();
            break;
        case '3':
            if(caja)
            {
                gotoxy(26,9);
                cout << "DESEA CERRAR LA CAJA? (0: SI / 1: NO): ";
                cin >> caja;
                if(caja==false)
                {
                    gotoxy(26,10);
                    cout << "-------------------------------------------------------------" << endl;
                    gotoxy(26,11);
                    cout << "CAJA CERRADA, REGRESE AL MENU PRINCIPAL..." << endl;
                }
                else
                {
                    gotoxy(26,10);
                    cout << "-------------------------------------------------------------" << endl;
                    gotoxy(26,11);
                    cout << "NO SE REALIZARON CAMBIOS" << endl;
                }
            }
            else
            {
                gotoxy(26,11);
                cout << "CAJA CERRADA, REGRESE AL MENU PRINCIPAL..." << endl;
            }
            anykey();
            resetColor();
            break;
        case '0':
            if(caja==false)
            {
                return;
            }
            else
            {
                gotoxy(26,11);
                cout << "CIERRE LA CAJA PARA VOLVER AL MENU PRINCIPAL..." << endl;
                anykey();
                resetColor();
            }
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
    resetColor();
    return;
}

/*FUNCIONES DE LA PANTALLA DE VENTAS*/
void pantallaVenta(int IDUsuario)
{

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 4, 83, 32);
    setBackgroundColor(WHITE);
    recuadro(25, 5, 79, 30);
    setColor(BLACK);

    int codArt;
    int IDVenta; //TIENE QUE PODER GENERARSE DE FORMA AUTOMATICA
    int pos;
    int cantidad, cantidadTotal;
    int y1, y2;
    float totalParcial, total;
    bool numero_conseguido;
    numero_conseguido = false;
    IDVenta = 0;
    cantidadTotal = 0;
    int pos_IDVenta;

    Fecha f;
    Venta reg;
    Articulo art;


    y1=9;
    y2=10;

    /*GENERACION DEL TICKET O IDVENTA*/
    while(numero_conseguido == false)
    {
        pos_IDVenta = buscarVentaxID(IDVenta);
        if(pos_IDVenta >= 0)
        {
            reg.leerEnDisco(pos_IDVenta);
            if(reg.getEstado()==false)
            {
                numero_conseguido = true;
                reg.setIDVenta(IDVenta);
                reg.setEstado(true);
                reg.escribirEnDisco(pos_IDVenta);
            }
            else
            {
                IDVenta++;
            }

        }
        else
        {
            reg.setIDVenta(IDVenta);
            reg.escribirEnDisco();
            numero_conseguido = true;
        }
    }

    /*OPCIONES:*/
    /*1. FINALIZAR TRANSACCION*/  //ESTA OPCION DEBERIA PODER GUARDAR LA VENTA, EL DETALLE DE VENTA Y EL STOCK DISPONIBLE EN EL/LOS ARTICULO INDICADO E IR A UN MENU QUE PERMITA VER EL TICKET, ELEGIR EL MEDIO DE PAGO E IMPRIMIRLO
    /*0. CANCELAR TRANSACCION:*/  //ESTA OPCION NO DEBERIA MODIFICAR NADA
    int i, pos_asterisco_vertical = 6;
    for(i=0; i<29; i++)
    {
        gotoxy(69, pos_asterisco_vertical++);
        cout << "*";
    }

    gotoxy(71, 6);
    cout << "PANTALLA DE VENTAS";
    gotoxy(71, 7);
    cout << "TICKET: #" << IDVenta << endl;
    gotoxy(71, 8);
    cout << "*OPCIONES";
    gotoxy(71, 11);
    cout << "1. CERRAR TRANSACCION Y COBRAR";
    gotoxy(71, 12);
    cout << "0. CANCELAR Y VOLVER";



    totalParcial = 0;
    cantidad = 0;


    gotoxy(26,7);
    cout << "-------------------------------------------" << endl;
    gotoxy(26,8);
    cout << "Cant. x Precio Unit." << endl;
    gotoxy(26,9);
    cout << "Descripcion\t\t" << "Importe\t"<< endl;
    gotoxy(26,10);
    cout << "-------------------------------------------" << endl;
    gotoxy(26,6);
    cout << "ARTICULO / OPCION: ";
    cin >> codArt;
    if(codArt == 0) //SE VA DE LA PANTALLA
    {
        reg.leerEnDisco(buscarVentaxID(IDVenta));
        reg.setEstado(false); //REALIZA LA BAJA LOGICA DEL TICKET O IDVENTA, SERA UTILIZADO PARA EMITIR INFORMES. LOS QUE ESTEN EN "FALSE" NO SE DEBERIAN EMITIR EN PANTALLA
        reg.escribirEnDisco(buscarVentaxID(IDVenta));
        return;
    }
    total = 0;
    while(codArt !=0)
    {
        pos = buscarArticuloxID(codArt);
        art.leerEnDisco(pos);
        if(pos >= 0)
        {
            gotoxy(36,6);
            cout << "                   " << endl;

            gotoxy(26,6);
            cout << "CANTIDAD: ";
            cin >> cantidad;

            while(cantidad<=0)
            {
                gotoxy(36,6);
                cout << "CANTIDAD INCORRECTA" << endl;
                anykey();
                gotoxy(36,6);
                cout << "                   " << endl;
                gotoxy(26,6);
                cout << "CANTIDAD: ";
                cin >> cantidad;
            }

            if(cantidad <= art.getStock())//VERIFICA SI HAY STOCK DISPONIBLE O NO
            {
                cantidadTotal += cantidad;
                y1+=2;
                y2+=2;
                gotoxy(29,y1);
                cout << cantidad;
                gotoxy(31,y1);
                cout << " x $" << art.getPrecioVenta();
                gotoxy(26,y2);
                cout << art.getNombreArticulo();
                gotoxy(49,y2);
                totalParcial = cantidad * art.getPrecioVenta();
                cout << "$" << totalParcial;

                total += totalParcial;

                gotoxy(71,23);
                cout << "TOTAL: $" << total << endl;

                DetalleVenta venta;
                venta.setIDVendedor(IDUsuario);
                venta.setCantidad(cantidad);
                venta.setIDArticulo(art.getIDArticulo()); //SETEO IDARTICULO DE LA CLASE ARTICULO Y LO ASIGNO A IDARTICULO DE LA CLASE DETALLEVENTA
                venta.setPrecioVenta(art.getPrecioVenta()); //SETEO PRECIOVENTA DE LA CLASE ARTICULO Y LO ASIGNO A PRECIOVENTA DE LA CLASE DETALLEVENTA
                venta.setIDVenta(IDVenta);
                venta.setNombreArticulo(art.getNombreArticulo());
                venta.setFecha(f);
                venta.setEstado(true);
                venta.escribirEnDisco();
            }
            else
            {
                gotoxy(36,6);
                cout << "NO HAY STOCK DISPONIBLE" << endl;
                anykey();
                gotoxy(36,6);
                cout << "                       " << endl;
            }
        }
        else
        {
            if(codArt == 1) //OPCION DE CERRAR TRANSACCION DE LA PANTALLA DE VENTAS
            {
                if(total > 0)
                {
                    cls();
                    resetColor();
                    reg.setFecha(f);
                    reg.setIDUsuario(IDUsuario);
                    reg.setTotal(total);
                    reg.setCantidadTotal(cantidadTotal);
                    reg.setEstado(true);
                    reg.escribirEnDisco(buscarVentaxID(IDVenta));

                    resetColor();
                    cls();
                    plantillaTicket(IDVenta);  //ACA SE CERRARIA LA TRANSACCION
                    return; //VUELVE AL MENU DE VENTAS PARA GENERAR OTRA TRANSACCION
                }
            }
            gotoxy(45,6);
            cout << "NO EXISTE EL ARTICULO" << endl;
            anykey();
            gotoxy(45,6);
            cout << "                     " << endl;
        }


        gotoxy(26,6);
        cout << "ARTICULO / OPCION: ";
        cin >> codArt;
    }


    //SE RECORRE EL ARCHIVO DE DETALLE VENTAS Y SE REALIZA LA BAJA LOGICA DE LAS TRANSACCIONES CANCELADAS
    if(codArt==0)  //CON ESTO SE CANCELARIA EL TICKET
    {
        DetalleVenta *vec;
        int cant;
        cant = contarDetalleVentas();
        vec = new DetalleVenta[cant] ;
        if(vec == NULL)
        {
            return;
        }

        leerDetalleVentas(vec, cant);
        for(i=0; i<cant; i++)
        {
            if(vec[i].getIDVenta()==IDVenta)
            {
                vec[i].setEstado(false);
                vec[i].escribirEnDisco(i);
            }
        }

        reg.leerEnDisco(buscarVentaxID(IDVenta));
        reg.setEstado(false); //REALIZA LA BAJA LOGICA DEL TICKET O IDVENTA, SERA UTILIZADO PARA EMITIR INFORMES
        reg.escribirEnDisco(buscarVentaxID(IDVenta));
        return;
    }

    resetColor();
    cls();
    anykey();
}

int buscarVentaxID(int IDVenta)
{
    Venta reg;
    int i=0;
    while(reg.leerEnDisco(i))
    {
        if(IDVenta == reg.getIDVenta())
        {
            return i;
        }
        i++;
    }
    return -1;//NUNCA ENCONTRO EL REGISTRO
}

int buscarDetalleVentaxIDArticulo(int IDArticulo)
{
    DetalleVenta reg;
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

void leerDetalleVentas(DetalleVenta *vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerEnDisco(i);
    }
}

void plantillaTicket(int IDventa)
{
    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 4, 40, 30);
    setBackgroundColor(WHITE);
    recuadro(25, 5, 36, 28);
    setColor(BLACK);
    Comercio comercio;
    Venta reg;
    Usuario user;

    int cant = contarDetalleVentas(); //TENGO CUANTOS DETALLES DE VENTA SON
    if(cant == 0)
    {
        gotoxy(26,7);
        cout << "NO HAY DETALLE DE VENTAS CARGADOS" << endl;
        return;
    }
    DetalleVenta *vec;
    vec = new DetalleVenta[cant] ;
    if(vec == NULL)
    {
        return;
    }

    leerDetalleVentas(vec, cant);

    int i;

    reg.leerEnDisco(buscarVentaxID(IDventa));  //LEO LA TRANSACCION RELACIONADA A IDVENTA
    user.leerEnDisco(buscarVendedorxID(reg.getIDUsuario()));


    //ACA SE DEBERIAN DEDUCIR LOS STOCKS DE ARTICULO
    for(i=0; i<cant; i++)
    {
        if(vec[i].getIDVenta() == reg.getIDVenta() && vec[i].getEstado()==true)
        {
            Articulo art;  //HAY QUE DEDUCIR STOCK
            int pos = buscarArticuloxID(vec[i].getIDArticulo());
            if(pos >= 0)
            {
                art.leerEnDisco(pos);
                art.setStock(art.getStock() - vec[i].getCantidad());
                if(art.escribirEnDisco(pos))
                {
                    /*cout << "SE GUARDO EL REGISTRO " << art.getStock() << endl;
                    anykey(); */
                }
                else
                {
                    cout << "NO SE GUARDO NADA"  << endl;
                    anykey();
                }
            }
        }
    }

    //ACA SE DEBERIA RECORRER EL ARCHIVO DETALLE PARA PLASMAR EN EL TICKET

    comercio.leerEnDisco(0);
    gotoxy(26,7);
    cout << comercio.getNombrecomercio() << endl;
    gotoxy(26,8);
    cout << "Cuit: " << comercio.getCuit() << endl;
    gotoxy(26,9);
    cout << comercio.getDireccioncomercio() << endl;
    gotoxy(26,10);
    cout << "Prov. de Buenos Aires" << endl;
    gotoxy(26,11);
    cout << "        A Consumidor Final" << endl;
    gotoxy(26,12);
    cout << "Numero de Transaccion: #" << IDventa <<endl;
    gotoxy(26,13);
    cout << "Fecha: " << reg.getFecha().getDia() <<"/"<< reg.getFecha().getMes() <<"/"<< reg.getFecha().getAnio() <<"        Hora: " << reg.getFecha().getHoras() <<":" << reg.getFecha().getMinutos();
    gotoxy(26,14);
    cout << "Vendedor/a: " << user.getNombre();
    gotoxy(26,15);
    cout << "Cant. Articulos: " << reg.getCantidadTotal() << endl;
    gotoxy(26,16);
    cout << "-----------------------------------"<<endl;
    gotoxy(26,17);
    cout << "ITEM:\t" << "      CANT:\t" << "\b\bPU:\t" << "\b\b\bSUBTOT:" << endl;


    int y;
    float subtotal;
    y = 18;


    for(i=0; i<cant; i++)
    {
        subtotal = 0;
        if(vec[i].getIDVenta() == IDventa && vec[i].getEstado()==true)
        {

            gotoxy(26,y);
            cout << vec[i].getNombreArticulo();
            gotoxy(39,y);
            cout << vec[i].getCantidad();
            gotoxy(47,y);
            cout << "$" <<vec[i].getPrecioVenta();
            subtotal = (vec[i].getCantidad()*vec[i].getPrecioVenta());
            gotoxy(54,y);
            cout << "$" << subtotal;
            y++;


        }

    }
    y++;
    gotoxy(47,y);
    cout << "TOTAL: $" << reg.getTotal() << endl;
    y++;
    gotoxy(33,y);
    cout << "Gracias por su compra" <<endl;


    anykey();

    delete vec;

}


void ordenarDetalleVentasxIDVenta(DetalleVenta *vec, int tam)
{
    int i, j, posMin;

    for(i=0; i<tam-1; i++) //LE RESTO
    {
        posMin = i;
        for(j=i+1; j<tam; j++)
        {
            if(vec[j].getIDVenta()<vec[posMin].getIDVenta()) //CAMBIANDO EL SIGNO ORDENAMOS DE MENOR A MAYOR
            {
                posMin = j;
            }
        }
        DetalleVenta aux = vec[i];
        vec[i] = vec[posMin];
        vec[posMin] = aux;
    }
}

void ordenarVentasxIDVenta(Venta *vec, int tam)
{
    int i, j, posMin;

    for(i=0; i<tam-1; i++) //LE RESTO
    {
        posMin = i;
        for(j=i+1; j<tam; j++)
        {
            if(vec[j].getIDVenta()<vec[posMin].getIDVenta()) //CAMBIANDO EL SIGNO ORDENAMOS DE MENOR A MAYOR
            {
                posMin = j;
            }
        }
        Venta aux = vec[i];
        vec[i] = vec[posMin];
        vec[posMin] = aux;
    }
}

void leerVentas(Venta *vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].leerEnDisco(i);
    }
}


