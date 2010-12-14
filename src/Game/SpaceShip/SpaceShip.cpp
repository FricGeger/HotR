#include "SpaceShip.h"

SpaceShip::SpaceShip() {
	// TODO Auto-generated constructor stub
	power = 0;
}

SpaceShip::~SpaceShip() {
	// TODO Auto-generated destructor stub
}

void SpaceShip::addPower(float value, float maxValue) {
	if (fabs(power) < maxValue) {
		power += value;
		direction.setY(power);
		cout << power << endl;
		aplyControlParametr();
	}
}

void SpaceShip::setDirection(btVector3 direction)
{
	/*cout << direction.x() << endl;
	cout << direction.y() << endl;
	cout << direction.z() << endl;
	cout << "--------------" << endl;*/
	if (direction.x()>0)
		this->direction.setZ(10);
	if (direction.x()<0)
		this->direction.setZ(-10);
	aplyControlParametr();
}

void SpaceShip::aplyControlParametr() {
	//capsule->getRigidBody()->applyForce(btVector3(power, 0,0), btVector3(0,0,0));

	capsule->getRigidBody()->activate(true);
	//capsule->getRigidBody()->applyCentralForce(btVector3(power,0,0));
	//capsule->getRigidBody()->applyCentralImpulse(btVector3(power, 0, 0));
	capsule->getRigidBody()->applyCentralImpulse(direction);

}

Vector3 SpaceShip::getPosition(){
	Vector3 pos;
	btVector3 btPos = capsule->getRigidBody()->getCenterOfMassPosition();
	pos.x = btPos.getX();
	pos.y = btPos.getY();
	pos.z = btPos.getZ();
	return pos;
}

void SpaceShip::loadShip(string fileName) {
	// read file
	string str;
	char s[81];
	FILE *file;
	file = fopen("Data/espadon.xml", "r");
	while (!feof(file)) {
		fscanf(file, "%s", s);
		str += s;
		str.append("\n");
	}
	fclose(file);

	//parce xml
	CMarkup xml;
	xml.SetDoc(str);
	if (xml.FindElem("SpaceShip")) {
		initShip = true;
		name = xml.GetAttrib("name");
		xml.IntoElem();
		if (xml.FindChildElem("Kinematic")) {
			xml.IntoElem();
			xml.FindChildElem("Start_Pos");
			xml.IntoElem();
		} else {
			initShip = false;
			cout << "Error: XML not found Kinematic Tag" << endl;
		}

	} else {
		initShip = false;
	}

	// init capsule element
	//ElementFactory::getInstance()->createCapsule("testCapsule", 10, 25, 13,
	//			btVector3(0, 100, 0), btQuaternion());

}

