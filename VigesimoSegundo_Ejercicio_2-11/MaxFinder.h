#pragma once
#include "Vector.h"

class MaxFinder
{
private:
    long long operaciones;

    double encontrarMaximoRecursivo(const std::vector<double> &v, int inicio, int fin)
    {
        operaciones++; // Contador de operaciones

        if (inicio == fin)
        {
            return v[inicio];
        }

        int medio = (inicio + fin) / 2;
        double maxIzq = encontrarMaximoRecursivo(v, inicio, medio);
        double maxDer = encontrarMaximoRecursivo(v, medio + 1, fin);

        operaciones++; // Operación de comparación max
        return std::max(maxIzq, maxDer);
    }

public:
    MaxFinder() : operaciones(0) {}

    double encontrarMaximo(const Vector &vector)
    {
        operaciones = 0;
        const std::vector<double> &v = vector.getData();
        if (v.empty())
        {
            throw std::runtime_error("El vector esta vacio");
        }
        return encontrarMaximoRecursivo(v, 0, v.size() - 1);
    }

    long long obtenerOperaciones() const
    {
        return operaciones;
    }
};