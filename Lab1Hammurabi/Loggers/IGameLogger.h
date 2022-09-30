#pragma once
#include <string>
#include "../City.h"
#include "../Round/RoundResultEnum.h"
#include "../PlayerGameInput/RoundCityManagement.h"

class GameResultData;
enum PlayerInputResult;

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
    virtual std::string GetGameResultText(City& city, GameResultData result_data) =0;
    virtual std::string GetAcreCostText(City& city, int acre_cost) =0;
    
    virtual std::string GetAcreBuyText(City& city) =0;
    virtual std::string GetAcreSellText(City& city) =0;
    virtual std::string GetWheatFoodText(City& city) =0;
    virtual std::string GetAcresSeedText(City& city) =0;
    
    virtual std::string GetPlayerInputReaction(City& city, PlayerInputResult result) =0;
    virtual std::string GetGameLoseText(City& city, RoundResultEnum round_result_enum)=0;
    
    virtual std::string AskLoadSave() =0;
};
