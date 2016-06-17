#include "PowerupManager.h"

int PowerupManager::globalCounter = 0;
int PowerupManager::previousCounter = 0;

PowerupManager::PowerupManager(sf::Clock &gameClock) {
	mGameClock = &gameClock;
}


PowerupManager::~PowerupManager() {

}

std::vector<Powerup> PowerupManager::getActivePowerups() {
	updatePowerups();
	return mActivePowerups;
}

void PowerupManager::updatePowerups() {
	previousCounter = globalCounter;
	globalCounter = mGameClock->getElapsedTime().asSeconds() / 5;

	if (globalCounter > previousCounter) {
		//generate powerup
		P_MakeNarrower powerup;
		mActivePowerups.push_back(powerup);
	}
}
