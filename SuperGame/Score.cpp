#include <iostream>
#include "Score.h"
#include "Stage.h"



Score::Score(Stage & stage) :
	mPlayer1Result(0),
	mPlayer2Result(0),
	mStage(&stage),
	mResetGame(true) {

	mFont.loadFromFile("GoodDog.otf");

	refresh();
}


Score::~Score() {
}

void Score::addScore(unsigned int playerNb) {
	if (playerNb == 1) {
		mPlayer1Result += 1;
	} 
	if (playerNb == 2) {
		mPlayer2Result += 1;
	}

	mResetGame = true;

}

sf::Text Score::getScoreText() {
	refresh();
	return mText;
}

bool Score::checkIfReset() {
	if (mResetGame) {
		mResetGame = false;
		return true;
	} else {
		return false;
	}
}

void Score::refresh() {
	mStringText = "Player 1    " + std::to_string(mPlayer1Result) + " : " + std::to_string(mPlayer2Result) + "    Player 2";
	mText = sf::Text(mStringText, mFont);
	mText.setCharacterSize(40);
	mText.setStyle(sf::Text::Bold);
	mText.setColor(sf::Color::White);
	mPosition = sf::Vector2f(
		(mStage->getScene("gameHeader").getWidth() - mText.getGlobalBounds().width) / 2,
		((mStage->getScene("gameHeader").getHeight() - mText.getGlobalBounds().height) / 2) + mStage->getScene("gameHeader").getAbsolutePosition().y
		);
	mText.setPosition(mPosition);
}
