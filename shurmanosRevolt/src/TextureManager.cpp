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
	texture[TEX_TILESET].loadFromFile("res/img/tileset.png");
    texture[TEX_PROTA].loadFromFile("res/img/prota_provisional.png");
    texture[TEX_ARM].loadFromFile("res/img/prota_arm_provisional.png");
}

Texture * TextureManager::getTexture(int id) {
    //if(id > NUM_TEXTURES) Utils::errLog("Texture id is out of bounds");
	return &texture[id];
}
