#include "MatrizInput.h"
#include "VerificadorMatrizSimetrica.h"
#include "MatrizPrinter.h"
#include "ComplexityAnalyzer.h"

int main()
{
    try
    {
        // Leer matriz
        std::cout << "Ingrese la matriz a verificar:" << std::endl;
        std::vector<std::vector<int>> matriz = MatrizInput::leerMatriz();

        // Mostrar matriz ingresada
        std::cout << "\nMatriz ingresada:" << std::endl;
        MatrizPrinter::imprimirMatriz(matriz);

        // Verificar simetría
        VerificadorMatrizSimetrica verificador;
        bool esSimetrica = verificador.esMatrizSimetrica(matriz);

        // Mostrar resultados
        std::cout << "\nResultados:" << std::endl;
        std::cout << "La matriz " << (esSimetrica ? "es" : "no es") << " simetrica" << std::endl;

        // Analizar complejidad
        ComplexityAnalyzer::analizarComplejidad(matriz.size(), verificador.obtenerOperaciones());
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}