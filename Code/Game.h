#pragma once
#include <SFML/Graphics.hpp>
#include "PlayingField.h"
#include "HumanPlayer.h"
#include "Computer.h"

//Основной класс игры

class Game
{
	PlayingField Field;//Объект игрового поля
	Player * player1;//Указатель на объект типа игрок
	Player * player2;//Указатель на объект типа игрок
	sf::RenderWindow * Window;//Указатель на окно
	int Complexity;//Сложность игры
	bool Computer;//Ведется ли игра с компьютером или с человеком 
	float PowerBalance = 12;// Переменная которая влиет на силу удара по шашке
public:

	Game(sf::RenderWindow * window,int complexity, bool ComputerGame = true);//Конструктор в котором инициализируются поля 
	void StartGame();//Основной цикл игры
	void Win(string Image);//Сообщение о победе
	float GetPowerBalanse() { return PowerBalance; }//Аксессор

	~Game();//Деструктор
};

