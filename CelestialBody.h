/*
	Charles Baxter
	CelesitalBody.h PS2b
	10/6/2021
*/

#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CelestialBody : public sf::Drawable
{
public:
	CelestialBody();

	void update(sf::Vector2f& center, double scale);

	double getMass() const { return mass; };
	double getXPos() const { return xpos; };
	double getYPos() const { return ypos; };
	double getXVel() const { return xvel; };
	double getYVel() const { return yvel; };

	void chgXPos(double c) { xpos += c; };
	void chgYPos(double c) { ypos += c; };
	void chgXVel(double c) { xvel += c; };
	void chgYVel(double c) { yvel += c; };

	friend std::istream& operator>>(std::istream& in, CelestialBody& c);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	double xpos;
	double ypos;
	double xvel;
	double yvel;
	double mass;

	std::string name;
	sf::Texture tex;
	sf::Sprite spr;
};

#endif