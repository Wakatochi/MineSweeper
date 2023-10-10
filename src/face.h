#ifndef FACE
#define FACE

#include <SFML/Graphics.hpp>

using namespace sf;

class Face
{
   public:
      Face();
      Face(float xPos, float yPos);
      ~Face();

      enum State
      {
         Face_Normal,
         Face_Open,
         Face_Win,
         Face_Dead
      };

      void Draw(RenderWindow& window);
      void setState(State state);

      void setPosition(float xPos, float yPos);

   private:
      float m_xPos;
      float m_yPos;
      State m_state;

      Sprite m_drawSprite;

};

#endif
