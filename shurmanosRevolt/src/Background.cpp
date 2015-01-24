#include "Background.h"

Background::Background(void){}
Background::~Background(void){}

void Background::init(std::vector<Texture*>textures) {
	for each (Texture* tex in textures){
       AnimatedSprite layer;
	   layer.init(tex,Vector2<int>(0,0), Vector2<int>(0,0));
	   layers.push_back(layer);
	}
}

//this updante needs the player position, to move each layer. Before implementing this we need to decide the final units of the game
void Background::update() {

}

void Background::render(RenderWindow *window) {
	for each (AnimatedSprite layer in layers) {
		layer.render(window);
	}
}