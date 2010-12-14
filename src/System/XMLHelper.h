#ifndef XMLHELPER_H_
#define XMLHELPER_H_

#include "Markup/Markup.h"
#include "btBulletCollisionCommon.h"

class XMLHelper {
public:
	XMLHelper();
	virtual ~XMLHelper();
	static btVector3 readVector3(CMarkup xml);
};

#endif /* XMLHELPER_H_ */
