#include "GameSave.h"

#include <fstream>


void GameSave::Save(City& city, Statistic& statistic, int last_round)
{
    LoadedData data = {city, statistic, last_round};
    std::fstream fs;
    fs.open("./save.txt", std::fstream::out | std::ofstream::trunc);

    fs.write((char*)&data, sizeof(data));


    fs.close();
}

bool GameSave::HasSave()
{
    try
    {
        Load();
        return true;
    }
    catch (...)
    {
        return false;
    }
}

LoadedData GameSave::Load()
{
    std::fstream fs;

    City city{0, 0, 0};
    Statistic statistic{};
    int round = 0;
    
    LoadedData data = {city, statistic, round};
    fs.open("./save.txt", std::fstream::in);

    fs.read((char*)&data, sizeof(LoadedData));

    fs.close();
    return data;
}
