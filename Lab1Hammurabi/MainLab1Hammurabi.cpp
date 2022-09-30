#include <cstdlib>
#include <iostream>
#include "City.h"
#include "HammurabiConfig.h"
#include "Loggers/TestGameLogger.h"
#include "Round/Round.h"
#include "RoundActions/CitizenIncome.h"
#include "RoundActions/CitizenWheatConsumptionAction.h"
#include "RoundActions/IRoundAction.h"
#include "RoundActions/PlaqueAction.h"
#include "RoundActions/RatsAction.h"
#include "RoundActions/WheatIncomeAction.h"
#include "Statistics/Statistic.h"
#include "GameSaving//GameSave.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    auto save_game = GameSave{};
    auto logger = TestGameLogger{};

    bool needLoad = false;
    if (save_game.HasSave())
    {
        cout << logger.AskLoadSave();
        bool valid_input = false;
        char input;
        while (!valid_input)
        {
            cin >> input;

            if (input == 'y')
            {
                valid_input = true;
                needLoad = true;
            }
            if (input == 'n')
            {
                valid_input = true;
                needLoad = false;
            }
        }
    }

    auto city = City{100, 2800, 1000};
    auto statistic = Statistic{};
    int start_round = 0;

    if (needLoad)
    {
        auto loaded_data = save_game.Load();
        city = loaded_data.city;
        statistic = loaded_data.statistic;
        start_round = loaded_data.last_round + 1;
    }


    auto config = HammurabiConfig{};

    auto wheat_income_action = WheatIncomeAction{};
    auto rats_action = RatsAction{};
    auto citizen_wheat_consumption_action = CitizenWheatConsumptionAction{};
    auto citizen_income = CitizenIncome{};
    auto plaque_action = PlaqueAction{};

    auto cityManagement = RoundCityManagement{};

    IRoundAction* round_actions[5]
    {
        &wheat_income_action,
        &rats_action,
        &citizen_wheat_consumption_action,
        &citizen_income,
        &plaque_action,
    };

    constexpr int rounds_count = 10;

    std::cout << logger.GetCityStatus(city) << std::endl;
    for (int i = start_round; i < rounds_count; ++i)
    {
        std::cout << "___Round: " << i + 1 << "___" << std::endl << std::endl;
        cityManagement.StartRoundManagement(city, config, logger);
        auto round = Round(round_actions, 5);
        auto round_result_enum = round.PlayRound(city, config, logger);
        statistic.EndRoundStat(round, city);
        if (round_result_enum != kRoundResultOk)
        {
            std::cout << logger.GetGameLoseText(city, round_result_enum);
            break;
        }
        save_game.Save(city, statistic, i);
    }

    std::cout << logger.GetGameResultText(city, statistic.GetGameResult(city));


    return 0;
}
