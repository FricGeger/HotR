#ifndef PHYSIC_H_
#define PHYSIC_H_

#include "btBulletDynamicsCommon.h"


class Physic {
public:
	Physic();
	virtual ~Physic();
	btDiscreteDynamicsWorld* getDynamicWord();
	void init();
private:
	btDiscreteDynamicsWorld* dynamicsWord;
};

#endif /* PHYSIC_H_ */
