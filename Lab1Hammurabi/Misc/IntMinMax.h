#pragma once
#include <cstdlib>

struct IntMinMax
{
    int min;
    int max;

    int GetRandomRange() const
    {
        return rand() % (max - min) + min;
    }
};
