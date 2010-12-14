#include "Player.h"

Player::Player() {
	this->playerCam = false;
}

Player::~Player() {

}

void Player::setPlayerCam(bool playerCam) {
	this->playerCam = playerCam;
}

void Player::setCamera(Camera* camera) {
	this->camera = camera;
}

void Player::setKeyboard(OIS::Keyboard* keyboard) {
	this->keyboard = keyboard;
}

void Player::setMouse(OIS::Mouse* mouse) {
	this->mouse = mouse;
}

void Player::setSpaceShip(SpaceShip* ship) {
	this->ship = ship;
}

bool Player::processUnbufferedKeyInput() {
	using namespace OIS;
	if (ship) {
		if (keyboard->isKeyDown(KC_W))
			ship->addPower(1, 100);// add power
		if (keyboard->isKeyDown(KC_S))
			ship->addPower(-1, 100);
	}
	return true;
}

bool Player::processUnbufferedMouseInput(){
	using namespace OIS;
	if(ship){
		const MouseState &ms = mouse->getMouseState();
		ship->setDirection(btVector3(ms.X.rel, ms.Y.rel, ms.Z.rel));
		//if(ms.buttonDown(MB_Left))


	}

	return true;
}

void Player::update() {
	if(playerCam){
		camera->lookAt(ship->getPosition());
		camera->setPosition(ship->getPosition()+Vector3(10,10,0));
	}
	//update playercam position

}

