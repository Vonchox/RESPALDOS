#include <iostream>
#include "Validador.h"
#include "TorresHanoi.h"

int main()
{
    std::cout << "=== Torres de Hanoi ===" << std::endl;

    int numDiscos = Validador::obtenerNumeroValido(
        "Ingrese el numero de discos (1-8): ",
        1,
        8 // Limitamos a 8 para que sea visualmente manejable
    );

    TorresHanoi hanoi(numDiscos);
    hanoi.verificarFormula(numDiscos);

    std::cout << "\nPresione cualquier tecla para salir...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}