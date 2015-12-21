#ifndef _AnimatedGraphic_
#define _AnimatedGraphic_

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject {
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed) :
		SDLGameObject(pParams), m_animSpeed(animSpeed) {}

	void draw() {
		SDLGameObject::draw();
	}

	void clean() {

	}

	void update() {
		m_currentFrame = (int)((SDL_GetTicks() / (1000/m_animSpeed)) % 2);
	}

private:
	const int m_animSpeed = 100;
};

#endif /* AnimatedGraphic */
