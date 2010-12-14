#include "OgreApp.h"

OgreApp::OgreApp() {
	root = 0;
}

OgreApp::~OgreApp() {
	if (root)
		delete root;
}

void OgreApp::go(void) {
	if (!setup())
		return;
	root->startRendering();
	//clean up
	destroyScene();
}

bool OgreApp::setup() {


	root = OGRE_NEW Root();
	//root = OGRE_NEW Root("plugins.cfg",  "ogre.cfg", "Ogre.log");


	setupResources();

	bool carryOn = configure();
	if (!carryOn)
		return false;

	chooseSceneManager();


	//setupPhysicsObject();
	createCamera();
	createViewports();
	// Set default mipmap level (NB some APIs ignore this)
	TextureManager::getSingleton().setDefaultNumMipmaps(5);

	// Create any resource listeners (for loading screens)
	createResourceListener();
	// Load resources
	loadResources();
	// init frame listener
	createFrameListener();

	// init some editional object (builders, physics, e.t.c.)

	SimpleGraphicsElmBuilder::getInstance()->setSceneManager(sceneManager);
	physic = new Physic();
	physic->init();
	frameListener->setPhysic(physic);
	ElementFactory::getInstance()->setSceneManager(sceneManager);
	ElementFactory::getInstance()->setDynamicWord(physic->getDynamicWord());
	// Create the scene
	createScene();

	return true;
}

void OgreApp::destroyScene(void) {

}

void OgreApp::setupResources(void) {
	// Load resource paths from config file
	ConfigFile cf;
	cf.load("resources.cfg");
	// Go through all sections & settings in the file
	ConfigFile::SectionIterator seci = cf.getSectionIterator();

	String secName, typeName, archName;
	while (seci.hasMoreElements()) {
		secName = seci.peekNextKey();
		ConfigFile::SettingsMultiMap *settings = seci.getNext();
		ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i) {
			typeName = i->first;
			archName = i->second;
			ResourceGroupManager::getSingleton().addResourceLocation(archName,
					typeName, secName);
		}
	}
}

bool OgreApp::configure(void)
{
	// Show the configuration dialog and initialise the system
		// You can skip this and use root.restoreConfig() to load configuration
		// settings if you were sure there are valid ones saved in ogre.cfg
		if (root->showConfigDialog())
		{
			// If returned true, user clicked OK so initialise
			// Here we choose to let the system create a default rendering window by passing 'true'
			renderWindow = root->initialise(true);
			return true;
		}
		else
		{
			return false;
		}
}

void OgreApp::chooseSceneManager(void)
{
	// Create the SceneManager, in this case a generic one
	sceneManager = root->createSceneManager(ST_GENERIC);
}

void OgreApp::createCamera(void)
{
	camera = sceneManager->createCamera("PlayerCam");

		// Position it at 500 in Z direction
	camera->setPosition(Vector3(0, 10, 70));
		// Look back along -Z
	camera->lookAt(Vector3(0, 0, 0));
	camera->setNearClipDistance(1);

}

void OgreApp::createViewports(void)
{
	// Create one viewport, entire window
	Viewport* vp = renderWindow->addViewport(camera);
	vp->setBackgroundColour(ColourValue(0, 0, 0));

	// Alter the camera aspect ratio to match the viewport
	camera->setAspectRatio(Real(vp->getActualWidth()) / Real(
			vp->getActualHeight()));
}

void OgreApp::createResourceListener(void)
{

}


void OgreApp::loadResources(void)
{
	// Initialise, parse scripts etc
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

}

void OgreApp::createFrameListener(void)
{
	frameListener = new MyFrameListener(renderWindow, camera);
	frameListener->showDebugOverlay(true);
	//frameListener->setPhysics(mPhysics);
	//frameListener->setAISimulator(mAISimulator);
	//mFrameListener->setEvolutionator(evolutionator);
	root->addFrameListener(frameListener);
}

