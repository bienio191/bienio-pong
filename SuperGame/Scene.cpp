#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Settings.h"


Scene::Scene(std::string name, unsigned int width, unsigned int height) :
	mName(name),
	mWidth(width),
	mHeight(height) {

	mTopBorderLine = sf::RectangleShape(sf::Vector2f(mWidth, 5));
	mTopBorderLine.setFillColor(sf::Color::Red);
	mBottomBorderLine = sf::RectangleShape(sf::Vector2f(mWidth, 5));
	mBottomBorderLine.setFillColor(sf::Color::Red);
}

Scene::~Scene() {
}

void Scene::setAbsolutePosition(sf::Vector2f absolutePosition) {
	mAbsolutePosition = absolutePosition;
}

void Scene::printInfo() {
	std::cout << "Name = " << mName << " ; AbsX = " << mAbsolutePosition.x << " AbsY = " << mAbsolutePosition.y << std::endl;
	std::cout << "Name = " << mName << " ; TopX = " << mTopBorderLine.getPosition().x << " TopY = " << mTopBorderLine.getPosition().y << std::endl;
}

std::string Scene::getName() {
	return mName;
}

unsigned int Scene::getWidth() {
	return mWidth;
}

unsigned int Scene::getHeight() {
	return mHeight;
}

sf::Vector2f Scene::getAbsolutePosition() {
	return mAbsolutePosition;
}

sf::RectangleShape Scene::getTopBorderLine() {
	return mTopBorderLine;
}

sf::RectangleShape Scene::getBottomBorderLine() {
	return mBottomBorderLine;
}

void Scene::setTopBorder(sf::Vector2f topBorder) {
	mTopBorderLine.setPosition(topBorder);
}

void Scene::setBottomBorder(sf::Vector2f bottomBorder) {
	mBottomBorderLine.setPosition(bottomBorder);
}


