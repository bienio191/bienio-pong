#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp> 

class Powerup {

public:
	Powerup();
	virtual ~Powerup();

	virtual void doAction() = 0;

private:
	sf::Clock mInternalClock;
	sf::Vector2f mPosition;
	unsigned int mDurationInSeconds;
};

#endif

