#ifndef BOXELEMENT_H_
#define BOXELEMENT_H_

#include "Element.h"
#include "../Ogre/SimpleGraphicsElmBuilder.h"

class BoxElement: public Element {
public:
	BoxElement();
	virtual ~BoxElement();
	void build(SceneManager* sceneManager,
			btDiscreteDynamicsWorld* dynamicsWorld);

};

#endif /* BOXELEMENT_H_ */
