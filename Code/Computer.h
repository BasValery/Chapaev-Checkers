#pragma once
#include "Player.h"
#include "Checker.h"
#include <vector>
#include <SFML/Graphics.hpp>

using std::vector;
class ComputerPlayer : public Player//Класс копьютерный игрок, наследует класс игрок
{

public:

	float GetKnock(int & ComputerCheker, int & HumanCheker);//Случайным образом выбираем свою и чужую шашку  и силу с которой бьем по шашке


};