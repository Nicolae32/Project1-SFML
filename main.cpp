#include <SFML\Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), ":]");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
       
        sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
            

       

        while (window.pollEvent(event))
        {

            switch (event.type)
            {

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::Resized:
                    std::cout << "height :" << " " << event.size.height << " " << "width :" << " " << event.size.width << "\n";
                    break;
                case sf::Event::MouseWheelScrolled:
                    std::cout << "Wheel Scrolled" << "\n";
                    break;
                //beta:
                case sf::Event::MouseButtonPressed:
                      shape.setFillColor(sf::Color::Blue);
                    //std::cout << "Window Clicked!" << "\n";
                     
                    break;

                case sf::Event::MouseButtonReleased:
                    shape.setFillColor(sf::Color::Red);
                    break;



            }
           
        }

        window.clear();
        window.draw(shape);
        window.display();
    }


	return 0;
}