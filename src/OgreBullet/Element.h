#ifndef ELEMENT_H_
#define ELEMENT_H_

#include "Ogre.h"
#include "btBulletDynamicsCommon.h"
#include "MyMotionState.h"
#include <string>

using namespace Ogre;
using namespace std;

class Element {
public:
	Element();
	virtual ~Element();
	virtual void build(SceneManager* sceneManager,
			btDiscreteDynamicsWorld* dynamicsWorld);
	virtual void setParam(const String& name, const btVector3 size,
			btScalar mass, const btVector3 startPos,
			btQuaternion startOrientation);
	btRigidBody* getRigidBody();
	SceneNode* getSceneNode();
	Entity* getEntity();
protected:
	string name;
	btRigidBody* rigidBody;
	btCollisionShape* collisionShape;
	btScalar mass;
	btVector3 inertia;
	btVector3 size;
	btVector3 startPos;
	btQuaternion startOrientation;

	MyMotionState* motionState;
	SceneNode* node;
	Entity* entity;

};

#endif /* ELEMENT_H_ */
