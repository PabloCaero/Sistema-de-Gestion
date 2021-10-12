#include<iostream>
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include "Articulo.h"
#include "Venta.h"
#include "Proveedor.h"
#include "Usuario.h"
#include "Comercio.h"
#include "DetalleVenta.h"
#include "Fecha.h"
#include "rlutil.h"
#include "modo_consultas.h"
#include "modo_ajustes.h"
#include "modo_ventas.h"

using namespace rlutil;
using namespace std;

void modoConsultas()
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
        cout<<" \tCONSULTAS"<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------"<<endl;
        gotoxy(26,13);
        cout<<" \t1. CONSULTA DE TICKET"<<endl;
        gotoxy(26,14);
        cout<<" \t2. REPORTE DE TRANSACCIONES POR FECHA"<<endl;
        gotoxy(26,15);
        cout<<" \t3. REPORTE DE RECAUDACION ANUAL"<<endl;
        gotoxy(26,16);
        cout<<" \t4. REPORTE DE RECAUDACION MENSUAL"<<endl;
        gotoxy(26,17);
        //cout<<" \t5. [Final 12/10/21] REPORTE"<<endl;
        gotoxy(26,18);
        cout<<" \t-------------------------"<<endl;
        gotoxy(26,19);
        cout<<" \t0. VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(26,20);
        cout<<" \t-------------------------"<<endl;
        gotoxy(26,21);
        cout<<"\t->"<<endl;
        gotoxy(35,21);
        cin >> opcion[0];

        resetColor();
        cls();


        switch(opcion[0])
        {
        case '1':
            consultaTicket();
            anykey();
            resetColor();
            break;
        case '2':
            reporteDetalleVentasxFecha();
            anykey();
            resetColor();
            break;
        case '3':
            reporteAnual();
            anykey();
            resetColor();
            break;
        case '4':
            reporteMensual();
            anykey();
            resetColor();
            break;
        case '5':
        reporteFinal();
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

void consultaTicket()
{
    int IDventa;
    Comercio comercio;
    Venta reg;
    Usuario user;

    gotoxy(34,2);
    cout << "CONSULTA DE TICKET";

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 4, 40, 2);

    gotoxy(25,5);
    cout << "TICKET: #";
    cin >> IDventa;

    int pos;
    pos = buscarVentaxID(IDventa);
    reg.leerEnDisco(pos);
    if(pos >= 0 && reg.getEstado()==true)
    {

        setBackgroundColor(BLACK);
        recuadro(23, 4, 40, 30);
        setBackgroundColor(WHITE);
        recuadro(25, 5, 36, 28);
        setColor(BLACK);


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

        //reg.leerEnDisco(buscarVentaxID(IDventa));  //LEO LA TRANSACCION RELACIONADA A IDVENTA
        user.leerEnDisco(buscarVendedorxID(reg.getIDUsuario()));


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
    else
    {
        gotoxy(33,5);
        cout << "NO EXISTE";
        anykey();
        return;
    }
}


void reporteDetalleVentasxFecha()
{

    DetalleVenta *vec;
    int dia;
    int mes;
    int anio;
    float totalRango;
    totalRango=0;

    gotoxy(49,2);
    cout << "REPORTE DE TRANSACCIONES POR FECHA";

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 4, 40, 2);

    gotoxy(25,5);
    cout << "DIA: ";
    cin >> dia;
    while(dia <= 0 || dia >=32)
    {
        gotoxy(30,5);
        cout << "FORMATO INCORRECTO";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> dia;
    }
    gotoxy(30,5);
    cout << "   ";
    gotoxy(25,5);
    cout << "MES: ";
    cin >> mes;
    while(mes <= 0 || mes >=13)
    {
        gotoxy(30,5);
        cout << "FORMATO INCORRECTO";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> mes;
    }
    gotoxy(30,5);
    cout << "   ";
    gotoxy(25,5);
    cout << "ANO: ";
    cin >> anio;
    while(anio <= 1900)
    {
        gotoxy(30,5);
        cout << "FORMATO INCORRECTO";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> anio;
    }

    int cant = contarDetalleVentas();
    vec = new DetalleVenta[cant];
    if(vec == NULL)
    {
        return;
    }

    Usuario user;
    Venta reg;


    leerDetalleVentas(vec, cant); //METE EN UN VECTOR DINAMICO CADA REGISTRO DEL ARCHIVO
    ordenarDetalleVentasxIDVenta(vec, cant);

    setBackgroundColor(BLACK);
    recuadro(23, 4, 85, 35);
    setBackgroundColor(WHITE);
    recuadro(25, 5, 81, 33);
    setColor(BLACK);
    gotoxy(26,7);
    cout << "TRANSACCIONES REALIZADAS\t\t\t\t\tFECHA: " << dia << "/"<< mes << "/"<< anio;
    gotoxy(26,8);
    cout << "--------------------------------------------------------------------------------" << endl;
    gotoxy(26,9);
    cout << "TICKET  " << "VENDEDOR/A\t  " << "\tHORA\t\t" << "ARTICULO\t"<<"CANT\t"<< "$TOTAL" << endl;
    gotoxy(26,10);
    cout << "--------------------------------------------------------------------------------" << endl;

    int y = 10;
    int i;
    for(i=0; i<cant; i++)
    {
        if(vec[i].getFecha().getAnio()==anio && vec[i].getFecha().getMes()==mes && vec[i].getFecha().getDia()==dia && vec[i].getEstado() == true)
        {
            y++;
            gotoxy(26,y);
            cout << "#" << vec[i].getIDVenta();
            gotoxy(34,y);
            reg.leerEnDisco(buscarVentaxID(vec[i].getIDVenta()));
            user.leerEnDisco(buscarVendedorxID(reg.getIDUsuario()));
            cout << user.getApellido()<<", "<<user.getNombre();
            gotoxy(57,y);
            cout << vec[i].getFecha().getHoras()<<":"<<vec[i].getFecha().getMinutos();
            gotoxy(73,y);
            cout << vec[i].getNombreArticulo();
            gotoxy(89,y);
            cout << vec[i].getCantidad();
            gotoxy(97,y);
            int total;
            total = vec[i].getCantidad() * vec[i].getPrecioVenta();
            cout << "$" << total;

            totalRango+=total;
        }

    }
    y++;
    gotoxy(26,y);
    cout << "--------------------------------------------------------------------------------" << endl;
    y++;
    gotoxy(80,y);
    cout << "TOTAL RECAUDADO: $" << totalRango;
    anykey();
    resetColor();
    delete vec;


}
void reporteAnual()
{

    DetalleVenta *vec;
    int anio;
    float totalAnio, total;
    totalAnio=0;

    gotoxy(49,2);
    cout << "RECAUDACION ANUAL";

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 4, 40, 2);

    gotoxy(25,5);
    cout << "ANO: ";
    cin >> anio;
    while(anio <= 1900)
    {
        gotoxy(30,5);
        cout << "FORMATO INCORRECTO";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> anio;
    }

    int cant = contarDetalleVentas();
    vec = new DetalleVenta[cant];
    if(vec == NULL)
    {
        return;
    }

    Venta reg;

    leerDetalleVentas(vec, cant); //METE EN UN VECTOR DINAMICO CADA REGISTRO DEL ARCHIVO
    ordenarDetalleVentasxIDVenta(vec, cant);


    int i;
    for(i=0; i<cant; i++)
    {
        if(vec[i].getFecha().getAnio()==anio && vec[i].getEstado() == true)
        {
            total = vec[i].getCantidad() * vec[i].getPrecioVenta();
            totalAnio+=total;
        }
    }

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 7, 50, 2);
    gotoxy(25,8);
    cout << "TOTAL RECAUDADO EN EL " << anio << ": $" << totalAnio;
    anykey();
    resetColor();
    delete vec;

}
void reporteMensual()
{
    DetalleVenta *vec;
    int mes;
    int anio;
    float totalMes, total;
    totalMes=0;

    gotoxy(49,2);
    cout << "RECAUDACION MENSUAL";

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 4, 40, 2);

    gotoxy(25,5);
    cout << "MES: ";
    cin >> mes;
    while(mes <= 0 || mes >=13)
    {
        gotoxy(30,5);
        cout << "FORMATO INCORRECTO";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> mes;
    }
    gotoxy(30,5);
    cout << "   ";
    gotoxy(25,5);
    cout << "ANO: ";
    cin >> anio;
    while(anio <= 1900)
    {
        gotoxy(30,5);
        cout << "FORMATO INCORRECTO";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> anio;
    }


    int cant = contarDetalleVentas();
    vec = new DetalleVenta[cant];
    if(vec == NULL)
    {
        return;
    }

    Venta reg;

    leerDetalleVentas(vec, cant); //METE EN UN VECTOR DINAMICO CADA REGISTRO DEL ARCHIVO
    ordenarDetalleVentasxIDVenta(vec, cant);


    int i;
    for(i=0; i<cant; i++)
    {
        if(vec[i].getFecha().getAnio()==anio && vec[i].getFecha().getMes()==mes && vec[i].getEstado() == true)
        {
            total = vec[i].getCantidad() * vec[i].getPrecioVenta();
            totalMes+=total;
        }
    }

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 7, 50, 2);
    gotoxy(25,8);
    cout << "TOTAL RECAUDADO EN EL MES " << mes << "/" << anio << ": $" << totalMes;
    anykey();
    resetColor();
    delete vec;
}

