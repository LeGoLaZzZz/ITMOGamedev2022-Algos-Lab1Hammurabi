#include "BeautyGameLogger.h"
#include "../Statistics/Statistic.h"
#include <sstream>

using namespace std;

std::string BeautyGameLogger::GetStatusWheatIncome(City& city, int random_acre_wheat_income, int handled_acres,
                                                   int income)
{
    std::stringstream ss;

    ss << "Мы собрали ";
    ss << to_string(income) << " бушелей пшеницы с " << to_string(handled_acres) << " акров земли";
    ss << " по " << to_string(random_acre_wheat_income) << " с акра;" << endl;
    ss << "После сборов в абмарах у нас стало " << to_string(city.GetWheatAmount()) << " бушелей пшеницы;" << endl;

    return ss.str();
}

std::string BeautyGameLogger::GetStatusRatsAction(City& city, int ratsAtePercentage, int wheatAte)
{
    std::stringstream ss;
    ss << "Крысы истребили " << to_string(ratsAtePercentage) << "% пшеницы в наших амбарах или ";
    ss << to_string(wheatAte) << " бушелей;" << endl;
    ss << "После этого у нас осталось " << to_string(city.GetWheatAmount()) << " бушелей пшеницы;" << endl;


    return ss.str();
}

std::string BeautyGameLogger::GetStatusCitizenWheatConsumption(City& city, int wheatConsumed, int deadPercentage,
                                                               int deadCitizen)
{
    std::stringstream ss;
    ss << "Бушелей пшеницы было потрачено на пропитание " << to_string(wheatConsumed) << ";" << endl;
    if (deadCitizen > 0)
    {
        ss << to_string(deadCitizen) << " человек умерли с голоду, это " << deadPercentage <<
            "% от населения нашего города" << endl;
    }
    return ss.str();
}

std::string BeautyGameLogger::GetStatusCitizenIncome(City& city, int citizensIncome)
{
    std::stringstream ss;
    ss << to_string(citizensIncome) << " человек прибыли в наш великий город;" << endl;
    ss << "Теперь в городе " << to_string(city.GetCitizenAmount()) << " жителей;" << endl;
    return ss.str();
}

string BeautyGameLogger::GetStatusPlaqueAction(City& city, bool wasPlaque, int deadCount)
{
    if (!wasPlaque) return "";

    std::stringstream ss;

    ss << "Чума уничтожила половину населения " << to_string(deadCount) << " человек;" << endl;
    return ss.str();
}


string BeautyGameLogger::GetCityStatus(City& city)
{
    std::stringstream ss;

    ss << "Состояние города теперь таково:" << endl;
    ss << "Пшеницы в амбарах " << to_string(city.GetWheatAmount()) << ";" << endl;
    // ss << "  Wheat on food:" << to_string(city.GetWheatToFood()) << endl;
    // ss << "  Wheat on seed:" << to_string(city.GetWheatToSeed()) << endl;
    ss << "В городе проживают " << to_string(city.GetCitizenAmount()) << " жителя;" << endl;
    ss << "город занимает " << to_string(city.GetAcreAmount()) << " акров;" << endl;

    return ss.str();
}

string BeautyGameLogger::GetGameResultText(City& city, GameResultData result_data)
{
    std::stringstream ss;
    ss << "Оценка игры: " << endl;
    switch (result_data.result)
    {
    case kBad1: ss <<
            "Плохо: Из-за вашей некомпетентности в управлении, народ устроил бунт, и изгнал вас их города. Теперь вы вынуждены влачить жалкое существование в изгнании"
            << endl;
        break;
    case kGood2: ss <<
            "Удовлетворительно: Вы правили железной рукой, подобно Нерону и Ивану Грозному. Народ вздохнул с облегчением, и никто больше не желает видеть вас правителем"
            << endl;
        break;
    case kGreat3: ss <<
            "Хорошо: Вы справились вполне неплохо, у вас,конечно, есть недоброжелатели, но многие хотели бы увидеть вас во главе города снова)"
            << endl;
        break;
    case kExcelent4: ss <<
            "Отлично: Фантастика! Карл Великий, Дизраэли и Джефферсон вместе не справились бы лучше»)"
            << endl;
        break;
    default: ;
    }

    // ss << "  average_hunger_percentage_P:" << to_string(result_data.average_hunger_percentage_P) << endl;
    // ss << "  acre_per_citizen_L:" << to_string(result_data.acre_per_citizen_L) << endl;

    return ss.str();
}

string BeautyGameLogger::GetGameLoseText(City& city, RoundResultEnum round_result_enum)
{
    std::stringstream ss;
    ss << "Вы проиграли!" << endl;

    switch (round_result_enum)
    {
    case kStarve: ss << "Слишком много людей погибло от голода!" << endl;
        break;
    case kNoCitizen: ss << "В городе не осталось жителей!" << endl;
        break;
    case kRoundResultOk: break;
    default: ;
    }

    return ss.str();
}

string BeautyGameLogger::GetAcreCostText(City& city, int acre_cost)
{
    std::stringstream ss;
    ss << "В этом году один акр стоит " << to_string(acre_cost) << " бушелей пшеницы;" << endl;

    return ss.str();
}

string BeautyGameLogger::GetAcreBuyText(City& city)
{
    std::stringstream ss;
    ss << "Сколько акров земли повелеваешь купить? ";
    return ss.str();
}


string BeautyGameLogger::GetAcreSellText(City& city)
{
    std::stringstream ss;
    ss << "Сколько акров земли повелеваешь продать? ";
    return ss.str();
}


string BeautyGameLogger::GetWheatFoodText(City& city)
{
    std::stringstream ss;
    ss << "Сколько бушелей пшеницы повелеваешь съесть? ";
    return ss.str();
}

string BeautyGameLogger::CurrentRoundText(City& city, int round)
{
    std::stringstream ss;
    ss << "В году " << round + 1 << " твоего высочайшего правления";
    return ss.str();
}


string BeautyGameLogger::GetAcresSeedText(City& city)
{
    std::stringstream ss;
    ss << "Сколько акров земли повелеваешь засеять? ";
    return ss.str();
}

string BeautyGameLogger::AskLoadSave()
{
    std::stringstream ss;
    ss << "Есть сохранение, желаете его загрузить? y/n:";
    return ss.str();
}

string BeautyGameLogger::GetPlayerInputReaction(City& city, PlayerInputResult result)
{
    std::stringstream ss;

    switch (result)
    {
    case PlayerInputResult::kOk: break;
    case kNoWheat: ss << "О, повелитель, пощади нас! у нас нет столько пшеницы!" << endl;
        break;
    case kNegativeNumber: ss << "О, повелитель, пощади нас! Мы не понимаем такие числа" << endl;
        break;
    case kNotNumber: ss << "О, повелитель, пощади нас! Мы не понимаем такие числа" << endl;
        break;
    case kTooBigNumber: ss << "О, повелитель, пощади нас! Мы не можем считать до таких больших чисел" << endl;
        break;
    case kNoAcres: ss << "О, повелитель, пощади нас! У нас нет столько земли" << endl;
        break;
    default: ;
    }

    return ss.str();
}
