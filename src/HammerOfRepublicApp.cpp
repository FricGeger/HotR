#include "HammerOfRepublicApp.h"
#include "Game/SpaceShip/Espadon.h"
HammerOfRepublic::HammerOfRepublic() {
	// TODO Auto-generated constructor stub

}

HammerOfRepublic::~HammerOfRepublic() {
	// TODO Auto-generated destructor stub
}

void HammerOfRepublic::createScene() {

	sceneManager->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
	Light* mainLight = sceneManager->createLight("MainLight");
	mainLight->setPosition(0, 0, 1000);

/*	Entity* espadon = sceneManager->createEntity("Espadon", "espadon.mesh");
	SceneNode* espadonNode = sceneManager->getRootSceneNode()->createChildSceneNode("Espadon");
	espadonNode->attachObject(espadon);
	espadonNode->setPosition(0,0,0);
	espadonNode->setScale(10,10,10);

	*/

	/*Entity* vityaz = sceneManager->createEntity("Vityaz", "vityaz.mesh");
	SceneNode* vityazNode = sceneManager->getRootSceneNode()->createChildSceneNode("Vityaz");
	vityazNode->attachObject(vityaz);
	vityazNode->setPosition(0,0,20);*/

	/*Entity* revolution = sceneManager->createEntity("Revolution", "revolution.mesh");
	SceneNode* revolutionNode = sceneManager->getRootSceneNode()->createChildSceneNode("Revolution");
	revolutionNode->attachObject(revolution);
	revolutionNode->setPosition(0,0,-100);
	*/

	/*Entity* dragon = sceneManager->createEntity("Dragon", "dragon.mesh");
	SceneNode* dragonNode = sceneManager->getRootSceneNode()->createChildSceneNode("Dragon");
	dragonNode->attachObject(dragon);
*/

	SimpleGraphicsElmBuilder::getInstance()->createPlane("ground test plane",
			5000, 5000, 100);
	Entity* planeEntity = sceneManager->createEntity("planeEntity",
			"ground test plane");
	SceneNode* planeNode =
			sceneManager->getRootSceneNode()->createChildSceneNode();
	planeNode->attachObject(planeEntity);

	/*ElementFactory::getInstance()->createBox("tetsBox", btVector3(10, 4, 4),
			10, btVector3(50, 100, 0), btQuaternion());
	ElementFactory::getInstance()->createCapsule("testCapsule", 10, 25, 13,
			btVector3(0, 100, 0), btQuaternion());
*/

	Espadon* testEspadon =  new Espadon();

	player = new Player();
	frameListener->setPlayer(player);
	player->setSpaceShip(testEspadon);



}
