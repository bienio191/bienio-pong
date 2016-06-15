#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {

public:
	Settings();
	virtual ~Settings();

	//getters and setters
	std::string getName();
	unsigned int getFramerateLimit();
	unsigned int getWindowWidth();
	unsigned int getWindowHeight();
	unsigned int getPaddleVelocity();
	sf::Vector2f getBallVelocity();
	float getPaddleMargin();
	float getPaddleWidth();
	float getPaddleHeight();
	float getBallSize();
	float getBallSpeedMultiplier();

	void setGameName(std::string gameName);
	void setBallSpeedMultiplier(float ballSpeedMultiplier);

private:

	std::string mGameName;
	unsigned int mFramerateLimit;
	unsigned int mWindowWidth;
	unsigned int mWindowHeight;
	unsigned int mPaddleVelocity;
	sf::Vector2f mBallVelocity;
	float mBallSpeedMuliplier;
	float mPaddleMargin;
	float mPaddleWidth;
	float mPaddleHeight;
	float mBallSize;

};

#endif