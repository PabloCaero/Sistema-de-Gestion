#include <iostream>
#include <cstring>

using namespace std;

#include "Comercio.h"

void Comercio::setNombrecomercio(char *nombreComercio)
{
    strcpy(_nombreComercio, nombreComercio);
}
void Comercio::setDireccioncomercio(char *direccionComercio)
{
    strcpy(_direccionComercio, direccionComercio);
}
void Comercio::setCuit(char *cuit)
{
    strcpy(_cuit, cuit);
}
void Comercio::setTelefonocomercio(char *telefonoComercio)
{
    strcpy(_telefonoComercio, telefonoComercio);
}

char *Comercio::getNombrecomercio()
{
    return _nombreComercio;
}
char *Comercio::getDireccioncomercio()
{
    return _direccionComercio;
}
char *Comercio::getCuit()
{
    return _cuit;
}
char *Comercio::getTelefonocomercio()
{
    return _telefonoComercio;
}

bool Comercio::leerEnDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("datoscomercio.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Comercio)*pos, SEEK_SET) ;
    lectura = fread(this, sizeof(Comercio), 1, p);
    fclose(p);
    return lectura;
}
bool Comercio::escribirEnDisco()
{
    bool guardo;
    FILE *p; //PUNTERO FILE
    p = fopen("datoscomercio.dat", "ab"); //ab: para grabar mas de un registro
    if(p==NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Comercio), 1, p) ; //THIS ES LA DIRECCION DE MEMORIA QUE LLAMA A ESTE METODO
    fclose(p);
    return guardo;
}
bool Comercio::escribirEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p=fopen("datoscomercio.dat", "rb+") ; //LEE Y SOBRESCRIBIR
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Comercio)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Comercio), 1, p);
    fclose(p);
    return guardo;
}
