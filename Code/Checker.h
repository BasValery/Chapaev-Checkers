#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using std::string;
//Класс шашки
class Checker
{
	sf::Image image_checker;//сфмл изображение
	sf::Texture texture_checker;//сфмл текстура
	sf::Sprite sprite_checker;//сфмл спрайт

	static float force_of_friction; //Сила трения о доску

	sf::Vector2f Coord;//Положение шашки

	float forse_knock;
	sf::Vector2f direction;//Вектор движения шашки
	
public:

	Checker(float X, float Y, string texture); //Конструктор
	
	sf::Vector2f GetCoordinates();//Акссесор для получения координат шашки
	void Show(sf::RenderWindow &window);//Отрисовка шашки
	bool Move();//Метод для того чтобы узнать двигается ли шашка
	void AddForse(sf::Vector2f Dir, float Forse);//Изменение движения шашки
	float Distance(Checker Object);//Расстояние до другой шашки
	float GetRadius();//Получение радиуса шашки
	void SetCoord(sf::Vector2f coord);

	//Группа простых аксессоров
	static float GetForseFriction() { return force_of_friction; }
	float GetKnockForce() { return forse_knock; }
	sf::Vector2f GetDirecton() { return direction; }
			
};