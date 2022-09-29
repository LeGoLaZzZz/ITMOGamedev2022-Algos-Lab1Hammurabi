#include "TestGameLogger.h"


string TestGameLogger::GetStatusWheatIncome(City& city, int random_acre_wheat_income, int handled_acres, int income)
{
    return "WheatIncomeAction:\n AcreAmount-" + to_string(handled_acres)
        + " * acreWheatIncome-" + to_string(random_acre_wheat_income) + "=" + to_string(income);
}

string TestGameLogger::GetStatusRatsAction(City& city, int ratsAtePercentage, int wheatAte)
{
    return "ratsPercentage: " + to_string(ratsAtePercentage) + "\n" + "wheatAte: " + to_string(wheatAte);
}

string TestGameLogger::GetStatusCitizenWheatConsumption(City& city, int deadPercentage, int deadCitizen)
{
    return "deadPercentage: " + to_string(deadPercentage) + "\n" + "deadCitizen: " + to_string(deadCitizen);
}

string TestGameLogger::GetStatusCitizenIncome(City& city, int citizensIncome)
{
    return "CitizenIncome: " + to_string(citizensIncome);
}

string TestGameLogger::GetStatusPlaqueAction(City& city, bool wasPlaque, int deadCount)
{
    return "wasPlaque: " + to_string(wasPlaque) + "\n" +        "deadCount" + to_string(deadCount);
}
