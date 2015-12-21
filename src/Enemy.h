#ifndef _enemy_
#define _enemy_

#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
		
public:
	Enemy(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};

#endif /* enemy */
