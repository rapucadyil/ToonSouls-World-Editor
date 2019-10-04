#include <SFML/Graphics.hpp>
#include "gui_lib/gui_lib.hpp"
using namespace integra::ui;
int main()
{
    render_target window(sf::VideoMode(1920, 1080), "Integra Engine [-editor]");
    auto half_width = window.getView().getCenter().x;
    auto half_height = window.getView().getCenter().y;
    label *lb = new label("INTEGRA EDITOR",600,550);   //@TODO -> not perfectly in the center but ok
    panel *pnl = new panel(1920,25,0,0);
     
    
    while (window.isOpen())
    {
        integra_evt event;
        while (window.pollEvent(event))
        {
            if (event.type == integra_evt::Closed)
                window.close();
            if(event.type == integra_evt::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        window.clear(integra_color4::White);
        lb->render(window, integra_color4::Blue);
	pnl->render(window, integra_color4(128, 128, 200, 128));
        window.display();
    }

    return 0;
}
