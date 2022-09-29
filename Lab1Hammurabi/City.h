#pragma once

class City
{
    int citizen_amount_ = 0;
    float wheat_amount_ = 0;
    int acre_amount_ = 0;
public:
    City(int citizen_amount, float wheat_amount, int acre_amount)
        : citizen_amount_(citizen_amount),
          wheat_amount_(wheat_amount),
          acre_amount_(acre_amount)
    {
    }

    void SetCitizenAmount(int citizen_amount);

    void SetWheatAmount(int wheat_amount);

    void AddWheatAmount(int add_wheat_amount);

    void RemoveWheatAmount(int remove_wheat_amount);

    void SetAcreAmount(int acre_amount);

    int GetCitizenAmount() const;

    int GetWheatAmount() const;

    int GetAcreAmount() const;

    void RemoveDeadCitizen(int dead_amount);

    void AddCitizen(int citizen_income);
    void AddAcres(int acres_income);
    void RemoveAcres(int acres_income);
};
