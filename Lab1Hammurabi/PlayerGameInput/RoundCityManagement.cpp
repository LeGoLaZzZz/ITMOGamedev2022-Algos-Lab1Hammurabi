#include "RoundCityManagement.h"
#include <functional>
#include <iostream>

#include "../City.h"
#include "../HammurabiConfig.h"
#include "../Loggers/IGameLogger.h"

bool isNumber(const std::string& s)
{
    for (char const& ch : s)
    {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

void RoundCityManagement::StartRoundManagement(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    acre_cost = config.GetRandomAcreCost();
    std::cout << logger.GetAcreCostText(city, acre_cost);

    std::cout << logger.GetAcreBuyText(city);
    BuyAcres(city, config, logger);
    std::cout << logger.GetAcreSellText(city);
    SellAcres(city, config, logger);
}


int RoundCityManagement::ReadUserInputInteger(City& city, IGameLogger& logger)
{
    std::string integer_input = "";
    bool is_valid_cin = false;
    while (!is_valid_cin)
    {
        std::cin >> integer_input;

        if (!isNumber(integer_input))
        {
            std::cout << logger.GetPlayerInputReaction(city, kNotNumber);
            is_valid_cin = false;
            continue;
        }

        int number_to_check_int = 0;
        try
        {
            int tmp = std::stoi(integer_input);

            if (std::numeric_limits<int>::max() < tmp)
            {
                std::cout << logger.GetPlayerInputReaction(city, kTooBigNumber);
                is_valid_cin = false;
                continue;
            }

            number_to_check_int = tmp;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << logger.GetPlayerInputReaction(city, kTooBigNumber);
            is_valid_cin = false;
            continue;
        }


        if (number_to_check_int < 1)
        {
            std::cout << logger.GetPlayerInputReaction(city, kNegativeNumber);
            is_valid_cin = false;
            continue;
        }

        return number_to_check_int;
    }
}


PlayerInputResult RoundCityManagement::BuyAcresConditions(City& city, int integer_input)
{
    int acres_to_buy = integer_input;
    if (city.GetWheatAmount() < acre_cost * acres_to_buy)
    {
        return kNoWheat;
    }
    return kOk;
}


int RoundCityManagement::ReadParamLoop(City& city, HammurabiConfig& config, IGameLogger& logger,
                                       std::function<PlayerInputResult(int)>& conditions_func)
{
    bool is_valid_cin = false;
    int read_int = 0;

    while (!is_valid_cin)
    {
        is_valid_cin = true;
        read_int = ReadUserInputInteger(city, logger);

        auto player_input_result = (conditions_func)(read_int);

        if (player_input_result != kOk)
        {
            std::cout << logger.GetPlayerInputReaction(city, kNoWheat);
            is_valid_cin = false;
        }
    }
    return read_int;
}

void RoundCityManagement::BuyAcres(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    std::function<PlayerInputResult(int)> buy_acr_condition_lambda = [city, this](int acres_to_buy)
    {
        if (city.GetWheatAmount() < acre_cost * acres_to_buy)
        {
            return kNoWheat;
        }
        return kOk;
    };

    int acres_to_buy = ReadParamLoop(city, config, logger, buy_acr_condition_lambda);

    city.RemoveWheatAmount(acres_to_buy * acre_cost);
    city.AddAcres(acres_to_buy);

    std::cout << logger.GetCityStatus(city);
}

void RoundCityManagement::SellAcres(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    std::function<PlayerInputResult(int)> sell_acr_condition_lambda = [city, this](int acres_to_sell)
    {
        if (city.GetAcreAmount() < acres_to_sell)
        {
            return kNoAcres;
        }
        return kOk;
    };

    int acres_to_sell = ReadParamLoop(city, config, logger, sell_acr_condition_lambda);

    city.AddWheatAmount(acres_to_sell * acre_cost);
    city.RemoveAcres(acres_to_sell);

    std::cout << logger.GetCityStatus(city);
}

void RoundCityManagement::WheatToFood(City& city, HammurabiConfig& config, IGameLogger& logger)
{
}

void RoundCityManagement::AcresToSeed(City& city, HammurabiConfig& config, IGameLogger& logger)
{
}
