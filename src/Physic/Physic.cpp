#include "Physic.h"

Physic::Physic() {
	// TODO Auto-generated constructor stub

}

Physic::~Physic() {
	// TODO Auto-generated destructor stub
}

btDiscreteDynamicsWorld* Physic::getDynamicWord() {
	return dynamicsWord;
}

void Physic::init() {
	btVector3 worldAabbMin(-10000, -10000, -10000);
	btVector3 worldAabbMax(10000, 10000, 10000);
	int maxProxies = 1024;
	btAxisSweep3* broadphase = new btAxisSweep3(worldAabbMin, worldAabbMax,
			maxProxies);

	btDefaultCollisionConfiguration* collisionConfiguration =
			new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(
			collisionConfiguration);

	btSequentialImpulseConstraintSolver* solver =
			new btSequentialImpulseConstraintSolver;

	dynamicsWord = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver,
			collisionConfiguration);

	dynamicsWord->setGravity(btVector3(0, 0, 0));
	btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0, 1, 0),
			1);

	// add groung
	// TODO remove init ground
	btDefaultMotionState* groundMotionState = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0,
			groundMotionState, groundShape, btVector3(0, 0, 0));
	btRigidBody* groundRigidBody = new btRigidBody(groundRigidBodyCI);
	dynamicsWord->addRigidBody(groundRigidBody);
}
