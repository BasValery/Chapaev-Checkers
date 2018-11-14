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

   // �������� ������������ ������������� (��� ������� ��������)
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);


	while (true)//���� � ������� �������� ���������.
	{
		Menu menu(&window);//����
		int complexy;//���������
		bool computer;//���������� ���������� �� ������ ������� ������������ ����������� �������
		computer = menu.ShowMenu(complexy);//����� ������ ���� � ������� ������������ ��������������� � �����������
		Game game(&window, complexy,computer);// ���������� ������� ���� ����
		game.StartGame();//���� � ������� ���������� ����
	}
	return 0;
}