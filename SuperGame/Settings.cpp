#include <iostream>
#include <SFML/Graphics.hpp>
#include "Settings.h"

Settings::Settings() :
	mGameName("Bienio Super Pong"),
	mWindowWidth(800),
	mWindowHeight(750),
	mFramerateLimit(60),
	mPaddleVelocity(8),
	mBallVelocity(sf::Vector2f(4.f, 4.f)),
	mPaddleMargin(5.f),
	mPaddleWidth(120.f),
	mPaddleHeight(10.f),
	mBallSize(4.f),
	mBallSpeedMuliplier(2.6) {

}


Settings::~Settings() {
}

std::string Settings::getName() {
	return mGameName;
}

unsigned int Settings::getFramerateLimit() {
	return mFramerateLimit;
}

unsigned int Settings::getWindowWidth() {
	return mWindowWidth;
}

unsigned int Settings::getWindowHeight() {
	return mWindowHeight;
}

unsigned int Settings::getPaddleVelocity() {
	return mPaddleVelocity;
}

sf::Vector2f Settings::getBallVelocity() {
	return mBallVelocity;
}

float Settings::getPaddleMargin() {
	return mPaddleMargin;
}

float Settings::getPaddleWidth() {
	return mPaddleWidth;
}

float Settings::getPaddleHeight() {
	return mPaddleHeight;
}

float Settings::getBallSize() {
	return mBallSize;
}

float Settings::getBallSpeedMultiplier()
{
	return mBallSpeedMuliplier;
}

void Settings::setGameName(std::string gameName) {
	mGameName = gameName;
}

void Settings::setBallSpeedMultiplier(float ballSpeedMultiplier) {
	mBallSpeedMuliplier = ballSpeedMultiplier;
}
