#pragma once

class ComplexityAnalyzer
{
private:
    static double cuadrado(int n)
    {
        return static_cast<double>(n) * static_cast<double>(n);
    }

public:
    static double getBestCaseOperations(int n)
    {
        // T_mejor(n) = (3/2)n² + (11/2)n - 5
        return (3.0 / 2.0) * cuadrado(n) + (11.0 / 2.0) * n - 5;
    }

    static double getWorstCaseOperations(int n)
    {
        // T_peor(n) = (5/2)n² + (13/2)n - 7
        return (5.0 / 2.0) * cuadrado(n) + (13.0 / 2.0) * n - 7;
    }
};