#ifndef MYFRAMELISTENER_H_
#define MYFRAMELISTENER_H_

#include "Ogre.h"
#include "OgreStringConverter.h"
#include "OgreFrameListener.h"
#include "OgreException.h"
#include "../Physic/Physic.h"
#include "../Game/Player.h"
#include <OIS.h>
#include <iostream>

using namespace Ogre;
using namespace std;

class MyFrameListener: public FrameListener, public WindowEventListener {
public:
	MyFrameListener(RenderWindow* win, Camera* cam, bool bufferedKeys = false, bool bufferedMouse = false, bool bufferedJoy = false);
	~MyFrameListener();
	bool playerCamera;
	bool frameStarted(const FrameEvent& evt);
	bool frameEnded(const FrameEvent& evt);
	void moveCamera();
	virtual void windowResized(RenderWindow* rw);
	virtual void windowClosed(RenderWindow* rw);
	virtual bool processUnbufferedKeyInput(const FrameEvent& evt);
	bool processUnbufferedMouseInput(const FrameEvent& evt);
	bool processUnbufferedJoyInput(const FrameEvent& evt);
	MyFrameListener();
	void showDebugOverlay(bool show);
	void setPhysic(Physic* physic);
	void setPlayerCam(Camera* camera);
	void setPlayer(Player* player);

protected:

	Physic* physic;
	Player* player;
	bool playerInit;

	bool mPaused;

	void updateStats(void);
	Camera* mCamera;
	Vector3 cameraOldPos;


	Vector3 mTranslateVector;
	RenderWindow* mWindow;
	bool mStatsOn;

	std::string mDebugText;

	unsigned int mNumScreenShots;
	float mMoveScale;
	Degree mRotScale;

	// just to stop toggles flipping too fast
	Real mTimeUntilNextToggle;
	Radian mRotX, mRotY;
	TextureFilterOptions mFiltering;
	int mAniso;

	int mSceneDetailIndex;
	Real mMoveSpeed;
	Degree mRotateSpeed;
	Overlay* mDebugOverlay;

	//OIS Input devices
	OIS::InputManager* mInputManager;
	OIS::Mouse* mMouse;
	OIS::Keyboard* mKeyboard;
	OIS::JoyStick* mJoy;

};

#endif /* MYFRAMELISTENER_H_ */
