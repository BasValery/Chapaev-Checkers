#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(string texture)// онструктор
{
	image_pointer.loadFromFile(texture);
	texture_pointer.loadFromImage(image_pointer);
	sprite_pointer.setTexture(texture_pointer);

	chosen = false;
}


void HumanPlayer::DrawArrow(sf::RenderWindow & window)//ќтрисовываем направление полета шашки
{

	sf::Vector2i direction = sf::Mouse::getPosition(window);//ѕолучаем координаты мышки



	direction.x -= ChosenCheker.x;
	direction.y -= ChosenCheker.y;
	float forse = sqrt(direction.x*direction.x + direction.y*direction.y);
	//ѕолучаем вектор от шашки до мышки и нормализуем его


	sf::Vector2f direction_normal;
	direction_normal.x = direction.x / sqrt(direction.x*direction.x + direction.y*direction.y);
	direction_normal.y = direction.y / sqrt(direction.x*direction.x + direction.y*direction.y);

	//„ерез арккосинус Y координаты получаем угол на который отклонилась мышка относительно центра шашки
	float angle = acos(direction_normal.y);
	angle = angle * 180 / 3.141592;
	if (direction_normal.x > 0)
		angle = 360 - angle;
	
	sf::Vector2f perpendicular;//ѕолучаем перпендикул€р к вектору от шашки до мышки
	perpendicular.x = direction_normal.y;
	perpendicular.y = -direction_normal.x;

	//ѕоварачиваем изображение стрелки и сдвигаем таким образом чтобы она шла от шашки до мыши
	sprite_pointer.setRotation(angle);
	sprite_pointer.setScale(1, forse/ image_pointer.getSize().y <= 1.5 ? forse / image_pointer.getSize().y : 1.5);
	sprite_pointer.setPosition({ (ChosenCheker.x - (perpendicular.x * image_pointer.getSize().x/2)), (ChosenCheker.y - (perpendicular.y * image_pointer.getSize().x / 2)) });
	window.draw(sprite_pointer);

}

void HumanPlayer::SetCheker(sf::Vector2f Cheker)
{
	ChosenCheker = Cheker;
}


