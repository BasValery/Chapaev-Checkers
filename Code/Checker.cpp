#include "Checker.h"

float Checker::force_of_friction = 0.1;

Checker::Checker(float X, float Y, string texture)
{
	Coord.x = X;
	Coord.y = Y;

	image_checker.loadFromFile(texture);
	texture_checker.loadFromImage(image_checker);
	sprite_checker.setTexture(texture_checker);
	direction.x = 0;
	direction.y = 0;

	forse_knock = 0;

}

sf::Vector2f Checker::GetCoordinates()
{
	return Coord;
}

void Checker::Show(sf::RenderWindow &window)
{
	sprite_checker.setPosition(Coord);
	window.draw(sprite_checker);
}

bool Checker::Move()
{
	if (forse_knock > 0.1)
	{
		Coord.x += direction.x*forse_knock;
		Coord.y += direction.y*forse_knock;
		forse_knock -= force_of_friction;
		return true;
	}
	else
		forse_knock = 0;
	return false;

}

void Checker::AddForse(sf::Vector2f Dir, float Forse)
{
	direction = Dir;
	forse_knock = Forse;

}

float Checker::Distance(Checker Object)
{
	sf::Vector2f Center1 = { GetCoordinates().x + 35, GetCoordinates().y + 35 };
	sf::Vector2f Center2 = { Object.GetCoordinates().x + 35,Object.GetCoordinates().y + 35 };


	return (  sqrt( (Center2.x - Center1.x) * (Center2.x - Center1.x) + (Center2.y - Center1.y) * (Center2.y - Center1.y)) );
}

float Checker::GetRadius()
{
	return image_checker.getSize().x / 2;
}

void Checker::SetCoord(sf::Vector2f coord)
{
	Coord = coord;
}

