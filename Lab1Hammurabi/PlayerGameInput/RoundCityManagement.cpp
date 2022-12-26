#include "RoundCityManagement.h"
#include <functional>
#include <iostream>

#include "../City.h"
#include "../HammurabiConfig.h"
#include "../Loggers/IGameLogger.h"

using namespace std;

bool isNumber(const string& s)
{
    for (char const& ch : s)
    {
        if (isdigit(ch) == 0)
            return false;
    }
    return true;
}

void RoundCityManagement::StartRoundManagement(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    acre_cost = config.GetRandomAcreCost();
    cout << logger.GetAcreCostText(city, acre_cost);

    BuyAcres(city, config, logger);
    SellAcres(city, config, logger);
    WheatToFood(city, config, logger);
    AcresToSeed(city, config, logger);
}


int RoundCityManagement::ReadUserInputInteger(City& city, IGameLogger& logger, string& preInputText)
{
    string integer_input = "";
    bool is_valid_cin = false;
    while (!is_valid_cin)
    {
        cout << preInputText;
        cin >> integer_input;

        if (!isNumber(integer_input))
        {
            cout << logger.GetPlayerInputReaction(city, kNotNumber);
            is_valid_cin = false;
            continue;
        }

        int number_to_check_int = 0;
        try
        {
            int tmp = stoi(integer_input);

            if (numeric_limits<int>::max() < tmp)
            {
                cout << logger.GetPlayerInputReaction(city, kTooBigNumber);
                is_valid_cin = false;
                continue;
            }

            number_to_check_int = tmp;
        }
        catch (const out_of_range& e)
        {
            cout << logger.GetPlayerInputReaction(city, kTooBigNumber);
            is_valid_cin = false;
            continue;
        }

        if (number_to_check_int < 0)
        {
            cout << logger.GetPlayerInputReaction(city, kNegativeNumber);
            is_valid_cin = false;
            continue;
        }

        return number_to_check_int;
    }
}


int RoundCityManagement::ReadParamLoop(City& city,
                                       HammurabiConfig& config,
                                       IGameLogger& logger,
                                       string& preInputText,
                                       function<PlayerInputResult(int)>& conditions_func)
{
    bool is_valid_cin = false;
    int read_int = 0;

    while (!is_valid_cin)
    {
        is_valid_cin = true;
        read_int = ReadUserInputInteger(city, logger, preInputText);

        auto player_input_result = (conditions_func)(read_int);

        if (player_input_result != kOk)
        {
            cout << logger.GetPlayerInputReaction(city, kNoWheat);
            is_valid_cin = false;
        }
    }
    return read_int;
}

void RoundCityManagement::BuyAcres(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    function<PlayerInputResult(int)> buy_acr_condition_lambda = [city, this](int acres_to_buy)
    {
        if (city.GetWheatAmount() < acre_cost * acres_to_buy)
        {
            return kNoWheat;
        }
        return kOk;
    };

    auto buy_text = logger.GetAcreBuyText(city);
    int acres_to_buy = ReadParamLoop(city, config, logger, buy_text, buy_acr_condition_lambda);

    city.RemoveWheatAmount(acres_to_buy * acre_cost);
    city.AddAcres(acres_to_buy);

    cout << endl << logger.GetCityStatus(city);
}

void RoundCityManagement::SellAcres(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    function<PlayerInputResult(int)> sell_acr_condition_lambda = [city, this](int acres_to_sell)
    {
        if (city.GetAcreAmount() < acres_to_sell)
        {
            return kNoAcres;
        }
        return kOk;
    };

    auto sell_text = logger.GetAcreSellText(city);
    int acres_to_sell = ReadParamLoop(city, config, logger, sell_text, sell_acr_condition_lambda);

    city.AddWheatAmount(acres_to_sell * acre_cost);
    city.RemoveAcres(acres_to_sell);

    cout << endl << logger.GetCityStatus(city);
}

void RoundCityManagement::WheatToFood(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    function<PlayerInputResult(int)> wheat_to_food_condition_lambda = [city, this](int wheat_to_move)
    {
        if (city.GetWheatAmount() < wheat_to_move)
        {
            return kNoWheat;
        }
        return kOk;
    };

    auto move_wheat_text = logger.GetWheatFoodText(city);
    int wheat_move = ReadParamLoop(city, config, logger, move_wheat_text, wheat_to_food_condition_lambda);

    city.AddWheatToFood(wheat_move);
}

void RoundCityManagement::AcresToSeed(City& city, HammurabiConfig& config, IGameLogger& logger)
{
    float seed_cost = config.citizen_seed_wheat_cost;
    int wheat_amount = city.GetWheatAmount();

    function<PlayerInputResult(int)> wheat_to_seed_condition_lambda = [wheat_amount, seed_cost](int acres_to_seed)
    {
        if (wheat_amount < acres_to_seed * seed_cost)
        {
            return kNoWheat;
        }
        return kOk;
    };

    auto acres_to_seed_text = logger.GetAcresSeedText(city);
    int acres_to_seed = ReadParamLoop(city, config, logger, acres_to_seed_text, wheat_to_seed_condition_lambda);
    city.AddWheatToSeed(acres_to_seed * seed_cost);
}
