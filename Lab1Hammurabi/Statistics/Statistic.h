#pragma once
#include "../Round/Round.h"

enum GameResult
{
    kBad1,
    kGood2,
    kGreat3,  
    kExcelent4,  
};

class GameResultData
{
public:
    GameResult result;
    float average_hunger_percentage_P;
    float acre_per_citizen_L;
};


class Statistic
{
private:
    int round_count_=0;
    int average_hunger_percentage_sum_=0;


public:
    void EndRoundStat(Round& round, City& city);
    GameResultData GetGameResult(City& city);
    
private:
    void AddHungerRoundDeadCount(float percentage);
    float CountAcrePerCitizen(int acre_count, int citizen_count);
    GameResult GetResult(float average_hunger_percentage_P, float acre_per_citizen_L);
};
