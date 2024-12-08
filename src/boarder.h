#ifndef BOARDER_H
#define BOARDER_H

#include <SFML/Graphics.hpp>
#include "face.h"
#include "display.h"

class Boarder
{
   public:
      Boarder();
      ~Boarder();

      void setBoarderSize(float x, float y);
      void SetFaceStatus(Face::State state);
      void setClockPosition(float x, float y);
      void setMinePosition(float x, float y);
      void setFacePosition(float x, float y);

      Vector2f getDisplaySize();

      void Update(sf::String clockStr, sf::String minesStr);
      void Draw(RenderWindow& window);

   private:
      float m_sizeX;
      float m_sizeY;

      sf::RectangleShape m_frame;
      Face* m_face;
      Display* m_time;
      Display* m_mines;
};

#endif