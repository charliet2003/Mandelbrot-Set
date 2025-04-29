#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

#include "ComplexPlane.h"

int main()
{
	int pixelWidth =  500; // VideoMode::getDesktopMode().width / 2;
	int pixelHeight = 500; // VideoMode::getDesktopMode().height / 2;
	VideoMode vm(pixelWidth, pixelHeight);
	RenderWindow window(vm, "Mandelbrot Set", Style::Default);

	ComplexPlane c(pixelWidth, pixelHeight);

	Font font;
        if (!font.loadFromFile("fonts/Ubuntu-Regular.ttf"))
        {
                return 1;
        }

	Text text;
	text.setFont(font);
	text.setCharacterSize(24);

	while (window.isOpen())
	{

		///Input

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::MouseButtonPressed)
                        {       
                                if (Mouse::isButtonPressed(Mouse::Button::Right))
				{
					c.zoomOut();
					c.setCenter(sf::Mouse::getPosition(window));
				}

				if (Mouse::isButtonPressed(Mouse::Button::Left))
                                {
                                        c.zoomIn();
					c.setCenter(sf::Mouse::getPosition(window));
                                } 
                        }

			if (event.type == Event::MouseMoved)
			{
				c.setMouseLocation(sf::Mouse::getPosition(window));
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
                {       
                        window.close();
                }

		///Update

		c.updateRender();
		c.loadText(text);

		///Draw	

		window.clear();

		window.draw(c);
		window.draw(text);

		window.display();

	}

	return 0;
}
