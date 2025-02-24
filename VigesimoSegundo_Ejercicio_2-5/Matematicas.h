#pragma once
#include <stdexcept>
#include <iostream>
#include <iomanip>

class Matematicas
{
private:
    static const double E; // e ≈ 2.71828...

    // Aproximación de raíz cuadrada usando el método de Newton-Raphson
    static double raizCuadrada(double numero)
    {
        if (numero < 0)
            throw std::invalid_argument("Número negativo para raíz cuadrada.");

        double aproximacion = numero;
        double precision = 0.00001;
        while (true)
        {
            double mejorAprox = 0.5 * (aproximacion + numero / aproximacion);
            if (std::abs(mejorAprox - aproximacion) < precision)
                break;
            aproximacion = mejorAprox;
        }
        return aproximacion;
    }

    // Implementación de potencia sin usar cmath
    static double potencia(double base, double exponente)
    {
        if (exponente == 0)
            return 1;
        if (base == 0)
            return 0;

        double resultado = 1;
        bool exponenteNegativo = exponente < 0;
        double expAbs = exponenteNegativo ? -exponente : exponente;

        // Parte entera
        int parteEntera = static_cast<int>(expAbs);
        double parteFraccionaria = expAbs - parteEntera;

        for (int i = 0; i < parteEntera; i++)
        {
            resultado *= base;
        }

        // Aproximación de la parte fraccionaria usando raíces sucesivas
        double factor = base;
        double precision = 0.0001;
        while (parteFraccionaria > precision)
        {
            if (parteFraccionaria >= 0.5)
            {
                resultado *= raizCuadrada(factor);
                parteFraccionaria -= 0.5;
            }
            factor = raizCuadrada(factor);
            parteFraccionaria *= 2;
        }

        return exponenteNegativo ? 1 / resultado : resultado;
    }

public:
    static double obtenerE()
    {
        return E;
    }

    static double calcularNE(double n)
    {
        return potencia(n, E);
    }

    static double calcularEN(double n)
    {
        return potencia(E, n);
    }
};

// Definición de la constante E
const double Matematicas::E = 2.71828182845904523536;
