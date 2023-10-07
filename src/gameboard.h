#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "display.h"
#include "tile.h"
#include "boarder.h"

class GameBoard
{
   public:
      GameBoard();
      GameBoard(int colums, int rows, int mines);
      ~GameBoard();

      void Update();
      void Draw(RenderWindow& window);

      void resizeBoard(int colums, int rows, int mines);

      void openKlick(float xPos, float yPos);
      void open(int column, int row);
      void flag(float xPos, float yPos);
      void reset();
      void setFaceState(Face::State state);

      Time getGameTime();
      bool getGameOver();
      bool getGameWin();

   private:
      int m_colums;
      int m_rows;
      bool m_first;
      int m_mines;
      int m_minesLeft;
      int m_spaceLeft;
      bool m_gameOver;
      bool m_gameWin;

      Tile** m_tiles;
//      Display m_clockDisplay;
//      Display m_minesDisplay;
      Boarder* m_boarder;

      void initTiles();
      void deleteTiles();

      void generateMines(int free);
      int checkMines(int x, int y);

      void calc1dTo2d(int& x, int& y, int index);
      int calc2dTo1d(int x, int y);

      Clock m_clock;
      
      Clock m_gameClock;
      Time m_gameTime;
};

#endif