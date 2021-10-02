#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "modo_ajustes.h"
#include "Comercio.h"
#include "Fecha.h"
using namespace rlutil;
using namespace std;

void recuadro(short x, short y, short ancho, short alto);

void ajustesArticulos()
{
    Fecha actual;
    char opcion[1];
    Comercio comercio;
    saveDefaultColor();

    do
    {
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
        cout<<" \tAJUSTES - ARTICULOS                                  "<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,13);
        cout<<" \t1. CARGAR ARTICULO NUEVO                             "<<endl;
        gotoxy(26,14);
        cout<<" \t2. AGREGAR STOCK                                     "<<endl;
        gotoxy(26,15);
        cout<<" \t3. BAJA/ALTA DE ARTICULO                             "<<endl;
        gotoxy(26,16);
        cout<<" \t4. LISTADO DE ARTICULOS                              "<<endl;
        gotoxy(26,17);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,18);
        cout<<" \t0. VOLVER AL MENU AJUSTES                            "<<endl;
        gotoxy(26,19);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,20);
        cout<<"\t->                                                   "<<endl;
        gotoxy(35,20);
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

            gotoxy(26,7);
            cout << "                    CARGAR ARTICULO NUEVO" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            if(cargarNuevoArticulo())
            {
                gotoxy(26,24);
                cout << "ARTICULO CARGADO EXITOSAMENTE" << endl;
            }
            else
            {
                gotoxy(26,24);
                cout << "PARAMETRO INCORRECTO O ARTICULO CON CODIGO REPETIDO " << endl;
            }
            resetColor();
            anykey();
            break;

        case '2':

            gotoxy(26,7);
            cout << "                       AGREGAR STOCK" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            agregarStock();
            resetColor();
            anykey();
            break;
        case '3':

            gotoxy(26,7);
            cout << "                   ALTA/BAJA DE ARTICULO" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            altabajaArticulo();
            resetColor();
            anykey();
            break;
        case '4':
            listadoArticulosxID();
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
        Fecha actual;
    }
    while(opcion != 0);



    return;


}

