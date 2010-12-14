#include "ElementFactory.h"

ElementFactory::ElementFactory() {
	// TODO Auto-generated constructor stub

}

ElementFactory::~ElementFactory() {
	// TODO Auto-generated destructor stub
}

ElementFactory* ElementFactory::getInstance() {
	static ElementFactory instance;
	return &instance;
}

void ElementFactory::setSceneManager(SceneManager* sceneManager) {
	this->sceneMgr = sceneManager;
}

SceneManager* ElementFactory::getSceneManager()
{
	return this->sceneMgr;
}

void ElementFactory::setDynamicWord(btDiscreteDynamicsWorld* dynamicWord) {
	this->dynamicWorld = dynamicWord;
}

Element* ElementFactory::createBox(const String& name, const btVector3 size,
		btScalar mass, const btVector3 startPos, btQuaternion startOrientation) {
	BoxElement* element = new BoxElement();
	element->setParam(name, size, mass, startPos, startOrientation);
	element->build(sceneMgr, dynamicWorld);

	return element;
}

Element* ElementFactory::createCapsule(const String& name, float radius,
		float height, btScalar mass, const btVector3 startPos,
		btQuaternion startOrientation) {
	CapsuleElement* element = new CapsuleElement();
	element->setParam(name, btVector3(radius, height, radius), mass, startPos,
			startOrientation);
	element->build(sceneMgr, dynamicWorld);

	return element;
}
