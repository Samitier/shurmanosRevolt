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

//this operation is very slow. Should not be used in real time, only when loading things.
void ImageUtils::generateImageFromTiles(Image* img, Texture * tileset, const vector <vector <int> >& tiles, int tilesize) {
	Image tilesetImg = tileset->copyToImage(); //loading the image from file would be faster (we need an image factory, where to put it?)
	img->create(tiles[0].size()*tilesize, tiles.size()*tilesize, Color::Transparent);//we create a transparent image
	int tilesetWidth = tilesetImg.getSize().x / tilesize;
	for (int i = 0; i < tiles.size(); ++i) {
		for (int j = 0; j < tiles[i].size(); ++j) {
			if (tiles[i][j] == 0) continue;
			int x = (tiles[i][j]-1) % tilesetWidth;
			int y = (tiles[i][j]-1) / tilesetWidth;
			img->copy(tilesetImg, j*tilesize, i*tilesize, IntRect(x*tilesize, y*tilesize, tilesize, tilesize), true);
		}
	}
}