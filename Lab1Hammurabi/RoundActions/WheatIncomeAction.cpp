#include "WheatIncomeAction.h"

ActionResult WheatIncomeAction::DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info,
                                              IGameLogger& logger)
{
    const int acre_wheat_income = config.GetRandomWheatIncome();
    const int can_citizen_handle_acres = city.GetCitizenAmount() * config.citizen_acre_handle_count;

    const int can_seed_handle_acres = city.GetWheatToSeed() / (float)config.citizen_seed_wheat_cost;


    int handled_acres = min(can_citizen_handle_acres, can_seed_handle_acres);
    handled_acres = std::clamp(handled_acres, 0, city.GetAcreAmount());

    city.RemoveWheatToSeed(handled_acres * config.citizen_seed_wheat_cost);
    const int income = handled_acres * acre_wheat_income;
    city.AddWheatAmount(income);
    shared_info.AcreWheatIncome = acre_wheat_income;

    string result_status_info = logger.GetStatusWheatIncome(city, acre_wheat_income, handled_acres, income);


    return ActionResultBuilder::BuildOkResult(result_status_info);
}
