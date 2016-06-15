#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Stage.h"
#include "Scene.h"

class Paddle {

public:
	Paddle(unsigned int number, Settings & settings, Stage & stage);
	virtual ~Paddle();

	void handleInput();
	void move();
	void reset();

	//getters and setters
	void setNumber(int number);
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	void setVeloctiy(int velocity);

	int getNumber();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::RectangleShape getBody();
	int getVelocity();

private:
	int mNumber;
	int mVelocity;
	sf::RectangleShape mBody;
	sf::Vector2f mPosition;
	sf::Vector2f mSize;

	bool mIsUp;
	bool mIsDown;

	Settings * mSettings;
	Stage * mStage;
	Scene mScene;

};

#endif