#pragma once
#include "Player.h"
#include <string>
#include <math.h>
#include <iostream>
using std::string;
//Класс игрока человека
class HumanPlayer : public Player
{
	//Тектуры для направления полета шашки
	sf::Image image_pointer;//сфмл изображение
	sf::Texture texture_pointer;//сфмл текстура
	sf::Sprite sprite_pointer;//сфмл спрайт
	sf::Vector2f ChosenCheker;//Выбранная игроком шашка

	bool chosen;//Переменная которая определяет выбрал ли игрок шашку

public:
	HumanPlayer(string texture);//Конструктор который получает путь к файлу текстуры
	void DrawArrow(sf::RenderWindow &window);//Отрисовка направления шашки
	void SetCheker(sf::Vector2f Cheker);//Запоминание выбранной шашки


	void ChangeChose() { chosen = chosen ? false : true; }//Изменение состояния выбора
	//Гетчеры
	bool GetChose() { return chosen; }
	sf::Vector2f GetCheker() { return ChosenCheker; }

};

