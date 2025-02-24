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
        int filas, columnas;

        // Leer dimensiones
        std::cout << "Ingrese el numero de filas: ";
        while (!(std::cin >> filas) || filas <= 0)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Por favor, ingrese un numero positivo valido: ";
        }

        std::cout << "Ingrese el numero de columnas: ";
        while (!(std::cin >> columnas) || columnas <= 0)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Por favor, ingrese un numero positivo valido: ";
        }

        std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));
        std::string entrada;

        // Leer elementos
        std::cout << "Ingrese los elementos de la matriz:" << std::endl;
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
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
