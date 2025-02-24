#pragma once
#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>

class Vector
{
private:
    std::vector<int> data;

    bool isNumber(const std::string &str) const
    {
        return !str.empty() && str.find_first_not_of("0123456789-") == std::string::npos;
    }

public:
    Vector() = default;

    void inputFromKeyboard()
    {
        std::cout << "Ingrese el tamanio del vector: ";
        int size;
        std::string input;
        std::cin >> input;

        if (!isNumber(input))
        {
            throw std::invalid_argument("El tamanio debe ser un numero");
        }

        size = std::stoi(input);
        if (size <= 0)
        {
            throw std::invalid_argument("El tamanio debe ser positivo");
        }

        data.clear();
        std::cout << "Ingrese " << size << " numeros:\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << "Elemento " << i + 1 << ": ";
            std::cin >> input;

            if (!isNumber(input))
            {
                throw std::invalid_argument("Solo se permiten numeros");
            }

            data.push_back(std::stoi(input));
        }
    }

    const std::vector<int> &getData() const { return data; }
    std::vector<int> &getData() { return data; }
    void setData(const std::vector<int> &newData) { data = newData; }
};