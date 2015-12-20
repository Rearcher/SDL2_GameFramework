#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != nullptr) {
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != nullptr) {
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			} else {
				std::cout << "renderer init fail\n";
				return false;
			}
		} else {
			std::cout << "window init fail\n";
			return false;
		}
	} else {
		std::cout << "SDL init fail\n";
		return false;
	}

	std::cout << "init success\n";
	m_bRunning = true;
	
	// todo, load pictures
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 50, 50, "hour")));
	m_gameObjects.push_back(new Player(new LoaderParams(200, 200, 50, 50, "hour")));
	TextureManager::Instance()->load("hour.bmp", "hour", m_pRenderer);
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);	// clear the renderer to the draw color
	
//	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	// todo, render pictures
	for (auto i : m_gameObjects)
		i->draw();
//	TextureManager::Instance()->draw("hour", 0, 0, 50, 50, m_pRenderer);
//	TextureManager::Instance()->drawFrame("hour", 100, 100, 50, 50, 1, m_currentFrame, m_pRenderer);
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update() {
	for (auto i : m_gameObjects)
		i->update();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
		}
	}
}

void Game::clean() {
	std::cout << "clean game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::running() {
	return m_bRunning;
}

Game* Game::s_pInstance = nullptr;
