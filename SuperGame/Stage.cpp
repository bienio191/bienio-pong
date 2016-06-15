#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.h"
#include "Settings.h"
#include "Stage.h"


Stage::Stage():
	mWidth(800),
	mHeight(750) {

}


Stage::~Stage() {
}

void Stage::addScene(Scene & scene, unsigned int position) {
	mScenes.insert(mScenes.begin() + position, scene);
	refresh();
}

void Stage::removeScene(Scene & scene) {
	for (int nIndex = 0; nIndex < mScenes.size(); nIndex++) {
		if (scene.getName() == mScenes[nIndex].getName()) {
			mScenes.erase(mScenes.begin() + nIndex);
		}
	}

	refresh();
}

void Stage::removeScene(std::string name) {
	for (int nIndex = 0; nIndex < mScenes.size(); nIndex++) {
		if (name == mScenes[nIndex].getName()) {
			mScenes.erase(mScenes.begin() + nIndex);
		}
	}

	refresh();
}

void Stage::removeAll() {
	mScenes.clear();
	refresh();
}

Scene Stage::getScene(std::string name) {
	for (int nIndex = 0; nIndex < mScenes.size(); nIndex++) {
		if (name == mScenes[nIndex].getName()) {
			return mScenes[nIndex];
		}
	}
}

unsigned int Stage::getHeight() {
	return mHeight;
}

unsigned int Stage::getWidth() {
	return mWidth;
}

void Stage::refresh() {
	unsigned int currHeight = 0;

	if (mScenes.size() == 0) {
		mHeight = 0;
		mWidth = 0;
		return;
	}

	for (int nIndex = 0; nIndex < mScenes.size(); nIndex++) {
		mScenes[nIndex].setAbsolutePosition(sf::Vector2f(0, currHeight));
		mScenes[nIndex].setTopBorder(sf::Vector2f(0, currHeight - 5));
		mScenes[nIndex].setBottomBorder(sf::Vector2f(0, currHeight + mScenes[nIndex].getHeight() + 5));
		currHeight += mScenes[nIndex].getHeight();
	}

	mHeight = currHeight;
	mWidth = mScenes[0].getWidth();

	printInfo();
}

void Stage::printInfo() {
	std::cout << "*********************************" << std::endl;
	for (int nIndex = 0; nIndex < mScenes.size(); nIndex++) {
		mScenes[nIndex].printInfo();
	}
}
