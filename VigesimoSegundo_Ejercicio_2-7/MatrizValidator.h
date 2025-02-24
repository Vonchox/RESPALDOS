#ifndef MATRIZ_VALIDATOR_H
#define MATRIZ_VALIDATOR_H

#include <vector>
#include <stdexcept>
#include <string>

class MatrizValidator
{
public:
    static void validarMatrizRectangular(const std::vector<std::vector<int>> &matriz)
    {
        if (matriz.empty())
        {
            throw std::invalid_argument("La matriz esta vacia");
        }

        size_t columnas = matriz[0].size();
        if (columnas == 0)
        {
            throw std::invalid_argument("Las filas de la matriz estan vacias");
        }

        for (const auto &fila : matriz)
        {
            if (fila.size() != columnas)
            {
                throw std::invalid_argument("Todas las filas deben tener el mismo numero de columnas");
            }
        }
    }

    static bool esNumero(const std::string &str)
    {
        if (str.empty())
            return false;

        for (char c : str)
        {
            if (!isdigit(c) && c != '-')
            {
                return false;
            }
        }
        return (str.size() == 1) || (str[0] != '-' || str.size() > 1);
    }
};

#endif
