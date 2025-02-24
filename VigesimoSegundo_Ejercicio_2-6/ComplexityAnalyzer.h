#ifndef COMPLEXITY_ANALYZER_H
#define COMPLEXITY_ANALYZER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class ComplexityAnalyzer
{
private:
    static unsigned long long calcularOperacionesCuadrada(int n)
    {
        // n es el lado de la matriz, por lo que n² es el número total de elementos
        unsigned long long resultado = static_cast<unsigned long long>(n) * n * n * n;
        return resultado;
    }

    static unsigned long long calcularOperacionesRectangular(int m, int n)
    {
        // m es número de filas, n es número de columnas
        unsigned long long resultado = static_cast<unsigned long long>(m) * n * m * n;
        return resultado;
    }

public:
    static void analizarMatrizCuadrada(const std::vector<std::vector<int>> &matriz)
    {
        int n = matriz.size(); // lado de la matriz

        std::cout << "\nAnalisis de Complejidad - Matriz Cuadrada:" << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        std::cout << "Dimension de la matriz: " << n << "x" << n << std::endl;
        std::cout << "Numero total de elementos: " << n * n << std::endl;
        std::cout << "Complejidad de ordenamiento:" << std::endl;
        std::cout << "- Formula: O(n^4) donde n es el lado de la matriz" << std::endl;
        std::cout << "- Sustituyendo n=" << n << ": O(" << n << "^4)" << std::endl;
        std::cout << "- Aproximadamente " << calcularOperacionesCuadrada(n)
                  << " operaciones en el peor caso" << std::endl;
    }

    static void analizarMatrizRectangular(const std::vector<std::vector<int>> &matriz)
    {
        int m = matriz.size();    // filas
        int n = matriz[0].size(); // columnas

        std::cout << "\nAnalisis de Complejidad - Matriz Rectangular:" << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        std::cout << "Dimensiones de la matriz: " << m << "x" << n << std::endl;
        std::cout << "Numero total de elementos: " << m * n << std::endl;
        std::cout << "Complejidad de ordenamiento:" << std::endl;
        std::cout << "- Formula: O(m^2*n^2) donde m=filas, n=columnas" << std::endl;
        std::cout << "- Sustituyendo m=" << m << ", n=" << n << ": O("
                  << m << "^2*" << n << "^2)" << std::endl;
        std::cout << "- Aproximadamente " << calcularOperacionesRectangular(m, n)
                  << " operaciones en el peor caso" << std::endl;
    }

    static void explicarComplejidades()
    {
        std::cout << "\nExplicacion Detallada de Complejidades:" << std::endl;
        std::cout << std::string(40, '-') << std::endl;

        std::cout << "1. Matriz Cuadrada:" << std::endl;
        std::cout << "   - Lado de la matriz = n" << std::endl;
        std::cout << "   - Total de elementos = n^2 (n*n)" << std::endl;
        std::cout << "   - Complejidad del Bubble Sort sobre n^2 elementos = O((n^2)^2)" << std::endl;
        std::cout << "   - Simplificando: O(n^4)" << std::endl;

        std::cout << "\n2. Matriz Rectangular:" << std::endl;
        std::cout << "   - Dimensiones: m filas * n columnas" << std::endl;
        std::cout << "   - Total de elementos = m*n" << std::endl;
        std::cout << "   - Complejidad del Bubble Sort sobre m*n elementos = O((m*n)^2)" << std::endl;
        std::cout << "   - Simplificando: O(m^2*n^2)" << std::endl;
    }
};

#endif