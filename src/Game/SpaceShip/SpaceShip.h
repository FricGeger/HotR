#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include "../../OgreBullet/CapsuleElement.h"
#include "../../OgreBullet/ElementFactory.h"
#include "../../System/Markup/Markup.h"
#include <string>
#include <stdio.h>
using namespace std;

class SpaceShip {
public:
	SpaceShip();
	virtual ~SpaceShip();
	void loadShip(string fileName);
	void addPower(float value, float maxValue);
	void setDirection(btVector3 direction);
	void aplyControlParametr();
	Vector3 getPosition();
	//btVector3 getPosition();

protected:
	// static param of ship
	Element* capsule;

	string name;
	bool initShip;
	btVector3 startPos;
	float lenght;
	float width;
	float height;
	string shape;
	string mesh;

	float mass;
	// dynamic param
	float power;
	btVector3 direction;


};

#endif /* SPACESHIP_H_ */

