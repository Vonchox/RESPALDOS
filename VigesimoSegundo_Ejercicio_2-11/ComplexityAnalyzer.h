#pragma once

class ComplexityAnalyzer
{
public:
    // T(n) = 2n - 1 ∈ θ(n) según la solución teórica
    static int getOperations(int n)
    {
        return 2 * n - 1;
    }

    // Método para calcular k dado n (donde n = 2^k)
    static int calculateK(int n)
    {
        int k = 0;
        while (n > 1)
        {
            n /= 2;
            k++;
        }
        return k;
    }
};