#include <SFML\Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), ":]");
    sf::RectangleShape player(sf::Vector2f(200, 200));
    player.setFillColor(sf::Color::Red);   
    sf::Clock clock;  
    sf::Time time;
    sf::Event event;
    sf::Text text;
   

    while (window.isOpen())                            //The game loop.
    {

        player.setOrigin(player.getSize().x / 2, player.getSize().y / 2); //Sets the origin of the player in the middle.

        time = clock.getElapsedTime();

        std::cout << int(time.asSeconds()) << "\n";      //Gets time in seconds as integer.




        while (window.pollEvent(event))
        {

            switch (event.type)                        //The debugging thing.
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

            case sf::Event::MouseButtonPressed:
                player.setFillColor(sf::Color::Blue);

                break;

            case sf::Event::MouseButtonReleased:
                player.setFillColor(sf::Color::Red);
                break;



            }

        }
        /*
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))       //Gets the Keyboard input.
           {

           player.move(-0.1f, 0.0f);

           }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
           {

           player.move(0.0f, -0.1f);

           }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
           {

           player.move(0.0f, 0.1f);

           }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
           {

           player.move(0.1f, 0.0f);

           }
           */

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))         //Moves the player to mouse.
        {
            sf::Vector2i mspoz = sf::Mouse::getPosition(window);
            player.setPosition(static_cast<float>(mspoz.x), static_cast<float>(mspoz.y));
            
        }
            
        window.clear();
        window.draw(player);
        window.display();
    }


	return 0;
}