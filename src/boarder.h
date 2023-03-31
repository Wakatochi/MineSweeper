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

      void Draw();
      void Update();

   private:
      float m_sizeX;
      float m_sizeY;

      Face* m_face;
      Display* m_time;
      Display* m_mines;
};

#endif