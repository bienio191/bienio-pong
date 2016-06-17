#include "Game.h"

//Aaything2 2222
Game::Game() {

	mState = END;
	if (!mFont.loadFromFile("GoodDog.otf")) {
		return;
	}
	mState = MENU;


}


Game::~Game() {
	
}

void Game::run() {
	while (mState != END) {
		switch (mState) {
			case GameState::MENU:
				menu();
				break;
			case GameState::GAME_AI:
				game(false);
				break;
			case GameState::GAME_PVP:
				game(true);
				break;
			case GameState::GAME_OVER:
				game(true);
				break;
		}
	}
}

void Game::menu() {
	sf::RenderWindow window(sf::VideoMode(mSettings.getWindowWidth(), mSettings.getWindowHeight()), mSettings.getName());
	window.setFramerateLimit(mSettings.getFramerateLimit());
	sf::Text title("Bienio Pong", mFont, 80);
	title.setStyle(sf::Text::Bold);
	title.setPosition(mStage.getWidth() / 2 - title.getGlobalBounds().width / 2, 20);
	const int ile = 3;

	sf::Text tekst[ile];

	std::string str[] = { "Player vs AI", "Player vs Player", "Exit" };
	for (int i = 0; i < ile; i++) {
		tekst[i].setFont(mFont);
		tekst[i].setCharacterSize(65);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(mStage.getWidth() / 2 - tekst[i].getGlobalBounds().width / 2, 250 + i * 120);
	}

	while (mState == MENU) {

		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				mState = END;
			} else if (tekst[0].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
				mState = GAME_AI;
			} else if (tekst[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
				mState = GAME_PVP;
			} else if (tekst[2].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
				mState = END;
			}
		}

		for (int i = 0; i<ile; i++) {
			if (tekst[i].getGlobalBounds().contains(mouse)) {
				tekst[i].setColor(sf::Color::Cyan);
			} else {
				tekst[i].setColor(sf::Color::White);
			}	
		}


		window.clear();
		window.draw(title);

		for (int i = 0; i<ile; i++)
			window.draw(tekst[i]);

		window.display();
	}
}

void Game::game(bool isPVP) {

	mStage.removeAll();
	Scene gameHeader("gameHeader", 800, 100);
	Scene gameBody("gameBody", 800, 600);
	Scene gameFooter("gameFooter", 800, 100);
	mStage.addScene(gameHeader, 0);
	mStage.addScene(gameBody, 1);
	mStage.addScene(gameFooter, 2);
	Score score(mStage);
	Paddle paddle1(1, mSettings, mStage);
	Paddle paddle2(2, mSettings, mStage);
	Ball ball(mSettings, mStage, score);
	sf::Text timeText;
	timeText.setFont(mFont);
	timeText.setColor(sf::Color::White);
	timeText.setCharacterSize(30);
	timeText.setPosition(20, mStage.getScene("gameFooter").getAbsolutePosition().y + 40);

	sf::RenderWindow window(sf::VideoMode(mStage.getWidth(), mStage.getHeight()), mSettings.getName());
	window.setFramerateLimit(mSettings.getFramerateLimit());

	mGameClock.restart();
	while (mState == GAME_AI || mState == GAME_PVP) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mState = END;
			} else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				mState = MENU;
			}
		}


		if (score.checkIfReset()) {
			resetGame(paddle1, paddle2, ball, window, score, mStage);
		}

		window.clear();

		int elapsedSeconds = mGameClock.getElapsedTime().asSeconds();
		timeText.setString("Elapsed time: " + std::to_string(elapsedSeconds));
		paddle1.handleInput();
		paddle1.move();

		if (isPVP) {
			paddle2.handleInput();
		} else {
			paddle2.handleAI(ball);
		}

		paddle2.move();
		handleCollision(paddle1, paddle2, ball);

		window.draw(paddle1.getBody());
		window.draw(paddle2.getBody());
		window.draw(ball.getBody());
		window.draw(score.getScoreText());
		window.draw(mStage.getScene("gameBody").getBottomBorderLine());
		window.draw(mStage.getScene("gameBody").getTopBorderLine());
		window.draw(timeText);
		ball.move();
		window.display();
	}

}

void Game::gameOver() {


}

