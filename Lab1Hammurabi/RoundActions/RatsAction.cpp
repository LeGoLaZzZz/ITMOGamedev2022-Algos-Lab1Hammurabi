#include "RatsAction.h"

#include "ActionResultBuilder.h"

ActionResult RatsAction::DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info,
                                       IGameLogger& logger)
{
    int ratsPercentage = config.GetRandomRatsPercentage();
    int wheatAte = city.GetWheatAmount() * (ratsPercentage / static_cast<float>(100));
    city.RemoveWheatAmount(wheatAte);

    string result_status_info = logger.GetStatusRatsAction(city, ratsPercentage, wheatAte);

    return ActionResultBuilder::BuildOkResult(result_status_info);
}
