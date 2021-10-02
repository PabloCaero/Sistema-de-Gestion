#ifndef COMERCIO_H
#define COMERCIO_H


class Comercio
{
public:
    void setNombrecomercio(char *);
    void setDireccioncomercio(char *);
    void setCuit(char *);
    void setTelefonocomercio(char *);

    char * getNombrecomercio();
    char * getDireccioncomercio();
    char * getCuit();
    char * getTelefonocomercio();

    bool leerEnDisco(int);
    bool escribirEnDisco();
    bool escribirEnDisco(int);

private:
    char _nombreComercio[50];
    char _direccionComercio[50];
    char _telefonoComercio[15];
    char _cuit[15];




};

#endif // COMERCIO_H
