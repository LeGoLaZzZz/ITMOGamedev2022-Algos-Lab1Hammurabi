#pragma once
#include "IRoundAction.h"

class RatsAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info, IGameLogger& logger) override;
};
