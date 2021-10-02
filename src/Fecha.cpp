#include "rlutil.h"
#include <iostream>
#include <ctime>
using namespace rlutil;
using namespace std;
#include "Fecha.h"

Fecha::Fecha()
{
    time_t t, h;
    t = time(NULL);
    h = time(NULL);
    tm *f; //TM ASIGNACION DE CTIME¿?
    tm *g;
    f = localtime(&t);
    g = localtime(&h);

    _anio = f -> tm_year + 1900;
    _mes = f -> tm_mon + 1;
    _dia = f -> tm_mday;

    _horas = g -> tm_hour;
    _minutos = g -> tm_min;
    _segundos = g -> tm_sec;


    /*gotoxy(79,2);
    cout << _dia << "/" <<_mes << "/" << _anio << endl;
    int decimalcero_minuto;
    decimalcero_minuto = _minutos;

    gotoxy(82,3);
    cout << _horas;
    if(decimalcero_minuto <10)
    {
        cout << ":0" << _minutos << endl;
    }
    else
    {
        cout << ":" << _minutos << endl;
    }*/



}

int Fecha::getDia()
{
    return _dia;
}
void Fecha::setDia(int val)
{
    _dia = val;
}
int Fecha::getMes()
{
    return _mes;
}
void Fecha::setMes(int val)
{
    _mes = val;
}
int Fecha::getAnio()
{
    return _anio;
}
void Fecha::setAnio(int val)
{
    _anio = val;
}
int Fecha::getHoras()
{
    return _horas;
}
void Fecha::setHoras(int val)
{
    _horas = val;
}
int Fecha::getMinutos()
{
    return _minutos;
}
void Fecha::setMinutos(int val)
{
    _minutos = val;
}
int Fecha::getSegundos()
{
    return _segundos;
}
void Fecha::setSegundos(int val)
{
    _segundos = val;
}



void Fecha::mostrar()
{
    cout << _dia << "/" << _mes << "/" << _anio ;
}


