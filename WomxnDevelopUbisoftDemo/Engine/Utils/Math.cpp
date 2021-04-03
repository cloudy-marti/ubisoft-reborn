#include <stdafx.h>

double getDistance(const sf::Vector2f& first, const sf::Vector2f& second)
{
	return pow(pow(first.x - second.x, 2) + pow(first.y - second.y, 2), 0.5);
}