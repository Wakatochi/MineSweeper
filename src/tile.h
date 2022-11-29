#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Tile
{
   public:
      Tile();
      Tile(float x, float y);
      ~Tile();

      enum State
      {
         State_Closed,
         State_Open,
         State_Flagged,
         State_Mine
      };

     void Draw(RenderWindow& window);
     bool clicked(float xPos, float yPos);

     void setState(State state);
     void setValue(int value);
     void setMine(bool mine);

     State getState();
     int getValue();
     bool getMine();

   private:
      float m_xPos;
      float m_yPos;

      bool m_mine;
      int m_value;
      Rect<float> m_rect;

      State m_currentState;
};

#endif
