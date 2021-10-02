#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "modo_ajustes.h"
#include "Comercio.h"
#include "Fecha.h"

using namespace rlutil;
using namespace std;

void recuadro(short x, short y, short ancho, short alto);

void ajustesComercio()
{
    char opcion[1];
    saveDefaultColor();
    Comercio comercio;


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
        cout<<" \tAJUSTES - DATOS DEL COMERCIO                         "<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------                            "<<endl;
        if(comercio.leerEnDisco(0)==true)
        {
            gotoxy(26,13);
            cout<<" \t1. MOSTRAR DATOS DEL COMERCIO                        "<<endl;
        }
        else
        {
            gotoxy(26,13);
            cout<<" \t1. CARGAR DATOS DEL COMERCIO                         "<<endl;
        }
        gotoxy(26,14);
        cout<<" \t2. MODIFICAR CUIT                                    "<<endl;
        gotoxy(26,15);
        cout<<" \t3. MODIFICAR RAZON SOCIAL                            "<<endl;
        gotoxy(26,16);
        cout<<" \t4. MODIFICAR DIRECCION                               "<<endl;
        gotoxy(26,17);
        cout<<" \t5. MODIFICAR TELEFONO                                "<<endl;
        gotoxy(26, 18);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,19);
        cout<<" \t0. VOLVER AL MENU AJUSTES                            "<<endl;
        gotoxy(26,20);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,21);
        cout<<"\t->                                                   "<<endl;
        gotoxy(35,21);
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
            if(comercio.leerEnDisco(0)==false)
            {
                gotoxy(26,7);
                cout << "                 CARGAR DATOS DE COMERCIO" << endl;
            }
            else
            {
                gotoxy(26,7);
                cout << "                    DATOS DEL COMERCIO" << endl;
            }
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            if(comercio.leerEnDisco(0)==false)
            {
                if(cargarDatosComercio())
                {
                    gotoxy(26,24);
                    cout << "DATOS DE COMERCIO CARGADO EXITOSAMENTE" << endl;
                }
                else
                {
                    gotoxy(26,24);
                    cout << "NO SE PUDIERON CARGAR LOS DATOS" << endl;
                }
            }
            else
            {
                gotoxy(26,9);
                cout << "RAZON SOCIAL: " << comercio.getNombrecomercio() << endl;
                gotoxy(26,10);
                cout << "CUIT        : " << comercio.getCuit()<< endl;
                gotoxy(26,11);
                cout << "DIRECCION   : " << comercio.getDireccioncomercio() << endl;
                gotoxy(26,12);
                cout << "TELEFONO    : " << comercio.getTelefonocomercio() << endl;

                gotoxy(26,24);
                cout << "PRESIONE UNA TECLA PARA CONTINUAR..."<<endl;
            }
            resetColor();
            anykey();
            break;

        case '2':

            gotoxy(26,7);
            cout << "                       MODIFICAR CUIT" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            modificarCuitComercio();
            resetColor();
            anykey();
            break;
        case '3':

            gotoxy(26,7);
            cout << "                   MODIFICAR RAZON SOCIAL" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            modificarNombreComercio();
            resetColor();
            anykey();
            break;
        case '4':

            gotoxy(26,7);
            cout << "                    MODIFICAR DIRECCION" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            modificarDireccionComercio();
            resetColor();
            anykey();
            break;
        case '5':

            gotoxy(26,7);
            cout << "                    MODIFICAR TELEFONO" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            modificarTelefonoComercio();
            resetColor();
            anykey();
            break;
        case '0':
            resetColor();
            return;
            break;
        default:
            setColor(RED);
            gotoxy(26,7);
            cout << ">>OPCION INCORRECTA<<" << endl;
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

