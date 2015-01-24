#pragma once
#include "Utils.h"
#include "AnimatedSprite.h"

class Background {

public:
	Background(void);
	~Background(void);

	void init(std::vector<Texture*>textures);
	void update();
	void render(RenderWindow* window);

private:

	std::vector<AnimatedSprite> layers;

};