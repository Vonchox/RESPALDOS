#pragma once
#include <graphics.h>
#include "Torre.h"
class VisualizadorHanoi
{
private:
    Torre *torres[3];
    int numDiscos;
    int ventanaAncho;
    int ventanaAlto;

public:
    VisualizadorHanoi(int n) : numDiscos(n)
    {
        ventanaAncho = 800;
        ventanaAlto = 600;

        initwindow(ventanaAncho, ventanaAlto, "Torres de Hanoi");
        setbkcolor(WHITE);
        cleardevice();

        int torreAncho = 20;
        int torreAlto = numDiscos * 25 + 100;
        int espacioEntreTorres = ventanaAncho / 4;

        torres[0] = new Torre(espacioEntreTorres, 100, torreAncho, torreAlto, 'A', numDiscos);
        torres[1] = new Torre(espacioEntreTorres * 2, 100, torreAncho, torreAlto, 'B', numDiscos);
        torres[2] = new Torre(espacioEntreTorres * 3, 100, torreAncho, torreAlto, 'C', numDiscos);

        // Inicializar primera torre
        for (int i = numDiscos; i > 0; i--)
        {
            torres[0]->agregarDisco(i);
        }
    }

    ~VisualizadorHanoi()
    {
        for (int i = 0; i < 3; i++)
        {
            delete torres[i];
        }
        closegraph();
    }

    void actualizarVisual()
    {
        cleardevice();
        for (int i = 0; i < 3; i++)
        {
            torres[i]->dibujar();
        }
        delay(500); // Pausa para mejor visualización
    }

    void moverDisco(int origen, int destino)
    {
        int disco = torres[origen]->quitarDisco();
        torres[destino]->agregarDisco(disco);
        actualizarVisual();
    }
};