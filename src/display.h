#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
 
using namespace sf;

class Display
{
   public:
      Display();
      Display(float x, float y);
      ~Display();

      void setPosition(float x, float y);
      void setText(String text);

      void Draw(RenderWindow& window);

   private:
      float m_xPos;
      float m_yPos;
      
      RectangleShape m_display;
      Text m_text;

      const float SIZE_X = 65.0f;
      const float SIZE_Y = 30.0f;
      const float TEXT_OFFSET_X = 2.0f;
      const float TEXT_OFFSET_Y = - 5.0f;
};

#endif
