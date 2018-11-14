#pragma once
#include <SFML/Graphics.hpp>

//Функции для работы с векторами
template <typename T>
T Distanse(sf::Vector2<T> vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y));
}

template <typename T>
sf::Vector2<T> Normalize(sf::Vector2<T> vector)
{
	float dist = Distanse(vector);
	return{ vector.x / dist, vector.y / dist };
}