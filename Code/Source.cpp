#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "Game.h"
#include "Menu.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Chapaev");
	sf::Image icon;
	icon.loadFromFile("images/icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

   // Включаем вертикальную синхронизацию (для плавной анимации)
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);


	while (true)//Цикл в котором работает программа.
	{
		Menu menu(&window);//Меню
		int complexy;//Сложность
		bool computer;//Логическая переменная на основе которой определяется колличество игроков
		computer = menu.ShowMenu(complexy);//Метод класса меню в котором пользователь взаимодействует с интерфейсом
		Game game(&window, complexy,computer);// Наполнение объекта типа игра
		game.StartGame();//Цикл в котором происходит игра
	}
	return 0;
}