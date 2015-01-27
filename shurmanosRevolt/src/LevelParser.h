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

	vector<int> getFacadeLayer();
	vector<int> getInteriorLayer();
	vector<int> getObjectLayer();

private:
	Value level;
};