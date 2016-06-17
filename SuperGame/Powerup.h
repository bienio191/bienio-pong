#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp> 

class Powerup {

public:
	Powerup();
	virtual ~Powerup();

	virtual void doAction();
	virtual sf::RectangleShape getBody();
	virtual bool isActive();
	virtual void update();

private:
	sf::Clock mInternalClock;
	sf::Vector2f mPosition;
	unsigned int mDurationInSeconds;
	bool mIsActive;
};

#endif

