#include "SelectionSort.h"
#include "ComplexityAnalyzer.h"
#include <iomanip>

void imprimirVector(const Vector &v)
{
    for (int elemento : v.getData())
    {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}

void analizarCaso(SelectionSort &sorter, Vector &vector, const std::string &caso)
{
    std::cout << "\n"
              << caso << ":" << std::endl;
    std::cout << "Original: ";
    imprimirVector(vector);

    sorter.ordenar(vector);

    std::cout << "Ordenado: ";
    imprimirVector(vector);
    std::cout << "Operaciones realizadas: " << sorter.obtenerOperaciones() << std::endl;

    int n = vector.getData().size();
    double teoricas = (caso == "Mejor caso") ? ComplexityAnalyzer::getBestCaseOperations(n) : ComplexityAnalyzer::getWorstCaseOperations(n);

    std::cout << "Operaciones teoricas: " << std::fixed << std::setprecision(2) << teoricas << std::endl;
}

int main()
{
    SelectionSort sorter;
    Vector vector;

    try
    {
        // Permitir entrada por teclado
        vector.inputFromKeyboard();

        std::cout << "\nVector original: ";
        imprimirVector(vector);

        sorter.ordenar(vector);

        std::cout << "Vector ordenado: ";
        imprimirVector(vector);
        std::cout << "Numero total de operaciones: " << sorter.obtenerOperaciones() << std::endl;

        // Probar casos específicos
        std::cout << "\nProbando casos especificos:" << std::endl;

        // Mejor caso: vector ya ordenado
        Vector mejorCaso;
        std::vector<int> datosMejorCaso = {1, 2, 3, 4, 5};
        mejorCaso.setData(datosMejorCaso);
        analizarCaso(sorter, mejorCaso, "Mejor caso");

        // Peor caso: vector ordenado inversamente
        Vector peorCaso;
        std::vector<int> datosPeorCaso = {5, 4, 3, 2, 1};
        peorCaso.setData(datosPeorCaso);
        analizarCaso(sorter, peorCaso, "Peor caso");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}