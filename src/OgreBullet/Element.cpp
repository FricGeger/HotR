#include "Element.h"

Element::Element() {
	// TODO Auto-generated constructor stub

}

Element::~Element() {
	// TODO Auto-generated destructor stub
}

void Element::build(SceneManager* sceneManager,
		btDiscreteDynamicsWorld* dynamicsWorld) {

}

void Element::setParam(const String& name, const btVector3 size, btScalar mass,
		const btVector3 startPos, btQuaternion startOrientation) {
	this->name = name;
	this->size = size;
	this->mass = mass;
	this->startPos = startPos;
	this->startOrientation = startOrientation;
}

btRigidBody* Element::getRigidBody() {
	return rigidBody;
}

SceneNode* Element::getSceneNode() {
	return node;
}

Entity* Element::getEntity() {
	return entity;
}
