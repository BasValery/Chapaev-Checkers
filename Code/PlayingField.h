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
	
	sf::Image image_field;//���� �����������
	sf::Texture texture_field;//���� ��������
	sf::Sprite sprite_field;//���� ������
	string texture_cheker1;
	string texture_checker2;

	static float Entropy;//�������� ����������� ������� ��� ������������ ����� 
	
	vector<Checker *> player1; //������ ����� �������
	vector<Checker *> player2; 


public:
	PlayingField(string texture_field_file, string texture_cheker1, string texture_checker2);//����������� ������� ��������� �������
	void NewLevel(int ScorePlayer1, int ScorePlayer2);//��������� ����� �� ����� �������� ��� ����� ������
	~PlayingField();
	void Drow(sf::RenderWindow &window);//��������� ���� � �����
	//�������� �� �������������� ����� �� ������������ ������
	bool IsChekerPlayer1(sf::Vector2f &CoordClick);
	bool IsChekerPlayer2(sf::Vector2f &CoordClick);
	

	void SetChekerSpeed(sf::Vector2f Cheker, sf::Vector2f Vector, double Force);//������������� ����������� �������� �����
	void ShootFromPlayer2ToPlayer1(int FirstCheker, int SecondCheker, float forse, int Error = 0);//�������� ����� ������ � ������
	bool Move();//��������� �������� �� �����
	void CheckClash();//��������� ������������
	void CheckPenetration();
	void CheckExit();//��������� ����� �� ������� ������

	//�������
	float GetEntropy() { return Entropy; }
	int GetSizeOfPlayer1Chekers() { return player1.size(); }
	int GetSizeOfPlayer2Chekers() { return player2.size(); }
};