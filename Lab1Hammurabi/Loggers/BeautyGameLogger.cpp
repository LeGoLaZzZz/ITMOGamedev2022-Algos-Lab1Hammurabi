#include "BeautyGameLogger.h"
#include "../Statistics/Statistic.h"
#include <sstream>

using namespace std;

std::string BeautyGameLogger::GetStatusWheatIncome(City& city, int random_acre_wheat_income, int handled_acres,
                                                   int income)
{
    std::stringstream ss;

    ss << "�� ������� ";
    ss << to_string(income) << " ������� ������� � " << to_string(handled_acres) << " ����� �����";
    ss << " �� " << to_string(random_acre_wheat_income) << " � ����;" << endl;
    ss << "����� ������ � ������� � ��� ����� " << to_string(city.GetWheatAmount()) << " ������� �������;" << endl;

    return ss.str();
}

std::string BeautyGameLogger::GetStatusRatsAction(City& city, int ratsAtePercentage, int wheatAte)
{
    std::stringstream ss;
    ss << "����� ��������� " << to_string(ratsAtePercentage) << "% ������� � ����� ������� ��� ";
    ss << to_string(wheatAte) << " �������;" << endl;
    ss << "����� ����� � ��� �������� " << to_string(city.GetWheatAmount()) << " ������� �������;" << endl;


    return ss.str();
}

std::string BeautyGameLogger::GetStatusCitizenWheatConsumption(City& city, int wheatConsumed, int deadPercentage,
                                                               int deadCitizen)
{
    std::stringstream ss;
    ss << "������� ������� ���� ��������� �� ���������� " << to_string(wheatConsumed) << ";" << endl;
    if (deadCitizen > 0)
    {
        ss << to_string(deadCitizen) << " ������� ������ � ������, ��� " << deadPercentage <<
            "% �� ��������� ������ ������" << endl;
    }
    return ss.str();
}

std::string BeautyGameLogger::GetStatusCitizenIncome(City& city, int citizensIncome)
{
    std::stringstream ss;
    ss << to_string(citizensIncome) << " ������� ������� � ��� ������� �����;" << endl;
    ss << "������ � ������ " << to_string(city.GetCitizenAmount()) << " �������;" << endl;
    return ss.str();
}

string BeautyGameLogger::GetStatusPlaqueAction(City& city, bool wasPlaque, int deadCount)
{
    if (!wasPlaque) return "";

    std::stringstream ss;

    ss << "���� ���������� �������� ��������� " << to_string(deadCount) << " �������;" << endl;
    return ss.str();
}


string BeautyGameLogger::GetCityStatus(City& city)
{
    std::stringstream ss;

    ss << "��������� ������ ������ ������:" << endl;
    ss << "������� � ������� " << to_string(city.GetWheatAmount()) << ";" << endl;
    // ss << "  Wheat on food:" << to_string(city.GetWheatToFood()) << endl;
    // ss << "  Wheat on seed:" << to_string(city.GetWheatToSeed()) << endl;
    ss << "� ������ ��������� " << to_string(city.GetCitizenAmount()) << " ������;" << endl;
    ss << "����� �������� " << to_string(city.GetAcreAmount()) << " �����;" << endl;

    return ss.str();
}

string BeautyGameLogger::GetGameResultText(City& city, GameResultData result_data)
{
    std::stringstream ss;
    ss << "������ ����: " << endl;
    switch (result_data.result)
    {
    case kBad1: ss <<
            "�����: ��-�� ����� ���������������� � ����������, ����� ������� ����, � ������ ��� �� ������. ������ �� ��������� ������� ������ ������������� � ��������"
            << endl;
        break;
    case kGood2: ss <<
            "�����������������: �� ������� �������� �����, ������� ������ � ����� ��������. ����� �������� � �����������, � ����� ������ �� ������ ������ ��� ����������"
            << endl;
        break;
    case kGreat3: ss <<
            "������: �� ���������� ������ �������, � ���,�������, ���� ���������������, �� ������ ������ �� ������� ��� �� ����� ������ �����)"
            << endl;
        break;
    case kExcelent4: ss <<
            "�������: ����������! ���� �������, �������� � ���������� ������ �� ���������� �� �����)"
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
    ss << "�� ���������!" << endl;

    switch (round_result_enum)
    {
    case kStarve: ss << "������� ����� ����� ������� �� ������!" << endl;
        break;
    case kNoCitizen: ss << "� ������ �� �������� �������!" << endl;
        break;
    case kRoundResultOk: break;
    default: ;
    }

    return ss.str();
}

string BeautyGameLogger::GetAcreCostText(City& city, int acre_cost)
{
    std::stringstream ss;
    ss << "� ���� ���� ���� ��� ����� " << to_string(acre_cost) << " ������� �������;" << endl;

    return ss.str();
}

string BeautyGameLogger::GetAcreBuyText(City& city)
{
    std::stringstream ss;
    ss << "������� ����� ����� ����������� ������? ";
    return ss.str();
}


string BeautyGameLogger::GetAcreSellText(City& city)
{
    std::stringstream ss;
    ss << "������� ����� ����� ����������� �������? ";
    return ss.str();
}


string BeautyGameLogger::GetWheatFoodText(City& city)
{
    std::stringstream ss;
    ss << "������� ������� ������� ����������� ������? ";
    return ss.str();
}

string BeautyGameLogger::CurrentRoundText(City& city, int round)
{
    std::stringstream ss;
    ss << "� ���� " << round + 1 << " ������ ����������� ���������";
    return ss.str();
}


string BeautyGameLogger::GetAcresSeedText(City& city)
{
    std::stringstream ss;
    ss << "������� ����� ����� ����������� �������? ";
    return ss.str();
}

string BeautyGameLogger::AskLoadSave()
{
    std::stringstream ss;
    ss << "���� ����������, ������� ��� ���������? y/n:";
    return ss.str();
}

string BeautyGameLogger::GetPlayerInputReaction(City& city, PlayerInputResult result)
{
    std::stringstream ss;

    switch (result)
    {
    case PlayerInputResult::kOk: break;
    case kNoWheat: ss << "�, ����������, ������ ���! � ��� ��� ������� �������!" << endl;
        break;
    case kNegativeNumber: ss << "�, ����������, ������ ���! �� �� �������� ����� �����" << endl;
        break;
    case kNotNumber: ss << "�, ����������, ������ ���! �� �� �������� ����� �����" << endl;
        break;
    case kTooBigNumber: ss << "�, ����������, ������ ���! �� �� ����� ������� �� ����� ������� �����" << endl;
        break;
    case kNoAcres: ss << "�, ����������, ������ ���! � ��� ��� ������� �����" << endl;
        break;
    default: ;
    }

    return ss.str();
}
