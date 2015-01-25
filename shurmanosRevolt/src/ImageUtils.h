#pragma once
#include "Utils.h"

class ImageUtils {
public:
	ImageUtils(void);
	~ImageUtils(void);

	//makes a hole of radius r in the image img on position x,y
	static void makeHole(Image* img, int x, int y, int r);

};