#include "LevelManager.h"

LevelManager* LevelManager::getInstance(){
	static LevelManager instance;
	return &instance;
}

LevelManager::LevelManager() {
	// TODO Auto-generated constructor stub

}

LevelManager::~LevelManager() {
	// TODO Auto-generated destructor stub
}
