#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "modo_ajustes.h"
#include "Usuario.h"
#include "Comercio.h"
#include "Fecha.h"

using namespace rlutil;
using namespace std;

void ajustesVendedores()
{
    char opcion;
    Usuario reg;
    Comercio comercio;
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
        cout<<" \tAJUSTES - VENDEDORES                                 "<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,13);
        cout<<" \t1. CARGAR NUEVO VENDEDOR                             "<<endl;
        gotoxy(26,14);
        cout<<" \t2. BUSCAR VENDEDOR POR ID                            "<<endl;
        gotoxy(26,15);
        cout<<" \t3. BAJA/ALTA DE VENDEDOR                             "<<endl;
        gotoxy(26,16);
        cout<<" \t4. LISTADO DE VENDEDORES                             "<<endl;
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

        switch(opcion)
        {
        case '1':

            gotoxy(26,7);
            cout << "                    CARGAR NUEVO VENDEDOR" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            if(cargarNuevoVendedor())
            {
                gotoxy(26,24);
                cout << "VENDEDOR AGREGADO EXITOSAMENTE" <<endl;
            }
            else
            {
                gotoxy(26,24);
                cout << "PARAMETRO INCORRECTO O ID DE VENDEDOR REPETIDO" <<endl;
            }
            resetColor();
            anykey();
            break;
        case '2':
            int id;

            gotoxy(26,7);
            cout << "                   BUSCAR VENDEDOR POR ID" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            gotoxy(26,9);
            cout << "ID DE VENDEDOR: ";
            cin >> id;
            int pos;
            pos = buscarVendedorxID(id);
            if(pos >= 0)
            {
                if(reg.leerEnDisco(buscarVendedorxID(id)))
                {
                    if(reg.getEstado())
                    {
                        gotoxy(26,10);
                        cout << "APELLIDO: " << reg.getApellido() << endl;
                        gotoxy(26,11);
                        cout << "NOMBRE  : " << reg.getNombre() << endl;
                        gotoxy(26,12);
                        cout << "ESTADO  : ACTIVO" << endl;
                    }
                    else
                    {
                        gotoxy(26,10);
                        cout << "APELLIDO: " << reg.getApellido() << endl;
                        gotoxy(26,11);
                        cout << "NOMBRE  : " << reg.getNombre() << endl;
                        gotoxy(26,12);
                        cout << "ESTADO  : INACTIVO" << endl;
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
            cout << "                   BUSCAR VENDEDOR POR ID" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            altabajaVendedor();
            resetColor();
            anykey();
            break;
        case '4':
            listadoVendedoresxID();
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


