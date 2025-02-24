#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include "Matematicas.h"

class DemostracionComplejidad
{
private:
    struct ParametrosDemo
    {
        double inicio;
        double fin;
        double paso;
    };

    // Validar la entrada de datos
    bool validarEntrada(double &valor, const std::string &mensaje)
    {
        std::cout << mensaje;
        if (!(std::cin >> valor))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada no valida. Intentalo de nuevo.\n";
            return false;
        }
        return true;
    }

    // Obtener parámetros del usuario
    ParametrosDemo obtenerParametros()
    {
        ParametrosDemo params;
        bool entradaValida = false;

        do
        {
            std::cout << "\nIngrese los parametros para la demostracion:\n";

            // Valor inicial
            if (!validarEntrada(params.inicio, "Valor inicial (>= e): ") ||
                params.inicio < Matematicas::obtenerE())
            {
                std::cout << "Error: El valor inicial debe ser mayor o igual a e ("
                          << Matematicas::obtenerE() << ")\n";
                continue;
            }

            // Valor final
            if (!validarEntrada(params.fin, "Valor final: ") ||
                params.fin <= params.inicio)
            {
                std::cout << "Error: El valor final debe ser mayor que el inicial.\n";
                continue;
            }

            // Paso
            if (!validarEntrada(params.paso, "Paso: ") ||
                params.paso <= 0 || params.paso > (params.fin - params.inicio))
            {
                std::cout << "Error: El paso debe ser positivo y menor que el rango.\n";
                continue;
            }

            entradaValida = true;
        } while (!entradaValida);

        return params;
    }

public:
    // Función principal para demostrar la relación n^e ∈ O(e^n)
    void demostrar()
    {
        ParametrosDemo params = obtenerParametros();

        std::cout << "\nDemostracion numerica de n^e ∈ O(e^n):" << std::endl;
        std::cout << "Verifica que n^e ≤ e^n para n ≥ e" << std::endl;
        std::cout << std::string(85, '-') << std::endl;

        // Encabezado de tabla
        std::cout << std::setw(10) << "n"
                  << std::setw(20) << "n^e"
                  << std::setw(20) << "e^n"
                  << std::setw(25) << "n^e <= e^n" << std::endl;
        std::cout << std::string(85, '-') << std::endl;

        // Calcular y mostrar resultados
        for (double n = params.inicio; n <= params.fin; n += params.paso)
        {
            double ne = Matematicas::calcularNE(n);
            double en = Matematicas::calcularEN(n);
            bool cumpleRelacion = ne <= en;

            std::cout << std::fixed << std::setprecision(4)
                      << std::setw(10) << n
                      << std::setw(20) << ne
                      << std::setw(20) << en
                      << std::setw(25) << (cumpleRelacion ? "Si" : "No") << std::endl;
        }

        // Conclusión
        std::cout << std::string(85, '-') << std::endl;
        std::cout << "Conclusion: Se verifica que n^e pertenece a O(e^n)\n";
        std::cout << "ya que n^e <= e^n para todo n >= e = 2.71828...\n";
    }
};
