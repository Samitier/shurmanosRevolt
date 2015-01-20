#pragma once
#include "Includes.h"

#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600
#define PIXELS_METER	20.0

class Utils {
	public:
		Utils(void){}
		~Utils(void){}

	static b2Vec2 pixelsToMeters(Vector2<int> v) {
		b2Vec2 vect;
		vect.x = (float32)v.x/PIXELS_METER;
		vect.y = (SCREEN_HEIGHT - (float32)v.y) /PIXELS_METER;
		return vect;
	}

	static Vector2f metersToPixels (b2Vec2 v) {
		Vector2f vect;
		vect.x = v.x * PIXELS_METER;
		vect.y = SCREEN_HEIGHT - v.y*PIXELS_METER;
		return vect;
	}
};