/*
	Charles Baxter
	CelesitalBody.cpp PS2b
	10/6/2021
*/

#include "CelestialBody.h"

CelestialBody::CelestialBody()
	: xpos{}, ypos{}, xvel{}, yvel{}, mass{}, name{}, tex{}, spr{} {}

void CelestialBody::update(sf::Vector2f& center, double scale) {
	spr.setPosition(
		center.x + (xpos*scale),
		center.y - (ypos*scale)
	);
}

std::istream& operator>>(std::istream& in, CelestialBody& c) {
	in >> c.xpos >> c.ypos >> c.xvel >> c.yvel >> c.mass >> c.name;
	c.tex.loadFromFile(c.name);
	c.spr.setTexture(c.tex);
	// set the origin to the center of the sprite instead of the top left
	c.spr.setOrigin(
		c.spr.getGlobalBounds().width / 2,
		c.spr.getGlobalBounds().height / 2
	);
	return in;
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(spr, states);
}