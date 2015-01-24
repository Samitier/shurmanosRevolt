#pragma once
#include "Utils.h"


class TextureManager
{
public:
	TextureManager(void);
	~TextureManager(void);

	static const int NUM_TEXTURES		=	6;
	static const int TEX_BACKGROUND		=	 0;
	static const int TEX_SPRITESHEET	=	 1;
	static const int TEX_BKG01			=	 2;
	static const int TEX_BKG02			=	 3;
	static const int TEX_BKG03			=	 4;
	static const int TEX_FLOOR			=	 5;

	void init();
	Texture * getTexture(int id);

private:
	Texture texture[NUM_TEXTURES];
};



