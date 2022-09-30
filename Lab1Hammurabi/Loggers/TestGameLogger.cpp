#include "TestGameLogger.h"
#include <sstream>
#include "../Statistics/Statistic.h"

string TestGameLogger::GetStatusWheatIncome(City& city, int random_acre_wheat_income, int handled_acres, int income)
{
    std::stringstream ss;
    ss << "_WheatIncomeAction_" << endl;
    ss << "  Handled_acres:" << to_string(handled_acres) << endl;
    ss << "  AcreWheatIncome:" << to_string(random_acre_wheat_income) << endl;
    ss << "  TotalIncome:" << to_string(income) << endl;
    ss << "  TotalCityWheat:" << to_string(city.GetWheatAmount()) << endl;

    return ss.str();
}

string TestGameLogger::GetStatusRatsAction(City& city, int ratsAtePercentage, int wheatAte)
{
    std::stringstream ss;
    ss << "_RatsAction_" << endl;
    ss << "  RatsPercentage:" << to_string(ratsAtePercentage) << endl;
    ss << "  WheatAte:" << to_string(wheatAte) << endl;
    ss << "  TotalCityWheat:" << to_string(city.GetWheatAmount()) << endl;


    return ss.str();
}

string TestGameLogger::GetStatusCitizenWheatConsumption(City& city, int wheatConsumed, int deadPercentage,
                                                        int deadCitizen)
{
    std::stringstream ss;
    ss << "_CitizenWheatConsumption_" << endl;
    ss << "  WheatConsumed:" << to_string(wheatConsumed) << endl;
    ss << "  HugerDeadPercentage:" << to_string(deadPercentage) << endl;
    ss << "  DeadCitizen:" << to_string(deadCitizen) << endl;
    ss << "  CityCitizen:" << to_string(city.GetCitizenAmount() + deadCitizen) << "->" << to_string(
        city.GetCitizenAmount()) << endl;
    ss << "  TotalCityWheat:" << to_string(city.GetWheatAmount()) << endl;

    return ss.str();
}

string TestGameLogger::GetStatusCitizenIncome(City& city, int citizensIncome)
{
    std::stringstream ss;
    ss << "_CitizenIncome_" << endl;
    ss << "  Income:" << to_string(citizensIncome) << endl;
    ss << "  TotalCityCitizen:" << to_string(city.GetCitizenAmount()) << endl;

    return ss.str();
}

string TestGameLogger::GetStatusPlaqueAction(City& city, bool wasPlaque, int deadCount)
{
    std::stringstream ss;
    ss << "_PlaqueAction_" << endl;
    ss << "  WasPlaque:" << to_string(wasPlaque) << endl;
    ss << "  DeadCount:" << to_string(deadCount) << endl;

    return ss.str();
}


string TestGameLogger::GetCityStatus(City& city)
{
    std::stringstream ss;

    ss << "_CityStatus_" << endl;
    ss << "  Wheat in ambars:" << to_string(city.GetWheatAmount()) << endl;
    ss << "  Wheat on food:" << to_string(city.GetWheatToFood()) << endl;
    ss << "  Wheat on seed:" << to_string(city.GetWheatToSeed()) << endl;
    ss << "  Citizen total:" << to_string(city.GetCitizenAmount()) << endl;
    ss << "  Acre total:" << to_string(city.GetAcreAmount()) << endl;

    return ss.str();
}

string TestGameLogger::GetGameResultText(City& city, GameResultData result_data)
{
    std::stringstream ss;
    ss << "___GameResult___" << endl;
    ss << "  result:" << to_string(result_data.result) << endl;
    ss << "  average_hunger_percentage_P:" << to_string(result_data.average_hunger_percentage_P) << endl;
    ss << "  acre_per_citizen_L:" << to_string(result_data.acre_per_citizen_L) << endl;

    return ss.str();
}

string TestGameLogger::GetGameLoseText(City& city, RoundResultEnum round_result_enum)
{
    std::stringstream ss;
    ss << "___GameLose___" << endl;

    switch (round_result_enum)
    {
    case kStarve: ss << " kStarve" << endl;
        break;
    case kNoCitizen: ss << " kNoCitizen" << endl;
        break;
    case kRoundResultOk: break;
    default: ;
    }

    return ss.str();
}

string TestGameLogger::GetAcreCostText(City& city, int acre_cost)
{
    std::stringstream ss;
    ss << "_acre_cost_" << to_string(acre_cost) << endl;

    return ss.str();
}

string TestGameLogger::GetAcreBuyText(City& city)
{
    std::stringstream ss;
    ss << "Enter acre count to buy:";
    return ss.str();
}


string TestGameLogger::GetAcreSellText(City& city)
{
    std::stringstream ss;
    ss << "Enter acre count to sell:";
    return ss.str();
}


string TestGameLogger::GetWheatFoodText(City& city)
{
    std::stringstream ss;
    ss << "Enter wheat amount to food:";
    return ss.str();
}


string TestGameLogger::GetAcresSeedText(City& city)
{
    std::stringstream ss;
    ss << "Enter wheat amount to seed:";
    return ss.str();
}

string TestGameLogger::AskLoadSave()
{
    std::stringstream ss;
    ss << "Wanna load saved game? y/n:";
    return ss.str();
}

std::string TestGameLogger::CurrentRoundText(City& city, int round)
{
    std::stringstream ss;
    ss << "___Round: " << round + 1 << "___";
    return ss.str();
}


string TestGameLogger::GetPlayerInputReaction(City& city, PlayerInputResult result)
{
    std::stringstream ss;

    switch (result)
    {
    case PlayerInputResult::kOk: break;
    case kNoWheat: ss << "Input Result: kNoWheat" << endl;
        break;
    case kNegativeNumber: ss << "Input Result: kNegativeNumber" << endl;
        break;
    case kNotNumber: ss << "Input Result: kNotNumber" << endl;
        break;
    case kTooBigNumber: ss << "Input Result: kTooBigNumber" << endl;
        break;
    case kNoAcres: ss << "Input Result: kNoAcres" << endl;
        break;
    default: ;
    }

    return ss.str();
}
