#ifndef LEVELMANAGER_H_
#define LEVELMANAGER_H_

class LevelManager {
public:
	static LevelManager* getInstance();
	virtual ~LevelManager();
	void loadLevel();
private:
	LevelManager();
};

#endif /* LEVELMANAGER_H_ */
