#pragma once
#include <SFML/Graphics.hpp>
class Menu //Клас меню
{
	
	sf::RenderWindow * Window;
public:
	Menu(sf::RenderWindow * window):Window(window){} //Конструктор который получает окно
	bool ShowMenu(int &Complexity);//Функция для определения колличества игроков
	int ChoseComplexity();//Функция для определения сложности
	void ShowHelp();
};