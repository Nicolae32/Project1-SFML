#include <SFML\Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), ":]");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);   
    sf::Clock clock;  
    sf::Time time;
    sf::Event event;




    while (window.isOpen())                            //The game loop.
    {
        
        

        time = clock.getElapsedTime();

        //std::cout << int(time.asSeconds())<< "\n";  //Gets time in seconds as integer.
      
        
       

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
                
                case sf::Event::MouseButtonPressed:
                      shape.setFillColor(sf::Color::Blue);
                  
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