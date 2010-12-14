#ifndef HAMMEROFEMPIREAPP_H_
#define HAMMEROFEMPIREAPP_H_

#include "Ogre/OgreApp.h"

class HammerOfRepublic: public OgreApp {
public:
	HammerOfRepublic();
	virtual ~HammerOfRepublic();
private:
	void createScene();
};

#endif /* HAMMEROFEMPIREAPP_H_ */
