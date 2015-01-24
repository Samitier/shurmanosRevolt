#include "TextureManager.h"


TextureManager::TextureManager(void) {}
TextureManager::~TextureManager(void){}


void TextureManager::init() {
	texture[TEX_BACKGROUND].loadFromFile("res/img/bkg.png");
	texture[TEX_SPRITESHEET].loadFromFile("res/img/tank.png");
	texture[TEX_BKG01].loadFromFile("res/img/bkg01.png");
	texture[TEX_BKG02].loadFromFile("res/img/bkg02.png");
	texture[TEX_BKG03].loadFromFile("res/img/bkg03.png");
	texture[TEX_FLOOR].loadFromFile("res/img/floor.png");
}

Texture * TextureManager::getTexture(int id) {
	return &texture[id];
}
