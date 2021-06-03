#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        int getDia();
        void setDia(int val);
        int getMes();
        void setMes(int val);
        int getAnio();
        void setAnio(int val);
        void mostrar();

    private:
        int _dia;
        int _mes;
        int _anio;
};

#endif // FECHA_H
