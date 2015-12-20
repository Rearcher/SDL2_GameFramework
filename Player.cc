#include "SDL2/SDL.h"
#include "Player.h"

Player::Player(const LoaderParams *pParams) :
	SDLGameObject(pParams) {}

void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
//	m_position.setX(m_position.getX() + 1);
	m_acceleration.setX(1);
//	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::clean() {

}
