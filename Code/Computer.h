#pragma once
#include "Player.h"
#include "Checker.h"
#include <vector>
#include <SFML/Graphics.hpp>

using std::vector;
class ComputerPlayer : public Player//����� ����������� �����, ��������� ����� �����
{

public:

	float GetKnock(int & ComputerCheker, int & HumanCheker);//��������� ������� �������� ���� � ����� �����  � ���� � ������� ���� �� �����


};