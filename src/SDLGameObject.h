#ifndef _SDLGameObject_
#define _SDLGameObject_

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	
	Vector2D &getPosition() {
		return m_position;
	}

	int getWidth() {
		return m_width;
	}

	int getHeight() {
		return m_height;
	}

protected:
	Vector2D m_position;
	int m_width, m_height;
	int m_currentRow, m_currentFrame;
	std::string m_textureID;

	Vector2D m_velocity;
	Vector2D m_acceleration;
};

#endif /* SDLGameObject */
