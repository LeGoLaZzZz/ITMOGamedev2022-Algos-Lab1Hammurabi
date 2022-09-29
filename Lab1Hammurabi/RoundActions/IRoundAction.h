#pragma once
#include "ActionResult.h"
#include "../City.h"
#include "../HammurabiConfig.h"
#include "../Round/RoundSharedInfo.h"
#include "../Loggers/IGameLogger.h"

class IRoundAction
{
public:
    virtual ~IRoundAction() = default;
    ActionResult virtual DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info,
                                       IGameLogger& logger) = 0;
};
