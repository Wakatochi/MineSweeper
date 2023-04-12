#include "gameboard.h"

#include "globals.h"
#include "resourcehandler.h"
#include <random>

using namespace std;

GameBoard::GameBoard()
{
   m_colums = 0;
   m_rows = 0;
   m_first = false;
   m_mines = 0;
   m_minesLeft = 0;
   m_spaceLeft = 0;
   m_gameOver = false;
   m_gameWin = false;

   m_tiles = NULL;
}

GameBoard::GameBoard(int colums, int rows, int mines)
{
   m_colums = colums;
   m_rows = rows;
   m_first = true;
   m_mines = mines;
   m_minesLeft = mines;
   m_gameOver = false;
   m_gameWin = false;
   m_spaceLeft = (m_colums * m_rows) - m_mines;
   m_gameTime = Time::Zero;

   initTiles();
}

GameBoard::~GameBoard()
{
   deleteTiles();
}

void
GameBoard::Draw(RenderWindow& window)
{
   for(int i = 0; i < m_colums * m_rows; i++)
   {
      m_tiles[i]->Draw(window);
   }

   ostringstream clockStr;
   ostringstream minesStr;
   clockStr << roundf(getGameTime().asSeconds() * 100) / 100;
   minesStr << m_minesLeft;
   
   m_clockDisplay.setText(clockStr.str());
   m_clockDisplay.Draw(window);

   m_minesDisplay.setText(minesStr.str());
   m_minesDisplay.Draw(window);
}

void
GameBoard::resizeBoard(int colums, int rows, int mines)
{
   deleteTiles();

   m_colums = colums;
   m_rows = rows;
   m_mines = mines;
   m_minesLeft = mines;
   m_spaceLeft = (m_colums * m_rows) - m_mines;

   initTiles();
}

void
GameBoard::openKlick(float xPos, float yPos)
{
   if(m_gameOver || m_gameWin)
   {
      return;
   }

   for(int i = 0; i < m_colums * m_rows; i++)
   {
      if(m_tiles[i]->getState() != Tile::State_Open && m_tiles[i]->clicked(xPos, yPos))
      {
         if(m_tiles[i]->getState() == Tile::State_Flagged)
         {
            return;
         }

         m_tiles[i]->setState(Tile::State_Open);
         if(m_tiles[i]->getMine())
         {
            m_gameOver = true;
            return;
         }

         if(m_first)
         {
            generateMines(i);
            m_gameClock.restart();
            m_first = false;
         }

         int x;
         int y;
         calc1dTo2d(x, y, i);

         open(x, y);

         return;
      }
   }
}

void
GameBoard::open(int column, int row)
{
   if(m_gameOver || m_gameWin)
   {
      return;
   }

   m_tiles[calc2dTo1d(column, row)]->setState(Tile::State_Open);

   if(m_tiles[calc2dTo1d(column, row)]->getMine())
   {
      m_gameOver = true;
      return;
   }

   m_spaceLeft--;
   if(m_spaceLeft == 0)
   {
      m_gameWin = true;
   }

   int val = checkMines(column, row);
   if(val == 0)
   {
      for(int i = -1; i < 2; i++)
      {
         for(int j = -1; j < 2; j++)
         {
            if((0 == i && 0 == j) || (0 > i + column || 0 > j + row || m_colums == i + column || m_rows == j + row))
            {
               continue;
            }

            if(m_tiles[calc2dTo1d(i + column, j + row)]->getState() == Tile::State_Closed)
            {
               open(i + column, j + row);
            }
         }
      }
   }
   else
   {
      m_tiles[calc2dTo1d(column, row)]->setValue(val);
   }

   return;
}

void
GameBoard::flag(float xPos, float yPos)
{
   if(m_gameOver || m_gameWin)
   {
      return;
   }

   for(int i = 0; i < m_colums * m_rows; i++)
   {
      if(m_tiles[i]->getState() != Tile::State_Open && m_tiles[i]->clicked(xPos, yPos))
      {
         if(m_tiles[i]->getState() == Tile::State_Open)
         {
            return;
         }
         else if(m_tiles[i]->getState() == Tile::State_Flagged)
         {
            m_tiles[i]->setState(Tile::State_Closed);
            m_minesLeft++;

            return;
         }

         m_tiles[i]->setState(Tile::State_Flagged);
         m_minesLeft--;

         return;
      }
   }
}

