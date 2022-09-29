#pragma once
#include <iostream>
#include <string>
#include "../RoundActions/IRoundAction.h"
#include "RoundSharedInfo.h"
#include "../RoundActions/ActionResult.h"
#include "../City.h"


struct HammurabiConfig;

using namespace std;

class Round
{
public:
    RoundSharedInfo shared_info;

    void PlayRound(City& city, HammurabiConfig& config, IGameLogger& game_logger)
    {
        for (int i = 0; i < round_actions_count_; ++i)
        {
            IRoundAction* round_action = round_actions_[i];
            ActionResult action_result = round_action->DoRoundAction(city, config, shared_info, game_logger);
            std::cout << action_result.ActionStatusInfo() << std::endl<< std::endl;

            if (action_result.IsLoseResult())
            {
                std::cout << "bro you lost";
                break;
            }
        }
        std::cout << game_logger.GetCityStatus(city) << std::endl;
    }


private:
    IRoundAction** round_actions_;
    int round_actions_count_;
public:
    Round(IRoundAction** round_actions, int round_actions_count)
        : shared_info(), round_actions_(round_actions),
          round_actions_count_(round_actions_count)
    {
    }
};
