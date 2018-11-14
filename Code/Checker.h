#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using std::string;
//����� �����
class Checker
{
	sf::Image image_checker;//���� �����������
	sf::Texture texture_checker;//���� ��������
	sf::Sprite sprite_checker;//���� ������

	static float force_of_friction; //���� ������ � �����

	sf::Vector2f Coord;//��������� �����

	float forse_knock;
	sf::Vector2f direction;//������ �������� �����
	
public:

	Checker(float X, float Y, string texture); //�����������
	
	sf::Vector2f GetCoordinates();//�������� ��� ��������� ��������� �����
	void Show(sf::RenderWindow &window);//��������� �����
	bool Move();//����� ��� ���� ����� ������ ��������� �� �����
	void AddForse(sf::Vector2f Dir, float Forse);//��������� �������� �����
	float Distance(Checker Object);//���������� �� ������ �����
	float GetRadius();//��������� ������� �����
	void SetCoord(sf::Vector2f coord);

	//������ ������� ����������
	static float GetForseFriction() { return force_of_friction; }
	float GetKnockForce() { return forse_knock; }
	sf::Vector2f GetDirecton() { return direction; }
			
};