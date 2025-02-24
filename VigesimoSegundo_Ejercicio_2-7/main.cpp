#include <iostream>
#include "MatrizInput.h"
#include "MatrizOrdenador.h"
#include "MatrizPrinter.h"
#include "ComplexityAnalyzer.h"

int main()
{
    try
    {
        // Leer matriz desde el teclado
        std::cout << "Ingrese la matriz rectangular:" << std::endl;
        std::vector<std::vector<int>> matriz = MatrizInput::leerMatriz();

        // Imprimir matriz original
        std::cout << "\nMatriz original:" << std::endl;
        MatrizPrinter::imprimirDimensiones(matriz);
        MatrizPrinter::imprimirMatriz(matriz);

        // Ordenar matriz
        std::vector<std::vector<int>> matrizOrdenada = MatrizOrdenador::ordenarMatriz(matriz);

        // Imprimir matriz ordenada
        std::cout << "\nMatriz ordenada:" << std::endl;
        MatrizPrinter::imprimirDimensiones(matrizOrdenada);
        MatrizPrinter::imprimirMatriz(matrizOrdenada);
        ComplexityAnalyzer::analizarMatrizRectangular(matriz);
        ComplexityAnalyzer::explicarComplejidades();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}