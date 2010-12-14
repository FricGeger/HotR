#include "CapsuleElement.h"

CapsuleElement::CapsuleElement() {
	// TODO Auto-generated constructor stub

}

CapsuleElement::~CapsuleElement() {
	// TODO Auto-generated destructor stub
}

void CapsuleElement::build(SceneManager* sceneManager,
		btDiscreteDynamicsWorld* dynamicsWorld) {

	// create graphics object for render
	SimpleGraphicsElmBuilder::getInstance()->createCapsule(name
			+ "_physicSCapsule", size.getX()/2, size.getY());
	entity = sceneManager->createEntity(name, name + "_physicSCapsule");
	node = sceneManager->getRootSceneNode()->createChildSceneNode(name);
	node->attachObject(entity);

	// create physics object for simylation
	motionState = new MyMotionState(btTransform(startOrientation, startPos),
			node);
	inertia = btVector3(1, 1, 1);
	collisionShape = new btCapsuleShape(size.getX()/2,size.getY());
	collisionShape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass, motionState,
			collisionShape, inertia);
	rigidBody = new btRigidBody(rigidBodyCI);
	dynamicsWorld->addRigidBody(rigidBody);

}
