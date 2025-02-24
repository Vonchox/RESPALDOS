#ifndef MATRIZ_INPUT_H
#define MATRIZ_INPUT_H

#include <vector>
#include <iostream>
#include <string>
#include "MatrizValidator.h"

class MatrizInput
{
public:
    static std::vector<std::vector<int>> leerMatriz()
    {
        int n;
        std::cout << "Ingrese el tamanio de la matriz cuadrada (n x n): ";
        while (!(std::cin >> n) || n <= 0)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Por favor, ingrese un numero positivo valido: ";
        }

        std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
        std::string entrada;

        std::cout << "Ingrese los elementos de la matriz:" << std::endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                while (true)
                {
                    std::cout << "Elemento [" << i << "][" << j << "]: ";
                    std::cin >> entrada;

                    if (MatrizValidator::esNumero(entrada))
                    {
                        matriz[i][j] = std::stoi(entrada);
                        break;
                    }
                    std::cout << "Por favor, ingrese un numero valido." << std::endl;
                }
            }
        }

        return matriz;
    }
};

#endif