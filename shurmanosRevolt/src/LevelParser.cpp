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

//gets the layer "facade" of the json generated with Tiled, and transfoms it into an int vector (a matrix may be better)
vector<int> LevelParser::getFacadeLayer() {
	Value layers = level["layers"];
	for (Value& layer : layers) {
		if (layer["name"].asString() == "facade") {
			Value facadeData = layer["data"];
			vector<int>facadeAsVector;
			for (Value& value : facadeData) {
				facadeAsVector.push_back(value.asInt());
			}
			return facadeAsVector;
		}
	}
}