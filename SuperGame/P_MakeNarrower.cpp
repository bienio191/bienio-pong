#include "P_MakeNarrower.h"
#include <random>
#include <iostream>

P_MakeNarrower::P_MakeNarrower() {

	mBody.setOutlineColor(sf::Color::Yellow);
	mBody.setOutlineThickness(5);
	mBody.setPosition(350, 350);
	mBody.setSize(sf::Vector2f(10.f, 10.f));
	mBody.setFillColor(sf::Color::Yellow);
}


P_MakeNarrower::~P_MakeNarrower() {

}

void P_MakeNarrower::doAction() {

}

sf::RectangleShape P_MakeNarrower::getBody() {
	return mBody;
}
