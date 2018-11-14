#pragma once
#include "Player.h"
#include <string>
#include <math.h>
#include <iostream>
using std::string;
//����� ������ ��������
class HumanPlayer : public Player
{
	//������� ��� ����������� ������ �����
	sf::Image image_pointer;//���� �����������
	sf::Texture texture_pointer;//���� ��������
	sf::Sprite sprite_pointer;//���� ������
	sf::Vector2f ChosenCheker;//��������� ������� �����

	bool chosen;//���������� ������� ���������� ������ �� ����� �����

public:
	HumanPlayer(string texture);//����������� ������� �������� ���� � ����� ��������
	void DrawArrow(sf::RenderWindow &window);//��������� ����������� �����
	void SetCheker(sf::Vector2f Cheker);//����������� ��������� �����


	void ChangeChose() { chosen = chosen ? false : true; }//��������� ��������� ������
	//�������
	bool GetChose() { return chosen; }
	sf::Vector2f GetCheker() { return ChosenCheker; }

};

