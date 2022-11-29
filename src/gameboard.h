#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "tile.h"

class GameBoard
{
   public:
      GameBoard();
      GameBoard(int colums, int rows, int mines);
      ~GameBoard();

      void Draw(RenderWindow& window);

      void resizeBoard(int colums, int rows, int mines);

      void openKlick(float xPos, float yPos);
      void open(int column, int row);
      void flag(float xPos, float yPos);
      void reset();

   private:
      int m_colums;
      int m_rows;
      bool m_first;
      int m_mines;
      int m_minesLeft;

      Tile** m_tiles;

      void initTiles();
      void deleteTiles();

      void generateMines(int free);
      int checkMines(int x, int y);

      void calc1dTo2d(int& x, int& y, int index);
      int calc2dTo1d(int x, int y);

      Clock m_clock;
};

#endif