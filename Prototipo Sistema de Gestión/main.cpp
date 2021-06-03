#include <iostream>
#include "funciones.h"
#include "rlutil.h"

using namespace rlutil;
using namespace std;

void recuadro(short x, short y, short ancho, short alto);

int main()
{
    saveDefaultColor();
    int opcion;

    do
    {
        setBackgroundColor(BLACK);
        recuadro(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro(25, 5, 62, 20);
        setColor(BLACK);
        gotoxy(26,7);
        cout<<"                     SISTEMA DE GESTION               "<<endl;
        gotoxy(26,8);
        cout<<"                    -[nombre del local]-              "<<endl;
        gotoxy(26,9);
        cout<<"                                                      "<<endl;
        gotoxy(26,10);
        cout<<" MENU PRINCIPAL                                       "<<endl;
        gotoxy(26,11);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,12);
        cout<<" 1. MODO VENTAS                                       "<<endl;
        gotoxy(26,13);
        cout<<" 2. MODO CONSULTAS                                    "<<endl;
        gotoxy(26,14);
        cout<<" 3. AJUSTES                                           "<<endl;
        gotoxy(26,15);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,16);
        cout<<" 0. SALIR DEL PROGRAMA                                "<<endl;
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
            setBackgroundColor(BLACK);
            recuadro(23, 4, 66, 22);
            setBackgroundColor(WHITE);
            recuadro(25, 5, 62, 20);
            setColor(BLACK);
            gotoxy(26,7);
            cout << "                 --FUNCION NO DISPONIBLE--" << endl;
            resetColor();
            anykey();
            //modoVentas();
            break;
        case 2:
            setBackgroundColor(BLACK);
            recuadro(23, 4, 66, 22);
            setBackgroundColor(WHITE);
            recuadro(25, 5, 62, 20);
            setColor(BLACK);
            gotoxy(26,7);
            cout << "                 --FUNCION NO DISPONIBLE--" << endl;
            resetColor();
            anykey();
            //modoConsultas();
            break;
        case 3:
            modoAjustes();
            break;
        case 0:
            return 0;
            break;
        default:
            setColor(RED);

            gotoxy(26,7);
            cout << "                   >>OPCION INCORRECTA<<" << endl;
            anykey();


            setColor(WHITE);
            resetColor();
            break;
        }

        cls();
    }
    while(opcion != 0);
    return 0;
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


