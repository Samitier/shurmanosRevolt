#pragma once
#include <json/json.h>
#include <iostream>
#include<fstream>

using namespace Json;
using namespace std;



class LevelParser {
public:

	LevelParser(void);
	~LevelParser(void);

	void parseLevel(string name);

	vector< vector<int> > getFacadeLayer();
	vector< vector<int> > getInteriorLayer();
	vector< vector<int> > getObjectLayer();
	int getTileSize();

private:
	Value level;
};