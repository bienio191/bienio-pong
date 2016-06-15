#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include "Stage.h"

class Score {

public:
	Score(Stage & stage);
	virtual ~Score();

	void addScore(unsigned int playerNb);
	sf::Text getScoreText();
	bool checkIfReset();

private:

	void refresh();

	sf::Font mFont;
	sf::Text mText;
	sf::Vector2f mPosition;
	std::string mStringText;
	unsigned int mPlayer1Result;
	unsigned int mPlayer2Result;
	bool mResetGame;

	Stage * mStage;

};

#endif

