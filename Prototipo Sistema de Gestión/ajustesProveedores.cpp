#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "modo_ajustes.h"
#include "Proveedor.h"
using namespace rlutil;
using namespace std;

void recuadro2(short x, short y, short ancho, short alto);
bool soloNumeros(const char *cadena);

void ajustesProveedores()
{
    Proveedor reg;
    int opcion;
    saveDefaultColor();

    do
    {
        setBackgroundColor(BLACK);
        recuadro2(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro2(25, 5, 62, 20);
        setColor(BLACK);
        gotoxy(26,7);
        cout<<"                     SISTEMA DE GESTION               "<<endl;
        gotoxy(26,8);
        cout<<"                    -[nombre del local]-              "<<endl;
        gotoxy(26,9);
        cout<<"                                                      "<<endl;
        gotoxy(26,10);
        cout<<" AJUSTES - PROVEEDORES                                "<<endl;
        gotoxy(26,11);
        cout<<" -------------------------                            "<<endl;
        gotoxy(26,12);
        cout<<" 1. CARGAR NUEVO PROVEEDOR                            "<<endl;
        gotoxy(26,13);
        cout<<" 2. BUSCAR PROVEEDOR POR DNI                          "<<endl;
        gotoxy(26,14);
        cout<<" 3. BAJA/ALTA DE PROVEEDOR                            "<<endl;
        gotoxy(26,15);
        cout<<" 4. PROVEEDORES ACTIVOS                               "<<endl;
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
        recuadro2(23, 4, 66, 22);
        setBackgroundColor(WHITE);
        recuadro2(25, 5, 62, 20);
        setColor(BLACK);


        switch(opcion)
        {
        case 1:
            gotoxy(26,7);
            cout << "                    CARGAR NUEVO PROVEEDOR" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            if(cargarNuevoProveedor())
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
            char dni[11];

            gotoxy(26,7);
            cout << "                  BUSCAR PROVEEDOR POR DNI" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            gotoxy(26,9);
            cout << "DNI DE PROVEEDOR: ";
            cin >> dni;
            if(reg.leerEnDisco(buscarProveedorxDNI(dni)))
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
                    cout << "ESTADO  : ACTIVO" << endl;
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
            cout << "                  BUSCAR PROVEEDOR POR DNI" << endl;
            gotoxy(26,8);
            cout << "-------------------------------------------------------------" << endl;
            altabajaProveedor();
            resetColor();
            anykey();
            break;
        case 4:
            listadoProveedores();
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
void recuadro2(short x, short y, short ancho, short alto)
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

