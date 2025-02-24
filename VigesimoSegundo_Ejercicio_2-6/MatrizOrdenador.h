#ifndef MATRIZ_ORDENADOR_H
#define MATRIZ_ORDENADOR_H

#include <vector>
#include <iostream>
#include "MatrizValidator.h"
using namespace std;

class MatrizOrdenador {
private:
    static void intercambiar(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    static std::vector<int> matrizAVector(const std::vector<std::vector<int>>& matriz) {
        std::vector<int> vector;
        for (const auto& fila : matriz) {
            vector.insert(vector.end(), fila.begin(), fila.end());
        }
        return vector;
    }
    
    static std::vector<std::vector<int>> vectorAMatriz(const std::vector<int>& vector, int n) {
        std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = vector[k++];
            }
        }
        return matriz;
    }
    
    static void bubbleSort(std::vector<int>& vector) {
        int n = vector.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (vector[j] > vector[j+1]) {
                    intercambiar(vector[j], vector[j+1]);
                }
            }
        }
    }

public:
    static std::vector<std::vector<int>> ordenarMatriz(std::vector<std::vector<int>> matriz) {
        MatrizValidator::validarDimensiones(matriz);
        int n = matriz.size();
        std::vector<int> vector = matrizAVector(matriz);
        bubbleSort(vector);
        return vectorAMatriz(vector, n);
    }
};

#endif