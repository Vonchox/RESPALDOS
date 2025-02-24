#ifndef MATRIZ_PRINTER_H
#define MATRIZ_PRINTER_H

#include <vector>
#include <iostream>
#include <iomanip>

class MatrizPrinter
{
public:
    static void imprimirMatriz(const std::vector<std::vector<int>> &matriz)
    {
        if (matriz.empty())
            return;

        // Encontrar el número más grande para alinear la salida
        int maxAncho = 1;
        for (const auto &fila : matriz)
        {
            for (int elemento : fila)
            {
                int ancho = std::to_string(elemento).length();
                maxAncho = std::max(maxAncho, ancho);
            }
        }

        // Imprimir matriz alineada
        for (const auto &fila : matriz)
        {
            for (int elemento : fila)
            {
                std::cout << std::setw(maxAncho + 1) << elemento << " ";
            }
            std::cout << std::endl;
        }
    }

    static void imprimirDimensiones(const std::vector<std::vector<int>> &matriz)
    {
        if (matriz.empty())
        {
            std::cout << "Matriz vacia" << std::endl;
            return;
        }
        std::cout << "Dimensiones: " << matriz.size() << "x" << matriz[0].size() << std::endl;
    }
};

#endif