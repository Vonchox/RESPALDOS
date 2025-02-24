#ifndef COMPLEXITY_ANALYZER_H
#define COMPLEXITY_ANALYZER_H

#include <iostream>
#include <string>
#include <vector>

class ComplexityAnalyzer
{
public:
    static void analizarComplejidad(int N, int operaciones)
    {
        std::cout << "\nAnalisis de Complejidad:" << std::endl;
        std::cout << "----------------------" << std::endl;

        // Mejor caso
        std::cout << "Mejor caso (O(1)):" << std::endl;
        std::cout << "- Ocurre cuando los primeros elementos comparados son diferentes" << std::endl;
        std::cout << "- Numero constante de operaciones independiente del tamanio" << std::endl;

        // Peor caso
        std::cout << "\nPeor caso (O(N^2)):" << std::endl;
        std::cout << "- Ocurre cuando la matriz es simetrica" << std::endl;
        std::cout << "- T(N) = (3N^2 + 5N)/2 + 4" << std::endl;

        // Caso actual
        double complejidadTeorica = (3.0 * N * N + 5.0 * N) / 2.0 + 4.0;
        std::cout << "\nPara N = " << N << ":" << std::endl;
        std::cout << "- Operaciones teoricas esperadas: " << complejidadTeorica << std::endl;
        std::cout << "- Operaciones realizadas: " << operaciones << std::endl;
    }
};

#endif