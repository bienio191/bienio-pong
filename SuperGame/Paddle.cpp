#include <iostream>
#include "Paddle.h"
#include "Settings.h"


Paddle::Paddle(unsigned int number, Settings & settings, Stage & stage) :
	mSettings(&settings),
	mStage(&stage),
	mNumber(number),
	mScene(stage.getScene("gameBody")) {

	mVelocity = mSettings->getPaddleVelocity();
	Scene mScene = mStage->getScene("gameBody");

	if (mNumber == 1) {
		mPosition = sf::Vector2f(
			mSettings->getPaddleMargin(),
			(mScene.getHeight() - mSettings->getPaddleWidth())/2 + mScene.getAbsolutePosition().y
		);

		mSize = sf::Vector2f(mSettings->getPaddleHeight(), mSettings->getPaddleWidth());
	}

	if (mNumber == 2) {
		mPosition = sf::Vector2f(
			mScene.getWidth() - mSettings->getPaddleHeight() - mSettings->getPaddleMargin(),
			(mScene.getHeight() - mSettings->getPaddleWidth()) / 2 + mScene.getAbsolutePosition().y
			);

		mSize = sf::Vector2f(mSettings->getPaddleHeight(), mSettings->getPaddleWidth());
	}

	mBody.setPosition(mPosition);
	mBody.setSize(mSize);

}


Paddle::~Paddle() {
	
}

//przenieœæ sterowanie do settings

void Paddle::handleInput() {
	
	if (mNumber == 1) {
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			mIsUp = true;
		else
			mIsUp = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			mIsDown = true;
		else
			mIsDown = false;

	}

	if (mNumber == 2) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			mIsUp = true;
		else
			mIsUp = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			mIsDown = true;
		else
			mIsDown = false;

	}
	
}

void Paddle::move() {
	
	if (mIsUp) {

		if(mBody.getGlobalBounds().top - mVelocity >= mScene.getAbsolutePosition().y)
			mBody.move(sf::Vector2f(0, -mVelocity));
			
		//std::cout << mBody.getPosition().x << " : " << mBody.getPosition().y << std::endl;
	}

	if (mIsDown) {

		if ((mBody.getGlobalBounds().top + mBody.getGlobalBounds().height) + mVelocity <= mScene.getAbsolutePosition().y + mScene.getHeight())
			mBody.move(sf::Vector2f(0, mVelocity));

		//std::cout << mBody.getPosition().x << " : " << mBody.getPosition().y << std::endl;
	}

}

void Paddle::reset() {
	if (mNumber == 1) {
		mPosition = sf::Vector2f(
			mSettings->getPaddleMargin(),
			(mScene.getHeight() - mSettings->getPaddleWidth()) / 2 + mScene.getAbsolutePosition().y
			);

		mSize = sf::Vector2f(mSettings->getPaddleHeight(), mSettings->getPaddleWidth());
	}

	if (mNumber == 2) {
		mPosition = sf::Vector2f(
			mScene.getWidth() - mSettings->getPaddleHeight() - mSettings->getPaddleMargin(),
			(mScene.getHeight() - mSettings->getPaddleWidth()) / 2 + mScene.getAbsolutePosition().y
			);

		mSize = sf::Vector2f(mSettings->getPaddleHeight(), mSettings->getPaddleWidth());
	}

	mBody.setPosition(mPosition);
	mBody.setSize(mSize);

}

void Paddle::setNumber(int number) {
	mNumber = number;
}

void Paddle::setPosition(sf::Vector2f position) {
	mPosition = position;
}

void Paddle::setSize(sf::Vector2f size) {
	mSize = size;
}

void Paddle::setVeloctiy(int velocity) {
	mVelocity = velocity;
}

int Paddle::getNumber() {
	return mNumber;
}

sf::Vector2f Paddle::getPosition() {
	return mPosition;
}

sf::Vector2f Paddle::getSize() {
	return mSize;
}

sf::RectangleShape Paddle::getBody() {
	return mBody;
}

int Paddle::getVelocity() {
	return mVelocity;
}
