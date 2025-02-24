#pragma once

#include <graphics.h>

class Torre
{
private:
    int x, y;
    int ancho, alto;
    char nombre;
    int *discos;
    int numDiscos;
    int discosActuales;

public:
    Torre(int posX, int posY, int w, int h, char n, int maxDiscos)
        : x(posX), y(posY), ancho(w), alto(h), nombre(n), numDiscos(maxDiscos), discosActuales(0)
    {
        discos = new int[maxDiscos];
    }

    ~Torre()
    {
        delete[] discos;
    }

    void dibujar() const
    {
        // Dibujar base
        rectangle(x - 10, y, x + 10, y + alto);

        // Dibujar discos
        for (int i = 0; i < discosActuales; i++)
        {
            int discoAncho = discos[i] * 20;
            int discoY = y + alto - (i + 1) * 20;
            setfillstyle(SOLID_FILL, COLOR(0, 0, 255));
            bar(x - discoAncho / 2, discoY, x + discoAncho / 2, discoY + 15);
        }

        // Dibujar nombre
        char nombreStr[2] = {nombre, '\0'};
        outtextxy(x - 5, y + alto + 10, nombreStr);
    }

    void agregarDisco(int tamano)
    {
        if (discosActuales < numDiscos)
        {
            discos[discosActuales++] = tamano;
        }
    }

    int quitarDisco()
    {
        if (discosActuales > 0)
        {
            return discos[--discosActuales];
        }
        return 0;
    }

    bool estaVacia() const
    {
        return discosActuales == 0;
    }
};