void reporteFinal()
{
    DetalleVenta *vec;
    Usuario vendedor;



    gotoxy(49,2);
    cout << "REPORTE FINAL 12/10/2021";

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 4, 40, 2);

    int legajo;
    int anio;
    float total;

    gotoxy(25,5);
    cout << "LEGAJO: ";
    cin >> legajo;
    while(buscarVendedorxID(legajo)==-1)
    {
        gotoxy(30,5);
        cout << "NO EXISTE VENDEDOR";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> legajo;
    }

    //EN CASO DE HABER MAS DE UNA CONDICION DE FILTRO
    gotoxy(30,5);
    cout << "                ";
    gotoxy(25,5);
    cout << "ANIO: ";
    cin >> anio;

    while(anio <= 1900)
    {
        gotoxy(30,5);
        cout << "FORMATO INCORRECTO";
        anykey();
        gotoxy(30,5);
        cout << "                  ";
        gotoxy(30,5);
        cin >> anio;
    }


    int cant = contarDetalleVentas();
    vec = new DetalleVenta[cant];
    if(vec == NULL)
    {
        return;
    }


    leerDetalleVentas(vec, cant); //METE EN UN VECTOR DINAMICO CADA REGISTRO DEL ARCHIVO
    ordenarDetalleVentasxIDVenta(vec, cant);


    int i;
    total = 0;
    for(i=0; i<cant; i++)
    {
        if(vec[i].getEstado() == true && vec[i].getIDVendedor()==legajo && vec[i].getFecha().getAnio()==2021)
        {
            total+=(vec[i].getPrecioVenta()*vec[i].getCantidad());
        }
    }

    saveDefaultColor();
    setBackgroundColor(BLACK);
    recuadro(23, 7, 70, 2);
    gotoxy(25,8);

    vendedor.leerEnDisco(buscarVendedorxID(legajo));


    cout << "EL TOTAL RECAUDADO POR " << vendedor.getNombre() << " " << vendedor.getApellido() << " EN EL ANIO " << anio << " FUE DE $" << total;
    anykey();
    resetColor();
    delete vec;
}


