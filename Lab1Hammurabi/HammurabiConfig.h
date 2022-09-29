#pragma once

#include "Misc/IntMinMax.h"

struct HammurabiConfig
{
    int citizen_wheat_consumption = 20;
    int citizen_acre_handle_count = 10;
    float citizen_seed_wheat_cost = 0.5f;
    int citizen_starved_lose_condition = 45;
    float plaque_dead_modifer = 0.5f;
    float plaque_chance = 0.15f;
    IntMinMax wheat_income_range = {1, 6};
    IntMinMax rats_percentage_range = {1, 7};
    IntMinMax acre_cost_range = {17, 26};

    int GetRandomWheatIncome() const
    {
        return wheat_income_range.GetRandomRange();
    }

    int GetRandomRatsPercentage() const
    {
        return rats_percentage_range.GetRandomRange();
    }

    int GetRandomAcreCost() const
    {
        return acre_cost_range.GetRandomRange();
    }
};
