#pragma once
#include "../Statistics/Statistic.h"

class City;

class LoadedData
{
public:
    LoadedData(City& city, Statistic& statistic, int last_round)
        : city(city),
          statistic(statistic),
          last_round(last_round)
    {
    }

public:
    City city;
    Statistic statistic;
    int last_round;
};

class GameSave
{
public:
    void Save(City& city, Statistic& statistic, int last_round);
    LoadedData Load();
    bool HasSave();
};
