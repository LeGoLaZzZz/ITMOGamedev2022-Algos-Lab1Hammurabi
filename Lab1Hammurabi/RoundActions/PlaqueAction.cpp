#include "PlaqueAction.h"

#include "ActionResultBuilder.h"

ActionResult PlaqueAction::DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info,
                                         IGameLogger& logger)
{
    float number = ((float)rand()) / RAND_MAX; // число от 0.0 до 1.0

    bool wasPlaque = number > config.plaque_chance;

    int deadCount = city.GetCitizenAmount() * (config.plaque_dead_modifer);
    if (wasPlaque) city.RemoveDeadCitizen(deadCount);

    string result_status_info = logger.GetStatusPlaqueAction(city, wasPlaque, deadCount);

    return ActionResultBuilder::BuildOkResult(result_status_info);
}
