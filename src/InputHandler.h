#ifndef _inputhandler_
#define _inputhandler_

#include "SDL2/SDL.h"
#include <vector>
#include "Vector2D.h"

const int m_joystickDeadZone = 10000;

class InputHandler {
public:
	static InputHandler *Instance() {
		if (s_pInstance == nullptr) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();
	
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	void initializeJoysticks();
	bool joysticksInitialized() {
		return m_bJoysticksInitialized;
	}

	bool getButtonState(int joy, int buttonNumber) {
		return m_buttonStates[joy][buttonNumber];
	}

private:
	InputHandler() {};
	~InputHandler() {}

	static InputHandler *s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialized;

	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;
};
typedef InputHandler TheInputHandler;

#endif /* inputhandler */
