/*
	Charles Baxter
	Universe.cpp PS2b
	10/6/2021
*/

#include "Universe.h"

using std::cout;
using std::setw;
using std::scientific;
using std::endl;

Universe::Universe(double ir, sf::Vector2u& idim, int inumParticles) 
	: radius(ir),
	scale{ ((idim.x > idim.y) ? idim.y : idim.x) / (2 * radius) },
	center{ (float(idim.x) / 2), (float(idim.y) / 2) } {

	bgrndTex.loadFromFile("background.jpg");
	bgrndSpr.setTexture(bgrndTex);

	double uScale = (bgrndSpr.getGlobalBounds().width / idim.x >
		bgrndSpr.getGlobalBounds().height / idim.y)
		? idim.y / bgrndSpr.getGlobalBounds().height
		: idim.x / bgrndSpr.getGlobalBounds().width;
	bgrndSpr.scale(float(uScale), float(uScale));

	for (int i = 0; i < inumParticles; i++) {
		bodies_uptr.push_back(std::make_unique<CelestialBody>());
		std::cin >> *bodies_uptr[i];
	}
}

void Universe::step(double seconds) {
	for (uint16_t i = 0; i < bodies_uptr.size(); i++) {
		double totalAcc[] = { 0, 0 };
		for (uint16_t j = 0; j < bodies_uptr.size(); j++) {
			// do not caluclate gravity with itself
			if (i != j) {
				// calculate acceleration
				accelerate(*bodies_uptr[i], *bodies_uptr[j], totalAcc);
			}
		}
		// change velocities
		bodies_uptr[i]->chgXVel(totalAcc[0] * seconds);
		bodies_uptr[i]->chgYVel(totalAcc[1] * seconds);
		// move positions
		bodies_uptr[i]->chgXPos(bodies_uptr[i]->getXVel() * seconds);
		bodies_uptr[i]->chgYPos(bodies_uptr[i]->getYVel() * seconds);
		// update sprites
		bodies_uptr[i]->update(center, scale);
	}
}

// change velocities based on the masses and posiitons
void Universe::accelerate(CelestialBody& a, CelestialBody& b, double* const ret) {
	double dx = b.getXPos() - a.getXPos();
	double dy = b.getYPos() - a.getYPos();

	double r = sqrt(pow(dx, 2) + pow(dy, 2));

	double F = G * a.getMass() * b.getMass() / pow(r, 2);

	ret[0] += F * dx / (r * a.getMass());
	ret[1] += F * dy / (r * a.getMass());
}

std::ostream& operator<<(std::ostream& out, Universe& u) {
	cout << u.bodies_uptr.size() << endl << u.radius << endl;
	
	for (uint16_t i = 0; i < u.bodies_uptr.size(); i++) {
		cout << setw(13) << scientific << u.bodies_uptr[i]->getXPos() << " ";
		cout << setw(13) << scientific << u.bodies_uptr[i]->getYPos() << " ";
		cout << setw(13) << scientific << u.bodies_uptr[i]->getXVel() << " ";
		cout << setw(13) << scientific << u.bodies_uptr[i]->getYVel() << " ";
		cout << setw(13) << scientific << u.bodies_uptr[i]->getMass() << " ";
		cout << setw(13) << scientific << u.bodies_uptr[i]->getName() << " ";
		cout << endl;
	}

	return out;
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(bgrndSpr);
	for (uint16_t i = 0; i < bodies_uptr.size(); i++) {
		target.draw(*bodies_uptr[i]);
	}
}