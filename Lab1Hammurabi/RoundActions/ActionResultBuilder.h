#pragma once
#include "ActionResult.h"


class ActionResultBuilder
{
public:
    static ActionResult BuildOkResult(string status_info)
    {
        return ActionResult{false, status_info, kRoundResultOk};
    }

    static ActionResult BuildStarveResult(string status_info)
    {
        return ActionResult{true, status_info, kStarve};
    }

    static ActionResult BuildNoCitizenResult(string status_info)
    {
        return ActionResult{true, status_info, kNoCitizen};
    }
};
