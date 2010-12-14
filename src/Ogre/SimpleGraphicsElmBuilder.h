#ifndef SIMPLEGRAPHICSELMBUILDER_H_
#define SIMPLEGRAPHICSELMBUILDER_H_

#include "Ogre.h"
using namespace Ogre;

class SimpleGraphicsElmBuilder {
public:
	static SimpleGraphicsElmBuilder* getInstance();
	void setSceneManager(SceneManager* sceneManager);
	void initMaterial();
	void createPlane(const String& strName, const float length,
			const float width, const int nSegment);
	void createSphere(const String& strName, const float r, const int nRings =
			16, const int nSegments = 16);
	void createBox(const String& strName, const float sizeX, const float sizeY,
			const float sizeZ);
	void createCube(const String& strName, const float sizeX, const float sizeY, const float sizeZ, const int step);
	void createCylinder(const String& strName, const float radius,
			const float height, const float size);
	void createCapsule(const String& strName, const float radius,
			const float height, const int nRings = 32, const int nSegment = 32);
	virtual ~SimpleGraphicsElmBuilder();

private:
	SimpleGraphicsElmBuilder();
	SceneManager *sceneManager;

};

#endif /* SIMPLEGRAPHICSELMBUILDER_H_ */
