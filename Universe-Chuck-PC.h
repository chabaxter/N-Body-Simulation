/*
	Charles Baxter
	Universe.h PS2b
	10/6/2021
*/

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iomanip>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "CelestialBody.h"

class Universe : public sf::Drawable
{
public:
	Universe(double ir, sf::Vector2u& idim, int inumParticles);

	void step(double seconds);
	
	friend std::ostream& operator<<(std::ostream& out, Universe& u);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void accelerate(CelestialBody& a, CelestialBody& b, double* const ret);

	double G = 6.67e-11;
	double radius;
	double scale;

	sf::Texture bgrndTex;
	sf::Sprite bgrndSpr;

	sf::Vector2f center;
	std::vector<std::unique_ptr<CelestialBody>> bodies_uptr;
};

#endif