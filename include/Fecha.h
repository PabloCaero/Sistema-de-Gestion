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
        int getHoras();
        void setHoras(int val);
        int getMinutos();
        void setMinutos(int val);
        int getSegundos();
        void setSegundos(int val);

        void mostrar();

    private:

        int _dia;
        int _mes;
        int _anio;
        int _horas;
        int _minutos;
        int _segundos;
};

#endif // FECHA_H
