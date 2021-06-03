
#include <iostream>
using namespace std;
#include "Fecha.h"

Fecha::Fecha()
{
    //ctor
}

int Fecha::getDia() { return _dia; }
void Fecha::setDia(int val) { _dia = val; }
int Fecha::getMes() { return _mes; }
void Fecha::setMes(int val) { _mes = val; }
int Fecha::getAnio() { return _anio; }
void Fecha::setAnio(int val) { _anio = val; }
void Fecha::mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}

