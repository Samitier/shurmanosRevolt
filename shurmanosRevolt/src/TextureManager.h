#pragma once
#include "Utils.h"


class TextureManager
{
public:
	TextureManager(void);
	~TextureManager(void);

	static const int NUM_TEXTURES		=	2;
	static const int TEX_BACKGROUND		=	 0;
	static const int TEX_SPRITESHEET	=	 1;

	void init();
	Texture * getTexture(int id);

private:
	Texture texture[NUM_TEXTURES];
};



