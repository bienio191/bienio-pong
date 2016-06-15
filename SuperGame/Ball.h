#ifndef BALL_H
#define BALL_H

#include <SFML\System.hpp>
#include "Settings.h"
#include "Scene.h"
#include "Stage.h"
#include "Score.h"

class Ball {

public:
	Ball(Settings & settings, Stage & stage, Score & score);
	virtual ~Ball();

	void move();

	//getters and setters
	sf::CircleShape getBody();
	sf::Vector2f getVelocity();

	void setVelocity(sf::Vector2f velocity);
	void setSpeedMultiplier(float speedMultiplier);
	void reset();

private:

	void handleBorderCollision();

	sf::CircleShape mBody;
	sf::Vector2f mVelocity;
	sf::Vector2f mPosition;
	unsigned int mSize;
	float mSpeedMultiplier;

	Settings * mSettings;
	Stage * mStage;
	Score * mScore;
	Scene mScene;
	static sf::Clock bufferStopwatch;
};



#endif

