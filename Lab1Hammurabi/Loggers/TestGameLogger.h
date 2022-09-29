#pragma once
#include <string>

#include "IGameLogger.h"
#include "../City.h"
using namespace std;

class TestGameLogger : public IGameLogger
{
public:
    std::string GetStatusWheatIncome(City& city, int random_acre_wheat_income, int handled_acres, int income) override;
    std::string GetStatusRatsAction(City& city, int ratsAtePercentage, int wheatAte) override;
    std::string GetStatusCitizenWheatConsumption(City& city, int wheatConsumed, int deadPercentage, int deadCitizen) override;
    std::string GetStatusCitizenIncome(City& city, int citizensIncome) override;
    std::string GetStatusPlaqueAction(City& city, bool wasPlaque, int deadCount) override;
    std::string GetCityStatus(City& city) override;
    std::string GetGameResultText(City& city, GameResultData result_data) override;
    std::string GetAcreCostText(City& city, int acre_cost) override;
    
    std::string GetPlayerInputReaction(City& city, PlayerInputResult result) override;
};