void
GameBoard::reset()
{
   resizeBoard(m_colums, m_rows, m_mines);
   m_first = true;
   m_gameOver = false;
   m_gameWin = false;
}

Time
GameBoard::getGameTime()
{
   if(m_first)
   {
      m_gameTime = Time::Zero;
   }
   else if(!m_gameOver && !m_gameWin)
   {
      m_gameTime = m_gameClock.getElapsedTime();
   }

   return m_gameTime;
}

bool
GameBoard::getGameOver()
{
   return m_gameOver;
}

bool
GameBoard::getGameWin()
{
   return m_gameWin;
}

void
GameBoard::initTiles()
{
   int col = 0;
   int row = 0;
   float size = 22.5f;
   int xOffset = (int)((global::Const_Window_Custom::WINDOW_WIDTH - (m_colums * size)) * 0.5f);
   int yOffset = (int)((global::Const_Window_Custom::WINDOW_HEIGHT - (m_colums * size)) * 0.5f);

   m_tiles = new Tile * [m_colums * m_rows];
   for(int i = 0; i < m_colums * m_rows; i++)
   {
      m_tiles[i] = new Tile(float((col * size) + xOffset) , float((row * size) + yOffset));

      if(col++ >= m_colums - 1)
      {
         row++;
         col = 0;
      }
   }
   m_clockDisplay.setPosition(xOffset + 50.0f, yOffset - 50.0f);
   m_minesDisplay.setPosition(xOffset + 180.0f, yOffset - 50.0f);
}

void
GameBoard::deleteTiles()
{
   for(int i = 0; i < m_colums * m_rows; i++)
   {
      if(m_tiles[i] != NULL)
      {
         delete m_tiles[i];
      }
   }

   if(m_tiles != NULL)
   {
      delete[] m_tiles;
   }
}

void
GameBoard::generateMines(int free)
{
   Time elapsed = m_clock.getElapsedTime();

   default_random_engine generator;
   uniform_int_distribution<int> distribution(0, (m_colums * m_rows) - 1);
   generator.seed((unsigned int)elapsed.asMicroseconds());

   int mines = 0;
   while(mines < m_mines)
   {
      int index = distribution(generator);

      while(!m_tiles[index]->getMine() && index != free)
      {
         m_tiles[index]->setMine(true);
         mines++;
      }
   }
}

int
GameBoard::checkMines(int x, int y)
{
   int retVal = 0;
   int checks[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

   // Calculate pos in 2d
   int pos = calc2dTo1d(x, y);

   if(y != 0)
   {
      if(x != 0)
      {
         checks[0] = pos - m_colums - 1;
      }

      checks[1] = pos - m_colums;
      
      if(x != m_colums -1)
      {
         checks[2] = pos - m_colums + 1;
      }
   }

   if(x != 0)
   {
      checks[3] = pos - 1;
   }

   if(x != m_colums -1)
   {
      checks[4] = pos + 1;
   }

   if(y != m_rows -1)
   {
      if(x != 0)
      {
         checks[5] = pos + m_colums - 1;
      }

      checks[6] = pos + m_colums;
      
      if(x != m_colums -1)
      {
         checks[7] = pos + m_colums + 1;
      }
   }
   for(int i = 0; i < 8; i++)
   {
      if(checks[i] >= 0 && checks[i] < m_colums * m_rows)
      {
         if(m_tiles[checks[i]]->getMine())
         {
            retVal++;
         }
      }
   }

   return retVal;
}

void
GameBoard::calc1dTo2d(int& x, int& y, int index)
{
   x = index % m_colums;
   y = (index - (index % m_rows)) / m_rows;
}

int
GameBoard::calc2dTo1d(int x, int y)
{
   return m_colums * y + x;
}