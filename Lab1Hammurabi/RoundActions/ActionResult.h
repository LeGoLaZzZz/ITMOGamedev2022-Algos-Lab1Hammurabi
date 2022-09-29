#pragma once
#include <string>
#include "../Round/RoundResultEnum.h"

using namespace std;

class ActionResult
{
public:
    ActionResult(bool is_lose_result, const string& action_status_info, RoundResultEnum result_enum)
        : is_lose_result_(is_lose_result),
          action_status_info_(action_status_info),
          result_enum_(result_enum)
    {
    }

    bool IsLoseResult() const
    {
        return is_lose_result_;
    }

    string ActionStatusInfo() const
    {
        return action_status_info_;
    }

private:
    bool is_lose_result_ = false;
    string action_status_info_;
    RoundResultEnum result_enum_ = kRoundResultOk;
};
