#include "MaxFinder.h"
#include "ComplexityAnalyzer.h"
#include <iomanip>

void analizarResultado(const Vector &vector, double maximo, long long operaciones)
{
    int n = vector.size();
    int operacionesTeoricas = ComplexityAnalyzer::getOperations(n);
    int k = ComplexityAnalyzer::calculateK(n);

    std::cout << "\nResultados del analisis:" << std::endl;
    std::cout << "Maximo encontrado: " << maximo << std::endl;
    std::cout << "Operaciones realizadas: " << operaciones << std::endl;
    std::cout << "Operaciones teoricas (2n-1): " << operacionesTeoricas << std::endl;
    std::cout << "k (para n = 2^k): " << k << std::endl;
}

int main()
{
    try
    {
        Vector vector;
        vector.inputFromKeyboard();

        MaxFinder finder;
        double maximo = finder.encontrarMaximo(vector);

        analizarResultado(vector, maximo, finder.obtenerOperaciones());
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}