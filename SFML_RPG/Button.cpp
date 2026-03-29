#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, sf::Color idleColor,
	sf::Color hoverColor, sf::Color activeColor)
	: font(font),
	text(*font, text, 12)
{
	this->buttonState = BTN_IDLE;

	//Set the position and size of the button
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	//Set button collor and text properties
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition({
		this->shape.getPosition().x + this->shape.getSize().x / 2.f - this->text.getGlobalBounds().size.x / 2.f,
		this->shape.getPosition().y + this->shape.getSize().y / 2.f - this->text.getGlobalBounds().size.y / 2.f
		});
	//Set the colors for different states of the button
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	//Set the initial color of the button to idle
	this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{
}


//Accessors

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;
	return false;
}


//Functions

void Button::update(const sf::Vector2f mousePos)
{
	/*Update the booleans for hover and pressed*/

	//Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}

}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
