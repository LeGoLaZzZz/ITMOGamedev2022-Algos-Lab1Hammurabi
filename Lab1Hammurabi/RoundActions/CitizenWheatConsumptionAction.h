#pragma once
#include "IRoundAction.h"

class CitizenWheatConsumptionAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) override;
};
