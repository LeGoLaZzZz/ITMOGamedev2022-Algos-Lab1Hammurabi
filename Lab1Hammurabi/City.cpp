#include "City.h"

void City::SetCitizenAmount(int citizen_amount)
{
    citizen_amount_ = citizen_amount;
}

void City::SetWheatAmount(int wheat_amount)
{
    wheat_amount_ = wheat_amount;
}

void City::AddWheatAmount(int add_wheat_amount)
{
    wheat_amount_ += add_wheat_amount;
}

void City::RemoveWheatAmount(int remove_wheat_amount)
{
    if (remove_wheat_amount >= wheat_amount_) wheat_amount_ = 0;
    else wheat_amount_ -= remove_wheat_amount;
}

void City::SetAcreAmount(int acre_amount)
{
    acre_amount_ = acre_amount;
}

int City::GetCitizenAmount() const
{
    return citizen_amount_;
}

int City::GetWheatAmount() const
{
    return wheat_amount_;
}

int City::GetAcreAmount() const
{
    return acre_amount_;
}

void City::RemoveDeadCitizen(int dead_amount)
{
    if (dead_amount >= citizen_amount_) citizen_amount_ = 0;
    else citizen_amount_ -= dead_amount;
}

void City::AddCitizen(int citizen_income)
{
    citizen_amount_ += citizen_income;
}

void City::AddAcres(int acres_income)
{
    acre_amount_ += acres_income;
}

void City::RemoveAcres(int acres_income)
{
    acre_amount_ -= acres_income;
}

bool City::AddWheatToFood(int wheat_to_food)
{
    if (wheat_amount_ >= wheat_to_food)
    {
        wheat_to_food_amount_ += wheat_to_food;
        RemoveWheatAmount(wheat_to_food);
        return true;
    }
    return false;
}

void City::RemoveWheatToFood(int wheat_consumed)
{
    if (wheat_consumed >= wheat_to_food_amount_) wheat_to_food_amount_ = 0;
    else wheat_to_food_amount_ -= wheat_consumed;
}

void City::RemoveWheatToSeed(int wheat_consumed)
{
    if (wheat_consumed >= wheat_to_seed_amount_) wheat_to_seed_amount_ = 0;
    else wheat_to_seed_amount_ -= wheat_consumed;
}

void City::LoadData(int citizen_amount, float wheat_amount, int acre_amount, float wheat_to_seed_amount,
                    float wheat_to_food_amount)
{
    citizen_amount_ = citizen_amount;
    wheat_amount_ = wheat_amount;
    acre_amount_ = acre_amount;
    wheat_to_seed_amount_ = wheat_to_seed_amount;
    wheat_to_food_amount_ = wheat_to_food_amount;
}

bool City::AddWheatToSeed(int wheat_to_seed)
{
    if (wheat_amount_ >= wheat_to_seed)
    {
        wheat_to_seed_amount_ += wheat_to_seed;
        RemoveWheatAmount(wheat_to_seed);
        return true;
    }
    return false;
}

int City::GetWheatToSeed()
{
    return wheat_to_seed_amount_;
}

int City::GetWheatToFood()
{
    return wheat_to_food_amount_;
}
