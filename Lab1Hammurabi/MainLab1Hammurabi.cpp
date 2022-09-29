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

using namespace std;

int main()
{
    srand(time(nullptr));
    auto city = City{100, 2800, 1000};
    auto config = HammurabiConfig{};

    auto wheat_income_action = WheatIncomeAction{};
    auto rats_action = RatsAction{};
    auto citizen_wheat_consumption_action = CitizenWheatConsumptionAction{};
    auto citizen_income = CitizenIncome{};
    auto plaque_action = PlaqueAction{};

    auto logger = TestGameLogger{};

    IRoundAction* round_actions[5]
    {
        &wheat_income_action,
        &rats_action,
        &citizen_wheat_consumption_action,
        &citizen_income,
        &plaque_action,
    };

    constexpr int rounds_count = 10;

    for (int i = 0; i < rounds_count; ++i)
    {
        auto round = Round(round_actions, 5);
        std::cout << "___Round: " << i + 1 << "___" << std::endl << std::endl;
        round.PlayRound(city, config, logger);
    }

    return 0;
}
