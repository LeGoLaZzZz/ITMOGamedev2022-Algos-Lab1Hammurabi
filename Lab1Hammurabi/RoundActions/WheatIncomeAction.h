#pragma once
#include <algorithm>
#include "ActionResultBuilder.h"
#include "IRoundAction.h"


class WheatIncomeAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info, IGameLogger& logger) override;
};
