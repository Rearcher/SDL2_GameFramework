#ifndef _Game_
#define _Game_
#include "TextureManager.h"
#include <iostream>
#include <vector>
#include "Player.h"
#include "InputHandler.h"

class Game {
public:
	bool init(const char*, int, int, int, int, int); 
	void render();
	void update();
	void handleEvents();
	void clean();
	
	bool running();
	
	static Game *Instance() {
		if (s_pInstance == nullptr) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer *getRenderer() const {
		return m_pRenderer;
	}

private:
	Game() {}
	~Game() {}

	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;
	
	SDL_Texture *m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	bool m_bRunning;

	int m_currentFrame;

	static Game *s_pInstance;
	std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;
#endif /* defined(_Game_) */
