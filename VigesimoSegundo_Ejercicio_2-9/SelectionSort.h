#pragma once
#include "Vector.h"
#include <iostream>

class SelectionSort
{
private:
    long long operaciones;

    void intercambiar(std::vector<int> &v, int i, int j)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        operaciones += 3; // 3 operaciones de asignación
    }

public:
    SelectionSort() : operaciones(0) {}

    void ordenar(Vector &vector)
    {
        operaciones = 0;
        std::vector<int> &v = vector.getData();
        int n = v.size();

        for (int i = 0; i < n - 1; i++)
        {
            operaciones++; // Incremento y comparación del for

            int valMenor = v[i];
            int posMenor = i;
            operaciones += 2; // 2 asignaciones

            for (int j = i + 1; j < n; j++)
            {
                operaciones++; // Incremento y comparación del for interno

                operaciones++; // Comparación del if
                if (v[j] < valMenor)
                {
                    valMenor = v[j];
                    posMenor = j;
                    operaciones += 2; // 2 asignaciones
                }
            }

            operaciones++; // Comparación del if
            if (posMenor != i)
            {
                v[posMenor] = v[i];
                v[i] = valMenor;
                operaciones += 2; // 2 asignaciones
            }
        }
    }

    long long obtenerOperaciones() const
    {
        return operaciones;
    }
};
