#pragma once
#include "Utils.h"
#include "Camera.h"
#include "AnimatedSprite.h"

class Background {

public:
	Background(void);
	~Background(void);

	void init(std::vector<Texture*>textures);
	
	void update(Camera *camera, int width);

	void render(RenderWindow* window);

private:
	std::vector<AnimatedSprite> layers;

};