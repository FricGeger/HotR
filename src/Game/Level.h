#ifndef LEVEL_H_
#define LEVEL_H_

#include <list>
#include <string>
#include "../OgreBullet/Element.h"

using namespace std;

class Level {
public:
	Level(string fileName);
	virtual ~Level();
	void loadLevel();
private:
	string name;
	string fileName;
	//list<Element*> staticObjects;
};

#endif /* LEVEL_H_ */
