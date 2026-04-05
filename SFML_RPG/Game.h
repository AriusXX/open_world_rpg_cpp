#ifndef GAME_H
#define GAME_H


#include "MainMenuState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();


public:
	//constructors and destructors
	Game();
	virtual ~Game();

	//Functions

	//Regular
	void  endApplication();

	//Update
	void updateDT();
	void updateSFMLEvents();
	void update();


	//Render
	void render();

	//Core
	void run();


};

#endif

