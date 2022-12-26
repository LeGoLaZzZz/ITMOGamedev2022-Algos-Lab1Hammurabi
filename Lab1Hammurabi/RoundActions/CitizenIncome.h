#pragma once
#include "IRoundAction.h"

class CitizenIncome : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info, IGameLogger& logger) override;
};
