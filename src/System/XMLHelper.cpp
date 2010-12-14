#include "XMLHelper.h"

XMLHelper::XMLHelper() {
	// TODO Auto-generated constructor stub

}

XMLHelper::~XMLHelper() {
	// TODO Auto-generated destructor stub
}

btVector3 XMLHelper::readVector3(CMarkup xml) {
	btVector3 vector;
	xml.FindChildElem("X");
	vector.setX(atof(xml.GetChildData().data()));
	xml.FindChildElem("Y");
	vector.setY(atof(xml.GetChildData().data()));
	xml.FindChildElem("Z");
	vector.setZ(atof(xml.GetChildData().data()));
	return vector;
}
