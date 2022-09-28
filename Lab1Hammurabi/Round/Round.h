#pragma once
#include <iostream>
#include <string>
#include "../RoundActions/IRoundAction.h"
#include "RoundSharedInfo.h"
#include "../RoundActions/ActionResult.h"
#include "../City.h"


class IRoundAction;
struct HammurabiConfig;

using namespace std;

class Round
{
public:
    RoundSharedInfo shared_info;

    void PlayRound(City& city, HammurabiConfig& config)
    {
        for (int i = 0; i < round_actions_count_; ++i)
        {
            IRoundAction* round_action = round_actions_[i];
            ActionResult action_result = round_action->DoRoundAction(city, config, shared_info);
            std::cout << action_result.ActionStatusInfo() << std::endl;

            if (action_result.IsLoseResult())
            {
                std::cout << "bro you lost";
                break;
            }
        }

        std::cout << "Wheat total:" << to_string(city.GetWheatAmount()) << endl;
        std::cout << "Citizen total:" << to_string(city.GetCitizenAmount()) << endl;
        std::cout << "Acre total:" << to_string(city.GetAcreAmount()) << endl;
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
