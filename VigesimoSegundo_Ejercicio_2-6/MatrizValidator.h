#ifndef MATRIZ_VALIDATOR_H
#define MATRIZ_VALIDATOR_H

#include <vector>
#include <stdexcept>
#include <string>

class MatrizValidator
{
public:
    static void validarDimensiones(const std::vector<std::vector<int>> &matriz)
    {
        if (matriz.empty())
        {
            throw std::invalid_argument("La matriz está vacía");
        }

        size_t n = matriz.size();
        for (const auto &fila : matriz)
        {
            if (fila.size() != n)
            {
                throw std::invalid_argument("La matriz debe ser cuadrada");
            }
        }
    }

    static bool esNumero(const std::string &str)
    {
        for (char c : str)
        {
            if (!isdigit(c) && c != '-')
            {
                return false;
            }
        }
        return !str.empty() && (str.size() == 1 || str[0] != '-' || str.size() > 1);
    }
};

#endif
