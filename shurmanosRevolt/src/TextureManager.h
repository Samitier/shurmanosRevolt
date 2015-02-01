#pragma once
#include "Utils.h"


class TextureManager
{
public:
	TextureManager(void);
	~TextureManager(void);

	static const int NUM_TEXTURES		=	9;
	static const int TEX_BACKGROUND		=	 0;
	static const int TEX_SPRITESHEET	=	 1;
	static const int TEX_BKG01			=	 2;
	static const int TEX_BKG02			=	 3;
	static const int TEX_BKG03			=	 4;
	static const int TEX_FLOOR			=	 5;
	static const int TEX_TILESET        =	 6;
    static const int TEX_PROTA          =    7;
    static const int TEX_ARM            =    8;


	void init();
	Texture * getTexture(int id);

private:
	Texture texture[NUM_TEXTURES];
};



