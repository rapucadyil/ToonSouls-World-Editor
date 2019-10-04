#include "definitions.hpp"
namespace integra {
    namespace ui {
        /*
            This struct represents a label for the Graphical User Interface
        */
        struct label {
            integra_font font;
            integra_text text;
            str display_text;
            real32 xpos, ypos;

            label(str text_to_display);
            label(str text_to_display, real32 x, real32 y);
            ~label();
            
            /*
                This is to change the default font passed in via constructor

                @param[in] : font_fp - the filepath pointing to the .ttf or .otf file
            */
            void set_font(const str font_fp);

            /* 
                This is to set the value of the text label of this gui label

                @param[in] : val - the string value to set for this gui label
            */
            void set_text_string(const str val);

            /*
                This renders the given gui label with the preset attributes

                @param[in] : window - the window to render to

                @param[in] : color - the color to render this label with
            */
            void render(render_target& window, integra_color4 color);

        };

        struct panel {
          integra_rect *panel_rectangle;
          real32 xpos, ypos;
          real32 width, height;
   	  integra_color4 color;

          panel(real32 w, real32 h, real32 x, real32 y);
          ~panel();
	  
	  /*
	   *	This will update the panel including position and other attributes 
	   *	in real-time while the editor is running. 
	   */
	  void update_panel();
	  
	  void render(render_target& target, integra_color4 col); 		  
          

        };
    }
}
