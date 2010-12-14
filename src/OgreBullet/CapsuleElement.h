#ifndef CAPSULEELEMENT_H_
#define CAPSULEELEMENT_H_

#include "Element.h"
#include "../Ogre/SimpleGraphicsElmBuilder.h"

class CapsuleElement: public Element {
public:
	CapsuleElement();
	virtual ~CapsuleElement();
	void build(SceneManager* sceneManager, btDiscreteDynamicsWorld* dynamicWord);
};

#endif /* CAPSULEELEMENT_H_ */
