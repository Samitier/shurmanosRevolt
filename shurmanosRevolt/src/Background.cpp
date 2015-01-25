#include "Background.h"

Background::Background(void){}
Background::~Background(void){}

void Background::init(std::vector<Texture*>textures) {
	for (Texture* tex : textures){
       AnimatedSprite layer; 
	   Vector2<int> size = Vector2<int>(tex->getSize().x, tex->getSize().y);
	   layer.init(tex,Vector2<int>(size.x/2,size.y/2),size);
	   layers.push_back(layer);
	}
}

void Background::update(Camera* camera, int width) {	
	float levelx = ((camera->getCenter().x - SCREEN_WIDTH / 2) / (width - SCREEN_WIDTH));
	for (AnimatedSprite &layer : layers) {
		int x = layer.getSize().x / 2 + (width-layer.getSize().x)*levelx;
		layer.setPosition(Vector2f(x,layer.getPosition().y));
	}
}

void Background::render(RenderWindow *window) {
	for (AnimatedSprite &layer : layers) {
		layer.render(window);
	}
}