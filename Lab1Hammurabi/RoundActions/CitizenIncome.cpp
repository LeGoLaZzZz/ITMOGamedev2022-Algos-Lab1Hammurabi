#include "CitizenIncome.h"

#include "ActionResultBuilder.h"

ActionResult CitizenIncome::DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info)
{
    int citizenIncome = shared_info.StarvedCitizenCount / 2 + (5 - shared_info.AcreWheatIncome) * city.GetWheatAmount()
        / 600 + 1;
    city.AddCitizen(citizenIncome);

    string result_status_info = "CitizenIncome: " + to_string(citizenIncome);

    return ActionResultBuilder::BuildOkResult(result_status_info);
}
