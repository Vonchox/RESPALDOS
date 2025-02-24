#pragma once
#include <iostream>
#include <cmath>
#include "VisualizadorHanoi.h"

class TorresHanoi
{
private:
    int movimientos;
    VisualizadorHanoi *visualizador;

    void moverDisco(int disco, char origen, char destino)
    {
        std::cout << "Mover disco " << disco << " desde " << origen << " hasta " << destino << std::endl;

        int origenIdx = origen - 'A';
        int destinoIdx = destino - 'A';
        visualizador->moverDisco(origenIdx, destinoIdx);

        movimientos++;
    }

    void hanoi(int n, char origen, char destino, char auxiliar)
    {
        if (n > 0)
        {
            hanoi(n - 1, origen, auxiliar, destino);
            moverDisco(n, origen, destino);
            hanoi(n - 1, auxiliar, destino, origen);
        }
    }

public:
    TorresHanoi(int numDiscos) : movimientos(0)
    {
        visualizador = new VisualizadorHanoi(numDiscos);
    }

    ~TorresHanoi()
    {
        delete visualizador;
    }

    int resolverHanoi(int n)
    {
        movimientos = 0;
        std::cout << "Resolviendo Torres de Hanoi para " << n << " discos:" << std::endl;
        hanoi(n, 'A', 'C', 'B');
        return movimientos;
    }

    void verificarFormula(int n)
    {
        int movimientosReales = resolverHanoi(n);
        int movimientosTeoria = pow(2, n) - 1;

        std::cout << "\nVerificacion de la formula para " << n << " discos:" << std::endl;
        std::cout << "Movimientos realizados: " << movimientosReales << std::endl;
        std::cout << "Movimientos segun formula (2^n - 1): " << movimientosTeoria << std::endl;
        std::cout << "La formula " << (movimientosReales == movimientosTeoria ? "coincide" : "no coincide")
                  << " con la implementacion" << std::endl;
    }
};