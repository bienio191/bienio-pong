#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Settings.h"
#include "Stage.h"
#include "Score.h"
#include "Powerup.h"

class Game {

public:
	Game();
	virtual ~Game();
	void run();

private:
	enum GameState { MENU, GAME_AI, GAME_PVP, GAME_OVER, END };
	GameState mState;
	sf::Font mFont;
	Settings mSettings;
	Stage mStage;
	sf::Clock mGameClock;

	void menu();
	void game(bool isPVP);
	void gameOver();
	sf::Vector2f calculateVelocity(Paddle& paddle, Ball& ball);
	template <typename T>
	bool isInBounds(const T& value, const T& low, const T& high);
	void resetGame(Paddle& paddle1, Paddle& paddle2, Ball& ball, sf::RenderWindow& window, Score& score, Stage& stage);
	void handleCollision(Paddle& paddle1, Paddle& paddle2, Ball& ball);

};


#endif
