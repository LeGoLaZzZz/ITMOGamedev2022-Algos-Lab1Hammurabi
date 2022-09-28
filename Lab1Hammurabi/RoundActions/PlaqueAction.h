#pragma once
#include "IRoundAction.h"

class PlaqueAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) override;
};
