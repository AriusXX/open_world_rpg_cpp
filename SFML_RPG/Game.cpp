#include "Game.h"

//Static functions


//Initializer functions
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "C++ SFML RPG");
}



//Constructors and Destructors
Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


//Functions
void Game::updateSFMLEvents()
{
    while (const std::optional event = this->window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();
    
    // Render items here
    
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }

}
