#ifndef MATRIZ_ORDENADOR_H
#define MATRIZ_ORDENADOR_H

#include <vector>
#include "MatrizValidator.h"

class MatrizOrdenador
{
private:
    static void intercambiar(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    static std::vector<int> matrizAVector(const std::vector<std::vector<int>> &matriz)
    {
        std::vector<int> vector;
        for (const auto &fila : matriz)
        {
            vector.insert(vector.end(), fila.begin(), fila.end());
        }
        return vector;
    }

    static std::vector<std::vector<int>> vectorAMatriz(const std::vector<int> &vector,
                                                       int filas, int columnas)
    {
        std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));
        int k = 0;
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                matriz[i][j] = vector[k++];
            }
        }
        return matriz;
    }

    static void bubbleSort(std::vector<int> &vector)
    {
        int n = vector.size();
        bool intercambioRealizado;

        for (int i = 0; i < n - 1; i++)
        {
            intercambioRealizado = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (vector[j] > vector[j + 1])
                {
                    intercambiar(vector[j], vector[j + 1]);
                    intercambioRealizado = true;
                }
            }
            if (!intercambioRealizado)
                break;
        }
    }

public:
    static std::vector<std::vector<int>> ordenarMatriz(std::vector<std::vector<int>> matriz)
    {
        MatrizValidator::validarMatrizRectangular(matriz);

        int filas = matriz.size();
        int columnas = matriz[0].size();

        std::vector<int> vector = matrizAVector(matriz);
        bubbleSort(vector);
        return vectorAMatriz(vector, filas, columnas);
    }
};

#endif
