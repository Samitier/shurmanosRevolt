#pragma once
#include "Includes.h"
#include <iostream>

#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	600
#define PIXELS_METER	20.0

//Useful macros
#define debLog(s) std::cout<<"[DEBUG]"<<s<<". From file "<<__FILE__<<" at line "<< __LINE__<<endl;  
#define errLog(s) std::cerr<<"[ERROR]"<<s<<". From file "<<__FILE__<<" at line "<< __LINE__<<endl;  
    
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
	
	static int metersToPixels (float f) {
        //TODO quick hack to avoid duplicating code, this needs fixing
        return metersToPixels(b2Vec2(f,0)).x; 
    }
    
    static float pixelsToMeters (int i) {
        //TODO quick hack to avoid duplicating code, this needs fixing
        return pixelsToMeters(Vector2<int> (i,0)).x;
    }
    
    
};