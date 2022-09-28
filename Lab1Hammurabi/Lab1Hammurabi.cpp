#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class RoundSharedInfo
{
public:
    int StarvedCitizen;
    int AcreWheatIncome;
};

class City
{
    int citizen_amount_ = 0;
    float wheat_amount_ = 0;
    int acre_amount_ = 0;
public:
    City(int citizen_amount, float wheat_amount, int acre_amount)
        : citizen_amount_(citizen_amount),
          wheat_amount_(wheat_amount),
          acre_amount_(acre_amount)
    {
    }

    void SetCitizenAmount(int citizen_amount)
    {
        citizen_amount_ = citizen_amount;
    }

    void SetWheatAmount(int wheat_amount)
    {
        wheat_amount_ = wheat_amount;
    }

    void AddWheatAmount(int add_wheat_amount)
    {
        wheat_amount_ += add_wheat_amount;
    }

    void RemoveWheatAmount(int remove_wheat_amount)
    {
        if (remove_wheat_amount >= wheat_amount_) wheat_amount_ = 0;
        else wheat_amount_ -= remove_wheat_amount;
    }

    void SetAcreAmount(int acre_amount)
    {
        acre_amount_ = acre_amount;
    }

    int GetCitizenAmount() const
    {
        return citizen_amount_;
    }

    int GetWheatAmount() const
    {
        return wheat_amount_;
    }

    int GetAcreAmount() const
    {
        return acre_amount_;
    }

    void RemoveDeadCitizen(int dead_amount)
    {
        if (dead_amount >= citizen_amount_) citizen_amount_ = 0;
        else citizen_amount_ -= dead_amount;
    }

    void AddCitizen(int citizen_income)
    {
        citizen_amount_ += citizen_income;
    }
};

struct IntMinMax
{
    int min;
    int max;

    int GetRandomRange() const
    {
        return rand() % (max - min) + min;
    }
};

struct HammurabiConfig
{
    int citizen_wheat_consumption = 20;
    int citizen_acre_handle_count = 10;
    float citizen_seed_wheat_cost = 0.5f;
    int citizen_starved_lose_condition = 45;
    float plaque_dead_modifer = 0.5f;
    float plaque_chance = 0.15f;
    IntMinMax wheat_income_range = {1, 6};
    IntMinMax rats_percentage_range = {1, 7};

    int GetRandomWheatIncome() const
    {
        return wheat_income_range.GetRandomRange();
    }

    int GetRandomRatsPercentage() const
    {
        return rats_percentage_range.GetRandomRange();
    }
};

class ActionResult
{
public:
    ActionResult(bool is_lose_result, string action_status_info)
        : is_lose_result_(is_lose_result),
          action_status_info_(move(action_status_info))
    {
    }

    bool IsLoseResult() const
    {
        return is_lose_result_;
    }

    string ActionStatusInfo() const
    {
        return action_status_info_;
    }

private:
    bool is_lose_result_ = false;
    string action_status_info_;
};

enum ActionResultEnum
{
    kStarve,
    kNoCitizen,
    kOk,
};

class IRoundAction
{
public:
    virtual ~IRoundAction() = default;
    ActionResult virtual DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) = 0;
};

class WheatIncomeAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) override
    {
        int acreWheatIncome = config.GetRandomWheatIncome();
        int income = city.GetAcreAmount() * acreWheatIncome;
        city.AddWheatAmount(income);
        shared_info.AcreWheatIncome = acreWheatIncome;
        return ActionResult(false, "WheatIncomeAction:\n AcreAmount-" + to_string(city.GetAcreAmount())
                            + " * acreWheatIncome-" + to_string(acreWheatIncome) + "=" + to_string(income));
    }
};

class RatsAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) override
    {
        int ratsPercentage = config.GetRandomRatsPercentage();
        int wheatAte = city.GetWheatAmount() * (ratsPercentage / static_cast<float>(100));
        city.RemoveWheatAmount(wheatAte);

        return ActionResult(false,
                            "ratsPercentage: " + to_string(ratsPercentage) + "\n"
                            + "wheatAte: " + to_string(wheatAte));
    }
};


class CitizenWheatConsumptionAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) override
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
        shared_info.StarvedCitizen = deadCitizen;
        bool isLose = deadPercentage >= config.citizen_starved_lose_condition;

        int wheat_consumed = citizenCanAlive * config.citizen_wheat_consumption * citizenCanAlive;
        city.RemoveWheatAmount(wheat_consumed);

        return ActionResult(isLose, "deadPercentage: " + to_string(deadPercentage) + "\n"
                            + "deadCitizen: " + to_string(deadCitizen));
    }
};


class CitizenIncome : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) override
    {
        int citizenIncome = shared_info.StarvedCitizen / 2 + (5 - shared_info.AcreWheatIncome) * city.GetWheatAmount() /
            600 + 1;
        city.AddCitizen(citizenIncome);
        return ActionResult(false, "CitizenIncome: " + to_string(citizenIncome));
    }
};


class PlaqueAction : public IRoundAction
{
public:
    ActionResult DoRoundAction(City& city, HammurabiConfig& config, RoundSharedInfo& shared_info) override
    {
        float number = ((float)rand()) / RAND_MAX; // число от 0.0 до 1.0

        bool wasPlaque = number > config.plaque_chance;

        int deadCount = city.GetCitizenAmount() * (config.plaque_dead_modifer);
        if (wasPlaque) city.RemoveDeadCitizen(deadCount);

        return ActionResult(false, "wasPlaque: " + to_string(wasPlaque) + "\n" +
                            "deadCount" + to_string(deadCount));
    }
};


class Round
{
public:
    RoundSharedInfo shared_info;

    void PlayRound(City& city, HammurabiConfig& config)
    {
        for (int i = 0; i < round_actions_count_; ++i)
        {
            IRoundAction* round_action = round_actions_[i];
            ActionResult action_result = round_action->DoRoundAction(city, config, shared_info);
            std::cout << action_result.ActionStatusInfo() << endl;

            if (action_result.IsLoseResult())
            {
                std::cout << "bro you lost";
                break;
            }
        }

        std::cout << "Wheat total:" << to_string(city.GetWheatAmount()) << endl;
        std::cout << "Citizen total:" << to_string(city.GetCitizenAmount()) << endl;
        std::cout << "Acre total:" << to_string(city.GetAcreAmount()) << endl;
    }

private:
    IRoundAction** round_actions_;
    int round_actions_count_;
public:
    Round(IRoundAction** round_actions, int round_actions_count)
        : shared_info(), round_actions_(round_actions),
          round_actions_count_(round_actions_count)
    {
    }
};


int main(int argc, char* argv[])
{
    City city = City{100, 2800, 1000};
    HammurabiConfig config = HammurabiConfig{};


    WheatIncomeAction wheat_income_action = WheatIncomeAction{};
    RatsAction rats_action = RatsAction{};
    CitizenWheatConsumptionAction citizen_wheat_consumption_action = CitizenWheatConsumptionAction{};
    CitizenIncome citizen_income = CitizenIncome{};
    PlaqueAction plaque_action = PlaqueAction{};

    IRoundAction* round_actions[5]
    {
        &wheat_income_action,
        &rats_action,
        &citizen_wheat_consumption_action,
        &citizen_income,
        &plaque_action,
    };

    int roundsCount = 1;

    for (int i = 0; i < roundsCount; ++i)
    {
        Round round = Round(round_actions, 5);
        round.PlayRound(city, config);
    }

    return 0;
}
