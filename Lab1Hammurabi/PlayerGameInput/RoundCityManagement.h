#pragma once
#include <functional>

#include "../City.h"
#include "../HammurabiConfig.h"
#include "../Loggers/IGameLogger.h"

class IGameLogger;
enum PlayerInputResult
{
    kOk,
    kNoWheat,
    kNoAcres,
    kNegativeNumber,
    kNotNumber,
    kTooBigNumber,
};

class RoundCityManagement
{
public:
    void StartRoundManagement(City& city, HammurabiConfig& config, IGameLogger& logger);
    int ReadUserInputInteger(City& city, IGameLogger& logger, std::string& preInputText);
    PlayerInputResult BuyAcresConditions(City& city, int integer_input);
   
private:
    int acre_cost = 0;
    int ReadParamLoop(City& city, HammurabiConfig& config, IGameLogger& logger,
                      std::string& preInputText, std::function<PlayerInputResult(int)>& conditions_func);
    void BuyAcres(City& city, HammurabiConfig& config, IGameLogger& logger);
    void SellAcres(City& city, HammurabiConfig& config, IGameLogger& logger);
    void WheatToFood(City& city, HammurabiConfig& config, IGameLogger& logger);
    void AcresToSeed(City& city, HammurabiConfig& config, IGameLogger& logger);
};
