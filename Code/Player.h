#pragma once
#include <SFML/Graphics.hpp>
class Player//Класс игрок, хранит счет.
{

	int score = 0;
public:

	int GetScore() { return score;}
	void operator++() {++score; }
	
	virtual ~Player() = 0 {}
};