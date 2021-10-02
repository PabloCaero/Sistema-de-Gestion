#include <iostream>
#include "Fecha.h"
#include "Comercio.h"
#include "funciones.h"
#include "modo_ajustes.h"
#include "rlutil.h"


using namespace rlutil;
using namespace std;


int main()
{
    Comercio comercio;
    saveDefaultColor();
    char opcion[1];
    do
    {
        Fecha actual;
        setBackgroundColor(BLACK);
        recuadro(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        setColor(BLACK);
        recuadro(25, 5, 62, 20);
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
        cout<<" \tMENU PRINCIPAL                                       "<<endl;
        gotoxy(26,12);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,13);
        cout<<" \t1. MODO VENTAS                                       "<<endl;
        gotoxy(26,14);
        cout<<" \t2. MODO CONSULTAS                                    "<<endl;
        gotoxy(26,15);
        cout<<" \t3. AJUSTES                                           "<<endl;
        gotoxy(26,16);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,17);
        cout<<" \t0. SALIR DEL PROGRAMA                                "<<endl;
        gotoxy(26,18);
        cout<<" \t-------------------------                            "<<endl;
        gotoxy(26,19);
        cout<<"\t->                                                   "<<endl;
        gotoxy(35,19);
        cin >> opcion[0];

        resetColor();
        cls();


        switch(opcion[0])
        {
        case '1':
            modoVentas();
            resetColor();
            break;
        case '2':
            modoConsultas();
            break;
        case '3':
            modoAjustes();
            break;
        case '0':
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
