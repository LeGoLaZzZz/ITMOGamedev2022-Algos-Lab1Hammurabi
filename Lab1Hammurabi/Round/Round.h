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

    RoundResultEnum PlayRound(City& city, HammurabiConfig& config, IGameLogger& game_logger)
    {
        RoundResultEnum lastResult;
        for (int i = 0; i < round_actions_count_; ++i)
        {
            IRoundAction* round_action = round_actions_[i];
            ActionResult action_result = round_action->DoRoundAction(city, config, shared_info, game_logger);

            string str = action_result.ActionStatusInfo();
            if (str != "") std::cout << str << std::endl;
            lastResult = action_result.GetResultEnum();
            if (action_result.IsLoseResult())
            {
                break;
            }
        }
        std::cout << game_logger.GetCityStatus(city) << std::endl;
        return lastResult;
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
