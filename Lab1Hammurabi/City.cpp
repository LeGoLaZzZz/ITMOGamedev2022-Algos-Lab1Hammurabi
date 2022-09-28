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
