#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "Settings.h"

class Scene {

public:
	Scene(std::string name, unsigned int width, unsigned int height);
	virtual ~Scene();
	void setAbsolutePosition(sf::Vector2f absoultePosition);
	void printInfo();
	std::string getName();
	unsigned int getWidth();
	unsigned int getHeight();
	sf::Vector2f getAbsolutePosition();
	sf::RectangleShape getTopBorderLine();
	sf::RectangleShape getBottomBorderLine();
	void setTopBorder(sf::Vector2f topBorder);
	void setBottomBorder(sf::Vector2f bottomBorder);

private:
	std::string mName;
	unsigned int mWidth;
	unsigned int mHeight;
	sf::Vector2f mAbsolutePosition;
	sf::RectangleShape mTopBorderLine;
	sf::RectangleShape mBottomBorderLine;
	
};


#endif
