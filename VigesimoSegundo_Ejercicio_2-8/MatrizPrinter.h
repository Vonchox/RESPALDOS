#ifndef MATRIZ_PRINTER_H
#define MATRIZ_PRINTER_H

#include <vector>
#include <iostream>
#include <iomanip>

class MatrizPrinter {
public:
    static void imprimirMatriz(const std::vector<std::vector<int>>& matriz) {
        for (const auto& fila : matriz) {
            for (int elemento : fila) {
                std::cout << std::setw(4) << elemento;
            }
            std::cout << std::endl;
        }
    }
};

#endif
