#include "CitizenIncome.h"

#include "ActionResultBuilder.h"

ActionResult CitizenIncome::DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info,
                                          IGameLogger& logger)
{
    int citizenIncome = shared_info.StarvedCitizenCount / 2 + (5 - shared_info.AcreWheatIncome) * city.GetWheatAmount()
        / 600 + 1;

    if (citizenIncome > 50) citizenIncome = 50;
    if (citizenIncome < 0) citizenIncome = 0;

    city.AddCitizen(citizenIncome);

    string result_status_info = logger.GetStatusCitizenIncome(city, citizenIncome);

    return ActionResultBuilder::BuildOkResult(result_status_info);
}
