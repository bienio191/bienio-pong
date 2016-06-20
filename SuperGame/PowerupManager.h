#ifndef POWERUP_MAPANGER_H
#define POWERUP_MAPANGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Settings.h"
#include "Stage.h"
#include "Score.h"
#include "Powerup.h"
#include "P_MakeNarrower.h"

class PowerupManager {

public:
	PowerupManager(sf::Clock& gameClock);
	virtual ~PowerupManager();
	std::vector<Powerup> getActivePowerups();

private:
	void updatePowerups();

	std::vector<Powerup> mActivePowerups;
	sf::Clock * mGameClock;
	static int globalCounter;
	static int previousCounter;

};

#endif

