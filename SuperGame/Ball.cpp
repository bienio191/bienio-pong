#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include "Ball.h"
#include "Settings.h"
#include "Stage.h"
#include "Score.h"


Ball::Ball(Settings & settings, Stage & stage, Score & score) :
	mSettings(&settings),
	mStage(&stage),
	mScore(&score),
	mScene(stage.getScene("gameBody")) {

	mBody.setRadius(mSettings->getBallSize());
	mBody.setPosition(sf::Vector2f(mScene.getWidth()/2, (mScene.getHeight()/2) + mScene.getAbsolutePosition().y));
	mSpeedMultiplier = mSettings->getBallSpeedMultiplier();
}

Ball::~Ball() {
}

void Ball::move() {
	mBody.move(sf::Vector2f(mVelocity.x, mVelocity.y));
	handleBorderCollision();
}

sf::CircleShape Ball::getBody() {
	return mBody;
}

sf::Vector2f Ball::getVelocity() {
	return mVelocity;
}

void Ball::setVelocity(sf::Vector2f velocity) {
	mVelocity = sf::Vector2f(velocity.x * mSpeedMultiplier, velocity.y * mSpeedMultiplier);
}

void Ball::setSpeedMultiplier(float speedMultiplier) {
	mSpeedMultiplier = speedMultiplier;
}

void Ball::reset() {
	mBody.setRadius(mSettings->getBallSize());
	mBody.setPosition(sf::Vector2f(mScene.getWidth() / 2, (mScene.getHeight() / 2) + mScene.getAbsolutePosition().y));
	
	std::random_device rd; 
	std::mt19937 eng(rd()); 
	std::uniform_int_distribution<> distr(-5, 5); 
	int x = 0;
	int z = 0;
	do {
		
		x = distr(eng);
	} while(x > -2 && x < 2);

	std::uniform_int_distribution<> distr2(-1, 1);
	do { 
		z = distr2(eng);
	} while (!z);
	
	float y = sqrt(40 - pow(x, 2));
	y = y * z;
	
	mVelocity = sf::Vector2f(x, y);
}

void Ball::handleBorderCollision() {

	//bottom border collision
	if (mBody.getGlobalBounds().top + mBody.getGlobalBounds().height >= mScene.getHeight() + mScene.getAbsolutePosition().y) {
		mVelocity.y *= -1;
	}

	//top border collision
	if (mBody.getGlobalBounds().top <= mScene.getAbsolutePosition().y) {
		mVelocity.y *= -1;
	}

	//left border collision
	if (mBody.getGlobalBounds().left < mScene.getAbsolutePosition().x) {
		//std::cout << "****** 2 scored ******" << std::endl;
		//std::cout << mScene.getAbsolutePosition().x << std::endl;
		//std::cout << mBody.getGlobalBounds().left << std::endl;
		mScore->addScore(2);
		
	}

	//right border collision
	if (mBody.getGlobalBounds().left + mBody.getGlobalBounds().width > mScene.getWidth()) {
		//std::cout << "****** 1 scored ******" << std::endl;
		//std::cout << mBody.getGlobalBounds().left + mBody.getGlobalBounds().width << std::endl;
		//std::cout << mScene.getWidth() << std::endl;
		mScore->addScore(1);
	}

}

