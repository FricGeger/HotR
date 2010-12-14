#include "BoxElement.h"

BoxElement::BoxElement() {
	// TODO Auto-generated constructor stub

}

BoxElement::~BoxElement() {
	// TODO Auto-generated destructor stub
}

void BoxElement::build(SceneManager* sceneManager,
		btDiscreteDynamicsWorld* dynamicsWorld) {

	SimpleGraphicsElmBuilder::getInstance()->createBox(name + "_physicBox",
			size.getX(), size.getY(), size.getZ());
	entity = sceneManager->createEntity(name, name + "_physicBox");
	node = sceneManager->getRootSceneNode()->createChildSceneNode(name);
	node->attachObject(entity);


	// create physics object for simylation
	motionState = new MyMotionState(btTransform(startOrientation, startPos),
			node);
	inertia = btVector3(1, 1, 1);
	collisionShape = new btBoxShape(size / 2);
	collisionShape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass, motionState,
			collisionShape, inertia);
	rigidBody = new btRigidBody(rigidBodyCI);
	dynamicsWorld->addRigidBody(rigidBody);
}
