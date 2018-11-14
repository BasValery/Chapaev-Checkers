#pragma once
#include <SFML/Graphics.hpp>
#include "PlayingField.h"
#include "HumanPlayer.h"
#include "Computer.h"

//�������� ����� ����

class Game
{
	PlayingField Field;//������ �������� ����
	Player * player1;//��������� �� ������ ���� �����
	Player * player2;//��������� �� ������ ���� �����
	sf::RenderWindow * Window;//��������� �� ����
	int Complexity;//��������� ����
	bool Computer;//������� �� ���� � ����������� ��� � ��������� 
	float PowerBalance = 12;// ���������� ������� ����� �� ���� ����� �� �����
public:

	Game(sf::RenderWindow * window,int complexity, bool ComputerGame = true);//����������� � ������� ���������������� ���� 
	void StartGame();//�������� ���� ����
	void Win(string Image);//��������� � ������
	float GetPowerBalanse() { return PowerBalance; }//��������

	~Game();//����������
};

