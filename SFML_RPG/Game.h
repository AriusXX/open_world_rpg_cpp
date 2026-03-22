#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//Initialization
	void initWindow();
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

