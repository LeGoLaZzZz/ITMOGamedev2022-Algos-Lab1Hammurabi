#include "CitizenWheatConsumptionAction.h"

#include "ActionResultBuilder.h"

ActionResult CitizenWheatConsumptionAction::DoRoundAction(City& city, HammurabiConfig& config,
                                                          RoundSharedInfo& shared_info)
{
    int citizenCanAlive = city.GetWheatAmount() / config.citizen_wheat_consumption;
    int deadCitizen = city.GetCitizenAmount() - citizenCanAlive;

    int deadPercentage = 0;

    if (deadCitizen > 0)
    {
        deadPercentage = deadCitizen / city.GetCitizenAmount();
        city.RemoveDeadCitizen(deadCitizen);
    }
    else
    {
        deadCitizen = 0;
    }
    shared_info.StarvedCitizenCount = deadCitizen;
    bool isLose = deadPercentage >= config.citizen_starved_lose_condition;

    int wheat_consumed = citizenCanAlive * config.citizen_wheat_consumption * citizenCanAlive;
    city.RemoveWheatAmount(wheat_consumed);

    string result_status_info = "deadPercentage: " + to_string(deadPercentage) + "\n"
        + "deadCitizen: " + to_string(deadCitizen);

    if (isLose) return ActionResultBuilder::BuildStarveResult(result_status_info);
    return ActionResultBuilder::BuildOkResult(result_status_info);
}