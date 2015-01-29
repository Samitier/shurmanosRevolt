#include "LevelParser.h"

LevelParser::LevelParser(void){}
LevelParser::~LevelParser(void){}

//reads json file and parses it to a value object that contains the root document
void LevelParser::parseLevel(string name) {
	string filename = "res/levels/" + name;
	Reader reader;
	ifstream jsonFile(filename, std::ifstream::in);
	if (!jsonFile.is_open()) cerr << "Can't open " << filename << endl;
	else {
		bool parsingSuccessful = reader.parse(jsonFile, level);
		if (!parsingSuccessful)	cerr << reader.getFormattedErrorMessages() << endl;
	}
}

//gets the layer "facade" of the json generated with Tiled, and transfoms it into an int matrix
vector< vector<int> > LevelParser::getFacadeLayer() {
	Value layers = level["layers"];
	for (Value& layer : layers) {
		if (layer["name"].asString() == "facade") {
			int width = layer["width"].asInt(), height = layer["height"].asInt();
			vector< vector<int> >facadeAsVector(height, vector<int>(width));
			int i = 0, j = 0;
			Value facadeData = layer["data"];
			for (Value& value : facadeData) {
				facadeAsVector[i][j] = value.asInt();
				++j;
				if (j == width) {
					j = 0;
					++i;
				}
			}
			return facadeAsVector;
		}
	}
}

vector< vector<int> > LevelParser::getInteriorLayer() {
	Value layers = level["layers"];
	for (Value& layer : layers) {
		if (layer["name"].asString() == "interior") {
			int width = layer["width"].asInt(), height = layer["height"].asInt();
			vector< vector<int> >interiorAsVector(height, vector<int>(width));
			int i = 0, j = 0;
			Value facadeData = layer["data"];
			for (Value& value : facadeData) {
				interiorAsVector[i][j] = value.asInt();
				++j;
				if (j == width) {
					j = 0;
					++i;
				}
			}
			return interiorAsVector;
		}
	}
}

int LevelParser::getTileSize() {
	return level["tilewidth"].asInt();
}