sf::Vector2f Game::calculateVelocity(Paddle& paddle, Ball& ball) {

	///////////////////////////////
	// paddle-zone representation//
	///////////////////////////////
	//  |1|
	//  |2|
	//  |3|       
	//  |4|       *
	//  |5|
	//  |6|
	//  |7|

	float relativeIntersectY = (paddle.getBody().getGlobalBounds().top + (paddle.getBody().getGlobalBounds().height / 2)) - ball.getBody().getGlobalBounds().top;
	float normValue = (relativeIntersectY / (paddle.getBody().getGlobalBounds().height / 2));

	//1
	if (isInBounds(normValue, (float) 0.8, (float)1)) {
		//cout << "isInBounds(normValue, 0.8, 1)" << endl;
		return sf::Vector2f(2.3, -5.2);
		//2
	}
	else if (isInBounds(normValue, (float) 0.6, (float) 0.8)) {
		//cout << "isInBounds(normValue, 0.6, 0.8)" << endl;
		return sf::Vector2f(3.2, -4.3);
		//3
	}
	else if (isInBounds(normValue, (float) 0.1, (float) 0.6)) {
		//cout << "isInBounds(normValue, 0.1, 0.6)" << endl;
		return sf::Vector2f(4.3, -3.2);
		//4
	}
	else if (isInBounds(normValue, (float)-0.1, (float) 0.1)) {
		//cout << "isInBounds(normValue, -0.1, 0.1)" << endl;
		return sf::Vector2f(5.5, 0);
		//5
	}
	else if (isInBounds(normValue, (float)-0.6, (float)-0.1)) {
		//cout << "isInBounds(normValue, -0.6, -0.1)" << endl;
		return sf::Vector2f(4.3, 3.2);
		//6
	}
	else if (isInBounds(normValue, (float)-0.8, (float)-0.6)) {
		//cout << "isInBounds(normValue, -0.8, -0.6)" << endl;
		return sf::Vector2f(3.2, 4.3);
		//7
	}
	else if (isInBounds(normValue, (float)-1, (float)-0.8)) {
		//cout << "isInBounds(normValue, -1, -0.8)" << endl;
		return sf::Vector2f(2.3, 5.2);
	}

	return sf::Vector2f(4.2, 4.1);

}

void Game::resetGame(Paddle & paddle1, Paddle & paddle2, Ball & ball, sf::RenderWindow & window, Score & score, Stage & stage) {
	paddle1.reset();
	paddle2.reset();
	ball.reset();


	//text indicating which player has won the game
	sf::Font font;
	sf::Text textStart;
	font.loadFromFile("GoodDog.otf");
	textStart.setFont(font);
	textStart.setCharacterSize(40);
	textStart.setStyle(sf::Text::Bold);
	textStart.setColor(sf::Color::White);
	textStart.setString("Click space to start!");
	sf::Vector2f position(
		(stage.getScene("gameBody").getWidth() - textStart.getGlobalBounds().width) / 2,
		((stage.getScene("gameBody").getHeight() - textStart.getGlobalBounds().height) / 2) + stage.getScene("gameBody").getAbsolutePosition().y
	);
	textStart.setPosition(position);

	window.clear();
	window.draw(score.getScoreText());
	window.draw(textStart);
	window.draw(paddle1.getBody());
	window.draw(paddle2.getBody());
	window.draw(stage.getScene("gameBody").getBottomBorderLine());
	window.draw(stage.getScene("gameBody").getTopBorderLine());
	window.display();

	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (mState == GAME_AI || mState == GAME_PVP)) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mState = END;
			} else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				mState = MENU;
			}
		}
	}
	mGameClock.restart();
}

void Game::handleCollision(Paddle & paddle1, Paddle & paddle2, Ball & ball) {
	if (paddle1.getBody().getGlobalBounds().intersects(ball.getBody().getGlobalBounds())) {
		sf::Vector2f newVelocity = calculateVelocity(paddle1, ball);
		ball.setVelocity(newVelocity);
	}

	if (paddle2.getBody().getGlobalBounds().intersects(ball.getBody().getGlobalBounds())) {
		sf::Vector2f newVelocity = calculateVelocity(paddle2, ball);
		sf::Vector2f reflectedNewVelocity = sf::Vector2f(newVelocity.x * (-1), newVelocity.y);
		ball.setVelocity(reflectedNewVelocity);
	}
}

template <typename T>
bool Game::isInBounds(const T& value, const T& low, const T& high) {
	return (value > low) && !(value > high); //  is int range (low, high]
}
