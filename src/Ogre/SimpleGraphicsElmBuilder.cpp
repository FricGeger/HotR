#include "SimpleGraphicsElmBuilder.h"

// TODO init material

SimpleGraphicsElmBuilder::SimpleGraphicsElmBuilder() {

}

SimpleGraphicsElmBuilder::~SimpleGraphicsElmBuilder() {

}

SimpleGraphicsElmBuilder* SimpleGraphicsElmBuilder::getInstance() {
	static SimpleGraphicsElmBuilder instance;
	return &instance;
}

void SimpleGraphicsElmBuilder::setSceneManager(SceneManager* sceneManager) {
	this->sceneManager = sceneManager;
}

void SimpleGraphicsElmBuilder::initMaterial() {

	MaterialPtr boxMaterial;
	MaterialPtr sphereMaterial;
	MaterialPtr planeMaterial;
	MaterialPtr cilinderMaterial;

	cilinderMaterial = MaterialManager::getSingleton().create(
			"cilinderMaterial", "debugger");
	cilinderMaterial->setReceiveShadows(false);
	cilinderMaterial->getTechnique(0)->setLightingEnabled(true);
	cilinderMaterial->getTechnique(0)->getPass(0)->setDiffuse(0.0, 1, 1, 0);
	cilinderMaterial->getTechnique(0)->getPass(0)->setAmbient(0.0, 1, 1.1);
	cilinderMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(0, 0, 0);
	cilinderMaterial->getTechnique(0)->getPass(0)->setPolygonMode(PM_WIREFRAME);

	boxMaterial = MaterialManager::getSingleton().create("boxMaterial",
			"debuger");
	boxMaterial->setReceiveShadows(false);
	boxMaterial->getTechnique(0)->setLightingEnabled(true);
	boxMaterial->getTechnique(0)->getPass(0)->setDiffuse(0.2, 1, 0.2, 0);
	boxMaterial->getTechnique(0)->getPass(0)->setAmbient(0.1, 1, 0.1);
	boxMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(0, 0, 0);
	boxMaterial->getTechnique(0)->getPass(0)->setPolygonMode(PM_SOLID);

	planeMaterial = MaterialManager::getSingleton().create("planeMaterial",
			"debuger");
	planeMaterial->setReceiveShadows(false);
	planeMaterial->getTechnique(0)->setLightingEnabled(true);
	planeMaterial->getTechnique(0)->getPass(0)->setDiffuse(0.2, 1, 0.2, 0);
	planeMaterial->getTechnique(0)->getPass(0)->setAmbient(0.1, 0.3, 0.1);
	planeMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(0, 0, 0);
	planeMaterial->getTechnique(0)->getPass(0)->setPolygonMode(PM_WIREFRAME);

	sphereMaterial = MaterialManager::getSingleton().create("sphereMaterial",
			"debuger");
	sphereMaterial->setReceiveShadows(false);
	sphereMaterial->getTechnique(0)->setLightingEnabled(true);
	sphereMaterial->getTechnique(0)->getPass(0)->setDiffuse(1, 0, 0, 0);
	sphereMaterial->getTechnique(0)->getPass(0)->setAmbient(0, 0, 1);
	sphereMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(0, 0, 0);
	sphereMaterial->getTechnique(0)->getPass(0)->setPolygonMode(PM_WIREFRAME);
}

void SimpleGraphicsElmBuilder::createPlane(const String& strName,
		const float length, const float width, const int nSegment) {
	ManualObject * manual = sceneManager->createManualObject(strName);
	manual->begin("planeMaterial", RenderOperation::OT_LINE_LIST);

	long vertexCounter = 0;

	float sizeLegth = length / nSegment;
	float sizeWidth = width / nSegment;

	for (int i = -nSegment / 2; i <= nSegment / 2; ++i) {
		manual->position(-width * 0.5, 0, i * sizeLegth);
		manual->normal(Vector3(-width * 0.5, 0, i * sizeLegth).normalisedCopy());
		manual->textureCoord(i / length, 0 / width);

		manual->position(width * 0.5, 0, i * sizeLegth);
		manual->normal(Vector3(width * 0.5, 0, i * sizeLegth).normalisedCopy());
		manual->textureCoord(i / length, 0 / width);

		manual->position(i * sizeWidth, 0, -length * 0.5);
		manual->normal(
				Vector3(i * sizeWidth, 0, -length * 0.5).normalisedCopy());
		manual->textureCoord(i / length, 0 / width);

		manual->position(i * sizeWidth, 0, length * 0.5);
		manual->normal(Vector3(i * sizeWidth, 0, length * 0.5).normalisedCopy());
		manual->textureCoord(i / length, 0 / width);

		manual->index(vertexCounter);
		manual->index(vertexCounter + 1);
		manual->index(vertexCounter + 2);
		manual->index(vertexCounter + 3);
		vertexCounter = vertexCounter + 4;
	}

	manual->end();
	MeshPtr mesh = manual->convertToMesh(strName);
	unsigned short src, dest;
	if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest)) {
		mesh->buildTangentVectors(VES_TANGENT, src, dest);
	}
}

