#include "TextureManager.h"


TextureManager::TextureManager(void) {}
TextureManager::~TextureManager(void){}


void TextureManager::init() {
	texture[TEX_BACKGROUND].loadFromFile("res/img/bkg.png");
	texture[TEX_SPRITESHEET].loadFromFile("res/img/tank.png");
}

Texture * TextureManager::getTexture(int id) {
	return &texture[id];
}
