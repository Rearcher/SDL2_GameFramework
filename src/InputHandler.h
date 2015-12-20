#ifndef _inputhandler_
#define _inputhandler_

#include "SDL2/SDL.h"
#include <vector>
#include "Vector2D.h"

const int m_joystickDeadZone = 10000;

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

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
	
	bool getMouseButtonState(int buttonNumber) {
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D *getMousePosition() {
		return m_mousePosition;
	}

	bool isKeyDown(SDL_Scancode key) {
		if (m_keystates != nullptr) {
			if (m_keystates[key] == 1)
				return true;
			else
				return false;
		}
		return false;
	}
private:
	// private functions to handle different event types
	
	// handle keyboard events
	void onKeyDown();
	void onKeyUp();

	// handle mouse events
	void onMouseMove(SDL_Event &event);
	void onMouseButtonDown(SDL_Event &event);
	void onMouseButtonUp(SDL_Event &event);

	// handle joysticks events
	void onJoystickAxisMove(SDL_Event &event);
	void onJoystickButtonDown(SDL_Event &event);
	void onJoystickButtonUp(SDL_Event &event);

	InputHandler() {
		for (int i = 0; i < 3; i++)
			m_mouseButtonStates.push_back(false);
		m_mousePosition = new Vector2D(0, 0);
	}
	~InputHandler() {}

	static InputHandler *s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialized;
	
	// joystick
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;
	
	// mouse
	std::vector<bool> m_mouseButtonStates;
	Vector2D *m_mousePosition;

	// keyboard
	const Uint8 *m_keystates;
};
typedef InputHandler TheInputHandler;

#endif /* inputhandler */
