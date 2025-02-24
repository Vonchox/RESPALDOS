#pragma once
#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <graphics.h>
#include <windows.h>

class Validador
{
public:
    static int obtenerNumeroValido(const std::string &mensaje, int min, int max)
    {
        int numero;
        bool valido = false;

        do
        {
            std::cout << mensaje;
            if (std::cin >> numero)
            {
                if (numero >= min && numero <= max)
                {
                    valido = true;
                }
                else
                {
                    std::cout << "Error: El numero debe estar entre " << min << " y " << max << std::endl;
                }
            }
            else
            {
                std::cout << "Error: Por favor ingrese un numero valido." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (!valido);

        return numero;
    }
};
