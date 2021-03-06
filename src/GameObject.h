#ifndef _GameObject_
#define _GameObject_

#include <string>

class LoaderParams {
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID) :
		m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID) {}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }

private:
	int m_x, m_y;
	int m_width, m_height;
	std::string m_textureID;
};

class GameObject {
public:
	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean()=0;

protected:
	GameObject(const LoaderParams *pParams) {}
	virtual ~GameObject() {}
};

#endif /* GameObject */
