#ifndef _Player_
#define _Player_

#include "SDLGameObject.h"

class Player : public SDLGameObject {
public:
	Player(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};

#endif /* Player */
