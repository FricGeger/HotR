#include "Espadon.h"


Espadon::Espadon() {
	this->name = "Espadon";
	this->mesh = "espadon.mesh";
	this->width = 3;
	this->lenght = 12;
	this->height = 3;
	this->mass = 5;

	//Init capsule element
	// TODO init capsule

	capsule = ElementFactory::getInstance()->createBox("EspadonCol",btVector3(lenght,width, height),mass, btVector3(0,10,0), btQuaternion(0,0,0,1) );
	capsule->getRigidBody()->activate(true);
	//Entity* espadon = sceneManager->createEntity("Espadon", "espadon.mesh");
	Entity* espadon = ElementFactory::getInstance()->getSceneManager()->createEntity(name, mesh);
	SceneNode* espadonNode = capsule->getSceneNode()->createChildSceneNode("Espadon");
	espadonNode->attachObject(espadon);

}

Espadon::~Espadon() {
	// TODO Auto-generated destructor stub
}
