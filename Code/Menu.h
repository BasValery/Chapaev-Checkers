#pragma once
#include <SFML/Graphics.hpp>
class Menu //���� ����
{
	
	sf::RenderWindow * Window;
public:
	Menu(sf::RenderWindow * window):Window(window){} //����������� ������� �������� ����
	bool ShowMenu(int &Complexity);//������� ��� ����������� ����������� �������
	int ChoseComplexity();//������� ��� ����������� ���������
	void ShowHelp();
};