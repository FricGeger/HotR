#ifndef ELEMETNFACTORY_H_
#define ELEMETNFACTORY_H_

#include "btBulletDynamicsCommon.h"
#include "Ogre.h"
#include "Element.h"
#include "BoxElement.h"
#include "CapsuleElement.h"
#include <string>

using namespace Ogre;
using namespace std;

class ElementFactory {
public:

	static ElementFactory* getInstance();
	virtual ~ElementFactory();
	void setSceneManager(SceneManager* sceneManager);
	SceneManager* getSceneManager();
	void setDynamicWord(btDiscreteDynamicsWorld* dynamicWord);
	Element* createBox(const String& name, const btVector3 size, btScalar mass,
			const btVector3 startPos, btQuaternion startOrientation);
	Element* createCapsule(const String& name, float radius, float height,
			btScalar mass, const btVector3 startPos,
			btQuaternion startOrientation);
private:
	ElementFactory();
	SceneManager* sceneMgr;
	btDiscreteDynamicsWorld* dynamicWorld;
};

#endif /* ELEMETNFACTORY_H_ */
