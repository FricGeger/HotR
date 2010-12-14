#ifndef PLAYER_H_
#define PLAYER_H_
#include <Ogre.h>
#include <OIS.h>
#include "SpaceShip/SpaceShip.h"


using namespace Ogre;

class Player {
public:
	Player();
	virtual ~Player();
	bool processUnbufferedKeyInput();
	bool processUnbufferedMouseInput();
	void setCamera(Camera* camera);
	void setKeyboard(OIS::Keyboard* keyboard);
	void setMouse(OIS::Mouse* mouse);
	void setSpaceShip(SpaceShip* ship);
	void setPlayerCam(bool playerCam);
	void update();
private:
	bool playerCam;
	Camera* camera;
	SpaceShip* ship;
	OIS::Keyboard* keyboard;
	OIS::Mouse* mouse;


};

#endif /* PLAYER_H_ */
