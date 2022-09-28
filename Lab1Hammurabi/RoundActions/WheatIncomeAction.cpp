#include "WheatIncomeAction.h"

ActionResult WheatIncomeAction::DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info)
{
    int acreWheatIncome = config.GetRandomWheatIncome();
    int can_handle_acres = city.GetCitizenAmount() * config.citizen_acre_handle_count;
    int handled_acres = std::clamp(can_handle_acres,0,city.GetAcreAmount());

    int income = handled_acres * acreWheatIncome;
    city.AddWheatAmount(income);
    shared_info.AcreWheatIncome = acreWheatIncome;

    string result_status_info = "WheatIncomeAction:\n AcreAmount-" + to_string(city.GetAcreAmount())
        + " * acreWheatIncome-" + to_string(acreWheatIncome) + "=" + to_string(income);


    return ActionResultBuilder::BuildOkResult(result_status_info);
}