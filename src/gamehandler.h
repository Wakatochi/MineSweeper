#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <SFML/Graphics.hpp>
#include "gameboard.h"
#include "face.h"

using namespace sf;

class GameHandler
{
   public:
      GameHandler();
      ~GameHandler();

      bool Run();

   private:
      RenderWindow* m_mainWindow;
      GameBoard* m_board;
      Face* m_face;

      void InitWindow();

      bool Update();
      void Draw();
};

#endif