void SimpleGraphicsElmBuilder::createCube(const String& strName, const float sizeX, const float sizeY, const float sizeZ, const int step)
{
	ManualObject * manual = sceneManager->createManualObject(strName);
	manual->begin("planeMaterial", RenderOperation::OT_LINE_LIST);
	// TODO create cube mesh
}

void SimpleGraphicsElmBuilder::createCylinder(const String& strName,
		const float radius, const float height, const float size) {
	ManualObject * manual = sceneManager->createManualObject(strName);
	manual->begin("cilinderMaterial", RenderOperation::OT_LINE_LIST);
	unsigned short wVerticeIndex = 0;
	float fDeltaRingAngle = (Math::PI / size);
	for (int i = 0; i < 2 * size; ++i) {
		float x0 = radius * sinf(i * fDeltaRingAngle);
		float y0 = -height / 2;
		float z0 = radius * cosf(i * fDeltaRingAngle);

		float x1 = radius * sinf(i * fDeltaRingAngle);
		float y1 = height / 2;
		float z1 = radius * cosf(i * fDeltaRingAngle);

		manual->position(x0, y0, z0);
		manual->normal(Vector3(x0, y0, z0).normalisedCopy());
		manual->textureCoord(x0, y0);

		manual->position(x1, y1, z1);
		manual->normal(Vector3(x1, y1, z1).normalisedCopy());
		manual->textureCoord(x1, y1);

		if (wVerticeIndex > 1) {
			manual->index(wVerticeIndex - 2);
			manual->index(wVerticeIndex);

			manual->index(wVerticeIndex);
			manual->index(wVerticeIndex + 1);

			manual->index(wVerticeIndex + 1);
			manual->index(wVerticeIndex - 1);
		} else {
			manual->index(wVerticeIndex);
			manual->index(wVerticeIndex + 1);
		}
		wVerticeIndex = wVerticeIndex + 2;
	}
	manual->index(wVerticeIndex - 2);
	manual->index(0);
	manual->index(wVerticeIndex - 1);
	manual->index(1);

	manual->end();
	MeshPtr mesh = manual->convertToMesh(strName);
	unsigned short src, dest;
	if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
		mesh->buildTangentVectors(VES_TANGENT, src, dest);
}

