#pragma once
#include <string>
#include "../City.h"

class IGameLogger
{
public:
    virtual ~IGameLogger() = default;
    virtual std::string GetStatusWheatIncome(City& city, int random_acre_wheat_income, int handled_acres, int income) =
    0;
    virtual std::string GetStatusRatsAction(City& city, int ratsAtePercentage, int wheatAte) =0;
    virtual std::string GetStatusCitizenWheatConsumption(City& city, int wheatConsumed, int deadPercentage, int deadCitizen) =0;
    virtual std::string GetStatusCitizenIncome(City& city, int citizensIncome) =0;
    virtual std::string GetStatusPlaqueAction(City& city, bool wasPlaque, int deadCount) =0;
    virtual std::string GetCityStatus(City& city) =0;
};
