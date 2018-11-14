#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(string texture)//�����������
{
	image_pointer.loadFromFile(texture);
	texture_pointer.loadFromImage(image_pointer);
	sprite_pointer.setTexture(texture_pointer);

	chosen = false;
}


void HumanPlayer::DrawArrow(sf::RenderWindow & window)//������������ ����������� ������ �����
{

	sf::Vector2i direction = sf::Mouse::getPosition(window);//�������� ���������� �����



	direction.x -= ChosenCheker.x;
	direction.y -= ChosenCheker.y;
	float forse = sqrt(direction.x*direction.x + direction.y*direction.y);
	//�������� ������ �� ����� �� ����� � ����������� ���


	sf::Vector2f direction_normal;
	direction_normal.x = direction.x / sqrt(direction.x*direction.x + direction.y*direction.y);
	direction_normal.y = direction.y / sqrt(direction.x*direction.x + direction.y*direction.y);

	//����� ���������� Y ���������� �������� ���� �� ������� ����������� ����� ������������ ������ �����
	float angle = acos(direction_normal.y);
	angle = angle * 180 / 3.141592;
	if (direction_normal.x > 0)
		angle = 360 - angle;
	
	sf::Vector2f perpendicular;//�������� ������������� � ������� �� ����� �� �����
	perpendicular.x = direction_normal.y;
	perpendicular.y = -direction_normal.x;

	//������������ ����������� ������� � �������� ����� ������� ����� ��� ��� �� ����� �� ����
	sprite_pointer.setRotation(angle);
	sprite_pointer.setScale(1, forse/ image_pointer.getSize().y <= 1.5 ? forse / image_pointer.getSize().y : 1.5);
	sprite_pointer.setPosition({ (ChosenCheker.x - (perpendicular.x * image_pointer.getSize().x/2)), (ChosenCheker.y - (perpendicular.y * image_pointer.getSize().x / 2)) });
	window.draw(sprite_pointer);

}

void HumanPlayer::SetCheker(sf::Vector2f Cheker)
{
	ChosenCheker = Cheker;
}


