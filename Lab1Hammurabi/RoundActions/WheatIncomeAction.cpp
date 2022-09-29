#include "WheatIncomeAction.h"

ActionResult WheatIncomeAction::DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info,
                                              IGameLogger& logger)
{
    const int acre_wheat_income = config.GetRandomWheatIncome();
    const int can_handle_acres = city.GetCitizenAmount() * config.citizen_acre_handle_count;
    const int handled_acres = std::clamp(can_handle_acres, 0, city.GetAcreAmount());

    const int income = handled_acres * acre_wheat_income;
    city.AddWheatAmount(income);
    shared_info.AcreWheatIncome = acre_wheat_income;

    string result_status_info = logger.GetStatusWheatIncome(city, acre_wheat_income, handled_acres, income);


    return ActionResultBuilder::BuildOkResult(result_status_info);
}
