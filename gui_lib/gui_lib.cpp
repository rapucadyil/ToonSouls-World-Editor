#include "gui_lib.hpp"
namespace integra {
    namespace ui {
        label::label(str text_to_display) {
            this->display_text = text_to_display;
        }

        label::label(str text_to_display, real32 x, real32 y) {
            this->xpos = x;
            this->ypos = y;
            this->display_text = text_to_display;
            if(!this->font.loadFromFile("Imperfecta.ttf")) {
                system("EXIT");
            }
            this->text.setFont(this->font);
            this->text.setString(text_to_display);
        }

        label::~label() {

        }

        void label::set_font(const str font_fp) {
            if(!this->font.loadFromFile(font_fp)) {
                printf("Could not load font");
                system("EXIT");
            }else{
                this->text.setFont(font);
            }
        }

        void label::render(render_target& window, integra_color4 color) {
            this->text.setPosition(this->xpos, this->ypos);
            this->text.setFillColor(color);
            window.draw(this->text);
        }



	panel::panel(real32 w, real32 h, real32 x, real32 y) {
	    this->width = w;
	    this->height = h;
	    this->panel_rectangle = new integra_rect(vec2f(w, h));
	    this->xpos = x;
	    this->ypos = y;
	}

	panel::~panel() {
	    // Does nothing at the moment
	}

	void panel::update_panel() {
	    // Does nothing at the moment
	
	}
	void panel::render(render_target& target, integra_color4 col) {
	    this->panel_rectangle->setPosition(this->xpos, this->ypos);
	    this->panel_rectangle->setFillColor(col);
	    target.draw(*this->panel_rectangle);
	}
    }

}
