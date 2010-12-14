#ifndef OGREAPP_H_
#define OGREAPP_H_

#include "Ogre.h"
#include "MyFrameListener.h"
#include "SimpleGraphicsElmBuilder.h"
#include "../Physic/Physic.h"
#include "../OgreBullet/ElementFactory.h"
#include "../Game/Player.h"

using namespace Ogre;

class OgreApp {
public:
	OgreApp();
	~OgreApp();
	virtual void go(void);

protected:

	Physic* physic;

	MyFrameListener *frameListener;

	Root *root;
	Camera* camera;
	SceneManager* sceneManager;
	RenderWindow* renderWindow;

	Player* player;

	virtual bool setup(void);
	virtual void destroyScene(void); // Optional to override this
	virtual void setupResources(void);
	virtual bool configure(void);
	virtual void chooseSceneManager(void);
	virtual void createCamera(void);
	virtual void createViewports(void);
	virtual void createResourceListener(void);
	virtual void loadResources(void);
	virtual void createScene(void) = 0;
	virtual void createFrameListener(void);
};

#endif /* OGREAPP_H_ */
