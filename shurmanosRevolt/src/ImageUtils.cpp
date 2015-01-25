#include "ImageUtils.h"

void ImageUtils::makeHole(Image* img, int x, int y, int r){
	if (!(x<0 || y<0 || x >= img->getSize().x || y >= img->getSize().y || r == 0)) {
		int prey = -1;
		for (int i = 0; i<r; ++i) {
			float ang = ((float)i / (float)r)*1.57079;
			int px = r*cosf(ang);
			int py = r*sinf(ang);
			for (int k = prey; k<py; ++k) {
				for (int j = x - px; j <= x + px; ++j) {
					if (j >= 0 && j<img->getSize().x){
						if (y - (k + 1) >= 0) img->setPixel(j, y - (k + 1), Color::Transparent);
						if (y + (k + 1)< img->getSize().y) img->setPixel(j, y + (k + 1), Color::Transparent);
					}
				}
			}
			prey = py;
		}
	}
}