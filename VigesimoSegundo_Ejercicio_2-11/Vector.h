#pragma once
#include <vector>
#include <iostream>
#include <limits>
#include <stdexcept>

class Vector
{
private:
    std::vector<double> data;

    bool validarEntrada()
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        return true;
    }

public:
    Vector() = default;

    void inputFromKeyboard()
    {
        int n;

        do
        {
            std::cout << "Ingrese el tamanio del vector (debe ser positivo): ";
            std::cin >> n;

            if (!validarEntrada() || n <= 0)
            {
                std::cout << "Error: Ingrese un numero valido positivo.\n";
                continue;
            }
            break;
        } while (true);

        data.resize(n);

        std::cout << "Ingrese " << n << " numeros:\n";
        for (int i = 0; i < n; i++)
        {
            do
            {
                std::cout << "Elemento " << i + 1 << ": ";
                std::cin >> data[i];

                if (!validarEntrada())
                {
                    std::cout << "Error: Ingrese un numero valido.\n";
                    continue;
                }
                break;
            } while (true);
        }
    }

    const std::vector<double> &getData() const { return data; }
    size_t size() const { return data.size(); }
};
