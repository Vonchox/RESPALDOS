#ifndef VERIFICADOR_MATRIZ_SIMETRICA_H
#define VERIFICADOR_MATRIZ_SIMETRICA_H

#include <vector>
#include "MatrizValidator.h"

class VerificadorMatrizSimetrica
{
private:
    int operacionesRealizadas;

public:
    VerificadorMatrizSimetrica() : operacionesRealizadas(0) {}

    bool esMatrizSimetrica(const std::vector<std::vector<int>> &matriz)
    {
        operacionesRealizadas = 0;
        MatrizValidator::validarMatrizCuadrada(matriz);

        int N = matriz.size();
        bool es_traspuesta = true;
        int columna = 1;

        // Implementación según el pseudocódigo del ejercicio
        while (columna <= N && es_traspuesta)
        {
            operacionesRealizadas++; // columna <= N
            int fila = N;

            while (fila > columna && es_traspuesta)
            {
                operacionesRealizadas++; // fila > columna

                if (matriz[fila - 1][columna - 1] != matriz[columna - 1][fila - 1])
                {
                    operacionesRealizadas++; // comparación de elementos
                    es_traspuesta = false;
                }

                fila--;
                operacionesRealizadas++; // decremento de fila
            }

            columna++;
            operacionesRealizadas++; // incremento de columna
        }

        return es_traspuesta;
    }

    int obtenerOperaciones() const
    {
        return operacionesRealizadas;
    }
};

#endif