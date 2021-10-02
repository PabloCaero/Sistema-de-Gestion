#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "modo_ajustes.h"
#include "Proveedor.h"
#include "Comercio.h"
#include "Fecha.h"
using namespace rlutil;
using namespace std;

void recuadro(short x, short y, short ancho, short alto);
bool soloNumeros(const char *cadena);

void ajustesProveedores()
{
    Proveedor reg;
    Comercio comercio;

    char opcion[1];
    saveDefaultColor();

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
        cout<<" \tAJUSTES - PROVEEDORES                                "<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,13);
        cout<<" \t1. CARGAR NUEVO PROVEEDOR                            "<<endl;
        gotoxy(26,14);
        cout<<" \t2. BUSCAR PROVEEDOR POR DNI                          "<<endl;
        gotoxy(26,15);
        cout<<" \t3. BAJA/ALTA DE PROVEEDOR                            "<<endl;
        gotoxy(26,16);
        cout<<" \t4. LISTADO DE PROVEEDORES                            "<<endl;
        gotoxy(26,17);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,18);
        cout<<" \t0. VOLVER AL MENU AJUSTES                            "<<endl;
        gotoxy(26,19);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,20);
        cout<<"\t->                                                   "<<endl;
        gotoxy(35,20);
        cin >> opcion;

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
            gotoxy(26,7);
            cout << "                    CARGAR NUEVO PROVEEDOR" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            if(cargarNuevoProveedor())
            {
                gotoxy(26,24);
                cout << "PROVEEDOR AGREGADO EXITOSAMENTE" <<endl;
            }
            resetColor();
            anykey();
            break;
        case '2':
            char dni[11];

            gotoxy(26,7);
            cout << "                  BUSCAR PROVEEDOR POR DNI" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            gotoxy(26,9);
            cout << "DNI DE PROVEEDOR: ";
            cin >> dni;
            if(soloNumeros(dni)==false)
            {
                gotoxy(26,10);
                cout << "DNI CON FORMATO INCORRECTO" <<endl;
                resetColor();
                anykey();
                break;
            }
            int pos;
            pos = buscarProveedorxDNI(dni);
            if(pos >= 0)
            {
                if(reg.leerEnDisco(pos))
                {
                    if(reg.getEstado())
                    {
                        gotoxy(26,10);
                        cout << "APELLIDO : " << reg.getApellido() << endl;
                        gotoxy(26,11);
                        cout << "NOMBRE   : " << reg.getNombre() << endl;
                        gotoxy(26,12);
                        cout << "DIRECCION: " << reg.getDireccion() << endl;
                        gotoxy(26,13);
                        cout << "TELEFONO : " << reg.getTelefono() << endl;
                        gotoxy(26,14);
                        cout << "ESTADO   : ACTIVO" << endl;
                    }
                    else
                    {
                        gotoxy(26,10);
                        cout << "APELLIDO : " << reg.getApellido() << endl;
                        gotoxy(26,11);
                        cout << "NOMBRE   : " << reg.getNombre() << endl;
                        gotoxy(26,12);
                        cout << "DIRECCION: " << reg.getDireccion() << endl;
                        gotoxy(26,13);
                        cout << "TELEFONO : " << reg.getTelefono() << endl;
                        gotoxy(26,14);
                        cout << "ESTADO   : INACTIVO" << endl;
                    }
                }
            }
            else
            {
                gotoxy(26,10);
                cout << "NO EXISTE LO BUSCADO" << endl;
            }
            resetColor();
            anykey();
            break;
        case '3':
            gotoxy(26,7);
            cout << "                 ALTA/BAJA PROVEEDOR POR DNI" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            altabajaProveedor();
            resetColor();
            anykey();
            break;
        case '4':
            listadoProveedores();
            anykey();
            break;
        case '0':
            resetColor();
            return;
            break;
        default:
            setColor(RED);
            gotoxy(26,7);
            cout << "                   >>OPCION INCORRECTA<<" << endl;
            anykey();
            setColor(BLACK);
            resetColor();
            break;
        }

        cls();

    }
    while(opcion != 0);



    return;


}

