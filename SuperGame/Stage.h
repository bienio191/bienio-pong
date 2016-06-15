#ifndef STAGE_H
#define STAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Scene.h"
#include "Settings.h"

class Stage {

public:
	Stage();
	virtual ~Stage();
	
	void addScene(Scene& scene, unsigned int position);
	void removeScene(Scene& scene);
	void removeScene(std::string name);
	void removeAll();
	Scene getScene(std::string name);
	unsigned int getHeight();
	unsigned int getWidth();
	void printInfo();

private:

	void refresh();
	std::vector<Scene> mScenes;
	unsigned int mHeight;
	unsigned int mWidth;

};

#endif