void SimpleGraphicsElmBuilder::createBox(const String& strName,
		const float sizeX, const float sizeY, const float sizeZ) {
	ManualObject * manual = sceneManager->createManualObject(strName);
	manual->begin("boxMaterial", RenderOperation::OT_LINE_LIST);

	manual->position(-sizeX / 2, -sizeY / 2, -sizeZ / 2);
	manual->normal(Vector3(-sizeX / 2, -sizeY / 2, -sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->position(sizeX / 2, -sizeY / 2, -sizeZ / 2);
	manual->normal(Vector3(sizeX / 2, -sizeY / 2, -sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->position(sizeX / 2, sizeY / 2, -sizeZ / 2);
	manual->normal(Vector3(sizeX / 2, sizeY / 2, -sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->position(-sizeX / 2, sizeY / 2, -sizeZ / 2);
	manual->normal(Vector3(-sizeX / 2, sizeY / 2, -sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->position(-sizeX / 2, -sizeY / 2, sizeZ / 2);
	manual->normal(Vector3(-sizeX / 2, -sizeY / 2, sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->position(sizeX / 2, -sizeY / 2, sizeZ / 2);
	manual->normal(Vector3(sizeX / 2, -sizeY / 2, sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->position(sizeX / 2, sizeY / 2, sizeZ / 2);
	manual->normal(Vector3(sizeX / 2, sizeY / 2, sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->position(-sizeX / 2, sizeY / 2, sizeZ / 2);
	manual->normal(Vector3(-sizeX / 2, sizeY / 2, sizeZ / 2).normalisedCopy());
	manual->textureCoord(-sizeX / 2, -sizeY / 2);

	manual->index(0);
	manual->index(1);
	manual->index(1);
	manual->index(2);
	manual->index(2);
	manual->index(3);
	manual->index(3);
	manual->index(0);
	manual->index(0);
	manual->index(4);
	manual->index(1);
	manual->index(5);
	manual->index(2);
	manual->index(6);
	manual->index(3);
	manual->index(7);
	manual->index(4);
	manual->index(5);
	manual->index(5);
	manual->index(6);
	manual->index(6);
	manual->index(7);
	manual->index(4);
	manual->index(7);

	manual->end();
	MeshPtr mesh = manual->convertToMesh(strName);
	unsigned short src, dest;
	if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
		mesh->buildTangentVectors(VES_TANGENT, src, dest);
}

void SimpleGraphicsElmBuilder::createSphere(const String& strName,
		const float r, const int nRings, const int nSegments) {
	ManualObject * manual = sceneManager->createManualObject(strName);
	manual->begin("sphereMaterial", RenderOperation::OT_LINE_LIST);

	float fDeltaRingAngle = (Math::PI / nRings);
	float fDeltaSegAngle = (2 * Math::PI / nSegments);
	unsigned short wVerticeIndex = 0;

	// Generate the group of rings for the sphere
	for (int ring = 0; ring <= nRings; ring++) {
		float r0 = r * sinf(ring * fDeltaRingAngle);
		float y0 = r * cosf(ring * fDeltaRingAngle);

		// Generate the group of segments for the current ring
		for (int seg = 0; seg <= nSegments; seg++) {
			float x0 = r0 * sinf(seg * fDeltaSegAngle);
			float z0 = r0 * cosf(seg * fDeltaSegAngle);

			// Add one vertex to the strip which makes up the sphere
			manual->position(x0, y0, z0);
			manual->normal(Vector3(x0, y0, z0).normalisedCopy());
			manual->textureCoord((float) seg / (float) nSegments, (float) ring
					/ (float) nRings);

			if (ring != nRings) {
				// each vertex (except the last) has six indicies pointing to it
				manual->index(wVerticeIndex + nSegments + 1);
				manual->index(wVerticeIndex);
				manual->index(wVerticeIndex + nSegments);
				manual->index(wVerticeIndex + nSegments + 1);
				manual->index(wVerticeIndex + 1);
				manual->index(wVerticeIndex);
				wVerticeIndex++;
			}
		}; // end for seg
	} // end for ring
	manual->end();
	MeshPtr mesh = manual->convertToMesh(strName);
	mesh->_setBounds(AxisAlignedBox(Vector3(-r, -r, -r), Vector3(r, r, r)),
			false);

	mesh->_setBoundingSphereRadius(r);
	unsigned short src, dest;
	if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest)) {
		mesh->buildTangentVectors(VES_TANGENT, src, dest);
	}
}

void SimpleGraphicsElmBuilder::createCapsule(const String& strName,
		const float radius, const float height, const int nRings,
		const int nSegment) {

	ManualObject * manual = sceneManager->createManualObject(strName);
	manual->begin("sphereMaterial", RenderOperation::OT_LINE_LIST);

	float fDeltaRingAngle = ( Math::PI / nRings);
	float fDeltaSegAngle = (2 * Math::PI / nSegment);
	unsigned short wVerticeIndex = 0;

	for (int ring = 0; ring <= nRings; ring++) {
			float r0 = radius * sinf(ring * fDeltaRingAngle);
			float y0 = height/2 * cosf(ring * fDeltaRingAngle);

			// Generate the group of segments for the current ring
			for (int seg = 0; seg <= nSegment; seg++) {
				float x0 = r0 * sinf(seg * fDeltaSegAngle);
				float z0 = r0 * cosf(seg * fDeltaSegAngle);
			// Add one vertex to the strip which makes up the sphere
			manual->position(x0, y0, z0);
			manual->normal(Vector3(x0, y0, z0).normalisedCopy());
			manual->textureCoord((float) seg / (float) nSegment, (float) ring
					/ (float) nRings);

			if (ring != nRings) {
				// each vertex (except the last) has six indicies pointing to it
				manual->index(wVerticeIndex + nSegment + 1);
				manual->index(wVerticeIndex);
				manual->index(wVerticeIndex + nSegment);
				manual->index(wVerticeIndex + nSegment + 1);
				manual->index(wVerticeIndex + 1);
				manual->index(wVerticeIndex);
				wVerticeIndex++;
			}
		}; // end for seg
	} // end for ring
	manual->end();
	MeshPtr mesh = manual->convertToMesh(strName);
	mesh->_setBounds(AxisAlignedBox(Vector3(-radius, -height / 2, -radius),
			Vector3(radius, height / 2, radius)), false);

	mesh->_setBoundingSphereRadius(radius);
	unsigned short src, dest;
	if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest)) {
		mesh->buildTangentVectors(VES_TANGENT, src, dest);
	}
}
