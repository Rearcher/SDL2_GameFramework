#include "PlayState.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	
	for (auto gameObject : m_gameObjects)
		gameObject->update();

	if(checkCollision(dynamic_cast<SDLGameObject*>
				(m_gameObjects[0]), dynamic_cast<SDLGameObject*>
				(m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()->pushState(new
				GameOverState());
	}
}

void PlayState::render() {
	for (auto gameObject : m_gameObjects)
		gameObject->draw();
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
				"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
				"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject *player = new Player(new LoaderParams(100, 500, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	GameObject *enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));
	m_gameObjects.push_back(enemy);

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	for (auto gameObject : m_gameObjects)
		gameObject->clean();

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject *p1, SDLGameObject *p2) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();
	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();
	//If any of the sides from A
	//are outside of B
	if( bottomA <= topB ){return false;}
	if( topA >= bottomB ){return false;}
	if( rightA <= leftB ){return false;}
	if( leftA >= rightB ){return false;}
	return true;
}
