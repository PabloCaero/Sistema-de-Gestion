#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "modo_ajustes.h"
#include "Usuario.h"

using namespace rlutil;
using namespace std;

void recuadro1(short x, short y, short ancho, short alto);

void ajustesVendedores()
{
    int opcion;
    Usuario reg;
    saveDefaultColor();

    do
    {
        setBackgroundColor(BLACK);
        recuadro1(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro1(25, 5, 62, 20);
        setColor(BLACK);
        gotoxy(26,7);
        cout<<"                     SISTEMA DE GESTION               "<<endl;
        gotoxy(26,8);
        cout<<"                    -[nombre del local]-              "<<endl;
        gotoxy(26,9);
        cout<<"                                                      "<<endl;
        gotoxy(26,10);
        cout<<" AJUSTES - VENDEDORES                                 "<<endl;
        gotoxy(26,11);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,12);
        cout<<" 1. CARGAR NUEVO VENDEDOR                             "<<endl;
        gotoxy(26,13);
        cout<<" 2. BUSCAR VENDEDOR POR ID                            "<<endl;
        gotoxy(26,14);
        cout<<" 3. BAJA/ALTA DE VENDEDOR                             "<<endl;
        gotoxy(26,15);
        cout<<" 4. VENDEDORES ACTIVOS                                "<<endl;
        gotoxy(26,16);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,17);
        cout<<" 0. VOLVER AL MENU AJUSTES                            "<<endl;
        gotoxy(26,18);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,19);
        cout<<"->                                                   "<<endl;
        gotoxy(29,19);
        cin >> opcion;

        resetColor();
        cls();


        saveDefaultColor();
        setBackgroundColor(BLACK);
        recuadro1(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro1(25, 5, 62, 20);
        setColor(BLACK);

        switch(opcion)
        {
        case 1:

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
                cout << "ID DE VENDEDOR REPETIDO" <<endl;
            }
            resetColor();
            anykey();
            break;
        case 2:
            int id;

            gotoxy(26,7);
            cout << "                   BUSCAR VENDEDOR POR ID" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            gotoxy(26,9);
            cout << "ID DE VENDEDOR: ";
            cin >> id;
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
            else
            {
                gotoxy(26,10);
                cout << "NO EXISTE LO BUSCADO" << endl;
            }
            resetColor();
            anykey();
            break;
        case 3:

            gotoxy(26,7);
            cout << "                   BUSCAR VENDEDOR POR ID" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            altabajaVendedor();
            resetColor();
            anykey();
            break;
        case 4:
            listadoVendedoresxID();
            anykey();
            break;
        case 0:
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

/*FUNCION PARA RECUADRO*/
void recuadro1(short x, short y, short ancho, short alto)
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

