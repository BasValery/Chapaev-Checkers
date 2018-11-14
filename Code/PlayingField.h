#pragma once
#include <ctime>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Checker.h"
#include "VectorOverloads.h"
#include <algorithm>
#include <iostream>
using std::vector;

class PlayingField

{
	
	sf::Image image_field;//сфмл изображение
	sf::Texture texture_field;//сфмл текстура
	sf::Sprite sprite_field;//сфмл спрайт
	string texture_cheker1;
	string texture_checker2;

	static float Entropy;//Имитация рассеивания энергии при столкновении шашек 
	
	vector<Checker *> player1; //Массив шашек игроков
	vector<Checker *> player2; 


public:
	PlayingField(string texture_field_file, string texture_cheker1, string texture_checker2);//Конструктор который принимает тектуры
	void NewLevel(int ScorePlayer1, int ScorePlayer2);//Отрисовка шашек на новых позициях при смене уровня
	~PlayingField();
	void Drow(sf::RenderWindow &window);//Отрисовка поля и шашек
	//Проверка на принадлежность шашки по кооридинатам игроку
	bool IsChekerPlayer1(sf::Vector2f &CoordClick);
	bool IsChekerPlayer2(sf::Vector2f &CoordClick);
	

	void SetChekerSpeed(sf::Vector2f Cheker, sf::Vector2f Vector, double Force);//Устанавливаем направление движения шашки
	void ShootFromPlayer2ToPlayer1(int FirstCheker, int SecondCheker, float forse, int Error = 0);//Стреляем одной шашкой в другую
	bool Move();//Проверяем движутся ли шашки
	void CheckClash();//Проверяем столкновения
	void CheckPenetration();
	void CheckExit();//Проверяем вылет за пределы экрана

	//Гетчеры
	float GetEntropy() { return Entropy; }
	int GetSizeOfPlayer1Chekers() { return player1.size(); }
	int GetSizeOfPlayer2Chekers() { return player2.size(); }
};