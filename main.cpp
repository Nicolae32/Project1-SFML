#include <SFML\Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), ":]");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                std::cout << "height :" << " " << event.size.height << " " << "width :" << " " << event.size.width<<"\n";

            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                
                std::cout << "Window Clicked!"<<"\n";
            }
            if (event.type == sf::Event::MouseWheelScrolled)
            {

                std::cout << "Wheel Scrolled" << "\n";
            }

        }

        window.clear();
        window.draw(shape);
        window.display();
    }


	return 0;
}