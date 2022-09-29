#include "Statistic.h"


void Statistic::EndRoundStat(Round& round, City& city)
{
    AddHungerRoundDeadCount(round.shared_info.StarvedCitizenPercentage);
    round_count_++;
}

void Statistic::AddHungerRoundDeadCount(float percentage)
{
    average_hunger_percentage_sum_ += percentage;
}

float Statistic::CountAcrePerCitizen(int acre_count, int citizen_count)
{
    return acre_count / (float)citizen_count;
}

GameResultData Statistic::GetGameResult(City& city)
{
    auto data = GameResultData{};

    float L = CountAcrePerCitizen(city.GetAcreAmount(), city.GetCitizenAmount());
    float P = average_hunger_percentage_sum_ / static_cast<float>(round_count_);
    data.acre_per_citizen_L = L;
    data.average_hunger_percentage_P = P;
    data.result = GetResult(P, L);
    return data;
}


GameResult Statistic::GetResult(float average_hunger_percentage_P, float acre_per_citizen_L)
{
    if (average_hunger_percentage_P > 0.33f && acre_per_citizen_L < 7) return kBad1;
    if (average_hunger_percentage_P > 0.1f && acre_per_citizen_L < 9) return kGood2;
    if (average_hunger_percentage_P > 0.03f && acre_per_citizen_L < 10) return kGreat3;
    return kExcelent4;
}
